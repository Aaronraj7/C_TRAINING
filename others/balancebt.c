//is the binary tree balanced?

#include<stdio.h>
#include<stdlib.h>

#define MAX(a,b) ((a>b)?a:b)
#define ABS(a) ((a>0)?a:-(a))

typedef struct Node{
    int data;
    struct Node *left, *right;
}Node;

int checkbalance(Node* root){
    if(!root) return 0;
    
    int left=checkbalance(root->left);
    if(left==-1) return -1;
    
    int right=checkbalance(root->right);
    if(right==-1) return -1;

    if(ABS(left-right)>1) return -1;

    return MAX(left,right)+1;
}

int isbalanced(Node* root){
    return(checkbalance(root)!=-1);
}

Node* createNode(int val){  
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=val;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

Node* insert(Node* root, int val){
    if(!root) return createNode(val);

    if(root->data>val){
        root->left=insert(root->left,val);
    }
    else if(root->data<val){ 
        root->right=insert(root->right,val);
    }
    return root;
}

int main(){
    Node* root=NULL;
    int n,a;
    printf("Enter n: \n");
    scanf("%d",&n);
    printf("Enter values for each node: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        root=insert(root,a);
    }
    if(isbalanced(root)) printf("balanced\n");
    else printf("Unbalanced\n");

    return 0;
}
