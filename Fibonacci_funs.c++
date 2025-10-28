#include <iostream>
#include <vector>
using namespace std;

int Fab(int n){
    if(n <= 1)
        return n;
    return Fab(n - 1) + Fab(n - 2);
}

int DFab(int n){
    long long int arr[n];
    arr[0] = 1;
    arr[1] = 1;
    for(int i = 2; i < n ; i++){
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n - 1];
}

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
void Run(){
    cout << "=========================================\n";
    cout << "Choose method to compute Fibonacci number\n";
    cout << "1. Recursive -> O(2^n)\n";
    cout << "2. Dynamic Programming -> O(n)\n";
    cout << "3. Matrix Exponentiation -> O(log n)\n";
    cout << "Enter choice (1/2/3): ";
    int choice;
    cin >> choice;

    cout << "\nEnter the value of n: ";
    int n;
    cin >> n;

    int ans;
    switch (choice)
    {
    case 1:
        ans = Fab(n);
        break;
    case 2:
        ans = DFab(n);
        break;
    case 3:
        ans = MFab(n);
        break;
    default:
        break;
    }
    cout << "Fibonacci number F(" << n << ") = " << ans << endl;
    cout << "\n1. Run again\n";
    cout << "2. Exit\n";
    cout << "Enter choice (1/2): ";
    int next;
    cin >> next;
    if(next == 1){
        cout << "\n";
        Run();
    }
}
int main(){
    Run();
    return 0;
}