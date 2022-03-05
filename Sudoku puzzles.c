#include <stdio.h>

int count;
typedef enum{true=1,false=0}boolean;

void printBoard(int board[9][9]){
  for(int row=0;row<9; row++)
    {
         if(row%3==0 && row!=0)
         {
        printf("----------------------------\n");
         }
    for(int column=0;column<9;column++)
     {
        if(column%3==0 && column !=0)
          {
            printf("|");
          }
        printf(" %d ",board[row][column]);
     }
    printf("\n");
  }
  printf("============================");
}
boolean isNumberInRow(int board[9][9],int number,int row){
  for(int i=0;i<9;i++)
  {
    if(board[row][i]==number)
    {
        return true;
    }
  }
  return false;
}
boolean isNumberInColumn(int board[9][9],int number,int column){
  for(int i=0;i<9;i++)
  {
    if(board[column][i]==number)
    {
        return true;
    }
  }
  return false;
}
boolean isNumberInBox(int board[9][9],int number,int row,int column){
  int localBoxRow=row-row % 3;
  int localBoxColumn=column-column % 3;

  for(int i=localBoxRow;i<localBoxRow+3;i++){
    for(int j=localBoxColumn;j<localBoxColumn+3;j++){
      if(board[i][j]==number){
        return true;
      }
    }
  }
  return false;
}
boolean isValidPlacement(int board[9][9],int number,int row,int column){
  return !isNumberInRow(board,number,row)&&
         !isNumberInColumn(board,number,column)&&
         !isNumberInBox(board,number,row,column);

}
boolean solveBoard(int board[9][9]){
  for(int row=0;row<9;row++){
    for(int column=0;column<9;column++){
      if(board[row][column]==0){
        for(int numberToTry=1;numberToTry<=9;numberToTry++){
         if(isValidPlacement(board,numberToTry,row,column)){

           board[row][column]=numberToTry;

           if(solveBoard(board)){
             return true;
           }
           else{
             board[row][column]=0;
           }
         }
        }
        return false;
      }
    }
    printBoard(board);
    count++;
    char c;
  }
  return true;
}



void main()
{
   int board[9][9]={
    {5,0,0,6,0,7,0,9,0},
    {1,2,6,0,0,0,0,4,0},
    {0,9,0,0,2,0,6,0,0},
    {6,0,0,0,0,0,0,2,4},
    {9,3,1,0,7,4,0,0,0},
    {0,4,5,8,3,6,0,7,9},
    {3,5,0,7,1,0,0,6,0},
    {0,0,2,0,0,3,8,1,5},
    {0,0,0,0,0,2,4,0,0}
   };

   printBoard(board);

   if(solveBoard(board)){
      printBoard("Solved successfully--%d\n\n",count);
   }
   else{
     printf("Unavaliable board.");
   }

}
