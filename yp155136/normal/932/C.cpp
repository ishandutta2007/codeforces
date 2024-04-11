#include <bits/stdc++.h>
using namespace std;

#define int long long

int extgcd(int a,int b,long long &x,long long &y)
{
    if (b==0)
    {
        x=1,y=0;
        return a;
    }
    int d=extgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return d;
}

main ()
{
    int n,a,b;
    cin >> n >>a >>b;
    long long x,y;
    int gcd = extgcd(a,b,x,y);
    //cout << "gcd = "<<gcd<<" ,x  = "<<x<<" , y = "<<y<<endl;
    if (n%gcd != 0)
    {
        puts("-1");
        return 0;
    }
    x *= (n/gcd);
    y *= (n/gcd);
    while (x<0)
    {
        x += b/gcd;
        y -= a/gcd;
    }
    while (y<0)
    {
        y += a/gcd;
        x -= b/gcd;
    }
    //cout << "x = "<<x<<" , y = "<<y<<endl;
    if (x<0)
    {
        puts("-1");
        return 0;
    }
    int now=1;
    vector<int> ans;
    assert(a*x + b*y == n);
    while (x--)
    {
        int tmp=a-1;
        int tmpnow = now;
        now++;
        while (tmp--)
        {
            ans.push_back(now++);
        }
        ans.push_back(tmpnow);
    }
    while (y--)
    {
        int tmp=b-1;
        int tmpnow = now;
        now++;
        while (tmp--)
        {
            ans.push_back(now++);
        }
        ans.push_back(tmpnow);
    }
    for (int i=0;n>i;i++)
    {
        if (i) cout << ' ';
        cout <<ans[i];
    }
    cout<<endl;
}