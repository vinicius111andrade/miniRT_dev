# Tuples Lib

### Tuple struct
x, y, z, coordinates and w to say if it is a vector or a point. Vector has w equal to 0 and point has w equal to 1. x, y, z, w are double data types.

### Addition
Adding two vectors is possible, adding a vector to a point is possible, adding two points is not possible. Because the tuples have 4 parameters, x, y, z, and w. w is 0 for vectors and 1 for points. When adding the w value is also added and that value can't be 2. So you can't add points.

### Subtraction
Subtracting two vectors is possible and gives a vector, subtracting two points is possible and gives a vector, subtracting a vector from a point is possible and gives a point, subtracting a point from a vector is not possible because it gives you a w equal to -1.

### Negation
It inverts vectors. It changes x, y, z, w to -x, -y, -z, -w.

### Scale
Multiplies x, y, z by a scalar.

### Dot Product
Receives two vectors and returns a double with the result of the dot product.

### Magnitude
The magnitude of a vector is it's length.

### Normalize
Receives a vector and returns the corresponding unit vector.

### Cross Product
Receives two vectors and returns the cross product vector. The result is always perpendicular to the inputs.