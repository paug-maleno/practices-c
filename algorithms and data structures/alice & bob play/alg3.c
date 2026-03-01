#include <stdio.h>

typedef struct{
    char name[10];
    int left;
    int right; 
} player;
int main(){
    player alice = {"alice", 1, 1};
    player bob = {"bob", 1, 1};

    int t;
    char main_player, main_hand, adversary_hand;
    scanf("%d", &t);

    for(int i=0; i<t; i++){
        scanf(" %c %c %c", &main_player, &main_hand, &adversary_hand);
    
        if(main_player == 'A'){
            if(main_hand == 'L' && alice.left != -1){
                if(adversary_hand == 'L' && bob.left != -1){
                    bob.left += alice.left;
                } else if(adversary_hand == 'R' && bob.right != -1){
                    bob.right += alice.left;
                }
            } else if(main_hand == 'R' && alice.right != -1){
                if(adversary_hand == 'L' && bob.left != -1){
                    bob.left += alice.right;
                } else if(adversary_hand == 'R' && bob.right != -1){
                    bob.right += alice.right;
                }
            } else {
            if(main_hand == 'L' && bob.left != -1){
                if(adversary_hand == 'L' && alice.left != -1){
                    alice.left += bob.left;
                } else if(adversary_hand == 'R' && alice.right != -1){
                    alice.right += bob.left;
                }
            } else if(main_hand == 'R' && bob.right != -1){
                if(adversary_hand == 'L' && alice.left != -1){
                    alice.left += bob.right;
                } else if(adversary_hand == 'R' && alice.right != -1){
                    alice.right += bob.right;
                }
            }
        }
    
  


        }
        if(bob.left == 5) bob.left = -1;
        if(bob.right == 5) bob.right = -1;
        if(alice.left == 5) alice.left = -1;
        if(alice.right == 5) alice.right = -1;

        if (bob.left >= 5) bob.left -=5;
        if (bob.right >= 5) bob.right -=5;
        if (alice.left >= 5) alice.left -=5;
        if (alice.right >= 5) alice.right -=5;
       
        printf("Alice L:%d R:%d | Bob L:%d R:%d\n", alice.left, alice.right, bob.left, bob.right);


    }
    if(alice.left <= 0 && alice.right <= 0){
            printf("bob wins");
        } else if (bob.left <= 0 && bob.right <= 0){
            printf("alice wins");
        }else{
            printf("none");
        }
    return 0;
}
    