//check valid paranthesis
#include<stdio.h>
#include<stdlib.h>
//int stack[100];
//int top=-1;

typedef struct Node{
    char data;
    struct Node *next;
}Node;
Node* top=NULL;

void push(char c){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=c;
    newNode->next=top;
    top=newNode;
}

char pop(){
    if(!top){
        return 0;
    }
    Node *temp=top;
    top=top->next;
    int popped=temp->data;
    free(temp);
    return popped;
}

int isEmpty(){
    return (top==NULL);
}

/*
void push_stack(char c){return stack[++top];}
char pop_stack(){return (top==-1)?0:stack[top--];}
int isEmpty_stack(){return top==-1;}
*/

int check_paranthesis(char* exp){
    for(int i=0;exp[i]!='\0';i++){
        char ch=exp[i];
        if(ch=='('|| ch=='['|| ch=='{'){
            push(ch);
        }
        
        else if(ch==')'|| ch==']'|| ch=='}'){
            if(isEmpty())   return 0;
            char last=pop();
            if(ch==')' && last!='('|| ch=='}' && last!='{'|| ch==']' && last!='[')   return 0;
        }
    }
    return isEmpty();
}

int main(){
    char exp[]="{}([])";
    if(!check_paranthesis(exp))  printf("Not balanced\n");
    else printf("Balanced\n");
    return 0;
}
