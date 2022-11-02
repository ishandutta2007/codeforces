#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long val[4000009];
long long kerdez(int cs, int k, int v, int x, int y)
{
    if(v<x || y<k) return 0;
    if(x<=k && v<=y)
    {
        return val[cs];
    }
    return kerdez(cs*2, k, (k+v)/2, x, y)+kerdez(cs*2+1, (k+v)/2+1, v, x, y);
}
void modosit(int cs, int k, int v, int mi)
{
    if(mi<k || v<mi) return;
    val[cs]++;
    if(k==mi && v==mi)
    {
        return;
    }
    modosit(cs*2, k, (k+v)/2, mi);
    modosit(cs*2+1, (k+v)/2+1, v, mi);
    return;
}
int main()
{
    cin>>n>>k;
    if(2*k>=n) k=n-k;
    long long ans=1;
    int akt=0;
    for(int i=1; i<=n; i++)
    {
        if(i<n) ans++;
        int ujk=(akt+1)%n;
        int ujv=(akt+k)%n;
        if(ujk<=ujv)
        {
            //cout<<"kerdez: "<<ujk<<" "<<ujv<<" :"<<kerdez(1, 0, n-1, ujk, ujv)<<endl;
            ans+=kerdez(1, 0, n-1, ujk, ujv);
        }
        else
        {
            //cout<<"kerdez: "<<ujk<<" n-1 :"<<kerdez(1, 0, n-1, ujk, n-1)<<endl;
            ans+=kerdez(1, 0, n-1, ujk, n-1);
            //cout<<"kerdez: 0 "<<ujv<<" :"<<kerdez(1, 0, n-1, 0, ujv)<<endl;
            ans+=kerdez(1, 0, n-1, 0, ujv);
        }
        modosit(1, 0, n-1, akt);
        modosit(1, 0, n-1, (akt+k)%n);
        akt+=k;
        akt%=n;
        cout<<ans<<" ";
    }
    cout<<endl;
    return 0;
}