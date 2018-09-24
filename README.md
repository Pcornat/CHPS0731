# CHPS0731
## Subject : ray tracing.

The goal of this code is to generate a picture with a white sphere at first then with different 
colours.

### Bugs :
* First, for the plane I cannot have a correct normal vector. Example :
A plan with an origin of x = 0, y = 5, z = 0, the normal vector should be : x = 0, y = -5, z = 0. BUT, it does not work as we want.

* Second, we had to replace our implementation of the ray plane intersection with the official one from GLM. It works now.
