
#include "header.h"
#include <string.h>

void SORT(ST *hptr)
{
    ST *temp;
    ST *last;

    char choice;
    int roll;
    char name[20];
    float percentage;

    if (hptr == NULL)
    {
        printf("No Records Available...\n");
        return;
    }

    printf("\nN/n : Sort by Name");
    printf("\nP/p : Sort by Percentage");
    printf("\nEnter Your Choice: ");

    scanf(" %c", &choice);

    // SORT BY NAME

    if (choice == 'N' || choice == 'n')
    {
        for (temp = hptr; temp->next != NULL; temp = temp->next)
        {
            for (last = hptr; last->next != NULL; last = last->next)
            {
                if (strcmp(last->name, last->next->name) > 0)
                {
                    roll = last->roll;
                    last->roll = last->next->roll;
                    last->next->roll = roll;

                    strcpy(name, last->name);
                    strcpy(last->name, last->next->name);
                    strcpy(last->next->name, name);

                    percentage = last->percentage;
                    last->percentage = last->next->percentage;
                    last->next->percentage = percentage;
                }
            }
        }

        printf("\nSorted by Name Successfully...\n");
    }

    // SORT BY PERCENTAGE

    else if (choice == 'P' || choice == 'p')
    {
        for (temp = hptr; temp->next != NULL; temp = temp->next)
        {
            for (last = hptr; last->next != NULL; last = last->next)
            {
                if (last->percentage > last->next->percentage)
                {
                    roll = last->roll;
                    last->roll = last->next->roll;
                    last->next->roll = roll;

                    strcpy(name, last->name);
                    strcpy(last->name, last->next->name);
                    strcpy(last->next->name, name);

                    percentage = last->percentage;
                    last->percentage = last->next->percentage;
                    last->next->percentage = percentage;
                }
            }
        }

        printf("\nSorted by Percentage Successfully...\n");
    }

    else
    {
        printf("Invalid Choice...\n");
        return;
    }

    SHOW(hptr);
}

