#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

// ---------------------------------------------------------------------------------------------------------------------- //

bool stringContem(char *string1, char *string2)
{
    for(int x = 0; x != strlen(string1); x++)
    {
        for(int y = 0; y != strlen(string2); y++)
        {
            if(*(string1 + x) == *(string2 + y)) 
            {
                x++;

                if(y == strlen(string2) - 1) return true;
            }
            else 
            {
                x -= y;
                break;
            }
        }
    }
    return false;
}

// ---------------------------------------------------------------------------------------------------------------------- //

int main()
{
    setlocale(LC_ALL, "Portuguese");

	// --------------------------- //

    char string[2][100];

    for(int x = 0; x != 2; x++)
    {
        printf("Digite a string %i: ", x + 1);
        scanf(" %[^\n]s", string + x);
    }

    printf("\nString 1: %s\nString 2: %s\n\n", *(string + 0), *(string + 1));

    printf("A string 2 %s contida na string 1.\n\n", stringContem(string + 0, string + 1) ? "está" : "não está");

    // --------------------------- //

    system("pause");

    return 0;
}