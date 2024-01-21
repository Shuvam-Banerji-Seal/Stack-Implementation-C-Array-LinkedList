
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

//global declaration for array
int S[SIZE];
int top_array = -1;

//global declaration for linked list

struct Node
{
	int data;
	struct Node* next;
};
struct Node* top = NULL;
struct Node* temp;
int count = 0;
int ch;
//func declaration
void push_array(int x);
int pop_array();
void push_linked_list(int x);
void pop_linked_list();
void display_array();
void display_linked_list();

//menu Functions

void main_menu();
void sub_menu_array();
void sub_menu_linked_list();

void main_menu()
{   printf("MAIN MENU");
    printf("\nWhat kind of DSA you want to use for Stack?");
        printf("\n\t1. Array");
        printf("\n\t2. Linked list");
        printf("\n\t3. exit");
        printf("\n Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            sub_menu_array();
            break;

            case 2:
            sub_menu_linked_list();
            break;

            case 3:
            exit(0);

            default:
                printf("\n Invalid Choice");

        }
}


void sub_menu_linked_list()
{
    int data;
    while(1)
    {
        printf("\n Sub-menu for Linked-list Implementation");
        printf("\n 1. Push");
        printf("\n 2. Pop");
        printf("\n 3. Display");
        printf("\n 4. Return to the Main Menu");
        printf("\n 5. Exit");
        printf("\n Enter your Choice:");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            printf("\n Enter the data:");
            scanf("%d", &data);
            push_linked_list(data);
            break;

            case 2:
            pop_linked_list();

            case 3:
            display_linked_list();
            break;

            case 4:
            main_menu();
            break;

            case 5:
            exit(0);

            default:
                printf("\n Invalid Choice");

        }
    }
}


void sub_menu_array()
{
    int data;
    while(1)
    {
        printf("\n Sub-menu for Array Implementation");
        printf("\n 1. Push");
        printf("\n 2. Pop");
        printf("\n 3. Display");
        printf("\n 4. Return to the Main Menu");
        printf("\n 5. Exit");
        printf("\n Enter your Choice:");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            printf("\n Enter the data:");
            scanf("%d", &data);
            push_array(data);
            break;

            case 2:
            pop_array();

            case 3:
            display_array();
            break;

            case 4:
            main_menu();
            break;

            case 5:
            exit(0);

            default:
                printf("\n Invalid Choice");

        }
    }
}

int main()
{
    main_menu();
}


void push_array(int x)
{
    if (top_array==SIZE)
    {
        printf("Stack Overflow");

    }
    else
    top_array++;
    S[top_array]=x;
}

void push_linked_list(int el)
{
	if(top == NULL)
	{
		top = (struct Node*) malloc(sizeof(struct Node*));
		top->data = el;
		top->next = NULL;
	}
	else
	{
		temp = (struct Node*) malloc(sizeof(struct Node*));
		temp->next = top;
		temp->data = el;
		top = temp;
	}
	count++;
	display_linked_list();
}




int pop_array()
{
    if (top_array<0)
    {
        printf("\n Stack Underflow");
    }
    else{
    int d = S[top_array];
    top_array--;
    return d;
    }
}


void pop_linked_list()
{
	temp = top;
	if(top == NULL)
	{
		printf("\nStack is empty!\n");
		exit(1);
	}
	else
		temp = temp->next;
	
	printf("\nItem to be removed is %d.", top->data);
	free(top);
	top = temp;
	count--;
	display_linked_list();
}


void display_array()
{   
    int i;
    if (top_array<0)
    {
        printf("\n Stack Underflow");
    }
    else{
    printf("\n The Stack is:");
    for (i =top_array; i>=0; i--)
    {
        printf("\n%d", S[i]);

    }
    }
}


void display_linked_list()
{
	temp = top;
	if(count == 0)
	{
		printf("\nStack is Empty!\n");
		return;
	}
	else
	{
		printf("\nThere are currently %d items:-\n", count);
		while(temp != NULL)
		{
			printf("%d \n", temp->data);
			temp = temp->next;
		}	
		printf("\n");
	}
}
