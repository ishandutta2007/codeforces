#include <bits/stdc++.h>
using namespace std;
int n;
long long lesz[100009];
long double ex[100009];
vector<int> Gyer[100009];
void dfs(int x)
{
    for(int gy: Gyer[x])
    {
        dfs(gy);
        lesz[x]+=lesz[gy];
    }
    lesz[x]++;
}
void dfs2(int x)
{
    if(x==1) ex[1]=1;
    for(int gy: Gyer[x])
    {
        ex[gy]=ex[x]+(long double)(lesz[x]-lesz[gy]-1)/2+1.0;
        dfs2(gy);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cout.precision(1);
    cout<<fixed;
    cin>>n;
    for(int i=2; i<=n; i++)
    {
        int a;
        cin>>a;
        Gyer[a].push_back(i);
    }
    dfs(1);
    dfs2(1);
    for(int i=1; i<=n; i++)
    {
        cout<<ex[i]<<" ";
    }
    return 0;
}