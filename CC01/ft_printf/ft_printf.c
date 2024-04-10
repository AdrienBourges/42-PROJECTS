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

#include <stdio.h>


/*
int main()
{
ft_printf("%10s","test" );
printf("\n");
printf("%10s", "test");
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
}

