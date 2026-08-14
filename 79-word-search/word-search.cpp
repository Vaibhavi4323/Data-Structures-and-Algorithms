class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word,
             int row, int col, int index) {

        // All characters have been found
        if (index == word.size()) {
            return true;
        }

        // Check boundaries and character
        if (row < 0 || row >= board.size() ||
            col < 0 || col >= board[0].size() ||
            board[row][col] != word[index]) {
            return false;
        }

        // Mark the current cell as visited
        char temp = board[row][col];
        board[row][col] = '#';

        // Explore all four directions
        bool found =
            dfs(board, word, row + 1, col, index + 1) ||
            dfs(board, word, row - 1, col, index + 1) ||
            dfs(board, word, row, col + 1, index + 1) ||
            dfs(board, word, row, col - 1, index + 1);

        // Restore the cell
        board[row][col] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {

                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};