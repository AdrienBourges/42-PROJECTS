#include "ft_printf.h"
#include "libft/libft.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int i;

	i = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			i++;
			format++;
			ft_specifier(&format , args);
		}
		else
			ft_putchar(*format);
		i++;
		format++;
	}
	va_end(args);
	return (i);
}

#include <stdio.h>  // Standard I/O for comparison
#include "ft_printf.h"  // Your custom ft_printf

#include <stdio.h>  // Standard I/O for comparison
#include "ft_printf.h"  // Your custom ft_printf header

int main() {
    // Different values for testing
    char chars[] = {'A', '\0', 'z', '1', '%'};
    char *strings[] = {"Hello, world!", "", "Another test string.", NULL, "1234567890"};
    void *pointers[] = {NULL, strings, (void *)0x7fff, (void *)0xFFFFFFFFFFFFFFFF, (void *)chars};
    int integers[] = {2147483647, -2147483648, 0, 1, -1};
    unsigned int uintegers[] = {0, 1, 4294967295, 256, 1024};
    int hexValues[] = {0x1, 0x10, 0xABC, 0xFFFF, 0x123456};

    // Header for clarity
    printf("Comprehensive Testing of ft_printf with Various Values and Flag Combinations\n");
    printf("============================================================================\n\n");

    // %c specifier tests with combinations
    printf("--- %%c Specifier ---\n");
    for (int i = 0; i < sizeof(chars) / sizeof(chars[0]); i++) {
        printf("Standard printf: |%c| |%5c| |%-5c|\n", chars[i], chars[i], chars[i]);
        ft_printf("Custom ft_printf: |%c| |%5c| |%-5c|\n\n", chars[i], chars[i], chars[i]);
    }

    // %s specifier tests with combinations
    printf("--- %%s Specifier ---\n");
    for (int i = 0; i < sizeof(strings) / sizeof(strings[0]); i++) {
        if (strings[i] == NULL) {
            printf("Standard printf: |%s| |%20s| |%-20s| |%.5s|\n", "(null)", "(null)", "(null)", "(null)");
            ft_printf("Custom ft_printf: |%s| |%20s| |%-20s| |%.5s|\n\n", "(null)", "(null)", "(null)", "(null)");
        } else {
            printf("Standard printf: |%s| |%20s| |%-20s| |%.5s|\n", strings[i], strings[i], strings[i], strings[i]);
            ft_printf("Custom ft_printf: |%s| |%20s| |%-20s| |%.5s|\n\n", strings[i], strings[i], strings[i], strings[i]);
        }
    }

    // %p specifier tests with combinations
    printf("--- %%p Specifier ---\n");
    for (int i = 0; i < sizeof(pointers) / sizeof(pointers[0]); i++) {
        printf("Standard printf: |%p| |%20p| |%-20p| |%20p|\n", pointers[i], pointers[i], pointers[i], pointers[i]);
        ft_printf("Custom ft_printf: |%p| |%20p| |%-20p| |%20p|\n\n", pointers[i], pointers[i], pointers[i], pointers[i]);
    }

    // %d and %i specifier tests with combinations
    printf("--- %%d and %%i Specifiers ---\n");
    for (int i = 0; i < sizeof(integers) / sizeof(integers[0]); i++) {
        printf("Standard printf: |%d| |%+d| |% d| |%05d| |%.5d| |%-10d| |%+10.5d|\n", integers[i], integers[i], integers[i], integers[i], integers[i], integers[i], integers[i]);
        ft_printf("Custom ft_printf: |%d| |%+d| |% d| |%05d| |%.5d| |%-10d| |%+10.5d|\n\n", integers[i], integers[i], integers[i], integers[i], integers[i], integers[i], integers[i]);
    }

    // %u specifier tests with combinations
    printf("--- %%u Specifier ---\n");
    for (int i = 0; i < sizeof(uintegers) / sizeof(uintegers[0]); i++) {
        printf("Standard printf: |%u| |%20u| |%-20u| |%010u| |%.5u| |%-20.10u|\n", uintegers[i], uintegers[i], uintegers[i], uintegers[i], uintegers[i], uintegers[i]);
        ft_printf("Custom ft_printf: |%u| |%20u| |%-20u| |%010u| |%.5u| |%-20.10u|\n\n", uintegers[i], uintegers[i], uintegers[i], uintegers[i], uintegers[i], uintegers[i]);
    }

    // %x and %X specifiers tests with combinations
    printf("--- %%x and %%X Specifiers ---\n");
    for (int i = 0; i < sizeof(hexValues) / sizeof(hexValues[0]); i++) {
        printf("Standard printf: |%x| |%#x| |%20x| |%-20x| |%010x| |%.5x| |%10x| |%#20.10X|\n", hexValues[i], hexValues[i], hexValues[i], hexValues[i], hexValues[i], hexValues[i], hexValues[i], hexValues[i]);
        ft_printf("Custom ft_printf: |%x| |%#x| |%20x| |%-20x| |%010x| |%.5x| |%10x| |%#20.10X|\n\n", hexValues[i], hexValues[i], hexValues[i], hexValues[i], hexValues[i], hexValues[i], hexValues[i], hexValues[i]);
    }

    printf("============================================================================\n\n");
    return 0;
}


