#include "header.h"

void SHOW(ST *ptr)
{
    if (ptr == NULL)
    {
        printf("\nNo Records Available...\n");
        return;
    }

    printf("\n---------------------------------------------\n");
    printf("Roll\tName\t\tPercentage\n");
    printf("---------------------------------------------\n");

    while (ptr != NULL)
    {
        printf("%d\t%-15s\t%.2f\n",
               ptr->roll,
               ptr->name,
               ptr->percentage);

        ptr = ptr->next;
    }

    printf("---------------------------------------------\n");
}

