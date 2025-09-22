// Write a program to simulate the working of stack using an array with the following :

//  a) Push

//  b) Pop

//  c) Display

// The program should print appropriate messages for stack overflow, stack underflow

#include <stdio.h>
#define max 1
int top = -1;
int nums[max];
int push(int val)
{
    if (top == (max - 1))
    {
        printf("The stack is overflowed, you can't input further\n");
        return 0;
    }
    else
    {
        top += 1;
        nums[top] = val;
        printf("%d is pushed into stack", val);
    }
    return 0;
}

int pop()
{
    if (top == -1)
    {
        printf("The stack is underflow, we cant remove further elements\n");
        return 0;
    }
    else
    {
        printf("%d is removed \n", nums[top]);
        top -= 1;
    }
    return -1;
}
int display()
{
    printf("The elements in nums are: ");
    for (int i = 0; i < max; i++)
    {
        printf("%d ", nums[i]);
    }
    return 0;
}

int main()
{
    int choice;
    int num;
    int check;
    while (1)
    {
        printf("press 0 to run code\n press 1 to exit: ");
        scanf("%d", &check);
        if (check == 1)
        {
            break;
        }
        else if (check == 0)
        {

            printf("Choose option: ");
            printf("1. Push\n 2.POP \n 3.Display \n 4.continue");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:

                printf("Enter element to push: ");
                scanf("%d", &num);
                push(num);
                

                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("The menu is exiting: ");
                continue;

            default:
                printf("Invalid choice");
            }
        }
    }
}