#include <stdio.h>
#include <stdio.h>  // Include standard I/O for comparison
#include "ft_printf.h"  // Replace with your custom ft_printf header file
/*
int main() {
    // Test numbers, including edge cases
    int nums[] = {123, -123, 0, 1, -1, 2147483647, -2147483648};

    // Loop through test numbers to print using both printf and ft_printf
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        int num = nums[i];

        // Test with various flags and width
        printf("--- Testing: %d ---\n", num);

        // No flags
        printf("Standard printf: |%d|\n", num);
        ft_printf("Custom ft_printf: |%d|\n\n", num);

        // Space flag
        printf("Standard printf: |% d|\n", num);
        ft_printf("Custom ft_printf: |% d|\n\n", num);

        // Plus flag
        printf("Standard printf: |%+d|\n", num);
        ft_printf("Custom ft_printf: |%+d|\n\n", num);

        // Minus (left justify) flag with width
        printf("Standard printf: |%-10d|\n", num);
        ft_printf("Custom ft_printf: |%-10d|\n\n", num);

        // Zero flag with width
        printf("Standard printf: |%010d|\n", num);
        ft_printf("Custom ft_printf: |%010d|\n\n", num);

        // Space and minus flags with width
        printf("Standard printf: |% -10d|\n", num);
        ft_printf("Custom ft_printf: |% -10d|\n\n", num);

        // Plus and minus flags with width
        printf("Standard printf: |%+-10d|\n", num);
        ft_printf("Custom ft_printf: |%+-10d|\n\n", num);

        // Space, plus, and minus flags with width (plus should override space)
        //printf("Standard printf: |% +-10d|\n", num);
        //ft_printf("Custom ft_printf: |% +-10d|\n\n", num);

        // Space, zero flag, and width (zero padding should be ignored due to space)
        printf("Standard printf: |% 010d|\n", num);
        ft_printf("Custom ft_printf: |% 010d|\n\n", num);

        // Plus, zero flag, and width
        printf("Standard printf: |%+010d|\n", num);
        ft_printf("Custom ft_printf: |%+010d|\n\n", num);

        // Complex combination: Plus, minus, zero flags with width
        //printf("Standard printf: |%+-010d|\n", num); // Zero flag should be ignored due to minus flag
        //ft_printf("Custom ft_printf: |%+-010d|\n\n", num);

        printf("=========================\n\n");
    }

    return 0;
}
*/
#include <stdio.h>  // Include standard I/O for comparison
#include "ft_printf.h"  // Replace with your custom ft_printf header file
/*
int main() {
    // Test numbers, including edge cases
    unsigned int nums[] = {123, 0, 1, 4294967295};  // Includes UINT_MAX

    // Loop through test numbers to print using both printf and ft_printf
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        unsigned int num = nums[i];

        // Test with various flags and width/precision
        printf("--- Testing: %u ---\n", num);

        // No flags, default width and precision
        printf("Standard printf: |%u|\n", num);
        ft_printf("Custom ft_printf: |%u|\n\n", num);

        // Width specification
        printf("Standard printf: |%10u|\n", num);
        ft_printf("Custom ft_printf: |%10u|\n\n", num);

        // Left justify with width
        printf("Standard printf: |%-10u|\n", num);
        ft_printf("Custom ft_printf: |%-10u|\n\n", num);

        // Zero padding with width
        printf("Standard printf: |%010u|\n", num);
        ft_printf("Custom ft_printf: |%010u|\n\n", num);

        // Precision only
        printf("Standard printf: |%.5u|\n", num);
        ft_printf("Custom ft_printf: |%.5u|\n\n", num);

        // Precision with width, precision overrides zero padding
        printf("Standard printf: |%10.5u|\n", num);
        ft_printf("Custom ft_printf: |%10.5u|\n\n", num);

        // Left justify with precision and width
        printf("Standard printf: |%-10.5u|\n", num);
        ft_printf("Custom ft_printf: |%-10.5u|\n\n", num);

        // Zero padding with precision and width (precision should override zero padding)
        //printf("Standard printf: |%010.5u|\n", num);
        //ft_printf("Custom ft_printf: |%010.5u|\n\n", num);

        printf("=========================\n\n");
    }

    return 0;
}
*/

