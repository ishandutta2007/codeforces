#include <iostream>

using namespace std;

int main()
{
    int x,y,z,a,b,c; cin>>x>>y>>z>>a>>b>>c;
    if(a<x){cout << "NO"; return 0;}
    a -= x;
    if(a+b<y){cout << "NO"; return 0;}
    if(a+b+c-y<z){cout << "NO"; return 0;}
    cout << "YES"; return 0;
}