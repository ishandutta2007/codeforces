#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n;
int t[400009];
int le[400009];
int ri[400009];
int lsmall[200009];
int rsmall[200009];
int m[2000009];
int lazy[2000009];
void modify(int cs, int k, int v, int x, int y, int val)
{
    if(lazy[cs]!=0)
    {
        m[cs]+=lazy[cs];
        if(k!=v)
        {
            lazy[2*cs]+=lazy[cs];
            lazy[2*cs+1]+=lazy[cs];
        }
        lazy[cs]=0;
    }
    if(y<k || v<x) return;
    if(x<=k && v<=y)
    {
        m[cs]+=val;
        if(k!=v)
        {
            lazy[2*cs]+=val;
            lazy[2*cs+1]+=val;
        }
        return;
    }
    modify(2*cs, k, (k+v)/2, x, y, val);
    modify(2*cs+1, (k+v)/2+1, v, x, y, val);
    m[cs]=max(m[2*cs], m[2*cs+1]);
}
int getmax(int cs, int k, int v, int x, int y)
{
    if(lazy[cs]!=0)
    {
        m[cs]+=lazy[cs];
        if(k!=v)
        {
            lazy[2*cs]+=lazy[cs];
            lazy[2*cs+1]+=lazy[cs];
        }
        lazy[cs]=0;
    }
    if(y<k || v<x) return 0;
    if(x<=k && v<=y) return m[cs];
    return max(getmax(2*cs, k, (k+v)/2, x, y), getmax(2*cs+1, (k+v)/2+1, v, x, y));
}
void mod2(int x, int y, int val)
{
    x=(x-1)%n;
    y=(y-1)%n;
    if(x<=y) modify(1, 0, n-1, x, y, val);
    else
    {
        modify(1, 0, n-1, x, n-1, val);
        modify(1, 0, n-1, 0, y, val);
    }
}
void co()
{
    cout<<"Values:"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<getmax(1, 0, n-1, i, i)<<" ";
    }
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
        t[i+n]=t[i];
    }
    le[1]=-1;
    for(int i=2; i<=2*n; i++)
    {
        le[i]=i-1;
        while(le[i]>0 && t[le[i]]>=t[i]) le[i]=le[le[i]];
    }
    ri[n]=-1;
    for(int i=2*n-1; i>=1; i--)
    {
        ri[i]=i+1;
        while(ri[i]>0 && t[ri[i]]>=t[i]) ri[i]=ri[ri[i]];
    }
    lsmall[1]=0;
    for(int i=2; i<=n; i++)
    {
        if(le[i]>0) lsmall[i]=lsmall[le[i]]+1;
        else lsmall[i]=0;
    }
    rsmall[n]=0;
    for(int i=n-1; i>=1; i--)
    {
        if(ri[i]>0 && ri[i]<=n) rsmall[i]=rsmall[ri[i]]+1;
        else rsmall[i]=0;
    }
    for(int i=1; i<=n; i++)
    {
        modify(1, 0, n-1, i-1, i-1, lsmall[i]+rsmall[i]);
    }
    int bestans=getmax(1, 0, n-1, 0, n-1);;
    int bestshift=0;
    //co();
    for(int i=1; i<n; i++)
    {
        if(ri[i]>0 && ri[i]<i+n) mod2(i, ri[i]-1, -1);
        else mod2(i, i+n-1, -1);
        if(le[i+n]>i) mod2(le[i+n]+1, i, 1);
        else mod2(i+1, i+n, 1);
        int currentval=getmax(1, 0, n-1, i-1, i-1);
        if(le[i+n]>i) mod2(i, i, getmax(1, 0, n-1, (le[i+n]-1)%n, (le[i+n]-1)%n)+1-currentval);
        else mod2(i, i, -currentval);
        int mmm=getmax(1, 0, n-1, 0, n-1);
        if(mmm<bestans)
        {
            bestans=mmm;
            bestshift=i;
        }
        //co();
    }
    cout<<bestans+1<<" "<<bestshift<<endl;

    return 0;
}