#pragma once

#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9; // Бесконечность

void findTriadicClosure(vector<vector<int>>& adjacencyMatrix) {
    int n = adjacencyMatrix.size();

    // Инициализируем матрицу смежности
    vector<vector<int>> pathMatrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                pathMatrix[i][j] = 0;
            }
            else if (adjacencyMatrix[i][j]) {
                pathMatrix[i][j] = 1;
            }
            else {
                pathMatrix[i][j] = INF;
            }
        }
    }

    // Поиск пар знакомств через три рукопожатия
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (pathMatrix[i][k] + pathMatrix[k][j] < pathMatrix[i][j]) {
                    pathMatrix[i][j] = pathMatrix[i][k] + pathMatrix[k][j];
                }
            }
        }
    }

    // Вывод пар знакомств через три рукопожатия
    cout << "Пары знакомств через три рукопожатия:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (pathMatrix[i][j] <= 3) {
                cout << "(" << i + 1 << ", " << j + 1 << ")" << endl;
            }
        }
    }
}
