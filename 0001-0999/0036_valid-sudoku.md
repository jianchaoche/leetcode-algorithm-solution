[36.valid-sudoku](https://leetcode.com/problems/valid-sudoku/)  

Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated **according to the following rules**:

1.  Each row must contain the digits `1-9` without repetition.
2.  Each column must contain the digits `1-9` without repetition.
3.  Each of the 9 `3x3` sub-boxes of the grid must contain the digits `1-9` without repetition.

![](https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)  
A partially filled sudoku which is valid.

The Sudoku board could be partially filled, where empty cells are filled with the character `'.'`.

**Example 1:**

**Input:**
\[
  \["5","3",".",".","7",".",".",".","."\],
  \["6",".",".","1","9","5",".",".","."\],
  \[".","9","8",".",".",".",".","6","."\],
  \["8",".",".",".","6",".",".",".","3"\],
  \["4",".",".","8",".","3",".",".","1"\],
  \["7",".",".",".","2",".",".",".","6"\],
  \[".","6",".",".",".",".","2","8","."\],
  \[".",".",".","4","1","9",".",".","5"\],
  \[".",".",".",".","8",".",".","7","9"\]
\]
**Output:** true

**Example 2:**

**Input:**
\[
  \["8","3",".",".","7",".",".",".","."\],
  \["6",".",".","1","9","5",".",".","."\],
  \[".","9","8",".",".",".",".","6","."\],
  \["8",".",".",".","6",".",".",".","3"\],
  \["4",".",".","8",".","3",".",".","1"\],
  \["7",".",".",".","2",".",".",".","6"\],
  \[".","6",".",".",".",".","2","8","."\],
  \[".",".",".","4","1","9",".",".","5"\],
  \[".",".",".",".","8",".",".","7","9"\]
\]
**Output:** false
**Explanation:** Same as Example 1, except with the **5** in the top left corner being 
    modified to **8**. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

**Note:**

*   A Sudoku board (partially filled) could be valid but is not necessarily solvable.
*   Only the filled cells need to be validated according to the mentioned rules.
*   The given board contain only digits `1-9` and the character `'.'`.
*   The given board size is always `9x9`.  



**Solution:**  

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int h[9];
        int row = board.size();
        int col = board[0].size();
        for( vector<vector<char> >::iterator iter=board.begin(); iter!=board.end(); ++iter)
        {
            memset( h, 0, sizeof(int)*9 );
            for( vector<char>::iterator ic = (*iter).begin(); ic!=(*iter).end(); ++ic )
            {
                char c = *ic;
                if( c == '.' ) continue;
                if( (h[c-'1']++)>=1)return false;
            }
        }
        for( int i = 0; i<col; i++)
        {
            memset( h, 0, sizeof(int)*9 );
            for( int j = 0; j<row;j++)
            {
                char c = board[j][i];
                if( c == '.' )continue;
                if( (h[c-'1']++)>=1)return false;
            }
        }
        for( int i=0; i<3; i++)
        {
           
            for( int j=0;j<3;j++)
            {
                 memset( h, 0, sizeof(int)*9 );
                for( int k=0; k<9;k++)
                {
                    char c = board[i*3+k/3][j*3+k%3];
                    if( c == '.')continue;
                    if( (h[c-'1']++)>=1)return false;
                }
            }
        }
        return true;
    }
}; 
```
      