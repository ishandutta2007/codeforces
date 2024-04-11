#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int gcd(int u, int v)
{
    while ( v != 0) {
        int r = u % v;
        u = v;
        v = r;
    }
    return u;
}
int main()
{
    cin>>a>>b>>c;
    if(c%(gcd(a, b))!=0)
    {
        cout<<"No";
        return 0;
    }
    if(c>=a*b)
    {
        cout<<"Yes";
        return 0;
    }
    for(int i=0; i<=b; i++)
    {
        for(int j=0; j<=a; j++)
        {
            if(i*a+j*b==c)
            {
                cout<<"Yes";
                return 0;
            }
        }
    }
    cout<<"No";
    return 0;
}