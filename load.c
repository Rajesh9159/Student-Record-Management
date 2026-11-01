#include "header.h"

void LOAD(ST **ptr)
{
    FILE *fp;
    ST *new, *last;

    fp = fopen("student.dat", "rb");

    if (fp == NULL)
    {
        printf("No Previous Records Found...\n");
        return;
    }

    while (1)
    {
        new = (ST *)malloc(sizeof(ST));

        if (new == NULL)
        {
            printf("Memory Allocation Failed...\n");
            fclose(fp);
            return;
        }

        // Read roll number
        if (fread(&new->roll, sizeof(new->roll), 1, fp) != 1)
        {
            free(new);
            break;
        }

        // Read student name
        if (fread(new->name, sizeof(new->name), 1, fp) != 1)
        {
            free(new);
            break;
        }

        // Read percentage
        if (fread(&new->percentage, sizeof(new->percentage), 1, fp) != 1)
        {
            free(new);
            break;
        }

        new->next = NULL;

        // Insert node into linked list
        if (*ptr == NULL)
        {
            *ptr = new;
        }
        else
        {
            last = *ptr;

            while (last->next != NULL)
                last = last->next;

            last->next = new;
        }
    }

    fclose(fp);

    printf("Previous Records Loaded Successfully...\n");
}
