#include <stdio.h>

const char* digitToLetters(char digit) {
    switch (digit) {
        case '2': return "ABC";
        case '3': return "DEF";
        case '4': return "GHI";
        case '5': return "JKL";
        case '6': return "MNO";
        case '7': return "PQRS";
        case '8': return "TUV";
        case '9': return "WXYZ";
        default: return "";
    }
}

int isInSet(char ch, const char *set) {
    while (*set) {
        if (*set == ch || *set == (ch - 32)) {
            return 1;
        }
        set++;
    }
    return 0;
}

int matchesWord(const char *digits, const char *word) {
    for (int i = 0; i < 4; i++) {
        if (!isInSet(word[i], digitToLetters(digits[i]))) {
            return 0;
        }
    }
    return 1;
}

int readWord(FILE *file, char *word) {
    int i = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n' || ch == '\r') {
            break;
        }
        if (i < 4) {
            word[i++] = ch;
        }
    }
    word[i] = '\0';
    return i == 4;
}

int main() {
    char phoneNumber[8];
    char word[5];
    int found = 0;

    printf("Enter a 7-digit phone number: ");
    for (int i = 0; i < 7; i++) {
        phoneNumber[i] = getchar();
        if (phoneNumber[i] == '\n') {
            i--;
        }
    }
    phoneNumber[7] = '\0';

    int valid = 1;
    for (int i = 0; i < 7; i++) {
        if (phoneNumber[i] < '0' || phoneNumber[i] > '9') {
            valid = 0;
            break;
        }
    }
    if (!valid) {
        printf("Invalid phone number.\n");
        return 1;
    }

    FILE *file = fopen("EnglishWords4Letters.txt", "r");
    if (!file) {
        printf("Error opening the word list file.\n");
        return 1;
    }

    while (readWord(file, word)) {
        if (matchesWord(phoneNumber + 3, word)) {
            phoneNumber[3] = '\0';
            printf("The phone number translates to: %s%s\n", phoneNumber, word);
            found = 1;
            break;
        }
    }

    fclose(file);

    if (!found) {
        printf("Translation failed.\n");
    }

    return 0;
}
