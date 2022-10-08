#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

// sudoku solver in C

int main(void)
{
    int board[9][9]= {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // allocate metadata trackers
        // one function to create arr of linked list of size 9
        // init in same function
        // allocate an array of size 9 of node stars

    // tracks the size of lls in trackers arrays
    int row_size[9] = {9, 9, 9, 9, 9, 9, 9, 9, 9};
    int col_size[9] = {9, 9, 9, 9, 9, 9, 9, 9, 9};
    int sqr_size[9] = {9, 9, 9, 9, 9, 9, 9, 9, 9};

    // initialize trackers
    struct node* row_tracker;
    init_tracker(&row_tracker);
    
    // call to solve positions
    solve_puzzle(board);

    // deallocate memory
        // kill lists
        // free arrays

    return 0;
}

// update which numbers are avail for the row, col, or sqr
// int row_update(int** ptr, board[][])
// {
//     for(int i = 0; i > 9; i++)
//     {
//         for(int j = 0; j > 9; j++)
//         {
//             number = board[i][j];
//             if (number != 0)
//             {
//                 if(search(ptr[i], number))
//                 {
//                     // shrink
//                 }
//             }
//         }
//         // check for number at board[j][i]
//         // zero indicates empty space 
//         // if number is in avail row ll, remove it        
//     }

//     return 0;
// }

// initializes tracking lists with available numbers 
void init_tracker(struct node** tracker)
{
    int* arr = *tracker;
    // initialize array of linked list heads
    for (int i = 0; i <= 8; i++)
    {
        if (((arr) = (int*)malloc(sizeof(int*) * 9)) == 0)
        {
            printf("failed to allocate memory\n");
            exit(0);
        }

        for (int j = 0; j < 8; j++)
        {
            tracker[i][j] = create(1);
            for (int k = 1; k <= 8; k++)
            {
                insert(tracker[i][j], k + 1);
            }
        }
    }
}

// check to see if position x, y can be solved
// int solve_position(int row, int col, )
// {
//     // initialize a list of avail numbers (cross reference)
//     // if size == 1 number found
//     // other win conditions here
//     return 0;
// }

// does pointer to 2d array even compile
int solve_puzzle(int *board[][])
{
    // for each position 
    //      call solve position (skip if position is non-zero)
    //      count number of solved positions
    //      if number of solved positions != 81
    //      then recurse

    return 0;
}