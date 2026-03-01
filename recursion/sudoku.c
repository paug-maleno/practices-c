#include <stdio.h>

typedef struct{
    int s[9][9]
} sudoku;

int is_valid (sudoku*s, int row, int col, int num){
    for(int j=0; j<9; j++){ //check rows
        if(s->s[row][j] == num) return 0;
    }
    for(int i=0; i<9; i++){ //check cols
        if(s->s[i][col] == num) return 0;
    }

    int block_row = (row / 3)*3;
    int block_col = (col/ 3)*3;
    for(int i=block_row; i<block_row+3; i++){
        for(int j=block_col; j<block_col+3; j++){
            if(s -> s[i][j] == num) return 0;
        }
    }
    return 1;
}

int sudoku_solver(sudoku*s, int x, int y){ 
    if (x==9) return 1;
    if (y == 9) return sudoku_solver(s, x+1, 0);
    if(s->s[x][y] != 0) return sudoku_solver(s , x, y+1);
    for(int num=1; num<=9; num++){
        if(is_valid(s, x, y, num)){
            s->s[x][y] = num;       
            if(sudoku_solver(s, x, y+1)) return 1; 
            s->s[x][y] = 0;          
        }
    }
    return 0;  
}