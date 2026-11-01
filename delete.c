
#include "header.h"
#include <string.h>

void DELETE(ST **ptr)
{
    ST *temp, *prev;
    char choice;
    int roll, found = 0;
    int count = 0;
    char name[20];

    if (*ptr == NULL)
    {
        printf("No Records Available...\n");
        return;
    }

    printf("\nR/r : Delete by Roll Number");
    printf("\nN/n : Delete by Name");
    printf("\nEnter Your Choice: ");

    scanf(" %c", &choice);

    // DELETE BY ROLL NUMBER
    if (choice == 'R' || choice == 'r')
    {
        printf("Enter Roll Number: ");
        scanf("%d", &roll);
    }

    // DELETE BY NAME
    else if (choice == 'N' || choice == 'n')
    {
        printf("Enter Name: ");
        scanf("%s", name);

        temp = *ptr;

        // COUNT MATCHING NAMES
        while (temp != NULL)
        {
            if (strcmp(temp->name, name) == 0)
                count++;

            temp = temp->next;
        }

        if (count == 0)
        {
            printf("Record Not Found...\n");
            return;
        }

        // MORE THAN ONE MATCHING RECORD
        if (count > 1)
        {
            printf("\nRoll\tName\tPercentage\n");

            temp = *ptr;

            while (temp != NULL)
            {
                if (strcmp(temp->name, name) == 0)
                {
                    printf("%d\t%s\t%.2f\n",
                           temp->roll,
                           temp->name,
                           temp->percentage);
                }

                temp = temp->next;
            }

            printf("\nEnter Roll Number to Delete: ");
            scanf("%d", &roll);
        }

        // ONLY ONE MATCHING RECORD
        else
        {
            temp = *ptr;

            while (temp != NULL)
            {
                if (strcmp(temp->name, name) == 0)
                {
                    roll = temp->roll;
                    break;
                }

                temp = temp->next;
            }
        }
    }

    else
    {
        printf("Invalid Choice...\n");
        return;
    }

    // SEARCH RECORD
    temp = *ptr;
    prev = NULL;
    found = 0;

    while (temp != NULL)
    {
        if (temp->roll == roll)
        {
            if (choice == 'N' || choice == 'n')
            {
                if (strcmp(temp->name, name) != 0)
                {
                    prev = temp;
                    temp = temp->next;
                    continue;
                }
            }

            found = 1;
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    if (found == 0)
    {
        printf("Record Not Found...\n");
        return;
    }

    // DELETE NODE
    if (prev == NULL)
        *ptr = temp->next;
    else
        prev->next = temp->next;

    free(temp);

    printf("Record Deleted Successfully...\n");
}

