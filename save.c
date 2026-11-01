
#include "header.h"

void SAVE(ST *ptr)
{
    FILE *fp;

    fp = fopen("student.dat", "wb");

    if (fp == NULL)
    {
        printf("File cannot be opened...\n");
        return;
    }

    while (ptr != NULL)
    {
        // Save roll number
        fwrite(&ptr->roll, sizeof(ptr->roll), 1, fp);

        // Save student name
        fwrite(ptr->name, sizeof(ptr->name), 1, fp);

        // Save percentage
        fwrite(&ptr->percentage, sizeof(ptr->percentage), 1, fp);

        ptr = ptr->next;
    }

    fclose(fp);

    printf("Records Saved Successfully...\n");
}

