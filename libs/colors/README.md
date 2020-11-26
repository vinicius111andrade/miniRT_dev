# Colors Lib

### Colors
Creates a struct with ARGB values.

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

### Final Colors
First calls refit_colors to make sure the values are fit, then multiplies everything by 255.