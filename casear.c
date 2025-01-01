#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Prototipler
int only_digits(char *str);
char rotate(char c, int key);

int main(int argc, char *argv[])
{
    // Komut satırı argüman sayısını kontrol et
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Anahtarın sadece rakamlardan oluşup oluşmadığını kontrol et
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Anahtarı tam sayıya çevir ve 26 ile sınırla
    int key = atoi(argv[1]) % 26;

    // Düz metin girişi
    char plaintext[100];
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        char c = plaintext[i];
        printf("%c", rotate(c, key));
    }

    
    printf("\n");
    return 0;
}


int only_digits(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
        {
            return 0; // false
        }
    }
    return 1; // true
}


char rotate(char c, int key)
{
    if (isupper(c))
    {
        return ((c - 'A' + key) % 26) + 'A';
    }
    else if (islower(c))
    {
        return ((c - 'a' + key) % 26) + 'a';
    }
    else
    {
        return c; 
    }
}