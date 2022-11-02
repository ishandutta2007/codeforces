#include <bits/stdc++.h>
using namespace std;
long long n;
long long t[100009];
long long hanyadik[100009];
bool parjo[100009];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
        hanyadik[t[i]]=i;
    }
    for(int i=1; i<=n-1; i++)
    {
        if(hanyadik[i]<hanyadik[i+1]) parjo[i]=true;
        else parjo[i]=false;
    }
    long long legh=0;
    long long akt=0;
    for(int i=1; i<=n-1; i++)
    {
        if(parjo[i]) akt++;
        else
        {
            legh=max(legh, akt);
            akt=0;
        }
    }
    legh=max(legh, akt);
    cout<<n-(legh+1);
    return 0;
}