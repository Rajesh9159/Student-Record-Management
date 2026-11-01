#include "header.h"

void ADD_DETAILS(ST **ptr)
{
    ST *new = (ST *)malloc(sizeof(ST));
    ST *temp;
    int roll = 1;

    if (new == NULL)
    {
        printf("Memory Allocation Failed...\n");
        return;
    }

    // Find the smallest available roll number
    while (1)
    {
        temp = *ptr;

        while (temp != NULL)
        {
            if (temp->roll == roll)
                break;

            temp = temp->next;
        }

        if (temp == NULL)
            break;

        roll++;
    }

    new->roll = roll;

    // Get student details
    printf("Enter the name: ");
    scanf(" %[^\n]", new->name);

    printf("Enter the percentage: ");
    scanf("%f", &new->percentage);

    new->next = NULL;

    // Insert new node
    if (*ptr == NULL)
    {
        *ptr = new;
    }
    else
    {
        ST *last = *ptr;

        while (last->next != NULL)
            last = last->next;

        last->next = new;
    }

    printf("\nDetails Added Successfully...\n");
    printf("Roll Number: %d\n", new->roll);
}

