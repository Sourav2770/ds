#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd()
{
    int data;
    printf("Enter the data :\t");
    scanf("%d",&data);

    if (head == NULL)
    {
        printf("Linked list is Empty");
        struct Node* newNode = createNode(data);
        head = newNode;
        head->next = head;
    }
    else
    {
        struct Node* temp = head;
        struct Node* newNode = createNode(data);
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next=head;
    }
    
}


void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("Linked List is Empty");
    }
    else
    {
        struct Node* temp = head;
        struct Node* ptr =head;
        while(temp->next->next!= head)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next=head;
    }
    
}



void displayList()
{
    struct Node* temp = head;
  
    
    do{
        printf("%d \t",temp->data);
        temp = temp->next;
    }while (temp!= head);
}

int main()
{
    int choice = 0;
    while (choice < 4)
    {
        printf("\n1 : insert at end \n");
        printf("2 : delete at end \n");
        printf("3 : Display\n");
        printf("4 : Exit \n");


        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertAtEnd();
            break;

        case 2:
            deleteAtEnd();
            break;


        case 3:
            displayList();

            break;

        default:
            printf("\n Invalid Choice");
            break;
        }
    }
    
    return 0;
}