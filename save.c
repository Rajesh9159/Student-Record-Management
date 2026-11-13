#include "header.h"
void SAVE(ST *ptr)
{
    FILE *fp;

    fp = fopen("student.txt", "w");

    if (fp == NULL)
    {
        printf("File cannot be opened...\n");
        return;
    }

    while (ptr != NULL)
    {
        // Save roll number
        fprintf(fp, "%d\n", ptr->roll);

        // Save student name
        fprintf(fp, "%s\n", ptr->name);

        // Save percentage
        fprintf(fp, "%.2f\n", ptr->percentage);

        ptr = ptr->next;
    }

    fclose(fp);

    printf("Records Saved Successfully...\n");
}
