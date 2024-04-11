#include <bits/stdc++.h>
using namespace std;
int main(){
    unsigned long long x,t=1,s=45*19;
    cin>>x;
    for (int i=1;i<=19;i++)
        t*=10;
    for (int i=1;i<=18;i++)
        s=s*10%x;
    s=(s+1)%x;
    s=(x-s)%x;
    unsigned long long L=s+1,R=t+s;
    cout<<L<<" "<<R<<endl;
    return 0;
}