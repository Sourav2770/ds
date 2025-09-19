#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;



struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void enqueue()
{
    int data;
    printf("Enter the data :");
    scanf("%d", &data);

    struct Node* newNode = createNode(data);

    if (front == NULL && rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue()
{
    if (front == NULL && rear == NULL)
    {
        printf("Linked List is empty\n");
    }
    else
    {
        struct Node* first = front;
        printf("Popped element: %d\n", first->data);

        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        free(first);
    }
}

void display()
{
    
struct Node* temp = front;
  
    while (temp != NULL)
    {
        printf("%d \t",temp->data);
        temp = temp->next;
    }

    
}

int main()
{
    int choice = 0;
    while (choice < 5)
    {
        printf("\n1 : Display \n");
        printf("2 : Enqueue \n");
        printf("3 : Dequeue \n");
        printf("4 : EXIT \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display();
            break;
        case 2:
            enqueue();
            break;
        case 3:
            dequeue();
            break;
        case 4:
            printf("EXITINGGGGGGGGGGGG>>>>>>>>>>>>>>>>>>>>>>>>>");
            break;
        default:
            printf("\n Invalid Choice");
            break;
        }
    }
    
    return 0;
}