# stdout (standard output)

In ALB, we can use two methods to access the standard output. These two methods are the _out_ method and the _specific/special outs_ method.

## out method

This is the easiest method to access the standard output, specially for beginners, but it might get tedious when it comes to an experienced programmer. The structure of this function is the following:

```
out {
  :data_type value attribute(s) ;
  // You can put as many as you need
}
```

Here, _data_type_ stands for the type of data you are going to display with _value_ (the type of output). These are the valid data types that can be used inside an _out_ function:

Numerics:
- `:int`: stands for _integer_ (signed by default). Holds an integer numeric value (e.g. 43, 0, -342).
- `:float`: stands for _floating-point number_ (also signed by default). Holds a floating-point numeric value (e.g. 54.122, 3.141592, 999.99999).
- `:hex`, `:oct` and `:bin`: they hold integers in hexadecimal, octal and binary base (base 16, base 8 and base 2), respectively. When using one of these, there is no need to add prefixes as `0x` in C to identify hexadecimal integers. Just the number in its respective base is required (e.g. 78f12e8ac1 (hexadecimal), 56170421 (octal, but this number would be also valid in hexadecimal and decimal bases), 1010100011101010 (binary, but also a valid number in hexadecimal, decimal and octal bases).

Non-numerics:
- `:string` or `:str`: requires a string of characters as a value, enclosed between double quotes (e.g. `"Hello, world!"`). It can have the attributes `NEWL` (_newline_), which will print on the screen a new line; `BSPACE` and `BTAB` (_blank space_ and _blank tab_ (indentation, 4 spaces by default)). The attributes can be put inmediately before, after the value, or at both sides, but NOT inside the value.
- `:char`: a simple character (inside the UTF-8 collation). It must be enclosed in single quotes (e.g. `'c'`). It cannot contain any attributes.
- `:newl` or `:newline`: with the same utility as `:string`'s `NEWL` attribute, it might be useful when a `:string` data output is not needed.

Others:
- `:var`: it will display the value contained in the indicated variable. Usage example: `:var $VAR_ID ;`.

## special/specific outs method

This method consists of a set of functions (one for each data type) that can only display ONE VALUE of a specific data type at a time. These are all valid special outs in ALB:

Non-numeric:
- `outs`: out string. Will only display a string-type value and attributes (if there is any). Usage example: `outs "Hello, world!" NEWL ;`, which would display the message _Hello, world!_ on the screen, inmediately followed by a new line.
- `outc`: out char (character). Can only display a single character at a time. No valid attributes for this special out. Usage example: `outc 'c' ;`, which would display the character _c_ on the screen.

Other:
- `outv`: out variable. Structure: `outv $VAR_ID ;`. Will display the value stored in the variable with the specified `VAR_ID`. Usage example: `outv $my_variable ;`, which would display the value in the variable _my_variable_, obviating it has been previously defined.
