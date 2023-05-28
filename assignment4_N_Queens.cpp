#include<bits/stdc++.h>
using namespace std;

int n; 

void printsolution(vector<vector<int>> &board)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool isSafe(int row, int col, vector<vector<int>>& board) {
	int duprow = row;
	int dupcol = col;
	while (row >= 0 && col >= 0) {
		if (board[row][col]) {
			return false;
		}
		row--;
		col--;
	}
	row = duprow;
	col = dupcol;
	while (col >= 0) {
		if (board[row][col]) {
			return false;
		}
		col--;
	}
	row = duprow;
	col = dupcol;
	while (row < n && col >= 0) {
		if (board[row][col]) {
			return false;
		}
		row++;
		col--;
	}
	return true;
}

bool solution(int col, vector<vector<int>> &board)
{
    if(col>=n)
    {return true;}
    for (int row=0; row<n; row++)
    {
        if(isSafe(row, col, board))
        {
            // cout<<"hi";
            board[row][col]=1;
            if(solution(col+1, board))
            {
                // cout<<"iind\n";
                return true;
            }
            board[row][col]=0;
        }
    }
    return false;
}

int main()
{
    cout<<"Enter the number of rows and columns in the chess board: ";
    cin>>n;
    vector<vector<int>> board(n+1, vector<int>(n+1, 0));
    if(!solution(0, board))
    {
        cout<<"Solution not possible."<<endl;
    }
    else printsolution(board);
    return 0;
}