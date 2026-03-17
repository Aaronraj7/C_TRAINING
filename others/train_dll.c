//sim compartment management using doubly linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct Comp{
    int compartment_no;
    int seat_count;
    struct Comp *next, *prev;
}Comp;

Comp* create_compartment(int n,int count){
    Comp* new_compartment=(Comp*)malloc(sizeof(Comp));
    new_compartment->compartment_no=n;
    new_compartment->next=NULL;
    new_compartment->prev=NULL;
    new_compartment->seat_count=count;
    return new_compartment;
}
Comp* add_compartment(Comp* head,int seats,int c){
    if(!head){
            return create_compartment(1,seats);
        }
    if(c){
        Comp* new_compartment=create_compartment(1,seats);
        new_compartment->next=head;
        head->prev=new_compartment;
        head=new_compartment;
        Comp* temp=head;
        int count=1;
        while(temp){
            temp->compartment_no=count++;
            temp=temp->next;
        }
        
    }
    else{
        Comp *new,*temp=head;
        while(temp->next){
            temp=temp->next;
        }
        new=create_compartment(temp->compartment_no+1,seats);
        new->prev=temp;
        temp->next=new;
    }
    return head;
}

void print_train(Comp* head,int c){
    if(!head){
        printf("No compartments\n");
        return;
    }
    Comp* temp=head;
    if(c){
        printf("Engine");
        while(temp){
            printf("<->[Comp: %d | seats: %d]",temp->compartment_no,temp->seat_count);
            temp=temp->next;
        }
        printf("\n");
    }
    else{
        while(temp->next){
            temp=temp->next;
        }
        while(temp){
            printf("[Comp: %d | seats: %d]<->",temp->compartment_no,temp->seat_count);
            temp=temp->prev;
        }
        printf("Engine\n");
    }
}

Comp* remove_compartment(Comp* head, int comp_no){
    if(!head){
        printf("No compartments :(\n");
        return NULL;
    }
    Comp* temp=head;
    while(temp && temp->compartment_no!=comp_no){
        temp=temp->next;
    }
    if(!temp){
        printf("Compartement %d not found\n",comp_no);
        return head;
    }
    if(temp==head){
        head=temp->next;
        if(head){
            head->prev=NULL;
        }
    }
    else{
        temp->prev->next=temp->next;
        if(temp->next){
            temp->next->prev=temp->prev;
        }
    }
    free(temp);
    return head;
}
void free_train(Comp* head) {
    Comp* current = head;
    Comp* next_node;
    while (current != NULL) {
        next_node = current->next; 
        free(current); 
        current = next_node; 
    }
}

int main(){
    Comp* train=NULL;
    int c,n,seats;
    train=add_compartment(train,45,0);
    train=add_compartment(train,45,0);
    train=add_compartment(train,45,0);
    train=add_compartment(train,45,0);
    print_train(train,1);
    printf("Enter 1 to add in front and 0 to add at rear\n");
    scanf("%d",&c);
    printf("Enter number of compartments to add: \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter no. of seats in this compartment\n");
        scanf("%d",&seats);
        train=add_compartment(train,seats,c);
    }
    printf("Enter 1 to view from front and 0 to view from rear\n");
    scanf("%d",&c);
    print_train(train,c);

    printf("Enter compartment no. to remove: \n");
    scanf("%d",&n);
    printf("After removing\n");
    train=remove_compartment(train,n);
    print_train(train,1);
    //print_train(train,0);
    free_train(train);
    return 0;
}
