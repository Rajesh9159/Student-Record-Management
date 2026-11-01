#include "header.h"

int main()
{
    ST *hptr = NULL;
    char choice;

    LOAD(&hptr);


    do
    {
        printf("\n**** STUDENT RECORD MENU ****\n");
        printf("A/a : Add New Record\n");
        printf("D/d : Delete a Record\n");
        printf("S/s : Show the List\n");
        printf("M/m : Modify a Record\n");
        printf("V/v : Save\n");
        printf("T/t : Sort the List\n");
        printf("E/e : Exit\n");

        printf("Enter Your Choice: ");
        scanf(" %c", &choice);

        switch(choice)
        {
            case 'A':
            case 'a':
                ADD_DETAILS(&hptr);
                break;

            case 'D':
            case 'd':
                DELETE(&hptr);
                break;

            case 'S':
            case 's':
                SHOW(hptr);
                break;

            case 'M':
            case 'm':
                MODIFY(hptr);
                break;

            case 'V':
            case 'v':
                SAVE(hptr);
                break;

            case 'T':
            case 't':
                SORT(hptr);
                break;

            case 'E':
            case 'e':
                printf("Are you sure you want to exit without saving ? (y/n): ");
                {
                    char op;
                    scanf(" %c", &op);
		    
		    if(op=='y'||op=='Y')
		    {
			    printf("existing program...\n");
			    return 0;
		    }
                    if(op == 'N' || op == 'n')
                    {
                        SAVE(hptr);
                        printf("Exiting program...\n");
                        return 0;
                    }
                }
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while(1);

    return 0;
}

