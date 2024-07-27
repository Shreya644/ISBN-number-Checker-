#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to check the validity of a 10-digit ISBN number
int isValidISBN(char *isbn)
{
    int length = strlen(isbn);

    // ISBN must be 10 characters long
    if (length != 10)
    {
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        if (isbn[i] >= '0' && isbn[i] <= '9')
        {
            sum += (isbn[i] - '0') * (10 - i);
        }
        else if (isbn[i] == 'X' && i == 9)
        {
            sum += 10;
        }
        else
        {
            return 0;
        }
    }

    return (sum % 11 == 0);
}

int main()
{
    char isbn[11];

    printf("Enter a 10-digit ISBN number: ");
    scanf("%10s", isbn);

    if (isValidISBN(isbn))
    {
        printf("The ISBN number is valid.\n");
    }
    else
    {
        printf("The ISBN number is invalid.\n");
    }

    return 0;
}
