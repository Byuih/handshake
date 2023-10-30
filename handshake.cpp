#include "handshake.h"
int main() {
    int n; // Количество людей
    cout << "Введите количество людей: ";
    cin >> n;

    // Ввод матрицы смежности
    vector<vector<int>> adjacencyMatrix(n, vector<int>(n));
    cout << "Введите матрицу смежности (0 - не знакомы, 1 - знакомы):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adjacencyMatrix[i][j];
        }
    }

    findTriadicClosure(adjacencyMatrix);

    return 0;
}