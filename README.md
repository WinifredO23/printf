Team project 
custom printf function that prints and handles diffrent specfiers 
in this project 
we have a list of goals to achieve and this are th outlines
0. I'm not going anywhere. You can print that wherever you want to. I'm here and I'm a Spur for life 
Write a function that produces output according to a format.

    Prototype: int _printf(const char *format, ...);
    Returns: the number of characters printed (excluding the null byte used to end output to strings)
    write output to stdout, the standard output stream
    format is a character string. The format string is composed of zero or more directives. See man 3 printf for more detail. You need to handle the following conversion specifiers:
        c
        s
        %
    You don’t have to reproduce the buffer handling of the C library printf function
    You don’t have to handle the flag characters
    You don’t have to handle field width
    You don’t have to handle precision
    You don’t have to handle the length modifiers

1. Education is when you read the fine print. Experience is what you get if you don't
Handle the following conversion specifiers:

    d
    i
    You don’t have to handle the flag characters
    You don’t have to handle field width
    You don’t have to handle precision
    You don’t have to handle the length modifiers
2. With a face like mine, I do better in print
Handle the following custom conversion specifiers:
    b: the unsigned int argument is converted to binary
3. What one has not experienced, one will never understand in print 
Handle the following conversion specifiers:

    u
    o
    x
    X
    You don’t have to handle the flag characters
    You don’t have to handle field width
    You don’t have to handle precision
    You don’t have to handle the length modifiers
4. Nothing in fine print is ever good news 
Use a local buffer of 1024 chars in order to call write as little as possible.

5. My weakness is wearing too much leopard print 
Handle the following custom conversion specifier:

    S : prints the string.
    Non printable characters (0 < ASCII value < 32 or >= 127) are printed this way: \x, followed by the ASCII code value in hexadecimal (upper case - always 2 characters)

6. How is the world ruled and led to war? Diplomats lie to journalists and believe these lies when they see them in print 
Handle the following conversion specifier: p.

    You don’t have to handle the flag characters
    You don’t have to handle field width
    You don’t have to handle precision
    You don’t have to handle the length modifiers
7. The big print gives and the small print takes away 
Handle the following flag characters for non-custom conversion specifiers:

    +
    space
    #
8. Sarcasm is lost in print 
Handle the following length modifiers for non-custom conversion specifiers:

    l
    h

Conversion specifiers to handle: d, i, u, o, x, X

9. Print some money and give it to us for the rain forests 
10. The negative is the equivalent of the composer's score, and the print the performance 
11. It's depressing when you're still around and your albums are out of print 
Handle the 0 flag character for non-custom conversion specifiers.
12. Every time that I wanted to give up, if I saw an interesting textile, print what ever, suddenly I would see a collection 
13. Print is the sharpest and the strongest weapon of our party 
Handle the following custom conversion specifier:

    r : prints the reversed string
14. The flood of print has turned reading into a process of gulping rather than savoring 
Handle the following custom conversion specifier:

    R: prints the rot13'ed string
15. * 
All the above options work well together.
aim of the project is to make ure everything works accordingly 
    specifier	Output	Example
    d or i	Signed decimal integer	392
    u	Unsigned decimal integer	7235
    o	Unsigned octal	610
    x	Unsigned hexadecimal integer	7fa
    X	Unsigned hexadecimal integer (uppercase)	7FA
    f	Decimal floating point, lowercase	392.65
    F	Decimal floating point, uppercase	392.65
    e	Scientific notation (mantissa/exponent), lowercase	3.9265e+2
    E	Scientific notation (mantissa/exponent), uppercase	3.9265E+2
    g	Use the shortest representation: %e or %f	392.65
    G	Use the shortest representation: %E or %F	392.65
    a	Hexadecimal floating point, lowercase	-0xc.90fep-2
    A	Hexadecimal floating point, uppercase	-0XC.90FEP-2
    c	Character	a
    s	String of characters	sample
    p	Pointer address	b8000000
    n	Nothing printed.
    The corresponding argument must be a pointer to a signed int.
    The number of characters written so far is stored in the pointed location.	
    %	A % followed by another % character will write a single % to the stream.	%

    The format specifier can also contain sub-specifiers: flags, width, .precision and modifiers (in that order), which are optional and follow these specifications:

    flags	description
    -	Left-justify within the given field width; Right justification is the default (see width sub-specifier).
    +	Forces to preceed the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a - sign.
    (space)	If no sign is going to be written, a blank space is inserted before the value.
    #	Used with o, x or X specifiers the value is preceeded with 0, 0x or 0X respectively for values different than zero.
    Used with a, A, e, E, f, F, g or G it forces the written output to contain a decimal point even if no more digits follow. By default, if no digits follow, no decimal point is written.
    0	Left-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier).

    width	description
    (number)	Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger.
    *	The width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.

    .precision	description
    .number	For integer specifiers (d, i, o, u, x, X): precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0.
    For a, A, e, E, f and F specifiers: this is the number of digits to be printed after the decimal point (by default, this is 6).
    For g and G specifiers: This is the maximum number of significant digits to be printed.
    For s: this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered.
    If the period is specified without an explicit value for precision, 0 is assumed.
    .*	The precision is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.

    The length sub-specifier modifies the length of the data type. This is a chart showing the types used to interpret the corresponding arguments with and without length specifier (if a different type is used, the proper type promotion or conversion is performed, if allowed):
    	specifiers
    length	d i	u o x X	f F e E g G a A	c	s	p	n
    (none)	int	unsigned int	double	int	char*	void*	int*
    hh	signed char	unsigned char					signed char*
    h	short int	unsigned short int					short int*
    l	long int	unsigned long int		wint_t	wchar_t*		long int*
    ll	long long int	unsigned long long int					long long int*
    j	intmax_t	uintmax_t					intmax_t*
    z	size_t	size_t					size_t*
    t	ptrdiff_t	ptrdiff_t					ptrdiff_t*
    L			long double				
    Note regarding the c specifier: it takes an int (or wint_t) as argument, but performs the proper conversion to a char value (or a wchar_t) before formatting it for output.

    Note: Yellow rows indicate specifiers and sub-specifiers introduced by C99. See <cinttypes> for the specifiers for extended types.
... (additional arguments)
    Depending on the format string, the function may expect a sequence of additional arguments, each containing a value to be used to replace a format specifier in the format string (or a pointer to a storage location, for n).
    There should be at least as many of these arguments as the number of values specified in the format specifiers. Additional arguments are ignored by the function.


Return Value
On success, the total number of characters written is returned.

If a writing error occurs, the error indicator (ferror) is set and a negative number is returned.

If a multibyte character encoding error occurs while writing wide characters, errno is set to EILSEQ and a negative number is returned.
