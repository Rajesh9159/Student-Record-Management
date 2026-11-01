
#include "header.h"
#include <string.h>

void MODIFY(ST *hptr)
{
    ST *temp;
    ST *p = NULL;

    char choice, opt;
    char search_name[20];

    float search_percentage;

    int roll;
    int count = 0;

    if (hptr == NULL)
    {
        printf("No Records Available...\n");
        return;
    }

    printf("\nR/r : Search by Roll Number");
    printf("\nN/n : Search by Name");
    printf("\nP/p : Search by Percentage");
    printf("\nEnter Your Choice: ");

    scanf(" %c", &choice);

//search by roll
    if (choice == 'R' || choice == 'r')
    {
        printf("Enter Roll Number: ");
        scanf("%d", &roll);

        temp = hptr;

        while (temp != NULL)
        {
            if (temp->roll == roll)
            {
                p = temp;
                break;
            }

            temp = temp->next;
        }

        if (p == NULL)
        {
            printf("Record Not Found...\n");
            return;
        }
    }

// SEARCH BY NAME
    else if (choice == 'N' || choice == 'n')
    {
        printf("Enter Name: ");
        scanf("%s", search_name);

        temp = hptr;
        count = 0;
        p = NULL;

        while (temp != NULL)
        {
            if (strcmp(temp->name, search_name) == 0)
            {
                count++;
                p = temp;
            }

            temp = temp->next;
        }

        if (count == 0)
        {
            printf("Record Not Found...\n");
            return;
        }

	if(count>1)
        {
            temp = hptr;

            printf("\nRoll No\tName\tPercentage\n");
            printf("--------------------------------\n");

            while (temp != NULL)
            {
                if (strcmp(temp->name, search_name) == 0)
                {
                    printf("%d\t%s\t%.2f\n",
                           temp->roll,
                           temp->name,
                           temp->percentage);
                }

                temp = temp->next;
            }

            printf("\nEnter Roll Number to Modify: ");
            scanf("%d", &roll);

            temp = hptr;
            p = NULL;

            while (temp != NULL)
            {
                if (temp->roll == roll &&
                    strcmp(temp->name, search_name) == 0)
                {
                    p = temp;
                    break;
                }

                temp = temp->next;
            }

            if (p == NULL)
            {
                printf("Invalid Roll Number...\n");
                return;
            }
        }
    }

// SEARCH BY PERCENTAGE
    else if (choice == 'P' || choice == 'p')
    {
        printf("Enter Percentage: ");
        scanf("%f", &search_percentage);

        temp = hptr;
        count = 0;
        p = NULL;

        while (temp != NULL)
        {
            if (temp->percentage == search_percentage)
            {
                count++;
                p = temp;
            }

            temp = temp->next;
        }

        if (count == 0)
        {
            printf("Record Not Found...\n");
            return;
        }


        if(count>1)
        {
            temp = hptr;

            printf("\nRoll No\tName\tPercentage\n");
            printf("--------------------------------\n");

            while (temp != NULL)
            {
                if (temp->percentage == search_percentage)
                {
                    printf("%d\t%s\t%.2f\n",
                           temp->roll,
                           temp->name,
                           temp->percentage);
                }

                temp = temp->next;
            }

            printf("\nEnter Roll Number to Modify: ");
            scanf("%d", &roll);

            temp = hptr;
            p = NULL;

            while (temp != NULL)
            {
                if (temp->roll == roll &&
                    temp->percentage == search_percentage)
                {
                    p = temp;
                    break;
                }

                temp = temp->next;
            }

            if (p == NULL)
            {
                printf("Invalid Roll Number...\n");
                return;
            }
        }
    }

    else
    {
        printf("Invalid Choice...\n");
        return;
    }


    printf("\nN/n : Modify Name");
    printf("\nP/p : Modify Percentage");
    printf("\nEnter Your Choice: ");

    scanf(" %c", &opt);

    if (opt == 'N' || opt == 'n')
    {
        printf("Enter New Name: ");
        scanf("%s", p->name);

        printf("Name Modified Successfully...\n");
    }

    else if (opt == 'P' || opt == 'p')
    {
        printf("Enter New Percentage: ");
        scanf("%f", &p->percentage);

        printf("Percentage Modified Successfully...\n");
    }

    else
    {
        printf("Invalid Choice...\n");
    }
}

