#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *morse;
    char english;
} MorseMapping;

MorseMapping morse_table[] = {
    {".-", 'A'},      // A Index = 0
    {"-...", 'B'},    // B Index = 1
    {"-.-.", 'C'},    // C Index = 2
    {"-..", 'D'},     // D Index = 3
    {".", 'E'},       // E Index = 4
    {"..-.", 'F'},    // F Index = 5
    {"--.", 'G'},     // G Index = 6
    {"....", 'H'},    // H Index = 7
    {"..", 'I'},      // I Index = 8   
    {".---", 'J'},    // J Index = 9
    {"-.-", 'K'},     // K Index = 10
    {".-..", 'L'},    // L Index = 11
    {"--", 'M'},      // M Index = 12
    {"-.", 'N'},      // N Index = 13
    {"---", 'O'},     // O Index = 14
    {".--.", 'P'},    // P Index = 15
    {"--.-", 'Q'},    // Q Index = 16
    {".-.", 'R'},     // R Index = 17
    {"...", 'S'},     // S Index = 18
    {"-", 'T'},       // T Index = 19
    {"..-", 'U'},     // U Index = 20
    {"...-", 'V'},    // V Index = 21
    {".--", 'W'},     // W Index = 22
    {"-..-", 'X'},    // X Index = 23
    {"-.--", 'Y'},    // Y Index = 24
    {"--..", 'Z'},    // Z Index = 25
    {"-----", '0'},   // 0 Index = 26
    {".----", '1'},   // 1 Index = 27
    {"..---", '2'},   // 2 Index = 28
    {"...--", '3'},   // 3 Index = 29
    {"....-", '4'},   // 4 Index = 30
    {".....", '5'},   // 5 Index = 31
    {"-....", '6'},   // 6 Index = 32
    {"--...", '7'},   // 7 Index = 33
    {"---..", '8'},   // 8 Index = 34
    {"----.", '9'},   // 9 Index = 35
    {"/", ' '},       // Space
    {".-.-.-", '.'},  // .
    {"--..--", ','},  // ,
    {"..--..", '?'},  // ?
    {"-..-.", '/'},   // /
    {"-.-.--", '!'},  // !
    {"-.--.", '('},   // (
    {"-.--.-", ')'},  // )
    {".-...", '&'},   // &
    {"---...", ':'},  // :
    {"-.-.-.", ';'},  // ;
    {"-...-", '='},   // =
    {".-.-.", '+'},   // +
    {"-....-", '-'},  // -
    {"..--.-", '_'},  // _
    {"...-..-", '$'}, // $
    {".--.-.", '@'}   // @
};

char *englishToMorse(char);

char morseToEnglish(char *);

int main()
{
    int choice;
    char *input;
    int len;
    input = (char *)malloc(1000 * sizeof(*input));
    if (input == NULL)
    {
        printf("Memory allocation failed!\n");
    }

    char *word;
    word = (char *)malloc(sizeof(*word));
    if (word == NULL)
    {
        printf("Memory allocation failed!\n");
    }

    int num_chars = sizeof(morse_table) / sizeof(morse_table[0]);

    printf("\t**** MORSE CODE TRANSLATOR ****\n\n");

    printf("Enter 1 to convert English to Morse.\nEnter 2 to convert Morse to English.\nEnter 3 to display Morse Table.\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter text to convert: ");
        getchar(); // consume newline character from scanf
        fgets(input, 1000, stdin);
        input[strcspn(input, "\n")] = '\0';

        // Convert each character to Morse code
        len = strlen(input);
        for (int i = 0; i < len; i++)
        {
            char *morse = englishToMorse(input[i]);
            printf("%s ", morse);
        }
        printf("\n");

        return 0;
        break;

        printf("\n");

    case 2:
        printf("Enter morse code to convert: ");
        getchar(); // consume newline character from scanf
        fgets(input, 1000, stdin);
        input[strcspn(input, "\n")] = '\0';

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
}

char *englishToMorse(char morse)
{
    int num_chars = sizeof(morse_table) / sizeof(morse_table[0]);

    for (int i = 0; i < num_chars; i++)
    {
        if (morse_table[i].english == morse)
        {
            return morse_table[i].morse;
        }
    }

    return 0;
}

char morseToEnglish(char *morsem)
{
    int num_chars = sizeof(morse_table) / sizeof(morse_table[0]);

    for (int i = 0; i < num_chars; i++)
    {
        if (strcmp(morsem, morse_table[i].morse) == 0)
        {
            return morse_table[i].english;
        }
    }

    return '\0'; // No match found
}
