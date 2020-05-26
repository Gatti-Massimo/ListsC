#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Struct containing the various information of each item in the list
struct element
{
    int ID;
    char charachter;
    int value;

    //Point to the next item
    struct element *next;
};

typedef struct element *ELEMENT;

//Prototypes
void Print(ELEMENT local_head);
void Menu();
void Add(ELEMENT *local_head, int n);
int Remove(ELEMENT *local_head, int local_typed, int position);
void MaxMinDiff(ELEMENT *local_head);
void TotAverage(ELEMENT *local_head);



//Main
int main()
{
    srand(time(NULL));
    ELEMENT head = NULL;
    int choice = 0, n;
    int typedP;

    do
    {
        system("cls");

        //Prints and Menu'
        Print(head);
        Menu();

        printf("\n  Choose a command --> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("\n  GoodBye!\n\n");
            break;

        case 1:
            printf("\n  Enter the number of elements that make up the list --> ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                Add(&head, n);
            }
            break;

        case 2:
            printf("\n  Enter the value to be deleted --> ");
            scanf("%d", &typedP);
            printf("\n");

            int cont = 0;

            for (int i = 0; i < n; i++)
            {
                if (Remove(&head, typedP, 1))
                {
                    cont++;
                }
            }

            if (cont > 0)
            {
                printf("\n  %d elements with a value of %d have been found and they were removed\n", cont, typedP);
                getchar();
                getchar();
            }
            else
            {
                printf("\n  No elements with a value of %d have been found!\n  ", typedP);
                getchar();
                getchar();
            }
            break;

        case 3:
            MaxMinDiff(&head);
            getchar();
            getchar();
            break;

        case 4:
            TotAverage(&head);
            getchar();
            getchar();
            break;

        default:
            printf("\n  Error, command not recognized!");
            getchar();
            getchar();
            break;
        }
    } while (choice != 0);
}



void Print(ELEMENT local_head)
{
    if (local_head == NULL)
    {
        printf("\n  The list is empty!");
    }
    else
    {
        printf("\n  Elements that make up the list:\n\n  ");

        while (local_head != NULL)
        {
            printf("%d |", local_head->ID);
            printf(" %c | ", local_head->charachter);
            printf("%d -> ", local_head->value);
            printf("\n  ");
            local_head = local_head->next;
        }

        printf("NULL\n\n");
    }
}



void Menu()
{
    printf("  Welcome! Select one of the available commands:\n");
    printf("\n  1) Add elements to the list.");
    printf("\n  2) Remove items from the list.");
    printf("\n  3) Greater, lesser values and difference between the two.");
    printf("\n  4) Total and average values.");
    printf("\n  0) Exit.\n");
}



void Add(ELEMENT *local_head, int n)
{
    ELEMENT temp;

    char randomLetter = rand() % 58 + 65;

    while (randomLetter >= 91 && randomLetter <= 96)
    {
        randomLetter = rand() % 58 + 65;
    }

    int randomID = rand() % 1001 + 1000;  //From 1000 to 2000
    int randomValue = rand() % 41 + 40;   //From 40   to 80

    temp = malloc(sizeof(struct element));
    temp->next = *local_head;
    temp->ID = randomID;
    temp->charachter = randomLetter;
    temp->value = randomValue;

    *local_head = temp;
}



int Remove(ELEMENT *local_head, int local_typed, int position)
{
    ELEMENT temp;
    ELEMENT previous;
    ELEMENT current;

    if (local_typed == (*local_head)->value)
    {
        temp = *local_head;
        *local_head = (*local_head)->next;

        printf("  Found in position %d!\n", position);

        free(temp);
        return local_typed;
    }
    else
    {
        previous = *local_head;
        current = (*local_head)->next;
        position = position+1;

        while (current != NULL && current->value != local_typed)
        {
            previous = current;
            current = corr->next;
            position = position+1;
        }

        if (current != NULL)
        {
            temp = current;
            previous->next = current->next;

            printf("  Found in position %d!\n", position);

            free(temp);
            return local_typed;
        }

        return '\0';
    }
}



void MaxMinDiff(ELEMENT *local_head)
{
    int max = 0;
    int min = 100;

    ELEMENT temp;
    temp = *local_head;

    while (temp != NULL)
    {
        if(temp -> value > max)
        {
            max = temp -> value;
        }

        if((*local_head) -> value < min)
        {
            min = temp -> value;
        }

        temp = temp -> next;
    }

    int diff = max - min;

    printf("\n  Greater value --> %d \n  Lower value --> %d \n  Difference --> %d\n  ", max, min, diff);
}



void TotAverage(ELEMENT *local_head)
{
    int total = 0;
    int count = 0;

    ELEMENT temp;
    temp = *local_head;

    while (temp != NULL)
    {
        total = total + temp -> value;
        temp = temp -> next;

        count++;
    }

    float average = (float)total/(float)count;

    printf("\n  Total of the values --> %d \n  Average value  --> %4.2f\n  ", total, average);
}