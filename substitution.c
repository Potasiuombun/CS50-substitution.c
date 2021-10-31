#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{   
    // If you receive more than the key in command line arguments, exit
    if (argc != 2)
    {
        printf("Incorrect number of arguments, correct syntax is './substitution key' \n");
        return 1;
    }
    // If you have an incorrect number of characters
    if (strlen(argv[1]) != 26)
    {
        printf("Incorrect number of characters \n");
        return 1;
    }
    
    for (int i = 0; i < strlen(argv[1]); i++)
    {   
        // checks if there are any non alphabetical characters
        if (!(isalpha(argv[1][i])))
        {
            printf("Non alphabetical character \n");
            return 1;
        }
        // checks if there are any duplicate characters
        for (int j = 0; j < strlen(argv[1]); j++)
        {
            if (i != j)
            {
                if ((argv[1][i] == argv[1][j]) || (toupper(argv[1][i]) == argv[1][j]) || (tolower(argv[1][i]) == argv[1][j]))
                {
                    printf("duplicate character \n");
                    return 1;
                }
            }
        }
    }
    
    // prompt the user for text
    string input;
    input = get_string("plaintext: ");
 
    
    // Change text based on key
    for (int i = 0; i < strlen(input); i++)
    {   
        // Acess each letter individually
        int ascii = (int) input[i];
        if (isupper(input[i]))
        {
            ascii = ascii - 65;
            input[i] = toupper(argv[1][ascii]);
        }
        if (islower(input[i]))
        {
            ascii = ascii - 97;
            input[i] = tolower(argv[1][ascii]);
        }
    }
    printf("ciphertext: %s\n", input);
    return 0;
}
