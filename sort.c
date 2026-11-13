#include "header.h"
#include <string.h>
#include <stdlib.h>

void SORT(ST *hptr)
{
    ST *temp;
    ST *last;
    ST *newnode;
    ST *head = NULL;
    ST *tail = NULL;

    char choice;
    int roll;
    char name[20];
    float percentage;

    if (hptr == NULL)
    {
        printf("No Records Available...\n");
        return;
    }

    // CREATE TEMPORARY LINKED LIST

    temp = hptr;

    while (temp != NULL)
    {
        newnode = malloc(sizeof(ST));

        if (newnode == NULL)
        {
            printf("Memory Allocation Failed...\n");

            while (head != NULL)
            {
                temp = head;
                head = head->next;
                free(temp);
            }

            return;
        }

        newnode->roll = temp->roll;
        strcpy(newnode->name, temp->name);
        newnode->percentage = temp->percentage;
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }

        temp = temp->next;
    }

    printf("\nN/n : Sort by Name");
    printf("\nP/p : Sort by Percentage");
    printf("\nEnter Your Choice: ");

    scanf(" %c", &choice);

    // SORT BY NAME

    if (choice == 'N' || choice == 'n')
    {
        for (temp = head; temp->next != NULL; temp = temp->next)
        {
            for (last = head; last->next != NULL; last = last->next)
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
        for (temp = head; temp->next != NULL; temp = temp->next)
        {
            for (last = head; last->next != NULL; last = last->next)
            {
                if (last->percentage < last->next->percentage)
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
    }

    // DISPLAY TEMPORARY LIST

    if (choice == 'N' || choice == 'n' ||
        choice == 'P' || choice == 'p')
    {
        SHOW(head);
    }

    // FREE TEMPORARY LIST

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
