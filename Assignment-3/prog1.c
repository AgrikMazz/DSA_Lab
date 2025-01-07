#include <stdio.h>

int isSafe(int n, int board[][n], int row, int col){
    for(int k=0; k<col; k++){
        if(board[row][k] == 1) return 0;
    }
    int i = row, j = col;
    while(i >= 0 && j >= 0){
        if(board[i][j] == 1) return 0;
        i--;
        j--;
    }
    i = row, j = col;
    while(i < n && j >= 0){
        if(board[i][j] == 1) return 0;
        i++;
        j--;
    }
    return 1;
}

int solve(int n, int board[][n], int col){
    if(col == n){
        return 1; 
    }
    
    for(int i=0; i<n; i++){
        if(isSafe(n,board,i,col)){ // Check if queen can be placed
            board[i][col] = 1; // Queen placed
            if(solve(n,board,col+1)) { // Placing queen in next column
                return 1; // Solution found exit
            }
            board[i][col] = 0; // Backtracking to look for other options
        }
    }
    return 0; 
}

void displayBoard(int n, int board[][n]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] == 1){
                printf("Q ");
            }
            else{
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    
    int board[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            board[i][j] = 0;
        }
    }
    
    if (!solve(n,board,0)) {
        printf("No solution exists\n");
    }
    else displayBoard(n, board);
}
