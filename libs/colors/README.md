# Colors Lib

### Colors
Creates a struct with ARGB values. Alpha value is its transparency, 0 is 100% tranparent, 255 or 1 is 0% transparent.

### Add Colors
Add all values.

### Sub Colors
Subtracts color B values to color A values.

### Scale Colors
Multiplies color A values by a number N.

### Norm Colors
Normalizes the colors dividing by 255 so that it's values range from 0 to 1 instead of 0 to 255.

### Refit Colors
If an attribute has an value less than 0 it becomes 0 if is greater than 1 it becomes 1.

### ARGB to int
First calls refit_colors to make sure the values are fit, then multiplies everything by 255. And at last use bitwise operators to return a int that has the ARGB info. An int has 4 bytes each component uses one byte, remember that one byte has 8 bits and with 8 bits you can write any number from 0 to 255.

### Hadamard Product
Used to blend colors together, the values are just multiplied one by one. It is called Hadamard Product or Schur Product.