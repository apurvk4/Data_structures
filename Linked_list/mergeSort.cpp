#include<iostream>
struct Node{
    int data;
    Node * next;
    Node(int x){
        data=x;
        next=NULL;
    }
    };
    void insert_before(Node * prev,Node * thisNode,Node * newNode){
    if(prev==NULL){
        newNode->next=thisNode;
    }else{
        prev->next=newNode;
        newNode->next=thisNode;
    }
}
void insert_after(Node * thisNode,Node * newNode){
    newNode->next=thisNode->next;
    thisNode->next=newNode;
}
Node* sortedMerge(Node* head_A, Node* head_B)  
{  
    if(head_A==NULL){
        return head_B;
    }
    if(head_B ==NULL){
        return head_A;
    }
    Node * tempA=head_A;
    Node * tempB=head_B;
    Node * preA=NULL;
    Node *newHead;
    if(head_A->data < head_B->data){
        newHead=head_A;
    }else{
        newHead=head_B;
    }
    while(tempA !=NULL && tempB !=NULL){
        if(tempA->data < tempB->data){
            preA=tempA;
            tempA=tempA->next;
        }else{
            Node * nxt=tempB->next;
            insert_before(preA,tempA,tempB);
            preA=tempB;
            tempB=nxt;
        }
    }
    while(tempB !=NULL){
        Node * nxt=tempB->next;
        insert_after(preA,tempB);
        preA=preA->next;
        tempB=nxt;
    }
    return newHead;
}
Node * mergeSort(Node * head,Node * tail){
    if(head==tail){return head;}
    Node * slow=head;
    Node * fast=head;
    while(fast->next->next !=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast->next==NULL){
            break;
        }
    }
   Node * slownxt=slow->next;
   slow->next=NULL;
   return sortedMerge(mergeSort(head,slow),mergeSort(slownxt,tail));
}
void push_back(Node **head,Node **tail,Node ** nxt){
    if(*head==NULL){
        *head=*nxt;
        *tail=*nxt;
    }else{
        (*tail)->next=*nxt;
        *tail=*nxt;
    }
}
int main(){
    int size;
    std::cout<<"size : ";
    std::cin>>size;
    Node * head=NULL;
    Node * tail=NULL;
    for(int i=0;i<size;i++){
        int num;
        std::cin>>num;
        Node * temp=new Node(num);
        push_back(&head,&tail,&temp);
    }

  head= mergeSort(head,tail);
  while(head !=nullptr){
      std::cout<<head->data<<" ";
      head=head->next;
  }
  std::cout<<"\n";
    return 0;
}