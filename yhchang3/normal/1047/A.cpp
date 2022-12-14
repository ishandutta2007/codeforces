#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a = 1, b = 1, c = n - 2;
    if((n-2)%3==0){
        c--;
        b++;
    }
    cout<<a<<' '<<b<<' '<<c<<endl;
}