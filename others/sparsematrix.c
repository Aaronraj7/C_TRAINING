//sparse matrix
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int row;
    int col;
    int value;
    struct Node *next;
}Node;

Node* create(int r, int c, int val){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->row=r;
    newNode->col=c;
    newNode->value=val;
    newNode->next=NULL;
    return newNode;
}

void insert(Node **head, int r, int c, int val){
    if(!val)  return;
    Node* newNode=create(r,c,val);
    if(!*head) *head=newNode;
    else{
        Node *temp = *head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}

void print(Node **pos,int i, int j){
    Node* temp=*pos;
    if(temp && temp->row==i && temp->col==j){
        printf("%d ",temp->value);
        *pos=temp->next;
    }
    else{
        printf("0 ");
    }
}

int main(){
    Node* head=NULL;
    /*int arr[3][3]={ 
        1,0,0,
        0,0,4,
        5,0,0    
    };*/
    int r,c;
    printf("Enter r , c : \n");
    scanf("%d %d",&r,&c);
    int arr[r][c];
    printf("Enter matrix elements: \n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&arr[i][j]);
            insert(&head,i,j,arr[i][j]);
        }
    }
    Node* curr=head;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            print(&curr,i,j);
        }
        printf("\n");
    }
    return 0;
}
