#include <stdio.h>

typedef struct{
    char name[20];
    char symbol;
} player;

typedef struct {
    char board[3][3];
} board;

int check_winner(board b){
    for (int i = 0; i<3; i++){
        if(b.board[i][0] != ' ' && b.board[i][0] == b.board[i][1] && b.board[i][1] == b.board[i][2]){
            return b.board[i][0];
        }
    }
    for(int j= 0; j <3; j++){   
        if(b.board[0][j] != ' ' && b.board[0][j] == b.board[1][j] && b.board[1][j] == b.board[2][j]){
        return b.board[0][j];
        }
    }
        if(b.board[0][0] != ' ' && b.board[0][0] == b.board [1][1] && b.board[1][1] == b.board[2][2]){
            return b.board[0][0];
        }
        if(b.board[0][2] != ' ' && b.board[0][2] == b.board [1][1] && b.board[1][1] == b.board[2][0]){
            return b.board [0][2];
        }
        return ' ';
    
    }
void print_board(board b){
    printf("\n");
    for(int i = 0 ; i<3; i++){
        printf(" %c %c %c \n", b.board[i][0], b.board[i][1], b.board[i][1]);
        if(i<2) printf("---|---|---\n");
    }
}

int main(){
    board board;
    for (int i = 0; i<3; i++){
        for(int j= 0; j <3; j++){
            board.board[i][j] = ' ';
        }
    }

    player alice = {"alice", 'X'};
    player bob = {"bob", 'O'};

    int t;
    char current_player;
    int row;
    int col;
    scanf("%d", &t);

    for(int i = 0; i <t; i++){
        scanf(" %c %d %d", &current_player, &row, &col);
        if(current_player == 'A'){
            board.board[row][col] = alice.symbol;
        } else {
            board.board[row][col] = bob.symbol;
        }
        print_board(board);
        char winner = check_winner(board);
        if (winner == 'X'){
            printf("Alice wins\n");
            break;
        } else if (winner == 'O'){
            printf("Bob wins \n");
            break;
        }
        
    }
    char winner = check_winner(board);
    if(winner==' '){
        printf("winner none \n");
    }

}
