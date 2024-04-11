#include <iostream>
using namespace std;
int n, m;
long long t[100009];
long long a[100009];
int main()
{
    cin>>n;
    t[0]=0;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
        t[i]+=t[i-1];
    }
    cin>>m;
    for(int i=1; i<=m; i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<=m; i++)
    {
        long long e, u, akt;
        e=1;
        u=n;
        while(e<=u)
        {
            akt=(e+u)/2;
            if(t[akt-1]<a[i] and a[i]<=t[akt])
            {
                cout<<akt<<endl;
                break;
            }
            if(a[i]>t[akt])
            {
                e=akt+1;
            }
            else
            {
                u=akt-1;
            }
        }
    }
    return 0;
}