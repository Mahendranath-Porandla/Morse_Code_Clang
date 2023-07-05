#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *morse;
    char english;
} morse_matching;

morse_matching *morse_table = NULL;

int num_chars = 0;

void initializeMorseTable()
{
    const morse_matching matchings[] = {
        {".-", 'A'},
        {"-...", 'B'},
        {"-.-.", 'C'},
        {"-..", 'D'},
        {".", 'E'},
        {"..-.", 'F'},
        {"--.", 'G'},
        {"....", 'H'},
        {"..", 'I'},
        {".---", 'J'},
        {"-.-", 'K'},
        {".-..", 'L'},
        {"--", 'M'},
        {"-.", 'N'},
        {"---", 'O'},
        {".--.", 'P'},
        {"--.-", 'Q'},
        {".-.", 'R'},
        {"...", 'S'},
        {"-", 'T'},
        {"..-", 'U'},
        {"...-", 'V'},
        {".--", 'W'},
        {"-..-", 'X'},
        {"-.--", 'Y'},
        {"--..", 'Z'},
        {"-----", '0'},
        {".----", '1'},
        {"..---", '2'},
        {"...--", '3'},
        {"....-", '4'},
        {".....", '5'},
        {"-....", '6'},
        {"--...", '7'},
        {"---..", '8'},
        {"----.", '9'},
        {"/", ' '},
        {".-.-.-", '.'},
        {"--..--", ','},
        {"..--..", '?'},
        {"-..-.", '/'},
        {"-.-.--", '!'},
        {"-.--.", '('},
        {"-.--.-", ')'},
        {".-...", '&'},
        {"---...", ':'},
        {"-.-.-.", ';'},
        {"-...-", '='},
        {".-.-.", '+'},
        {"-....-", '-'},
        {"..--.-", '_'},
        {"...-..-", '$'},
        {".--.-.", '@'}};

    num_chars = sizeof(matchings) / sizeof(matchings[0]);

    // declaring morse table dynamically
    morse_table = (morse_matching *)malloc(num_chars * sizeof(morse_matching));

    // copying data into morse table
    for (int i = 0; i < num_chars; i++)
    {
        morse_table[i].morse = strdup(matchings[i].morse);
        morse_table[i].english = matchings[i].english;
    }
}

char *englishToMorse(char text)
{
    for (int i = 0; i < num_chars; i++)
    {
        if (morse_table[i].english == text)
        {
            return morse_table[i].morse;
        }
    }

    return NULL; // No match found
}

char morseToEnglish(char *morse)
{
    for (int i = 0; i < num_chars; i++)
    {
        if (strcmp(morse, morse_table[i].morse) == 0)
        {
            return morse_table[i].english;
        }
    }

    return '\0'; // No match found
}

int main()
{
    initializeMorseTable();

    int choice;
    char *input = NULL;
    char *word = NULL;
    int len;

    input = (char *)malloc(1000 * sizeof(*input));
    if (input == NULL)
    {
        printf("Memory allocation failed!\n");
        free(morse_table);
        return 1;
    }

    word = (char *)malloc(sizeof(*word));
    if (word == NULL)
    {
        printf("Memory allocation failed!\n");
        free(input);
        free(morse_table);
        return 1;
    }

    printf("\t**** MORSE CODE TRANSLATOR ****\n\n");

    printf("Enter 1 to convert English to Morse.\n"
           "Enter 2 to convert Morse to English.\n"
           "Enter 3 to display Morse Table.\n");

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:

        printf("Enter text to convert: ");
        getchar(); // consume newline(\n) character from scanf
        fgets(input, 1000, stdin);
        input[strcspn(input, "\n")] = '\0';

        // for converting into morse code
        len = strlen(input);
        for (int i = 0; i < len; i++)
        {
            char *morse = englishToMorse(input[i]);
            if (morse != NULL)
            {
                printf("%s ", morse);
            }
        }
        printf("\n");

        break;

    case 2:

        printf("Enter morse code to convert: ");
        getchar(); // consume newline(\n) character from scanf
        fgets(input, 1000, stdin);
        input[strcspn(input, "\n")] = '\0';

        // splitting the input
        word = strtok(input, " ");
        while (word != NULL)
        {
            // for converting into english text
            char cm = morseToEnglish(word);
            if (cm != '\0')
            {
                printf("%c", cm);
            }

            // Moves to the next word
            word = strtok(NULL, " ");
        }
        printf("\n");

        break;

    case 3:

        printf("**** MORSE TABLE ****\n\n");

        for (int i = 0; i < num_chars; i++)
        {
            printf("%s  <--->  %c\n", morse_table[i].morse, morse_table[i].english);
        }
        break;

    default:

        printf("Invalid choice!\n");
        break;
    }

    free(input);

    free(word);

    free(morse_table);

    return 0;
}
