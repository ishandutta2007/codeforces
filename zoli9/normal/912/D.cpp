#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
long long n, m, r, k;
long long hanyban(long long x, long long y)
{
    long long felx=max(1ll, x-r+1);
    long long fely=max(1ll, y-r+1);
    long long lex=min(x+r-1, n);
    long long ley=min(y+r-1, m);
    felx+=(r-1);
    fely+=(r-1);
    return (lex-felx+1)*(ley-fely+1);
}
bool palyan(int ax, int ay)
{
    if(ax<1 || ax>n || ay<1 || ay>m) return false;
    return true;
}
long long dx[4];
long long dy[4];
map<pair<long long, long long>, bool> s;
priority_queue<pair<long long, pair<long, long> > > q;
long long ans=0;
int main()
{
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;
    dx[0]=1;
    dy[0]=0;
    dx[1]=-1;
    dy[1]=0;
    dx[2]=0;
    dy[2]=1;
    dx[3]=0;
    dy[3]=-1;
    cin>>n>>m>>r>>k;
    long long mx=(n+1)/2;
    long my=(m+1)/2;
    s[{mx, my}]=true;
    q.push({hanyban(mx, my), {mx, my}});
    int cnt=0;
    while(q.size()>0)
    {
        pair<long long, pair<long, long> > w=q.top();
        q.pop();
        ans+=hanyban(w.S.F, w.S.S);
        cnt++;
        if(cnt==k) break;
        s[w.S]=true;
        for(int u=0; u<4; u++)
        {
            long long ujx=dx[u]+w.S.F;
            long long ujy=dy[u]+w.S.S;
            if(!palyan(ujx, ujy)) continue;
            if(s[{ujx, ujy}]) continue;
            s[{ujx, ujy}]=true;
            q.push({hanyban(ujx, ujy), {ujx, ujy}});
        }
    }
    long long osszes=(n-r+1)*(m-r+1);
    long double valasz=(long double)(ans)/(long double)(osszes);
    cout<<valasz<<endl;
    return 0;
}