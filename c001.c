#include <stdio.h>
int main()
{        
 
    int size = 0;
    int stars = 0, blank1 = 0, blank2 = 0;
    int i = 0, j = 0;

    // Input size
    printf("Enter the size: ");
    scanf("%d", &size);

    // Make tropy
    // Make upper!
    for (i = 0; i < size; i++)
    {
        blank1 = i;
        for (j = 0; j < blank1; j++)
        {
            printf(" ");
        }
        printf("*");
        blank2 = 2 * size - 2 * (i + 1);
        for (j = 0; j < blank2; j++)
        {
            printf(" ");
        }
        printf("*");
        printf("\n");
    }

    // Make squar!!
    for (i = 0; i < size; i++)
    {
        stars = 2 * size;
        for (j = 0; j < stars; j++)
        {
            printf("*"); 
        } 
        printf("\n");
    }

    // Make triangle!!!
    for (i = 0; i < size; i++)
    {

        blank1 = i;
        for (j = 0; j < blank1; j++)
        {
            printf(" ");
        }
        stars = 2 * size - 2 * i;
        for (j = 0; j < stars; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    // Make line!!!!
    stars = 2 * size;
    for (i = 0; i < stars; i++)
    {
        printf("*");
    }
    printf("\n");

    return 0;
}