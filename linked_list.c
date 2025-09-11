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
        head = newNode;
    }

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
    }
    else
    {
        struct Node* temp = head;
        struct Node* newNode = createNode(data);
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
}

void insertAtPosition()
{
    int pos,data;
    printf("Enter the position you want to insert :\t");
    scanf("%d",&pos);

    printf("Enter the data :\t");
    scanf("%d",&data);

    struct Node* temp = head;

    struct Node* newNode = createNode(data);

    for (int i = 1; i < pos-1 && temp->next != NULL; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtBeginning()
{
    if (head == NULL)
    {
        printf("Linked List is empty");
    }
    else
    {
        struct Node* first = head;
        head = head->next;
        free(first);
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
        while(temp->next->next!= NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }
    
}

void deleteAtPosition()
{
    int pos;
    printf("\n Enter the position you want to delete : \t");
    scanf("%d",&pos);
    if (pos == 0)
    {
        printf("invalid position ");
        return;
    }
    else if (pos == 1)
    {
        insertAtBeginning();
    }
    else
    {
        struct Node* temp = head;
        struct Node* ptr;
        for (int i = 1; i < pos-1 && temp->next != NULL; i++)
        {
            ptr = temp;
            temp = temp->next;

        }
        if (ptr->next != NULL && temp->next != NULL)
        {
            ptr->next = temp->next;
        }
    }
    
    
}

void mergeList(struct Node* list1, struct Node* list2)
{
    struct Node* head1 = list1;
    struct Node* head2 = list2;
    struct Node* temp = head1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    
    temp->next = head2;

    printf("\n New List \n");
    while (temp != NULL)
    {
        print("%d \t",temp->data);
        temp = temp->next;
    }

}

void displayList()
{
    struct Node* temp = head;
  
    while (temp!= NULL)
    {
        printf("%d \t",temp->data);
        temp = temp->next;
    }
}

int main()
{
    int choice = 0;
    while (choice < 6)
    {
        printf("\nLINKED LIST OPERATIONS \n");
        printf("1 : insert at beginning \n");
        printf("2 : insert at End \n");
        printf("3 : Delete at beginning \n");
        printf("4 : Delete at End \n");
        printf("5 : Display \n");
        printf("6 : insert at a Position \n");
        printf("7 : delete at a Position \n");
        printf("8 : EXIT \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertAtBeginning();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            deleteAtBeginning();
            break;
        case 4:
            deleteAtEnd();
            displayList();

            break;
        case 5:
            displayList();
            break;
        case 6:
            insertAtPosition();
            displayList();
            break;
        case 7:
            deleteAtPosition();
            displayList();
            break;
        case 8:
            printf("EXITINGGGGGGGGGGGG>>>>>>>>>>>>>>>>>>>>>>>>>");
            break;
        default:
            printf("\n Invalid Choice");
            break;
        }
    }
    
    return 0;
}