#include <iostream>
using namespace std;
int main(){
    int a, b, c;
    cin>>a>>b>>c;
    b/=2; c/=4;
    cout<<min(min(a, b), c)*7;
}