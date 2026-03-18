//delete from binarytree
#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node *left, *right;
};
void freetree(struct node* root){
    if(root==NULL){
        return;
    }
    freetree(root->left);
    freetree(root->right);
    free(root);
}
struct node* findMin(struct node *root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
struct node* deleteNode(struct node* root,int key){
    if(root==NULL) return root;
    if(key<root->value)
        root->left=deleteNode(root->left,key);
    else if(key>root->value)
        root->right=deleteNode(root->right,key);
    else{
        if(root->left==NULL){
            struct node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct node *temp=root->left;
            free(root);
            return temp;
        }     
        struct node *temp=findMin(root->right);
        root->value=temp->value;
        root->right=deleteNode(root->right,temp->value);
    }
    return root;       
}
struct node* createNode(int value){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->value=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
struct node* insert(struct node* root,int value){
    if(root==NULL) return createNode(value);
    if(value<root->value){
        root->left=insert(root->left,value);
    }
    else if(value>root->value){
        root->right=insert(root->right,value);
    }
    return root;
}
void inorder(struct node* root){
    if(root){
      inorder(root->left);
      printf("%d ",root->value);
      inorder(root->right);
    }
}
int main(){
    struct node *root=NULL;
    int n,value;
    printf("Enter size of bst: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter value %d: ",i+1);
        scanf("%d",&value);
        root=insert(root,value);
    }
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    printf("Enter element to delete: ");
    scanf("%d",&n);
    root=deleteNode(root,n);
    printf("Inorder after deletion: ");
    inorder(root);
    printf("\n");
    freetree(root);
    return 0;
}
