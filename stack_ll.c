#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push()
{
    int data;
    printf("Enter the data :");
    scanf("%d",&data);

    if (top == NULL)
    {
        struct Node* newNode = createNode(data);
        top = newNode;
    }
    else
    {
        struct Node* newNode = createNode(data);
        newNode->next = top;
        top = newNode;
    }

}

void pop()
{
    if (top == NULL)
    {
        printf("Linked List is empty");
    }
    else
    {
        struct Node* first = top;
        printf("Popped element: %d\n", first->data);

        top = top -> next;
        free(first);
    }
} 


void display()
{
    struct Node* temp = top;
  
    while (temp!= NULL)
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
        printf("2 : Push \n");
        printf("3 : Pop \n");
        printf("4 : EXIT \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display();
            break;
        case 2:
            push();
            break;
        case 3:
            pop();
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