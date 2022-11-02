#include <bits/stdc++.h>
using namespace std;
int n, m;
struct el
{
    int k, v;
    long long suly;
};
el elek[1000009];
int apa[200009];
int mag[200009];
int rendez(const void *a, const void *b)
{
    return (*(el*)a).suly-(*(el*)b).suly;
}
void unio(int x, int y)
{
    if(mag[x]<mag[y]) apa[x]=y;
    else if(mag[x]>mag[y]) apa[y]=x;
    else
    {
        mag[x]++;
        apa[y]=x;
    }
}
int holvan(int x)
{
    if(apa[x]==-1) return x;
    int xxx=holvan(apa[x]);
    apa[x]=xxx;
    return xxx;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        apa[i]=-1;
        mag[i]=1;
    }
    int a1, a2, a3;
    cin>>a1>>a2>>a3;
    for(int i=1; i<m; i++)
    {
        cin>>elek[i].k>>elek[i].v>>elek[i].suly;
    }
    qsort(elek+1, m-1, sizeof(el), rendez);
    for(int i=1; i<m; i++)
    {
        if(holvan(elek[i].k)!=holvan(elek[i].v))
        {
            unio(holvan(elek[i].k), holvan(elek[i].v));
        }
        if(holvan(a1)==holvan(a2))
        {
            cout<<elek[i].suly<<endl;
            return 0;
        }
    }
    cout<<1000000000<<endl;
    return 0;
}