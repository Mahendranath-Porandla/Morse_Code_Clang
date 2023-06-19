#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static const char *morse_table[] = {
    ".-",    // A Index = 0
    "-...",  // B Index = 1
    "-.-.",  // C Index = 2
    "-..",   // D Index = 3
    ".",     // E Index = 4
    "..-.",  // F Index = 5
    "--.",   // G Index = 6
    "....",  // H Index = 7
    "..",    // I Index = 8
    ".---",  // J Index = 9
    "-.-",   // K Index = 10
    ".-..",  // L Index = 11
    "--",    // M Index = 12
    "-.",    // N Index = 13
    "---",   // O Index = 14
    ".--.",  // P Index = 15
    "--.-",  // Q Index = 16
    ".-.",   // R Index = 17
    "...",   // S Index = 18
    "-",     // T Index = 19
    "..-",   // U Index = 20
    "...-",  // V Index = 21
    ".--",   // W Index = 22
    "-..-",  // X Index = 23
    "-.--",  // Y Index = 24
    "--..",  // Z Index = 25
    "-----", // 0 Index = 26
    ".----", // 1 Index = 27
    "..---", // 2 Index = 28
    "...--", // 3 Index = 29
    "....-", // 4 Index = 30
    ".....", // 5 Index = 31
    "-....", // 6 Index = 32
    "--...", // 7 Index = 33
    "---..", // 8 Index = 34
    "----.", // 9 Index = 35

};

const char *englishToMorse(char);

char morseToEnglish(const char *);

int main()
{
    int choice;
    char *input;
    input = (char *)malloc(100 * sizeof(*input));
    if (input == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    char c;

    char *word;
    word = (char *)malloc(sizeof(*word));

    printf("Enter 1 to convert English to Morse.\nEnter 2 to convert Morse to English.\n");
    scanf("%d", &choice);

    printf("Enter text to convert: ");
    getchar(); // consume newline character from scanf
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove trailing newline character

    switch (choice)
    {
    case 1:
        englishToMorse(c);
        // Convert each character to Morse code
        int len = strlen(input);
        for (int i = 0; i < len; i++)
        {
            const char *morse = englishToMorse(input[i]);
            printf("%s ", morse);
        }
        printf("\n");
        free(input);

        return 0;
        break;
    case 2:

        // Split the input into Morse code words and characters
        word = strtok(input, " ");
        while (word != NULL)
        {
            // Convert the Morse code word to an English character
            char cm = morseToEnglish(word);
            if (cm != '\0')
            {
                printf("%c", cm);
            }

            // Move to the next word
            word = strtok(NULL, " ");
        }
        printf("\n");
        free(input);
        free(word);

        return 0;
        break;

    default:
        printf("Invalid choice!\n");
        break;
    }

    return 0;
}

const char *englishToMorse(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return morse_table[c - 'A'];
    }
    else if (c >= 'a' && c <= 'z')
    {
        return morse_table[c - 'a'];
    }
    else if (c >= '0' && c <= '9')
    {
        return morse_table[c - '0' + 26];
    }
    else
    {
        switch (c)
        {
        case ' ':
            return "/";
        case '.':
            return ".-.-.-";
        case ',':
            return "--..--";
        case '?':
            return "..--..";
        case '/':
            return "-..-.";
        case '!':
            return "-.-.--";

        case '(':
            return "-.--.";
        case ')':
            return "-.--.-";
        case '&':
            return ".-...";
        case ':':
            return "---...";
        case ';':
            return "-.-.-.";
        case '=':
            return "-...-";
        case '+':
            return ".-.-.";
        case '-':
            return "-....-";
        case '_':
            return "..--.-";

        case '$':
            return "...-..-";
        case '@':
            return ".--.-.";
        default:
            return "";
        }
    }
}

char morseToEnglish(const char *morsem)
{
    if (strcmp(morsem, "/") == 0)
    {
        return ' '; // Return space for "/"
    }
    // Search the Morse Code lookup table for a match
    int num_chars = sizeof(morse_table) / sizeof(morse_table[0]);
    for (int i = 0; i < num_chars; i++)
    {
        if (strcmp(morsem, morse_table[i]) == 0)
        {
            // Return the corresponding English character
            return (char)'A' + i;
        }
    }

    // No match found
    return '\0';
}
