#include <stdio.h>
#include <locale.h>
#include <tgmath.h>
#include <stdbool.h>
#include <string.h>

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

    setlocale(LC_ALL, "Portuguese");

	// --------------------------- //

    char frase[2][50];

    printf("> Digite a primeira frase: ");
    scanf(" %[^\n]s", &frase[0]);

    printf("> Digite a segunda frase: ");
    scanf(" %[^\n]s", &frase[1]);

    int length[2];

    length[0] = strlen(frase[0]);
    length[1] = strlen(frase[1]);

    bool igual = true;

    for(int x = length[0] - length[1], y = 0; x != length[0]; x++, y++)
    {
        if(frase[0][x] != frase[1][y])
        {
            igual = false;
            break;
        }
    }

    printf("\nA frase \"%s\" %s a frase \"%s\" no final.\n\n", frase[0], igual == true ? "contém" : "não contém", frase[1]);

    // --------------------------- //

    system("pause");

    return 0;
}