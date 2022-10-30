#include <bits/stdc++.h>
using namespace std;
long long n;
vector<int> G[300009];
bool bejar[300009];
long long apa[300009];
long long gy[300009];
int A, B;
void dfs(int x)
{
    bejar[x]=true;
    for(int sz: G[x])
    {
        if(!bejar[sz])
        {
            apa[sz]=x;
            dfs(sz);
            gy[x]+=gy[sz];
        }
    }
    gy[x]++;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>A>>B;
    for(int i=1; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(A);
    int mm=B;
    while(apa[mm]!=A)
    {
        mm=apa[mm];
    }
    long long gyb=gy[mm];
    long long gya=n-gyb;
    long long ossz=n*(n-1);
    long long rossz=gya*gy[B];
    ossz-=rossz;
    cout<<ossz<<endl;
    return 0;
}