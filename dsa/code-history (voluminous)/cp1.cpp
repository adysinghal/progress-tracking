#include <iostream>
#include <vector>

using namespace std;

void traverseSubmatrices(const vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = i; k < n; ++k) {
                for (int l = j; l < m; ++l) {
                    // Check if the submatrix contains the element at i = 0, j = 0
                    if (i == 0 && j == 0) {
                        // Now, grid[i][j] is the top-left corner,
                        // and grid[k][l] is the bottom-right corner of the submatrix
                        for (int row = i; row <= k; ++row) {
                            for (int col = j; col <= l; ++col) {
                                // Access the elements of the submatrix: grid[row][col]
                                cout << grid[row][col] << " ";
                            }
                            cout << endl;
                        }
                        cout << "----" << endl;
                    }
                }
            }
        }
    }
}

int main() {
    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    traverseSubmatrices(grid);

    return 0;
}
