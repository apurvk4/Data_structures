#include<iostream>
#include<unordered_map>
struct Node 
{ 
    int data; 
    Node *next,*random; 
    Node(int x) 
    { 
        data = x; 
        next = random = NULL; 
    } 
}; 
  
void print(Node *start) 
{ 
    Node *ptr = start; 
    while (ptr) 
    { 
        std::cout << "Data = " << ptr->data << ", Random  = "
             << ptr->random->data << std::endl; 
        ptr = ptr->next; 
    } 
} 
Node* clone(Node *start){
    std::unordered_map<Node *,Node *> mp,mp1;
    Node * head=nullptr;
    Node * tail=nullptr;
    while(start !=nullptr){
        Node * ptr=new Node(start->data);
        mp[ptr]=start;
        mp1[start]=ptr;
        ptr->next=nullptr;
        if(head !=nullptr){
          tail->next=ptr;
          tail=ptr;
        }else{
            head=ptr;
            tail=ptr;
        }
        start=start->next;
    }
    Node * ptr=head;
    while(ptr !=nullptr){
        Node * temp=mp[ptr]->random;
        if(mp1.find(temp) !=mp1.end()){
            temp=mp1[temp];
        }else{
            temp=nullptr;
        }
        ptr->random=temp;
        ptr=ptr->next;
    }
    return head;
}
int main(){
      Node* start = new Node(1); 
    start->next = new Node(2); 
    start->next->next = new Node(3); 
    start->next->next->next = new Node(4); 
    start->next->next->next->next = new Node(5); 
    // 1's random points to 3 
    start->random = start->next->next; 
  
    // 2's random points to 1 
    start->next->random = start; 
  
    // 3's and 4's random points to 5 
    start->next->next->random = 
                    start->next->next->next->next; 
    start->next->next->next->random = 
                    start->next->next->next->next; 
  
    // 5's random points to 2 
    start->next->next->next->next->random = 
                                      start->next; 
  
    std::cout << "Original list : \n"; 
    print(start); 
  
    std::cout << "\nCloned list : \n"; 
    Node *cloned_list = clone(start); 
    print(cloned_list); 
    return 0; 
}