/*
#include <stdio.h>  // Include standard I/O for comparison
#include "ft_printf.h"  // Replace with your custom ft_printf header file

int main() {
    // Test numbers, including edge cases
    unsigned int nums[] = {0, 1, 255, 0x12345, 0xFFFFFFFF};  // Includes 0, a small number, a typical number, and UINT_MAX

    // Loop through test numbers to print using both printf and ft_printf
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        unsigned int num = nums[i];

        // Test with various flags and width/precision
        printf("--- Testing: 0x%X ---\n", num);

        // Default
        printf("Standard printf: |%x|\n", num);
        ft_printf("Custom ft_printf: |%x|\n\n", num);

        // Width
        printf("Standard printf: |%10x|\n", num);
        ft_printf("Custom ft_printf: |%10x|\n\n", num);

        // Left justify with width
        printf("Standard printf: |%-10x|\n", num);
        ft_printf("Custom ft_printf: |%-10x|\n\n", num);

        // Precision
        printf("Standard printf: |%.5x|\n", num);
        ft_printf("Custom ft_printf: |%.5x|\n\n", num);

        // Width and precision
        printf("Standard printf: |%10.5x|\n", num);
        ft_printf("Custom ft_printf: |%10.5x|\n\n", num);

        // Left justify with width and precision
        printf("Standard printf: |%-10.5x|\n", num);
        ft_printf("Custom ft_printf: |%-10.5x|\n\n", num);

        // Hash flag
        printf("Standard printf: |%#x|\n", num);
        ft_printf("Custom ft_printf: |%#x|\n\n", num);

        // Hash flag with width
        printf("Standard printf: |%#10x|\n", num);
        ft_printf("Custom ft_printf: |%#10x|\n\n", num);

        // Hash flag with precision
        printf("Standard printf: |%#.5x|\n", num);
        ft_printf("Custom ft_printf: |%#.5x|\n\n", num);

        // Hash flag with width and precision
        printf("Standard printf: |%#10.5x|\n", num);
        ft_printf("Custom ft_printf: |%#10.5x|\n\n", num);

        // Zero padding with width
        printf("Standard printf: |%010x|\n", num);
        ft_printf("Custom ft_printf: |%010x|\n\n", num);

        // Zero padding with width, overridden by precision
        //printf("Standard printf: |%010.5x|\n", num);
        //ft_printf("Custom ft_printf: |%010.5x|\n\n", num);

        printf("=========================\n\n");
    }

    return 0;
}
*/
/*
#include <stdio.h>  // Standard I/O for comparison
#include "ft_printf.h"  // Your custom ft_printf header

int main() {
    // Test pointers
    int a = 42;
    void *ptrs[] = {NULL, &a, (void*)0x12345678, (void*)0xFFFFFFFF};

    // Loop through test pointers to print using both printf and ft_printf
    for (int i = 0; i < sizeof(ptrs) / sizeof(ptrs[0]); i++) {
        void *ptr = ptrs[i];

        // Test with various width specifications
        printf("--- Testing pointer: %p ---\n", ptr);
        printf("Standard printf: |%p|\n", ptr);
        ft_printf("Custom ft_printf: |%p|\n\n", ptr);

        // Width
        printf("Standard printf: |%20p|\n", ptr);
        ft_printf("Custom ft_printf: |%20p|\n\n", ptr);

        // Left justify with width
        printf("Standard printf: |%-20p|\n", ptr);
        ft_printf("Custom ft_printf: |%-20p|\n\n", ptr);

        printf("=========================\n\n");
    }

    return 0;
}
*/

