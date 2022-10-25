// stack implement using linked lsit
1.push 2.pop 3.display

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
} *top = NULL;

void push(int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    temp->next = top;
    top = temp;
}
int pop()
{
    struct node *temp;
    int item;
    if (top == NULL)
        printf("\nList is empty.\n");
    else
    {
        temp = top;
        item = top->info;
        top = top->next;
        free(temp);
        return (item);
    }
}
void display()
{
    struct node *q;
    q = top;
    if (top == NULL)
        printf("\nStack underflow\n");
    else
    {
        printf("\nThe elements are :\n");
        while (q != NULL)
        {
            printf("%d\n", q->info);
            q = q->next;
        }
    }
}
int main()
{
    int ch, data;
    while (1)
    {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the element to be inserted : ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nWrong choice !\n");
        }
    }
    return 0;
}
