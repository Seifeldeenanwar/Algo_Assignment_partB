#include<iostream>
#include<vector>
#include <algorithm>
using namespace std ;


template<typename t>
int sequentialIteration(vector<t> v ,t target){ //O(n)
    int pos = 0 ;
    for(t elem : v){
        if(elem == target){
            return pos ;
        }
        pos++ ;
    }
    return -1 ;
}
template<typename t>
int sequentialRecursive(vector<t> v ,t target){ //O(n) in my implmentation worst case if target value at first
    if(v.back() == target){
        return v.size()-1 ;
    }
    else if(v.empty()){
        return -1 ;
    }
    v.pop_back();
    return sequentialRecursive(v ,target) ; 
}
template<typename t>
int binaryRecursive(vector<t> v , t target , int f , int l ){ //O(logn)
    int mid = (f+l)/2 ;
    if(f > l){
        return -1 ;
    }
    if(target == v[mid]){
        return mid ;
    }
    else if(target > v[mid]){
        return binaryRecursive(v , target , mid+1 ,l) ;
    }
    else{
        return binaryRecursive(v, target , f ,mid-1) ;
    }
}
template<typename t>
int binaryInteration(vector<t> v , t target , int f , int l) {//O(logn)
    while(l >= f){
        int mid = (f+l)/2 ;
        if(target == v[mid]){
            return mid ;
        }
        else if(target > v[mid]){
            f = mid+1 ;
        }
        else {
            l = mid-1 ;
        }
    }
    return -1 ;
}
template<typename t>
bool issorted(vector<t> v){
    for(int i = 1; i < v.size() ; i++){
        if(v[i] < v[i-1]){
            return false ;
        }
    }
    return true ;
}
template<typename t>
void choosemethod(){
    int sz ;
    int flag = 1 ;
    int choice ;
    t target ;
    cout << "enter the size of array -> " ;
    cin >> sz ;
    vector<t> v(sz) ;
    for(int i = 0 ; i < sz ;i++){
        cout << "insert element to array -> " ;
        cin >> v[i] ;
    }
    cout << "\nArray -> " ;
    for(int i = 0 ; i < sz ; i++){
        cout << v[i] << " ";
    }
    cout <<"\n\n";
    while(flag){
    cout << "Choose searching method: \n1-Sequential iteration\n2-Sequential recursive\n3-Binary iteration\n4-Binary recursive\n-> ";
    cin >> choice ;
    cout << "Enter element you want to search -> " ;
    cin >> target ;
    switch (choice)
    {
    case 1:
        cout << sequentialIteration(v,target) << endl ;
        break;
    case 2:
        cout << sequentialRecursive(v,target) << endl; ;
        break;
    case 3:
        if(issorted<t>(v)){
        cout << binaryInteration(v,target,0,v.size()-1) << endl ;
        }
        else{
            cout << "cannot apply binary search array not sorted !\n" << endl;
        }
        break;
    case 4:
        if(issorted<t>(v)){
        cout << binaryRecursive(v,target,0,v.size()-1) << endl ;
        }
        else{
            cout << "cannot apply binary search array not sorted ! \n" << endl;
        }
        break ;         
    default:
        cout << "Invalid choice ! try again" << endl;
        break;
    }
    cout << "if you want exit press 0 -> " ;
    cin >> flag ; 
}
}



int main(){
    choosemethod<int>() ;


    return 0;
}