#include <stdio.h>  // Standard I/O for comparison
#include "ft_printf.h"  // Replace with your custom ft_printf header
/*
int main() {
    // Array of characters to test
    char chars[] = {'a', 'Z', '0', '*', ' '};  // Include a whitespace character

    // Test each character with varying widths and the minus flag
    for (int i = 0; i < sizeof(chars) / sizeof(chars[0]); i++) {
        char c = chars[i];

        // Header to indicate what is being tested
        printf("--- Testing character: '%c' ---\n", c);

        // Test without any flags or width
        printf("Standard printf: |%c|\n", c);
        ft_printf("Custom ft_printf: |%c|\n\n", c);

        // Test with width
        printf("Standard printf: |%5c|\n", c);
        ft_printf("Custom ft_printf: |%5c|\n\n", c);

        // Test with minus flag and width
        printf("Standard printf: |%-5c|\n", c);
        ft_printf("Custom ft_printf: |%-5c|\n\n", c);

        // Further tests with different widths to see edge cases
        printf("Standard printf: |%1c|\n", c);
        ft_printf("Custom ft_printf: |%1c|\n\n", c);

        printf("Standard printf: |%10c|\n", c);
        ft_printf("Custom ft_printf: |%10c|\n\n", c);

        printf("Standard printf: |%-10c|\n", c);
        ft_printf("Custom ft_printf: |%-10c|\n\n", c);

        printf("=========================\n\n");
    }

    return 0;
}

*/





