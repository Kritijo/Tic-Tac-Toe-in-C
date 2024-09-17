//Tic tac toe
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

char board[3][3];
const char PLAYER = 'X';    //Global constant variables
const char COMPUTER = 'O';

//funcation prototypes
void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

int main(){
    char winner = ' ';
    char response;

    do {
        winner = ' ';
        response = ' ';
        resetBoard();

        while(winner == ' ' && checkFreeSpaces() != 0){
            printBoard();
            playerMove();
            winner = checkWinner();
            if (winner != ' ' || checkFreeSpaces()==0){
                break;
            }
            computerMove();
            winner = checkWinner();
            if (winner != ' ' || checkFreeSpaces()==0){
                break;
            }  
        }
        printBoard();
        printf("\n");
        printWinner(winner);
        printf("********************\n");
        
        printf("\nWould you like to play again (Y/N): ");
        scanf(" %c",&response);
        response = toupper(response);
    } while(response == 'Y');

    printf("\nThanks for playing!\n\n");
    return 0;  
} 

void resetBoard(){
    for (int i=0; i<3; i++){
        for(int j =0; j<3; j++){ 
            board[i][j] = ' ';
        }
    }
}
void printBoard(){
    printf(" %c | %c | %c ",board[0][0],board[0][1],board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ",board[1][0],board[1][1],board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c \n",board[2][0],board[2][1],board[2][2]);
}

int checkFreeSpaces(){
    int freeSpaces = 9;
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(board[i][j] != ' '){
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}

void playerMove(){
    int x; 
    int y;
    do{
        printf("Enter the row #(1-3): ");
        scanf("%d",&x);
        x--;
        printf("Enter the column #(1-3): ");
        scanf("%d",&y);
        y--;
        if(board[x][y]!=' '){
            printf("Invalid Move\n");
        }
        else{
            board[x][y] = PLAYER;
            break;
        }
    }while(board[x][y]!=' ');

}
void computerMove(){
    int x;
    int y;
    srand(time(0));
    
    if(checkFreeSpaces()>0){
        do{
            x = rand()%3;
            y = rand()%3;
        }while(board[x][y]!=' ');
        board[x][y] = COMPUTER;
    }
    else{
        printWinner(' ');
    }
}

char checkWinner(){
    //for rows
    for(int i=0; i<3; i++){
        if(board[i][0]==board[i][1] && board[i][0]==board[i][2]){
            return board[i][0];
        }
    }
    //for cols 
    for(int i=0; i<3; i++){
        if(board[0][i]==board[1][i] && board[0][i]==board[2][i]){
            return board[0][i];
        }
    }
    //for diagonal 1
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2]){
        return board[0][0];
    }
    //for diagonal 2
    if(board[2][0] == board[1][1] && board[2][0] == board[0][2]){
        return board[2][0];
    }
    return ' ';
}

void printWinner(char winner){
    if (winner == PLAYER){
        printf("YOU WIN! :D\n");
    }
    else if(winner == COMPUTER){
        printf("YOU LOSE :P\n");
    }
    else{
        printf("IT'S A TIE :< \n");
    }
}
