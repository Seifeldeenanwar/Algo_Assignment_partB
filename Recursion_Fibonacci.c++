#include <iostream>
using namespace std;

int Fab(int n){
    if(n <= 1)
        return n;
    return Fab(n - 1) + Fab(n - 2);
}

int main(){
    int n;
    cin >> n;
    cout << Fab(n) << endl;
    return 0;
}