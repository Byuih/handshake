#include "handshake.h"
int main() {
    int n; // ���������� �����
    cout << "������� ���������� �����: ";
    cin >> n;

    // ���� ������� ���������
    vector<vector<int>> adjacencyMatrix(n, vector<int>(n));
    cout << "������� ������� ��������� (0 - �� �������, 1 - �������):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adjacencyMatrix[i][j];
        }
    }

    findTriadicClosure(adjacencyMatrix);

    return 0;
}