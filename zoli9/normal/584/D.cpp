#include <bits/stdc++.h>
using namespace std;
long long n;
bool osszetett[1000009];
bool prim(long long a)
{
    for(long long i=2; i<=sqrt(a)+1; i++)
    {
        if(a%i==0) return false;
    }
    return true;
}
int main()
{
    cin>>n;
    if(n<=7)
    {
        cout<<1<<endl;
        cout<<n;
        return 0;
    }
    long long p=n-4;
    while(!prim(p))
    {
        p-=2;
    }
    long long m=n-p;
    long long ccnntt=2;
    while(ccnntt<=m+2)
    {
        for(long long u=2*ccnntt; u<=m+3; u+=ccnntt)
        {
            osszetett[u]=true;
        }
        ccnntt++;
        while(ccnntt<=m+1 && osszetett[ccnntt]) ccnntt++;
    }
    for(long long s=2; s<=m-1; s++)
    {
        if(!osszetett[s] && !osszetett[m-s])
        {
            cout<<3;
            cout<<endl;
            cout<<p<<" "<<s<<" "<<m-s;
            return 0;
        }
    }
    cout<<1<<endl;
    cout<<n;
    return 0;
}