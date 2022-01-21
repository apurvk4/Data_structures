#include<bits/stdc++.h>
using namespace std;
struct triple{
    int first;
    int second;
    int third;
    triple(int a,int b,int c):first{a},second{b},third{c}{
    }
    bool operator==(const triple & other){
        if(this->first==other.first && this->second==other.second && this->third==other.third){
            return true;
        }
        return false;
    }
};
struct myComp { 
    constexpr bool operator()( 
        triple const& a, 
        triple const& b) 
        const noexcept 
    { 
     return a.third < b.third;  
    } 
}; 
class user{
    public:
     int id;
     priority_queue<triple, vector<triple>, myComp> Tweets; 
     std::unordered_set<int> followers;
     std::unordered_set<int> followings;
     user(int id_):id{id_}{
     }
};
class dataBase{
    std::unordered_map<int,user * > mp;
    public:
     bool find(int id){return mp.find(id) != mp.end();}
     user * get_user(int id){
         return mp[id];
     }
     void add(int id){
         if(mp.find(id)==mp.end()){
             mp[id]=new user(id);
         }
     }
     dataBase(){
     }
};
class Twitter {
    dataBase db;
    int u_id;
    void sync_feed(int userId,int followeeId){
        user * owee=db.get_user(followeeId);
        user * ower=db.get_user(userId);
        std::vector<triple> temp;
        while(!owee->Tweets.empty()){
            if(owee->Tweets.top().first==followeeId){
                ower->Tweets.push(owee->Tweets.top());
                temp.push_back(owee->Tweets.top());
                owee->Tweets.pop();
            }else{
                temp.push_back(owee->Tweets.top());
                owee->Tweets.pop();
            }
        }
        for(int i=0;i<temp.size();i++){
            owee->Tweets.push(temp[i]);
        }
    }
public:
    /** Initialize your data structure here. */
    Twitter():u_id{0}{
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if(!db.find(userId)){
            db.add(userId);
        }
        user *u=db.get_user(userId);
        u->Tweets.push({userId,tweetId,++u_id});
        for(auto f : u->followers){
            user * temp=db.get_user(f);
            temp->Tweets.push({userId,tweetId,++u_id});
        }
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        std::vector<int> out;
        if(!db.find(userId)){
            db.add(userId);
            return out;
        }
        std::vector<triple> feed;
        user * u=db.get_user(userId);
        while(feed.size()<10 && !u->Tweets.empty()){
            feed.push_back(u->Tweets.top());
            u->Tweets.pop();
        }
        for(int i=0;i<feed.size();i++){
            u->Tweets.push(feed[i]);
        }
        for(int i=0;i<feed.size();i++){
            out.push_back(feed[i].second);
        }
        return out;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId==followeeId){
            return;
        }
        if(!db.find(followeeId)){
            db.add(followeeId);
        }
        if(!db.find(followerId)){
            db.add(followerId);
        }
        if(db.get_user(followeeId)->followers.count(followerId)==1){
            return;
        }
        user * f=db.get_user(followeeId);
        f->followers.insert(followerId);
        user * f1=db.get_user(followerId);
        f1->followings.insert(followeeId);
        sync_feed(followerId,followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followerId==followeeId){
            return;
        }
        if(!db.find(followeeId)){
            db.add(followeeId);
        }
        if(!db.find(followerId)){
            db.add(followerId);
        }
        if(db.get_user(followeeId)->followers.count(followerId)==0){
            return;
        }
        std::vector<triple> temp;
        while(!db.get_user(followerId)->Tweets.empty()){
            if(db.get_user(followerId)->Tweets.top().first==followeeId){
                db.get_user(followerId)->Tweets.pop();
            }else{
                temp.push_back(db.get_user(followerId)->Tweets.top());
                db.get_user(followerId)->Tweets.pop();
            }
        }
        for(int i=0;i<temp.size();i++){
            db.get_user(followerId)->Tweets.push(temp[i]);
        }
        user * ower=db.get_user(followerId);
        ower->followings.erase(followeeId);
        user * owee=db.get_user(followeeId);
        owee->followers.erase(followerId);
    }
};
 int main(){
    Twitter* obj = new Twitter();
    obj->postTweet(1,5);
    obj->postTweet(1,3);
    for(auto num : obj->getNewsFeed(1)){
        std::cout<<num<<" ";
    }
    std::cout<<"\n";
    obj->follow(1,2);
    obj->postTweet(2,1);
    for(auto num : obj->getNewsFeed(1)){
        std::cout<<num<<" ";
    }
    std::cout<<"\n";
    obj->unfollow(1,2);
    for(auto num : obj->getNewsFeed(1)){
        std::cout<<num<<" ";
    }
    std::cout<<"\n";
     return 0;
 }