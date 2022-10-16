#include <iostream>
using namespace std;
unsigned long long a, b, c;
int main(){
    cin>>a>>b>>c;
    unsigned long long x=b, y=c, z=a;
    if(a<x||a==x&&b<=y){
        a=x;
        b=y;
        c=z;
    }
    unsigned long long t=x;
    x=y;
    y=z;
    z=t;
    if(a<x||a==x&&b<=y){
        a=x;
        b=y;
        c=z;
    }
    unsigned long long d=a-1;
    if(d>=c>=0&&d>=b)
        cout<<d-b+d-c;
    else if(d>=c){
        cout<<a-b+d-c;
    }
    else cout<<a-b+a-c;
}