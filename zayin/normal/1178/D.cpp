#include<bits/stdc++.h>
#define maxn 1000050
using namespace std;

int n;
bool noprime[maxn];

int f[maxn];

vector<pair<int,int> > E;

int main()  {
    for (int i=2;i<maxn;++i)    {
        if (noprime[i]) continue;
        for (int j=i<<1;j<maxn;j+=i)
            noprime[j]=1;
    }
    for (int n=1;n<=5000;++n)   {
        for (f[n]=n;noprime[f[n]];++f[n]);
    }
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        E.emplace_back(i,i%n+1);
    int i=1;
    for (int t=f[n]-n;t;--t)
        E.emplace_back(i,n/2+i),++i;
    cout<<E.size()<<endl;
    for (auto p:E)
        cout<<p.first<<" "<<p.second<<endl;
    return 0;
}