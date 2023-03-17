# Matching-Game-Project
This C++ program is a guessing game of matching numbers in a 2D array. There are two 2D arrays - one array is visible to the user while the other array (the answer array) is not visible to the user.

Running the Program: 
To run the program, compile the source code using a C++ compiler and run the resulting executable. The program will prompt the user to enter an email address to play the game. The email address is validated using the isWrongFormat function that checks if the email is in the correct format.
After entering a valid email address, the program will generate a 10x10 2D array of random numbers between 1 and 21. The user will then be prompted to guess the position of the number they want to match by entering the row and column values. If the user guesses the correct position, the program will reveal the number in the answer array at that position. The user can continue to guess until they find all the matching numbers.
The program keeps track of the coordinates the user has already guessed to avoid repetition using the checkRepeat function.

Functions:
The program uses the following functions:
isWrongFormat(string email)
This function checks if the email provided by the user is in the correct format. It checks each individual character of the email to see if they are alphanumeric characters or have multiple @ or . characters. It also checks if @ and . are written and in the correct order. Finally, it checks if there are alphanumeric characters before and after both @ and . characters.
initialize(int arrayType, int array[][COLS], int rows, int columns)
This function assigns values to the arrays depending on the input. If arrayType is -1, the function assigns -1 to each element of the array. If arrayType is not -1, the function assigns a random number between 1 and 21 to each element of the array.
display(int disp_array[][COLS], int rows, int columns)
This function displays the 2D array in a matrix format.
checkRepeat(int count, int revealed_cord[][2], int match_row, int match_column)
This function checks if the user has already guessed the coordinates of the number they want to match by comparing the revealed_cord array to the current coordinates provided by the user.

Variables: 
The program uses the following global variables:
ROWS: an integer variable representing the number of rows in the 2D array
COLS: an integer variable representing the number of columns in the 2D array
The program also uses the following local variables:
email: a string variable representing the email address entered by the user
repeat: a char variable representing whether the user wants to play the game again
disp_array: a 2D integer array representing the visible array displayed to the user
num_array: a 2D integer array representing the answer array not visible to the user
revealed_cord: a 2D integer array representing the coordinates the user has already guessed
count: an integer variable representing the number of coordinates the user has already guessed
