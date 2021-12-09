#include<iostream>
#include<vector>

using std::vector;
using std::string;

class Solution
{
private:
    bool isEnd(vector<string>& board, char c)
    {
        if((board[0][0]==c&&board[1][1]==c&&board[2][2]==c)||(board[0][2]==c&&board[1][1]==c&&board[2][0]==c))
            return true;
        for(int i=0; i<3; i++)
        {
            if((board[i][0]==c&&board[i][1]==c&&board[i][2]==c)||(board[0][i]==c&&board[1][i]==c&&board[2][i]==c))
                return true;
        }
        return false;
    }
public:
    bool validTicTacToe(vector<string> &board)
    {
        int x=0, o=0;
        for(string s:board)
        {
            for(char c:s)
            {
                if(c=='X')
                    x++;
                else if(c=='O')
                    o++;
            }
        }
        bool isEnd_x = isEnd(board, 'X'), isEnd_o = isEnd(board, 'O');
        if(!isEnd_o&&isEnd_x&&x-o==1)
            return true;
        else if(!isEnd_x&&isEnd_o&&x==o)
            return true;
        else if(!isEnd_o&&!isEnd_x&&(x-o)<=1&&(x-o)>=0)
            return true;
        else 
            return false;

    }
};