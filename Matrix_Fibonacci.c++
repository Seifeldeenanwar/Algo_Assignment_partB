#include <iostream>
#include <vector>
using namespace std;

// Function to multiply two 2x2 matrices
void multiply(vector<vector<int>>& MA, vector<vector<int>>& MB) {
    int x = MA[0][0] * MB[0][0] + MA[0][1] * MB[1][0];
    int y = MA[0][0] * MB[0][1] + MA[0][1] * MB[1][1];
    int z = MA[1][0] * MB[0][0] + MA[1][1] * MB[1][0];
    int w = MA[1][0] * MB[0][1] + MA[1][1] * MB[1][1];

    MA[0][0] = x;
    MA[0][1] = y;
    MA[1][0] = z;
    MA[1][1] = w;
}

void matrixPower(vector<vector<int>>& MA, int n) {
    if (n == 0 || n == 1) 
        return;

    vector<vector<int>> MB = {{1, 1}, {1, 0}};
    matrixPower(MA, n / 2);
    multiply(MA, MA);

    if (n % 2 != 0) {
        multiply(MA, MB);
    }
}

int MFab(int n) {
    if (n <= 1) 
        return n;

    vector<vector<int>> MA = {{1, 1}, {1, 0}};
    matrixPower(MA, n - 1);
    return MA[0][0];
}

int main(){
    int n;
    cin >> n;
    cout << MFab(n) << endl;
    return 0;
}