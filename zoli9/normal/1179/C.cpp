#include <bits/stdc++.h>
using namespace std;
int n, m, qq;
int msum[10000009];
int lpref[10000009];
int t[1000009];
int maxn=1000001;
int A[300009];
int B[300009];
void initst(int cs, int k, int v)
{
    if(k==v)
    {
        msum[cs]=t[k];
        lpref[cs]=min(t[k], 0);
        return;
    }
    initst(2*cs, k, (k+v)/2);
    initst(2*cs+1, (k+v)/2+1, v);
    msum[cs]=msum[2*cs]+msum[2*cs+1];
    lpref[cs]=min(lpref[2*cs+1], msum[2*cs+1]+lpref[2*cs]);
}
void modify(int cs, int k, int v, int x, long long df)
{
    if(x<k || v<x) return;
    if(k==v)
    {
        msum[cs]+=df;
        lpref[cs]=min(msum[cs], 0);
        return;
    }
    modify(2*cs, k, (k+v)/2, x, df);
    modify(2*cs+1, (k+v)/2+1, v, x, df);
    msum[cs]=msum[2*cs]+msum[2*cs+1];
    lpref[cs]=min(lpref[2*cs+1], msum[2*cs+1]+lpref[2*cs]);
}
int ans(int cs, int k, int v, int crit)
{
    if(k==v) return k;
    if(lpref[2*cs+1]<crit) return ans(2*cs+1, (k+v)/2+1, v, crit);
    crit-=msum[2*cs+1];
    return ans(2*cs, k, (k+v)/2, crit);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>A[i];
        t[A[i]]--;
    }
    for(int i=1; i<=m; i++)
    {
        cin>>B[i];
        t[B[i]]++;
    }
    initst(1, 0, maxn-1);
    cin>>qq;
    for(int u=1; u<=qq; u++)
    {
        int tp;
        int ind;
        int newval;
        cin>>tp>>ind>>newval;
        if(tp==1)
        {
            modify(1, 0, maxn-1, A[ind], 1);
            A[ind]=newval;
            modify(1, 0, maxn-1, A[ind], -1);
        }
        else
        {
            modify(1, 0, maxn-1, B[ind], -1);
            B[ind]=newval;
            modify(1, 0, maxn-1, B[ind], 1);
        }
        int answer=ans(1, 0, maxn-1, 0);
        if(answer==0) cout<<-1<<endl;
        else cout<<answer<<endl;
    }

    return 0;
}