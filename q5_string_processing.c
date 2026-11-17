/* Q5. Processing Text Without the Library (no string.h) */
#include <stdio.h>
#include <ctype.h>

/* Count words separated by spaces */
int word_count(const char s[])
{
    int count = 0, inside = 0, i = 0;
    while (s[i] != '\0')
    {
        if (s[i] != ' ' && inside == 0)
        {
            count++;
            inside = 1;
        }
        else if (s[i] == ' ')
        {
            inside = 0;
        }
        i++;
    }
    return count;
}

/* Convert string to uppercase in place */
void to_upper(char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
        s[i] = (char)toupper((unsigned char)s[i]);
}

/* Reverse string in place */
void reverse(char s[])
{
    int len = 0;
    while (s[len] != '\0')
        len++;
    for (int i = 0, j = len - 1; i < j; i++, j--)
    {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}

/* Palindrome check: ignores case and non-alphabetic characters */
int is_palindrome(const char s[])
{
    int left = 0, right = 0;
    while (s[right] != '\0')
        right++;
    right--;

    while (left < right)
    {
        while (left < right && !isalpha((unsigned char)s[left]))
            left++;
        while (left < right && !isalpha((unsigned char)s[right]))
            right--;
        if (tolower((unsigned char)s[left]) != tolower((unsigned char)s[right]))
            return 0;
        left++;
        right--;
    }
    return 1;
}

int main(void)
{
    char msg[] = "Meet at the library at 5 PM";

    printf("Words: %d\n", word_count("  Meet at  the library at 5 PM "));

    to_upper(msg);
    printf("Uppercase: %s\n", msg);

    reverse(msg);
    printf("Reversed: %s\n", msg);

    printf("%d %d\n", is_palindrome("Madam, I'm Adam"), is_palindrome("Hello"));
    return 0;
}
