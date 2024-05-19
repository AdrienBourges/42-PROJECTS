#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "libft.h"

char strmapi_test(unsigned int i, char c) 
{
    return c + i;
}

void striteri_test(unsigned int i, char *c) 
{
    *c = *c + i;
}


int main() {
    // Test ft_isalpha
    printf("Testing ft_isalpha:\n");
    printf("ft_isalpha('A') = %d, expected = %d\n", ft_isalpha('A'), isalpha('A'));
    printf("ft_isalpha('z') = %d, expected = %d\n", ft_isalpha('z'), isalpha('z'));
    printf("ft_isalpha('1') = %d, expected = %d\n", ft_isalpha('1'), isalpha('1'));
    printf("ft_isalpha('!') = %d, expected = %d\n", ft_isalpha('!'), isalpha('!'));
    printf("\n");

    // Test ft_isdigit
    printf("Testing ft_isdigit:\n");
    printf("ft_isdigit('0') = %d, expected = %d\n", ft_isdigit('0'), isdigit('0'));
    printf("ft_isdigit('5') = %d, expected = %d\n", ft_isdigit('5'), isdigit('5'));
    printf("ft_isdigit('a') = %d, expected = %d\n", ft_isdigit('a'), isdigit('a'));
    printf("ft_isdigit(' ') = %d, expected = %d\n", ft_isdigit(' '), isdigit(' '));
    printf("\n");

    // Test ft_isalnum
    printf("Testing ft_isalnum:\n");
    printf("ft_isalnum('A') = %d, expected = %d\n", ft_isalnum('A'), isalnum('A'));
    printf("ft_isalnum('9') = %d, expected = %d\n", ft_isalnum('9'), isalnum('9'));
    printf("ft_isalnum('!') = %d, expected = %d\n", ft_isalnum('!'), isalnum('!'));
    printf("ft_isalnum(' ') = %d, expected = %d\n", ft_isalnum(' '), isalnum(' '));
    printf("\n");

    // Test ft_isascii
    printf("Testing ft_isascii:\n");
    printf("ft_isascii('A') = %d, expected = %d\n", ft_isascii('A'), isascii('A'));
    printf("ft_isascii(128) = %d, expected = %d\n", ft_isascii(128), isascii(128));
    printf("ft_isascii(0) = %d, expected = %d\n", ft_isascii(0), isascii(0));
    printf("ft_isascii(255) = %d, expected = %d\n", ft_isascii(255), isascii(255));
    printf("\n");

    // Test ft_isprint
    printf("Testing ft_isprint:\n");
    printf("ft_isprint('A') = %d, expected = %d\n", ft_isprint('A'), isprint('A'));
    printf("ft_isprint(' ') = %d, expected = %d\n", ft_isprint(' '), isprint(' '));
    printf("ft_isprint(31) = %d, expected = %d\n", ft_isprint(31), isprint(31));
    printf("ft_isprint(127) = %d, expected = %d\n", ft_isprint(127), isprint(127));
    printf("\n");

    // Test ft_strlen
    printf("Testing ft_strlen:\n");
    printf("ft_strlen(\"Hello\") = %zu, expected = %zu\n", ft_strlen("Hello"), strlen("Hello"));
    printf("ft_strlen(\"\") = %zu, expected = %zu\n", ft_strlen(""), strlen(""));
    printf("ft_strlen(\"1234567890\") = %zu, expected = %zu\n", ft_strlen("1234567890"), strlen("1234567890"));
    printf("\n");

    // Test ft_memset
    printf("Testing ft_memset:\n");
    char str1[50] = "Hello World!";
    char str2[50] = "Hello World!";
    ft_memset(str1, 'a', 5);
    memset(str2, 'a', 5);
    printf("ft_memset(str1, 'a', 5) = %s, expected = %s\n", str1, str2);
    printf("\n");

    // Test ft_bzero
    printf("Testing ft_bzero:\n");
    char str1_bzero[50] = "Hello World!";
    char str2_bzero[50] = "Hello World!";
    ft_bzero(str1_bzero, 5);
    bzero(str2_bzero, 5);
    printf("ft_bzero(str1, 5) = %s, expected = %s\n", str1_bzero + 5, str2_bzero + 5); // Offset by 5
    printf("\n");

    // Test ft_memcpy
    printf("Testing ft_memcpy:\n");
    char src_memcpy[] = "Hello World!";
    char dest1_memcpy[50];
    char dest2_memcpy[50];
    ft_memcpy(dest1_memcpy, src_memcpy, 12);
    memcpy(dest2_memcpy, src_memcpy, 12);
    printf("ft_memcpy(dest1, src, 12) = %s, expected = %s\n", dest1_memcpy, dest2_memcpy);
    printf("\n");

    // Test ft_memmove
    printf("Testing ft_memmove:\n");
    char src_memmove[] = "Hello World!";
    ft_memmove(src_memmove + 6, src_memmove, 5);
    printf("ft_memmove(src + 6, src, 5) = %s, expected = %s\n", src_memmove, "Hello Hello!");
    printf("\n");

    // Test ft_strlcpy
    printf("Testing ft_strlcpy:\n");
    char dest1_strlcpy[20];
    char expected1_strlcpy[20] = "Hello";
    size_t ret1_strlcpy = ft_strlcpy(dest1_strlcpy, "Hello", 20);
    printf("ft_strlcpy(dest1, \"Hello\", 20) = %zu, expected = %zu, dest1 = %s, expected1 = %s\n", ret1_strlcpy, strlen("Hello"), dest1_strlcpy, expected1_strlcpy);
    printf("\n");

    // Test ft_strlcat
    printf("Testing ft_strlcat:\n");
    char dest1_strlcat[20] = "Hello ";
    char expected1_strlcat[20] = "Hello World!";
    size_t ret1_strlcat = ft_strlcat(dest1_strlcat, "World!", 20);
    printf("ft_strlcat(dest1, \"World!\", 20) = %zu, expected = %zu, dest1 = %s, expected1 = %s\n", ret1_strlcat, strlen("Hello World!"), dest1_strlcat, expected1_strlcat);
    printf("\n");

    // Test ft_strnstr
    printf("Testing ft_strnstr:\n");
    char big[] = "Foo Bar Baz";
    char little[] = "Bar";
    char *result1_strnstr = ft_strnstr(big, little, 11);
    char *expected1_strnstr = strstr(big, little);
    printf("ft_strnstr(big, little, 11) = %s, expected = %s\n", result1_strnstr, expected1_strnstr);
    result1_strnstr = ft_strnstr(big, "xyz", 11);
    expected1_strnstr = strstr(big, "xyz");
    printf("ft_strnstr(big, \"xyz\", 11) = %s, expected = %s\n", result1_strnstr, expected1_strnstr);
    printf("\n");

    // Test ft_atoi
    printf("Testing ft_atoi:\n");
    printf("ft_atoi(\"42\") = %d, expected = %d\n", ft_atoi("42"), atoi("42"));
    printf("ft_atoi(\"-42\") = %d, expected = %d\n", ft_atoi("-42"), atoi("-42"));
    printf("ft_atoi(\"   1234\") = %d, expected = %d\n", ft_atoi("   1234"), atoi("   1234"));
    printf("ft_atoi(\"+5678\") = %d, expected = %d\n", ft_atoi("+5678"), atoi("+5678"));
    printf("\n");

    // Test ft_calloc
    printf("Testing ft_calloc:\n");
    int *arr1_calloc = (int *)ft_calloc(5, sizeof(int));
    int *arr2_calloc = (int *)calloc(5, sizeof(int));
    int identical_calloc = 1;
    for (int i = 0; i < 5; i++) {
        if (arr1_calloc[i] != arr2_calloc[i]) {
            identical_calloc = 0;
            break;
        }
    }
    printf("ft_calloc(5, sizeof(int)) = %s\n", identical_calloc ? "identical" : "different");
    free(arr1_calloc);
    free(arr2_calloc);
    printf("\n");

    // Test ft_strdup
    printf("Testing ft_strdup:\n");
    char *dup1_strdup = ft_strdup("Hello World!");
    char *dup2_strdup = strdup("Hello World!");
    printf("ft_strdup(\"Hello World!\") = %s, expected = %s\n", dup1_strdup, dup2_strdup);
    free(dup1_strdup);
    free(dup2_strdup);
    printf("\n");

// Test for ft_substr
    printf("Testing ft_substr:\n");
    char *substr = ft_substr("Hello World", 6, 5);
    printf("ft_substr(\"Hello World\", 6, 5) = %s, expected = World\n", substr);
    free(substr);
    printf("\n");

    // Test for ft_strjoin
    printf("Testing ft_strjoin:\n");
    char *strjoin = ft_strjoin("Hello", " World");
    printf("ft_strjoin(\"Hello\", \" World\") = %s, expected = Hello World\n", strjoin);
    free(strjoin);
    printf("\n");

    // Test for ft_strtrim
    printf("Testing ft_strtrim:\n");
    char *strtrim = ft_strtrim("   Hello World   ", " ");
    printf("ft_strtrim(\"   Hello World   \", \" \") = %s, expected = Hello World\n", strtrim);
    free(strtrim);
    printf("\n");

    // Test for ft_split
    printf("Testing ft_split:\n");
    char **split = ft_split("Hello World Hello", ' ');
    printf("ft_split(\"Hello World Hello\", ' ') = [%s, %s, %s], expected = [Hello, World, Hello]\n", split[0], split[1], split[2]);
    for (int i = 0; split[i] != NULL; i++) {
        free(split[i]);
    }
    free(split);
    printf("\n");

    // Test for ft_itoa
    printf("Testing ft_itoa:\n");
    char *itoa = ft_itoa(-12345);
    printf("ft_itoa(-12345) = %s, expected = -12345\n", itoa);
    free(itoa);
    printf("\n");

    // Test for ft_strmapi
    printf("Testing ft_strmapi:\n");
    char *strmapi = ft_strmapi("abcd", strmapi_test);
    printf("ft_strmapi(\"abcd\", f) = %s, expected = aceg\n", strmapi);
    free(strmapi);
    printf("\n");

    // Test for ft_striteri
    printf("Testing ft_striteri:\n");
    char striteri[] = "abcd";
    ft_striteri(striteri, striteri_test);
    printf("ft_striteri(\"abcd\", f) = %s, expected = aceg\n", striteri);
    printf("\n");

    // Test for ft_putchar_fd
    printf("Testing ft_putchar_fd:\n");
    printf("Output expected: A\n");
    ft_putchar_fd('A', STDOUT_FILENO);
    printf("\n");

    // Test for ft_putstr_fd
    printf("Testing ft_putstr_fd:\n");
    printf("Output expected: Hello World\n");
    ft_putstr_fd("Hello World", STDOUT_FILENO);
    printf("\n");

    // Test for ft_putendl_fd
    printf("Testing ft_putendl_fd:\n");
    printf("Output expected: Hello World\n");
    ft_putendl_fd("Hello World", STDOUT_FILENO);
    printf("\n");

    // Test for ft_putnbr_fd
    printf("Testing ft_putnbr_fd:\n");
    printf("Output expected: -12345\n");
    ft_putnbr_fd(-12345, STDOUT_FILENO);
    printf("\n");

// Test for ft_lstnew
    printf("Testing ft_lstnew:\n");
    t_list *node = ft_lstnew("Hello");
    printf("ft_lstnew(\"Hello\") -> content: %s, expected: Hello\n", (char *)node->content);
    printf("\n");

    // Test for ft_lstadd_front and ft_lstsize
    printf("Testing ft_lstadd_front and ft_lstsize:\n");
    t_list *head = ft_lstnew("World");
    ft_lstadd_front(&head, node);
    printf("List size after adding a node to the front: %d, expected: 2\n", ft_lstsize(head));
    printf("\n");

    // Test for ft_lstlast
    printf("Testing ft_lstlast:\n");
    t_list *last = ft_lstlast(head);
    printf("Last node content: %s, expected: World\n", (char *)last->content);
    printf("\n");

    // Test for ft_lstadd_back
    printf("Testing ft_lstadd_back:\n");
    t_list *new_node = ft_lstnew("!");
    ft_lstadd_back(&head, new_node);
    last = ft_lstlast(head);
    printf("Last node content after adding to back: %s, expected: !\n", (char *)last->content);
    printf("\n");

    // Test for ft_lstdelone
    printf("Testing ft_lstdelone:\n");
    ft_lstdelone(new_node, free);
    printf("List size after deleting the last node: %d, expected: 2\n", ft_lstsize(head));
    printf("\n");

    // Test for ft_lstclear
    printf("Testing ft_lstclear:\n");
    ft_lstclear(&head, free);
    printf("List size after clearing the list: %d, expected: 0\n", ft_lstsize(head));
    printf("\n");


    return 0;
}

