#include <bits/stdc++.h>
using namespace std;

void cofact(vector<vector<int>>& mat, vector<vector<int>>& temp, int p, int q, int n) {
    int i = 0, j = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = mat[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int det(vector<vector<int>>& mat, int n) {
    if (n == 1) {
        return mat[0][0];
    }

    int dete = 0;
    vector<vector<int>> temp(n, vector<int>(n));
    int sign = 1;

    for (int f = 0; f < n; f++) {
        cofact(mat, temp, 0, f, n);
        dete += sign * mat[0][f] * det(temp, n - 1);
        sign = -sign;
    }

    return dete;
}

int main() {
    int n;
    cout << "Enter the size of the matrix : ";
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));
    cout << "Enter the elements of the matrix :" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    cout << "The entered matrix is:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    int dete = det(mat, n);
    cout << "Determinant of the matrix is: " << dete << endl;

    return 0;
}
