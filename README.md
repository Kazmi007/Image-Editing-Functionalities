# Image-Editing-Functionalities
This program provides a basic terminal version of common image editing functionalities like filling a part of an image by a color, copying and pasting selected parts of the image, along with the option of rotation.

Three different functionalities are defined:
- 'Bucket Fill' type color fill.
- Copying an area of an image and pasting it on another part of the image.
- Copying an area of image, rotating it, and pasting it on another part of the image.

The program takes input form stdin. The first thing provided in all three scenarios should be a matrix-like input of the image pixels where each line of input is a different row with blank-separated numbers being the individual pixels in each row.
Eight different colors can be represented in the program, numbered 0-7. Specific input after the opcode differs for the three operations.

The size of the image can be changed using the macro defined at the start of the file (25x25 by default).


'F'
- This opcode following the image input is for the fill operation. Following this the user will give two coordinates as inputs, the first being of the color to be filled and the second being the pixel it starts filling from.
- The program will fill the color-continuous area surrounding that certain pixel with the chosen color, and print the resulting image in the same format as the input out to stdout.


'P'
- After this opcode the user provides four coordinates in two lines. The first line holding the two diagonally opposite pixels of the rectangular area to be copied, and the second line holding the same for the area to be copied to.
- As above, the resulting image will be printed to stdout.


'R'
- The user will provide the rotation information after this opcode. In the next line, 'L' should be entered for anti-clockwise rotation, and similarly 'R' for clockwise, followed by an angle of either 0, 90, 180, or 270.
- The user will then input the diagonally opposite pixels for a square area like in the second operation, and the resulting image will be printed to stdout after the operation has been carried out.


C you next time :)
