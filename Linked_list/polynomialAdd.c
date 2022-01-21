#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int coeff;
    int pow;
    struct node * next;
};
void insert(int pow,int coeff,struct node ** h,struct node **t){
    struct node * head=*h;
    struct node * tail=*t;
    if(head==NULL){
        head=malloc(sizeof(struct node));
        head->coeff=coeff;
        head->pow=pow;
        head->next=NULL;
        tail=head;
        *t=tail;
        *h=head;
    }else{
        struct node * temp=head;
        while(temp !=NULL){
            if(temp->pow==pow){
                temp->coeff+=coeff;
                break;
            }
            temp=temp->next;
        }
        if(temp==NULL){
            temp=malloc(sizeof(struct node));
            temp->coeff=coeff;
            temp->pow=pow;
            temp->next=NULL;
            tail->next=temp;
            tail=temp;
            *t=tail;
        }
    }
}

struct node * add(struct node ** p1,struct node **p2){
    int arr[100];
    struct node *nhead=NULL;
    struct node *ntail=NULL;
    struct node * temp=*p1;
    while(temp !=NULL){
        arr[temp->pow]=temp->coeff;
        temp=temp->next;
    }
    temp=*p2;
    while(temp != NULL){
        if(nhead==NULL){
            nhead=malloc(sizeof(struct node));
            nhead->next=NULL;
            ntail=nhead;
            nhead->pow=temp->pow;
            nhead->coeff=arr[temp->pow]+temp->coeff;
        }else{
            ntail->next=malloc(sizeof(struct node));
            ntail->next->next=NULL;
            ntail->next->pow=temp->pow;
            ntail->next->coeff=arr[temp->pow]+temp->coeff;
            ntail=ntail->next;
        }
        temp=temp->next;
    }
    return nhead;
}

int main(){
    struct node *p1h=NULL,*p1t=NULL,*p2h=NULL,*p2t=NULL;
    insert(3,1,&p1h,&p1t);
    insert(2,3,&p1h,&p1t);
    insert(1,4,&p1h,&p1t);
    insert(0,5,&p1h,&p1t);
    insert(3,5,&p2h,&p2t);
    insert(2,4,&p2h,&p2t);
    insert(1,3,&p2h,&p2t);
    insert(0,2,&p2h,&p2t);
    struct node * h=add(&p1h,&p2h);
    while(h !=NULL){
        printf("%dx%d +",h->coeff,h->pow);
        h=h->next;
    }
    printf("\n");
    return 0;
}