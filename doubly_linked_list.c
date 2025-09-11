#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning()
{
    int data;
    printf("Enter the data :\t");
    scanf("%d",&data);

    if (head == NULL)
    {
        struct Node* newNode = createNode(data);
        head = newNode;
    }
    else
    {
        struct Node* newNode = createNode(data);
        newNode->next = head;
        newNode->prev = NULL;
        head->prev = newNode;
        head = newNode;
    }
    
}

void insertAtEnd(){
    int data;
    printf("Enter the data :\t");
    scanf("%d", &data);
    struct Node* temp = head;
    struct Node* newNode = createNode(data);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = NULL;

}

void deletionAtBeg(){
    struct Node* temp = head;

    if(temp==NULL){
        printf("CANNOT BE DELETED");
    }else{
        head=temp->next;
        temp=temp->next;
        temp->prev=head;
    }
}

void deletionAtEnd(){
    struct Node* temp = head;
        struct Node* ptr = head;


    if(temp==NULL){
        printf("CANNOT BE DELETED");
    }else{
        while(temp->next!=NULL){
            temp=temp->next;
            ptr=temp->prev;
        }
        ptr->next=NULL;
    
    }
}

void insertAtPos(){
        struct Node* temp = head;
        struct Node* ptr = head;
            int pos;
            int pos1 = 0;
    printf("Enter the pos :\t");
    scanf("%d", &pos);

    while(temp->next){
        pos1++;
        if(pos1==pos){

            break;
        }
        temp=temp->next;
        ptr=temp->prev;

    }
    printf("Enter the data :\t");
    scanf("%d", &pos);
    struct Node* newNode = createNode(pos);
    ptr->next=newNode;
    newNode->prev=ptr;
    newNode->next=temp;
    temp->prev=newNode;
}

void deleteAtPos(){
    struct Node* temp = head;
        struct Node* ptr = head;
                struct Node* ptr1 = head;

            int pos;
            int pos1 = 0;
    printf("Enter the pos :\t");
    scanf("%d", &pos);

    while(temp->next){
        pos1++;
        if(pos1==pos){

            break;
        }
        temp=temp->next;
        ptr=temp->prev;
        ptr1=temp->next;
    }
    ptr->next=temp->next;
    ptr1->prev=ptr;

}



void display()
{
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d \t",temp->data);
        temp = temp->next;
    }
}

int main()
{
    int choice=1;
    while (choice)
    {
        printf("\nDOUBLY LINKED LIST OPERATIONS \n");
        printf("1 : display \n");
        printf("2 : Insert at Beginning \n");
        printf("3 : Insert at End \n");
                printf("4 : delete at begining \n");
                        printf("5 : delete at end \n");
        printf("6 : insert at pos \n");
                printf("7 : delete at pos \n");
                               


        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            display();
            break;
        case 2:
            insertAtBeginning();
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            deletionAtBeg();
            break;
        case 5:
            deletionAtEnd();
            break;
        case 6:
            insertAtPos();
            break;
        case 7:
            deleteAtPos();
            break;

       
        default:
            break;
        }

    }
    
    return 0;
}