/*
int main()
{
ft_printf("%15d", -42 );
printf("\n");
printf("%15d", -42);
}*/
/*
#include <stdio.h>  // Include standard I/O for comparison
#include "ft_printf.h"  // Include your custom ft_printf header

int main() {
    // Test numbers
    int nums[] = {123, -123, 0, 1, -1};

    // Loop through test numbers to print using both printf and ft_printf
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        int num = nums[i];

        // Test without flags, with various width values
        printf("Standard printf: |%4d|\n", num);
        ft_printf("Custom ft_printf: |%4d|\n\n", num);

        printf("Standard printf: |%8d|\n", num);
        ft_printf("Custom ft_printf: |%8d|\n\n", num);

        // Test with left-justification flag and various width values
        printf("Standard printf: |%-4d|\n", num);
        ft_printf("Custom ft_printf: |%-4d|\n\n", num);

        printf("Standard printf: |%-8d|\n", num);
        ft_printf("Custom ft_printf: |%-8d|\n\n", num);

        // Test with zero padding flag and various width values
        printf("Standard printf: |%04d|\n", num);
        ft_printf("Custom ft_printf: |%04d|\n\n", num);

        printf("Standard printf: |%08d|\n", num);
        ft_printf("Custom ft_printf: |%08d|\n\n", num);

        // Test with precision
        printf("Standard printf: |%.4d|\n", num);
        ft_printf("Custom ft_printf: |%.4d|\n\n", num);

        printf("Standard printf: |%.8d|\n", num);
        ft_printf("Custom ft_printf: |%.8d|\n\n", num);

        // Test with precision and width
        printf("Standard printf: |%8.4d|\n", num);
        ft_printf("Custom ft_printf: |%8.4d|\n\n", num);

        // Test with zero padding, precision, and width (precision should override zero padding)
        //printf("Standard printf: |%08.4d|\n", num);
        //ft_printf("Custom ft_printf: |%08.4d|\n\n", num);

        printf("========================================\n");
    }

    return 0;
}
*/
/*
#include <stdio.h>  // Include standard I/O for comparison
#include "ft_printf.h"  // Include your custom ft_printf header

int main() {
    // Test unsigned numbers for hexadecimal representation
    unsigned int nums[] = {123, 0, 1, 4294967295};  // Includes UINT_MAX

    // Loop through test numbers to print using both printf and ft_printf
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        // Testing with %x specifier (lowercase hexadecimal)
        printf("Lowercase Hexadecimal (%%x):\n");
        printf("printf   : %x\n", nums[i]);
        ft_printf("ft_printf: %x\n\n", nums[i]);

        printf("printf   : %3x\n", nums[i]);
        ft_printf("ft_printf: %3x\n\n", nums[i]);

        printf("printf   : %5x\n", nums[i]);
        ft_printf("ft_printf: %5x\n\n", nums[i]);

        printf("printf   : %10x\n", nums[i]);
        ft_printf("ft_printf: %10x\n\n", nums[i]);

        printf("printf   : %03x\n", nums[i]);
        ft_printf("ft_printf: %03x\n\n", nums[i]);

        printf("printf   : %05x\n", nums[i]);
        ft_printf("ft_printf: %05x\n\n", nums[i]);

        printf("printf   : %-3x\n", nums[i]);
        ft_printf("ft_printf: %-3x\n\n", nums[i]);

        printf("printf   : %-5x\n", nums[i]);
        ft_printf("ft_printf: %-5x\n\n", nums[i]);

        printf("printf   : %-10x\n", nums[i]);
        ft_printf("ft_printf: %-10x\n\n", nums[i]);

        // Testing with %X specifier (uppercase hexadecimal)
        printf("Uppercase Hexadecimal (%%X):\n");
        printf("printf   : %X\n", nums[i]);
        ft_printf("ft_printf: %X\n\n", nums[i]);

        printf("printf   : %3X\n", nums[i]);
        ft_printf("ft_printf: %3X\n\n", nums[i]);

        printf("printf   : %5X\n", nums[i]);
        ft_printf("ft_printf: %5X\n\n", nums[i]);

        printf("printf   : %10X\n", nums[i]);
        ft_printf("ft_printf: %10X\n\n", nums[i]);

        printf("printf   : %03X\n", nums[i]);
        ft_printf("ft_printf: %03X\n\n", nums[i]);

        printf("printf   : %05X\n", nums[i]);
        ft_printf("ft_printf: %05X\n\n", nums[i]);

        printf("printf   : %-3X\n", nums[i]);
        ft_printf("ft_printf: %-3X\n\n", nums[i]);

        printf("printf   : %-5X\n", nums[i]);
        ft_printf("ft_printf: %-5X\n\n", nums[i]);

        printf("printf   : %-10X\n", nums[i]);
        ft_printf("ft_printf: %-10X\n\n", nums[i]);

        printf("========================================\n");
    }

    return 0;
}

*/
/*
#include <stdio.h>  // Include standard I/O for comparison
#include "ft_printf.h"  // Include your custom ft_printf header

int main() {
    // Test unsigned numbers
    unsigned int nums[] = {123, 0, 1, 4294967295};  // Includes UINT_MAX

    // Loop through test numbers to print using both printf and ft_printf
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        // Without flags
        printf("printf   : %u\n", nums[i]);
        ft_printf("ft_printf: %u\n\n", nums[i]);

        printf("printf   : %3u\n", nums[i]);
        ft_printf("ft_printf: %3u\n\n", nums[i]);

        printf("printf   : %5u\n", nums[i]);
        ft_printf("ft_printf: %5u\n\n", nums[i]);

        printf("printf   : %10u\n", nums[i]);
        ft_printf("ft_printf: %10u\n\n", nums[i]);

        // With zero padding flag
        printf("printf   : %03u\n", nums[i]);
        ft_printf("ft_printf: %03u\n\n", nums[i]);

        printf("printf   : %05u\n", nums[i]);
        ft_printf("ft_printf: %05u\n\n", nums[i]);

        printf("printf   : %010u\n", nums[i]);
        ft_printf("ft_printf: %010u\n\n", nums[i]);

        // With left-justification flag
        printf("printf   : %-3u\n", nums[i]);
        ft_printf("ft_printf: %-3u\n\n", nums[i]);

        printf("printf   : %-5u\n", nums[i]);
        ft_printf("ft_printf: %-5u\n\n", nums[i]);

        printf("printf   : %-10u\n", nums[i]);
        ft_printf("ft_printf: %-10u\n\n", nums[i]);

        printf("========================================\n");
    }

    return 0;
}
*/

