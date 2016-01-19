#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int counter,top_element ;

struct nodes {
    int data;
    struct nodes *ptr;
} *top,*temp,*temp2;

void push(int data)
{
    if(top == NULL)
        {
        top=(struct nodes*)malloc(1*sizeof(struct nodes));
        top->data=data;
        top->ptr=NULL ;
        }
    else
    {
        temp=(struct nodes*)malloc(1*sizeof(struct nodes));
        temp->data = data ;
        temp->ptr=top ;
        top = temp ;
    }
    counter++ ;
}

void pop()
{
    temp2 = top ;
    if(top == NULL)
    {
        printf("List is empty..!\n");
        return ;
    }
    else
    {
        temp2=top->ptr ;

        printf("Popped value %d.\n",top->data);

        free(top);
        top = temp2 ;
        counter-- ;
    }
}

void operate()
{

    top = NULL ;
}

void displaystack()
{
    temp = top ;
    if(top == NULL)
        printf("No stack to diplay.Error:Empty stack.!\n");
    else
    {
        while(temp != NULL)
        {
            printf("%4d ",temp->data);
            temp = temp->ptr ;
        }
    }
}

int main(void)
{
    int data; // ch;
    char ch;
    printf("Welcome to STACK using LinkedList.\n");
    printf(" 1 - Push\n");
    printf(" 2 - Pop\n");
    printf(" 3 - Top\n");
    printf(" 4 - Empty\n");
    printf(" 5 - Exit\n");
    printf(" 6 - Dipslay\n");
    printf(" 7 - Stack Count\n");

    operate() ;

  //  char buf[64];
    //memset(buf, 0, sizeof(buf));
    while(1)
    {
        printf("Enter your choice:\n");
         scanf("%d",&ch);
      //  scanf("%s", (char *)buf);
       // ch = buf[0] - '0';
        printf("selected %d\n", ch);
        switch(ch)
        {
        case 1:
            printf("Enter data to push:\n");
            scanf("%d",&data);
            push(data);
            break ;
        case 2:
            pop();
            break;
        case 3:
            if(top == NULL)
                printf("Stack is empty.\n");
            else
            {
                top_element = top->data;
                printf("Top element is %d\n",top_element);
            }
            break;
        case 4:
            if(top == NULL)
                printf("Stack is empty.\n");
            else
                printf("Stack contains %d elements.\n",counter);
            break;
        case 5:
            exit(0);
        case 6:
            displaystack();
            break;
        case 7:
            printf("Number of containing elements are %d.\n",counter);
            break;
        default:
            printf("Enter the right choise.1-7.");
            fflush(stdin);
            break;
        }
    }
    return 0;
}
