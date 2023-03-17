/*
 * Description: This is a C++ program that plays a guessing game of matching numbers in a 2D array. There are two 2D arrays - one array is visible to the user while the other array (the answer array) is not visible to the user.  
*/

#include <iostream>
using namespace std;

//declaring global variables
const int ROWS = 10;
const int COLS = 10;

//isWrongFormat function that checks if the email is in the correct format
bool isWrongFormat(string email)
{
    bool invalid_email = false;
    int atCount = 0;
    int periodCount = 0;
    int atPosition = -1;
    int periodPosition = -1;

    //for loop that checks each individual character of the email if they are not alphanumeric characters or have multiple @ or . characters 
    for (int i = 0; i < email.length(); ++i)
    {
        if ((isalnum(email.at(i)) == false) && (email.at(i) != '@') && (email.at(i) != '.'))
        {
            invalid_email = true;
            cout << "Your email format is not correct. Please try again. (Not alpha num)" << endl;
            return invalid_email;
        }

        if (email.at(i) == '@')
        {
            atPosition = i;
            ++atCount;
        }
        else if (email.at(i) == '.')
        {
            periodPosition = i;
            ++periodCount;
        }

        if (atCount >= 2 || periodCount >= 2)
        {
            invalid_email = true;
            cout << "Your email format is not correct. Please try again. (too many @ or .)" << endl;
            return invalid_email;
        }


    }

    //checks to see if @ or . have been written and checks if they are in the correct order 
    if (atPosition == -1 || periodPosition == -1)
    {
        invalid_email = true;
        cout << "Your email format is not correct. Please try again. (no @ or .)" << endl;
        return invalid_email;
    }
    else if (atPosition > periodPosition)
    {
        invalid_email = true;
        cout << "Your email format is not correct. Please try again. (. before @)" << endl;
        return invalid_email;
    }

    
    //if block that checks if there are alphanumeric characters before and after both @ and . characters 
    if(!isalnum(email.at(email.find('.') - 1)))
    {
        invalid_email = true;
        cout << "Your email format is not correct. Please try again. (no letter before or after)" << endl;
        return invalid_email;
    }
    if (!isalnum(email.at(email.find('.') + 1)))
    {
        invalid_email = true;
        cout << "Your email format is not correct. Please try again. (no letter before or after)" << endl;
        return invalid_email;
    }

    if (!isalnum(email.at(email.find('@') - 1)))
    {
        invalid_email = true;
        cout << "Your email format is not correct. Please try again. (no letter before or after)" << endl;
        return invalid_email;
    }
    if (!isalnum(email.at(email.find('@') + 1)))
    {
        invalid_email = true;
        cout << "Your email format is not correct. Please try again. (no letter before or after)" << endl;
        return invalid_email;
    }


    return invalid_email;
}


//initialize function that assigns to the arrays depending on the input 
void initialize(int arrayType, int array[][COLS], int rows, int columns)
{
    
    srand(time(NULL));

    if (arrayType == -1)
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                array[i][j] = -1;
            }
        }
    }
    else if (!(arrayType == -1))
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                array[i][j] = (rand()%21) + 1;
            }
        }
 
}

//display function that displays the array 
void display(int disp_array[][COLS], int rows, int columns)
{
    cout << "Your new matrix is:" << endl;

    for (int i = 0; i < rows; ++i)
    {
        for (int h = 0; h < columns; ++h)
        {
            cout << disp_array[i][h] << "\t";
        }
        cout << endl;
    }

}

//checkRepeat function that checks if the coordinates have been repeated 
bool checkRepeat(int count, int revealed_cord[][2], int match_row, int match_column)
{
    bool is_repeated = false;

    for (int i = 0; i < count; ++i)
    {
        if (revealed_cord[i][0] == match_row)
        {
            if (revealed_cord[i][1] == match_column)
            {
                is_repeated = true;
                break;
            }
        }
    }

    return is_repeated;
}


