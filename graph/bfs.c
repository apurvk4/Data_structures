#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int v;
struct queue{
    int data;
    struct queue * prev;
    struct queue * next;
};
struct queue * root=NULL;
struct queue * end=NULL;
void enqueue(int val){
 if(root==NULL){
    root=malloc(sizeof(struct queue));
    root->next=NULL;
    root->prev=NULL;
    root->data=val;
    end=root;
    return;
 }
 struct queue * temp=malloc(sizeof(struct queue));
 temp->next=NULL;
 temp->data=val;
 temp->prev=end;
 end->next=temp;
 end=temp;
}
void dequeue(){
    if(root==NULL){
        return;
    }
    if(root==end){
        free(root);
        root=NULL;
        end=NULL;
        return;
    }
    struct queue * temp=root;
    root=root->next;
    free(temp);
    root->prev=NULL;
}
int top(){
   return root->data;
}
void clear(){
    struct queue * temp=root;
    struct queue * pre=NULL;
    while(temp !=NULL){
        pre=temp;
        temp=temp->next;
        free(pre);
    }
}
bool empty(){
    return root==NULL;
}
int main(){
   int v;
   scanf("%d",&v);
   int g[v][v];
   for(int i=0;i<v;i++){
      for(int j=0;j<v;j++){
         int d;
         scanf("%d",&d);
         g[i][j]=d;
       }
   }
   bool visited[v];
   for(int i=0;i<v;i++){
      visited[i]=false;
   }
   int j=0;
   enqueue(j);
   visited[j]=1;
   while(!empty()){
      for(int i=0;i<v;i++){
         if(g[top()][i]==1){
            if(visited[i]==0){
                enqueue(i);
                visited[i]=1;
            }
         }
      }
      printf("%d ",top());
      dequeue();
   }
   printf("\n");
   clear();
   return 0;
}