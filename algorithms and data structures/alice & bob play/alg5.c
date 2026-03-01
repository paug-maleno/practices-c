#include<stdio.h>

typedef struct{
    char name[20];
    int row;
    int col;
    int alive;
} player;

typedef struct{
    char board[5][5];
} board;

int main(){
    
    int t, ar, ac, br,bc;
    scanf("%d %d %d %d %d\n",&t, &ar,&ac, &br, &bc);
    printf("t=%d ar=%d ac=%d br=%d bc=%d\n", t, ar, ac, br, bc);
    player alice = {"alice", ar, ac, 1};
    player bob = {"bob", br, bc, 1};
    

    board alice_board;
    board bob_board;
    for(int i = 0; i<5; i++){
        for(int j=0 ; j < 5; j++){
            alice_board.board[i][j] = '-';
            bob_board.board [i][j] = '-';
        }
    }
    alice_board.board[ar][ac] = 'S';
    bob_board.board[br][bc] = 'S';

    char current_player;
    int row;
    int col;
    for(int i=0; i<t; i++){
        scanf("%c %d %d", &current_player, &row, &col);
        printf("player=%c row=%d col=%d\n", current_player, row, col);
        if(current_player == 'A'){
            if (bob_board.board[row][col] == 'S'){
                bob.alive = 0;
                break;
            }else{
                bob_board.board[row][col] = 'X';
            }

        }else{
            if(alice_board.board[row][col] == 'S'){
                alice.alive = 0;
                break;
            }else{
                alice_board.board[row][col] ='X';
            }
        }
    }
    if(bob.alive == 0){
        printf("Alice wins \n");
    } else if(alice.alive == 0){
        printf("bob wins \n");
    }else{
        printf("none \n");
    }
    return 0;
}
