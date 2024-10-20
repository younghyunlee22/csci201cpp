#include <iostream>
#include <iomanip>

using namespace std;

void fill(int **p, int rowSize, int columnSize);
void print(int **p, int rowSize, int columnSize);

int main()
{
    int **board;
    int rows;
    int columns;

    cout << "Enter the number of rows and columns: ";
    cin >> rows >> columns;
    cout << endl;

    // Create the rows of board
    board = new int *[rows];

    // Create the columns of board
    for (int row = 0; row < rows; row++)
        board[row] = new int[columns];

    // Print addresses of rows and columns
    cout << "Address of board (pointer to rows): " << board << endl;
    for (int row = 0; row < rows; row++)
    {
        cout << "Address of board[" << row << "] (pointer to columns): " << board[row] << endl;
        for (int col = 0; col < columns; col++)
        {
            cout << "Address of board[" << row << "][" << col << "] (element): " << &(board[row][col]) << endl;
        }
    }

    // Insert elements into board
    fill(board, rows, columns);

    cout << "Board:" << endl;

    // Output the elements of board
    print(board, rows, columns);

    // Free allocated memory
    for (int row = 0; row < rows; row++)
        delete[] board[row];
    delete[] board;

    return 0;
}

void fill(int **p, int rowSize, int columnSize)
{
    for (int row = 0; row < rowSize; row++)
    {
        cout << "Enter " << columnSize << " number(s) for row number " << row << ": ";
        for (int col = 0; col < columnSize; col++)
            cin >> p[row][col];
        cout << endl;
    }
}

void print(int **p, int rowSize, int columnSize)
{
    for (int row = 0; row < rowSize; row++)
    {
        for (int col = 0; col < columnSize; col++)
            cout << setw(5) << p[row][col];
        cout << endl;
    }
}
