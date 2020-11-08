class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessboard(n, string(n, '.'));
        dfs(chessboard, n, 0, 0, 0, 0);
        vector<string> nQueens(n, string(n, '.'));
        return res;
    }


    void dfs(vector<string>& chessboard, int n, int row, int col, int ld, int rd) {
        if (row >= n) {
            res.push_back(chessboard);
            return;
        }
        int bits = ((1 << n) - 1) & (~ (col | ld | rd));
        while (bits != 0) {
            int bit = bits & (-bits);
            bits &= (bits - 1);
            chessboard[row][log2(bit)] = 'Q';
            dfs(chessboard, n, row + 1, col | bit, (ld | bit) << 1, (rd | bit) >> 1);
            chessboard[row][log2(bit)] = '.';     
        }
    }
       
private:
    vector<vector<string>> res;
};//位运算

class Solution {
public:
    std::vector<std::vector<std::string> > solveNQueens(int n) {
        std::vector<std::vector<std::string> > res;
        std::vector<std::string> nQueens(n, std::string(n, '.'));
        std::vector<int> flag_col(n, 1), flag_45(2 * n - 1, 1), flag_135(2 * n - 1, 1);
        solveNQueens(res, nQueens, flag_col, flag_45, flag_135, 0, n);
        return res;
    }
private:
    void solveNQueens(std::vector<std::vector<std::string> > &res, std::vector<std::string> &nQueens, std::vector<int> &flag_col, std::vector<int> &flag_45, std::vector<int> &flag_135, int row, int &n) {
        if (row == n) {
            res.push_back(nQueens);
            return;
        }
        for (int col = 0; col != n; ++col)
            if (flag_col[col] && flag_45[row + col] && flag_135[n - 1 + col - row]) {
                flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 0;
                nQueens[row][col] = 'Q';
                solveNQueens(res, nQueens, flag_col, flag_45, flag_135, row + 1, n);
                nQueens[row][col] = '.';
                flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 1;
            }
    }
}; //数组

class Solution {
private:
void backtracking(int n, int row, vector<string>& chessboard, vector<vector<string>>& res) {
    if (row == n) {
        res.push_back(chessboard);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isValid(row, col, chessboard, n)) {
            chessboard[row][col] = 'Q';
            backtracking(n, row + 1, chessboard, res);
            chessboard[row][col] = '.';
        }
    }
}

bool isValid(int row, int col, vector<string>& chessboard, int n) {
    int count = 0;

    for (int i = 0; i < row; ++i) {
        if (chessboard[i][col] == 'Q') 
          return false;
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (chessboard[i][j] == 'Q')
          return false;
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (chessboard[i][j] == 'Q')
          return false;
    }

    return true;
}

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessboard(n, string(n, '.'));
        vector<vector<string>> res;
       
        
        backtracking(n, 0, chessboard, res);
        return res;
    }
}; //回溯



