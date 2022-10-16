#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main(){
    cin>>a>>b>>c>>d;
    if(a>b) swap(a, b);
    if(b>c) swap(b, c);
    if(c>d) swap(c, d);
    cout<<d-a<<' '<<d-b<<' '<<d-c<<'\n';
}