/*
#include <stdio.h>  // Include standard I/O for comparison
#include "ft_printf.h"  // Include your custom ft_printf header

int main() {
    // Test numbers
    int nums[] = {123, -123, 0, 1, -1, 2147483647};
    // Widths are now part of the format strings below, so this array is not needed.

    // Loop through test numbers to print using both printf and ft_printf
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        // Without flags
        printf("printf   : %d\n", nums[i]);
        ft_printf("ft_printf: %d\n\n", nums[i]);

        printf("printf   : %3d\n", nums[i]);
        ft_printf("ft_printf: %3d\n\n", nums[i]);

        printf("printf   : %5d\n", nums[i]);
        ft_printf("ft_printf: %5d\n\n", nums[i]);

        printf("printf   : %10d\n", nums[i]);
        ft_printf("ft_printf: %10d\n\n", nums[i]);

        // With zero padding flag
        printf("printf   : %03d\n", nums[i]);
        ft_printf("ft_printf: %03d\n\n", nums[i]);

        printf("printf   : %05d\n", nums[i]);
        ft_printf("ft_printf: %05d\n\n", nums[i]);

        printf("printf   : %010d\n", nums[i]);
        ft_printf("ft_printf: %010d\n\n", nums[i]);

        // With left-justification flag
        printf("printf   : %-3d\n", nums[i]);
        ft_printf("ft_printf: %-3d\n\n", nums[i]);

        printf("printf   : %-5d\n", nums[i]);
        ft_printf("ft_printf: %-5d\n\n", nums[i]);

        printf("printf   : %-10d\n", nums[i]);
        ft_printf("ft_printf: %-10d\n\n", nums[i]);

        printf("========================================\n");
    }

    return 0;
}

*/
/*
#include <stdio.h>  // For standard printf
#include <limits.h> // For INT_MIN, INT_MAX, etc.

int main(void) {
	// Test with simple strings
	printf("Standard printf: Hello, World!\n");
	ft_printf("ft_printf: Hello, World!\n\n");

	// Test with characters
	printf("Standard printf: Char: %c\n", 'A');
	ft_printf("ft_printf: Char: %c\n\n", 'A');

	// Test with strings
	printf("Standard printf: String: %-10s\n", "Test Str");
	ft_printf("ft_printf: String: %-s\n\n", "Test Str");

	// Test with integers
	printf("Standard printf: Integer: %d\n", 42);
	ft_printf("ft_printf: Integer: %d\n\n", 42);

	// Test with unsigned integers
	printf("Standard printf: Unsigned Integer: %u\n", 42u);
	ft_printf("ft_printf: Unsigned Integer: %u\n\n", 42u);

	// Test with hexadecimal (lowercase and uppercase)
	printf("Standard printf: Hex (lowercase): %x, Hex (uppercase): %X\n", 255, 255);
	ft_printf("ft_printf: Hex (lowercase): %x, Hex (uppercase): %X\n\n", 255, 255);

	// Test with pointers
	int num = 42;
	printf("Standard printf: Pointer: %p\n", (void*)&num);
	ft_printf("ft_printf: Pointer: %p\n\n", (void*)&num);

	// Test with percent sign
	printf("Standard printf: Percent: %%\n");
	ft_printf("ft_printf: Percent: %%\n\n");

	// Test with multiple format specifiers
	printf("Standard printf: Combo: %d %s %c %x\n", 42, "Hello", 'A', 255);
	ft_printf("ft_printf: Combo: %d %s %c %x\n\n", 42, "Hello", 'A', 255);

	// Test with edge cases
	printf("Standard printf: INT_MIN: %d, INT_MAX: %d\n", INT_MIN, INT_MAX);
	ft_printf("ft_printf: INT_MIN: %d, INT_MAX: %d\n\n", INT_MIN, INT_MAX);

	printf("Standard printf: UINT_MAX: %u\n", UINT_MAX);
	ft_printf("ft_printf: UINT_MAX: %u\n\n", UINT_MAX);

	// Add more tests as needed...
	// Edge Case: Zero with various specifiers
	printf("Standard printf: Zero: %d, %u, %x, %X\n", 0, 0, 0, 0);
	ft_printf("ft_printf: Zero: %d, %u, %x, %X\n\n", 0, 0, 0, 0);

	// Edge Case: Negative numbers for %d and %i
	printf("Standard printf: Negative: %d, %i\n", -42, -42);
	ft_printf("ft_printf: Negative: %d, %i\n\n", -42, -42);

	// Edge Case: Printing NULL pointers
	printf("Standard printf: NULL pointer: %p\n", (void*)NULL);
	ft_printf("ft_printf: NULL pointer: %p\n\n", (void*)NULL);

	// Edge Case: Maximum and Minimum values for %u, %x, %X
	printf("Standard printf: Max/Min: %u, %x, %X\n", UINT_MAX, 0, UINT_MAX);
	ft_printf("ft_printf: Max/Min: %u, %x, %X\n\n", UINT_MAX, 0, UINT_MAX);

	// Add more edge cases as needed based on the features you've implemented

	return 0;
}
*/
/*
#include "ft_printf.h"  // Make sure to include the header for your ft_printf function
#include <stdio.h>
int main() {
    // Basic string printing
    ft_printf("Basic string: %s\n\n", "Hello, world!");

    // Precision specifier examples
    ft_printf("Precision (cut off): %.5s\n", "Hello, world!");
    ft_printf("Precision (full): %.12s\n", "Hello, world!");
    ft_printf("Precision (exceeding): %.15s\n\n", "Hello, world!");

    // Field width examples
    ft_printf("Field width (right-aligned): %10s\n", "test");
    ft_printf("Field width (exact): %4s\n", "test");
    ft_printf("Field width (narrow): %2s\n\n", "test");

    // Left-justification with the minus flag examples
    ft_printf("Left-justify: %-10s end\n", "test");
    ft_printf("Left-justify with exact field width: %-4s end\n", "test");
    ft_printf("Left-justify with narrow field: %-2s end\n\n", "test");

    // Combining precision and field width
    ft_printf("Combined precision and width (right-aligned): %10.5s\n", "Hello, world!");
    ft_printf("Combined precision and width (left-justified): %-10.5s end\n", "Hello, world!");
    ft_printf("Precision and narrow field: %.3s\n", "Hello");
    ft_printf("Precision exceeding field width: %3.5s\n\n", "Hello");

    // Edge cases
    ft_printf("Empty string with width: %5s\n", "");
   // ft_printf("Null string: %s\n", (char *)NULL);  // Depending on how you handle NULL
    ft_printf("Empty string with precision: %.5s\n", "");
    ft_printf("Width with empty string: %5.s\n", "");  // Precision set to 0 explicitly



    // Basic string printing
    printf("Basic string: %s\n", "Hello, world!");  // Expected: Basic string: Hello, world!

    // Precision specifier examples
    printf("Precision (cut off): %.5s\n", "Hello, world!");  // Expected: Precision (cut off): Hello
    printf("Precision (full): %.12s\n", "Hello, world!");  // Expected: Precision (full): Hello, world!
    printf("Precision (exceeding): %.15s\n", "Hello, world!");  // Expected: Precision (exceeding): Hello, world!

    // Field width examples
    printf("Field width (right-aligned): %10s\n", "test");  // Expected: Field width (right-aligned):       test
    printf("Field width (exact): %4s\n", "test");  // Expected: Field width (exact): test
    printf("Field width (narrow): %2s\n", "test");  // Expected: Field width (narrow): test

    // Left-justification with the minus flag examples
    printf("Left-justify: %-10s end\n", "test");  // Expected: Left-justify: test       end
    printf("Left-justify with exact field width: %-4s end\n", "test");  // Expected: Left-justify with exact field width: test end
    printf("Left-justify with narrow field: %-2s end\n", "test");  // Expected: Left-justify with narrow field: test end

    // Combining precision and field width
    printf("Combined precision and width (right-aligned): %10.5s\n", "Hello, world!");  // Expected: Combined precision and width (right-aligned):      Hello
    printf("Combined precision and width (left-justified): %-10.5s end\n", "Hello, world!");  // Expected: Combined precision and width (left-justified): Hello      end
    printf("Precision and narrow field: %.3s\n", "Hello");  // Expected: Precision and narrow field: Hel
    printf("Precision exceeding field width: %3.5s\n", "Hello");  // Expected: Precision exceeding field width: Hello

    // Edge cases
    printf("Empty string with width: %5s\n", "");  // Expected: Empty string with width:      
    //printf("Null string: %s\n", (NULL);  // Expected: Null string: (null)
    printf("Empty string with precision: %.5s\n", "");  // Expected: Empty string with precision: 
    printf("Width with empty string: %5.s\n", "");  // Expected: Width with empty string:      

    return 0;
}*/

