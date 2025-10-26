#include <iostream>
using namespace std;

int DFab(int n){
    long long int arr[n];
    arr[0] = 1;
    arr[1] = 1;
    for(int i = 2; i < n ; i++){
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n - 1];
}

int main(){
    int n;
    cin >> n;
    cout << DFab(n) << endl;
    return 0;
}