int main()
{
    //declaring variables 
    string email;
    char repeat;
    int disp_array[ROWS][COLS];
    int num_array[ROWS][COLS];
    int revealed_cord[50][2];
    int count = 0;
    int rows;
    int columns;
    int reveal_row;
    int reveal_column;
    int match_row;
    int match_column;
    int points = 10;
    int arrayType = -1;
    bool valid_entry1 = false;
    bool valid_entry2 = false;
    bool valid_entry3 = false;
    bool invalid_email = false;
    bool is_repeated = false;
    bool to_repeat = true;
    bool restart = false;
    

    //takes in user email and checks if it is in the right format using the isWrongFormat function
    do
    {
        cout << "Enter your email address: ";
        cin >> email;
        invalid_email = isWrongFormat(email);
    } while (invalid_email);

    //takes in the rows and columns for the array and checks if they are within the range 
    do
    {
        cout << "Enter the rows and columns of the matrix: ";
        cin >> rows >> columns;

        if ((rows < 10 && rows > 1) && (columns < 10 && columns > 1))
        {
            valid_entry1 = true;
        }
        else
        {
            cout << "Number entered is out out bounds." << endl;
        }
    } while (!valid_entry1);

    //initializes the display array and the hidden array 
    initialize(arrayType, disp_array, rows, columns);

    arrayType = 0;

    initialize(arrayType, num_array, rows, columns);

    display(disp_array, rows, columns);

    //main body 
    do
    {
	//checks if user is out of points 
        if (points < 1)
        {
            cout << "You are out of points. The game is Over.";
            restart = false;
            break;
        }


        //starts do-while loop that takes in the user's reveal coordinates, checks if they are within range, checks if they are repeated, and stores them in an array 
        do
        {
            cout << "Enter the coordinates to reveal: ";
            cin >> reveal_row >> reveal_column;

            if ((reveal_row < 10 && reveal_row >= 0) && (reveal_column < 10 && reveal_column >= 0))
            {
                is_repeated = checkRepeat(count, revealed_cord, reveal_row, reveal_column);

                if (is_repeated)
                {
                    cout << "You have already entered these co-ordinates. Please try again." << endl;
                    valid_entry2 = false;
                }
                else
                {
                    ++count;
                    for (int i = (count - 1); i < count; ++i)
                    {
                        for (int j = 0; j < 2; ++j)
                        {
                            if (j == 0)
                            {
                                revealed_cord[i][j] = reveal_row;
                            }
                            else if (j == 1)
                            {
                                revealed_cord[i][j] = reveal_column;
                            }
                        }
                    }

                    valid_entry2 = true;
                }
            }
            else
            {
                cout << "Number entered is out out bounds." << endl;
            }
        } while (!valid_entry2);


        //displays the display array with the hidden character chosen by the user revealed 
        disp_array[reveal_row][reveal_column] = num_array[reveal_row][reveal_column];

        display(disp_array, rows, columns);


        //prompts the user for coordinates then checks if they are in range and if they have been repeated 
        do
        {
            cout << "Select co-ordinates to match: ";
            cin >> match_row >> match_column;

            
            
                if ((match_row < 10 && match_row >= 0) && (match_column < 10 && match_column >= 0))
                {
                    valid_entry3 = true;

                    is_repeated = checkRepeat(count, revealed_cord, match_row, match_column);

                    if (is_repeated)
                    {
                        cout << "You have already entered these co-ordinates. Please try again." << endl;
                        valid_entry3 = false;
                    }

                }
                else
                {
                    cout << "Number entered is out out bounds. (match)" << endl;
                }
            
        } while (!valid_entry3);

  
        //checks if the match coordinates are the same as the revealed coordinates in the previous step and if so, informs the user and adds 2 points to their score and if not, informs the user and removes 1 point 
        if (num_array[match_row][match_column] == disp_array[reveal_row][reveal_column])
        {
            cout << "You found a match!" << endl;
            points += 2;
            disp_array[match_row][match_column] = num_array[match_row][match_column];

            display(disp_array, rows, columns);
        }
        else if (num_array[match_row][match_column] != disp_array[reveal_row][reveal_column])
        {
            cout << "It does not match" << endl;
            points -= 1;
            cout << "Points balance: " << points << endl;
        }


        //asks the user if they would like to repeat the game after they have made a guess 
        do
        {
            cout << "Do you want to repeat? Y/N: ";
            cin >> repeat;
            if (toupper(repeat) == 'Y')
            {
                to_repeat = false;
                restart = true;
            }
            else if (toupper(repeat) == 'N')
            {
                to_repeat = false;
                restart = false;
                break;
            }
            else
            {
                cout << "Incorrect choice, try again." << endl;
                to_repeat = true;
            }
        } while (to_repeat);

    } while (restart == true);
    
    //displays the user's points after they have ended the game
    cout << "You have " << points << " remaining." << endl;
    cout << "Your results will be emailed to you at " << email <<endl;
    cout << "Goodbye." << endl;
    
  
    return 0;
}






