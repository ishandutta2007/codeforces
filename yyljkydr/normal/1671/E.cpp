#include<bits/stdc++.h>
using namespace std;

const int N=2e6+1e3+7,P=998244353;

int n;

char s[N];

int ans=1;

string dfs(int x,int d)
{
    if(d==n-1)
    {
        string r;
        r+=s[x];
        return r;
    }
    int ls=x<<1,rs=x<<1|1;
    string L=dfs(ls,d+1),R=dfs(rs,d+1);
    if(L>R)
        swap(L,R);
    if(L!=R)
        ans=ans*2%P;
    string r;r+=s[x];
    return r+L+R;
}

int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    dfs(1,0);
    printf("%d\n",ans);
}