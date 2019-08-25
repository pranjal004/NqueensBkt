#include<iostream>
#include<math.h>
#include<conio.h>

using namespace std;
bool isSafe(int board[][10], int i, int j, int n)
{
  // for col
  for(int row=0; row<i; row++)
  {
    if(board[row][j]==1)
    {
      return false;
    }
  }
    // for left diagonal
    int x= i;
    int y= j;
    while(x>=0 && y>=0)
    {
      if(board[x][y]==1)
      {
        return false;
      }
      x--;
      y--;
    }
    // for right diagonal
    x= i;
    y= j;
    while(x>=0 && y<n)
    {
      if(board[x][y]==1)
      {
        return false;
      }
      x--;
      y++;
    }

    //no attack position found then
    return true;

}
bool solveNQueen(int board[][10], int i, int n)
{
  // base case
   if(i==n)
   {
     //print board
     for(int i=0; i<n; i++)
     {
       for(int j=0 ; j<n; j++)
       {
         if(board[i][j]== 1)
         {
         cout<<"Q ";
         }
         else
         {
           cout<<"_ ";
         }

       }
       cout<<endl;
     }
     cout<<endl<<"********"<<endl;
     return false;
   }

   for(int j=0; j<n; j++)
   {
     // if position is safe
    if(isSafe(board, i, j, n))
       //assume i, J is right position
      {
        board[i][j] = 1;

        bool nextQueenrow= solveNQueen(board, i+1, n);
        if(nextQueenrow)
        {
        return true;
        }
        //if not right position
        board[i][j]=0; //Backtrack
      }
    }
  //all positions done in the current row
  return false;

}

int main()
{
   int n;
   cin>>n;
   int board[10][10]= {0};
   solveNQueen(board, 0, n);
   return 0;
}
