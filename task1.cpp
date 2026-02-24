#include <iostream>
using namespace std;

namespace MatrixNS {
    void readMatrix(int** matrix, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
    }
    int** transposeMatrix(int** matrix, int n, int m) {
        int** transposedMatrix = new int*[m];
        for (int i = 0; i < m; i++) {
            transposedMatrix[i] = new int[n];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                transposedMatrix[i][j] = matrix[j][i];
            }
        }
        return transposedMatrix;
    }
    void swapRows(int r1, int r2, int** matrix, int m) {
        for (int i = 0; i < m; i++) {
            int temp = matrix[r1][i];
            matrix[r1][i] = matrix[r2][i];
            matrix[r2][i] = temp;
        }
    }
    void printMatrix(int** matrix, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
}
int main() {
    using namespace MatrixNS;
    int n, m;
    cin >> n >> m;
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }
    readMatrix(matrix, n, m);
    printMatrix(matrix, n, m);
    cout << endl;
    swapRows(0, 1, matrix, m);
    printMatrix(matrix, n, m);
    cout << endl;
    int** transposedMatrix = transposeMatrix(matrix, n, m);
    printMatrix(transposedMatrix, m, n);
    cout << endl;
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    for (int i = 0; i < m; i++) {
        delete[] transposedMatrix[i];
    }
    delete[] matrix;
    delete[] transposedMatrix;
}
