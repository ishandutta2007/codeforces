#include <bits/stdc++.h>
using namespace std;
long long f(long long x)
{
    long long ans=0;
    long long tt=2;
    while(tt*tt*tt<=x)
    {
        ans+=x/(tt*tt*tt);
        tt++;
    }
    return ans;
}
long long m;
int main()
{
    cin>>m;
    long long elso=1;
    long long utolso=100000000000000000;
    while(elso<=utolso)
    {
        long long kozep=(elso+utolso)/2;
        if(f(kozep)<m) elso=kozep+1;
        else utolso=kozep-1;
    }
    if(f(elso)==m) cout<<elso<<endl;
    else cout<<-1<<endl;
    return 0;
}