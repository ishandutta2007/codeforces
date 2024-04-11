#include <bits/stdc++.h>
using namespace std;
int n;
long double t[100009];
long double le(long double x)
{
    int r = round(x);
    if(r<=x) return r;
    else return r-1;
}
long double fel(long double x)
{
    int r = round(x);
    if(r>=x) return r;
    else return r+1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
    }
    long double ext=0.0;
    for(int i=1; i<=n; i++)
    {
        if(ext>0.0)
        {
            int l = le(t[i]);
            cout<<l<<endl;
            ext-=(t[i]-(long double)(l));
        }
        else
        {
            int f = fel(t[i]);
            cout<<f<<endl;
            ext+=((long double)(f)-t[i]);
        }
    }
    return 0;
}