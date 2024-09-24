// includes
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// functions prototype
bool isAlphabet(string key);
bool isRepeated(string key);
void encrypt(string key, string plain_text);

// main function
int main(int argc, string argv[])
{
    // check wether the argument is 1
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        // check wether the argument's length is 26
        printf("The KEY must be of 26 letters\n");
        return 1;
    }
    else if (!isAlphabet(argv[1]))
    {
        // check wether the argument is alphabetic
        printf("Only Alphabets\n");
        return 1;
    }
    else if (!isRepeated(argv[1]))
    {
        // check wether the argument's individual character's are repeated or not
        printf("The KEY must be Unique\n");
        return 1;
    }
    else
    {
        // Get input from the user for plain text
        string plain_text = get_string("plaintext: ");
        encrypt(argv[1], plain_text);
    }
}

bool isAlphabet(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i])) // checking the giving string is alphabets or not
        {
            return false;
        }
    }
    return true;
}

bool isRepeated(string key)
{
    // comparing each individual with every other individual of the key
    for (int i = 0, n = strlen(key); i < n; i++) // comparing 1st element when i == 0 and so on
    {
        for (int j = i + 1; j < n;
             j++) // when i ==  0 compare it with key[every other element of the key]
        {
            if (key[i] == key[j])
            {
                return false;
            }
        }
    }
    return true;
}

void encrypt(string key, string plain_text)
{
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plain_text); i < n;
         i++) // running the loop till the plain text is inspected individually
    {
        if (isupper(plain_text[i])) // seperate condition for upper case
        {
            int position = plain_text[i] -
                           'A'; // getting the position of the plain text's individual character
            plain_text[i] = toupper(key[position]); // setting the plain text to the position
                                                    // equivalent to the key's character
            printf("%c", plain_text[i]);
        }
        else if (islower(plain_text[i])) // same comments but for lower case
        {
            int position = plain_text[i] - 'a';
            plain_text[i] = tolower(key[position]);
            printf("%c", plain_text[i]);
        }
        else
        {
            printf("%c", plain_text[i]); // to keep the non-alphabetical characters as it is
        }
    }
    printf("\n");
}
