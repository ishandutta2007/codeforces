#include <bits/stdc++.h>
using namespace std;
long long n;
bool isin(long long x1, long long y1, long long x2, long long y2, long long a1, long long b1, long long a2, long long b2)
{
    if(a1<=x1 && x2<=a2 && b1<=y1 && y2<=b2) return true;
    return false;
}
int main()
{
    cin>>n;
    long long x1, y1, x2, y2;
    x1=1;
    y1=1;
    x2=n;
    y2=n;
    long long x2min=1;
    long long x2max=n;
    while(x2min<=x2max)
    {
        long long x2koz=(x2min+x2max)/2;
        cout<<"? "<<x1<<" "<<y1<<" "<<x2koz<<" "<<y2<<endl;
        fflush(stdout);
        int ans;
        cin>>ans;
        if(ans==0)
        {
            x2min=x2koz+1;
        }
        else x2max=x2koz-1;
    }
    x2=x2min;

    long long x1min=1;
    long long x1max=x2;
    while(x1min<=x1max)
    {
        long long x1koz=(x1min+x1max)/2;
        cout<<"? "<<x1koz<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
        fflush(stdout);
        int ans;
        cin>>ans;
        if(ans==0)
        {
            x1max=x1koz-1;
        }
        else x1min=x1koz+1;
    }
    x1=x1max;

    long long y2min=1;
    long long y2max=n;
    while(y2min<=y2max)
    {
        long long y2koz=(y2min+y2max)/2;
        cout<<"? "<<x1<<" "<<y1<<" "<<x2<<" "<<y2koz<<endl;
        fflush(stdout);
        int ans;
        cin>>ans;
        if(ans==0)
        {
            y2min=y2koz+1;
        }
        else y2max=y2koz-1;
    }
    y2=y2min;

    long long y1min=1;
    long long y1max=y2;
    while(y1min<=y1max)
    {
        long long y1koz=(y1min+y1max)/2;
        cout<<"? "<<x1<<" "<<y1koz<<" "<<x2<<" "<<y2<<endl;
        fflush(stdout);
        int ans;
        cin>>ans;
        if(ans==0)
        {
            y1max=y1koz-1;
        }
        else y1min=y1koz+1;
    }
    y1=y1max;


    long long a1, b1, a2, b2;
    a1=1;
    b1=1;
    a2=n;
    b2=n;


    long long a2min=1;
    long long a2max=n;
    while(a2min<=a2max)
    {
        long long a2koz=(a2min+a2max)/2;
        cout<<"? "<<a1<<" "<<b1<<" "<<a2koz<<" "<<b2<<endl;
        fflush(stdout);
        int ans;
        cin>>ans;
        if(isin(x1, y1, x2, y2, a1, b1, a2koz, b2)) ans--;
        if(ans==0)
        {
            a2min=a2koz+1;
        }
        else a2max=a2koz-1;
    }
    a2=a2min;

    long long a1min=1;
    long long a1max=a2;
    while(a1min<=a1max)
    {
        long long a1koz=(a1min+a1max)/2;
        cout<<"? "<<a1koz<<" "<<b1<<" "<<a2<<" "<<b2<<endl;
        fflush(stdout);
        int ans;
        cin>>ans;
        if(isin(x1, y1, x2, y2, a1koz, b1, a2, b2)) ans--;
        if(ans==0)
        {
            a1max=a1koz-1;
        }
        else a1min=a1koz+1;
    }
    a1=a1max;

    long long b2min=1;
    long long b2max=n;
    while(b2min<=b2max)
    {
        long long b2koz=(b2min+b2max)/2;
        cout<<"? "<<a1<<" "<<b1<<" "<<a2<<" "<<b2koz<<endl;
        fflush(stdout);
        int ans;
        cin>>ans;
        if(isin(x1, y1, x2, y2, a1, b1, a2, b2koz)) ans--;
        if(ans==0)
        {
            b2min=b2koz+1;
        }
        else b2max=b2koz-1;
    }
    b2=b2min;

    long long b1min=1;
    long long b1max=b2;
    while(b1min<=b1max)
    {
        long long b1koz=(b1min+b1max)/2;
        cout<<"? "<<a1<<" "<<b1koz<<" "<<a2<<" "<<b2<<endl;
        fflush(stdout);
        int ans;
        cin>>ans;
        if(isin(x1, y1, x2, y2, a1, b1koz, a2, b2)) ans--;
        if(ans==0)
        {
            b1max=b1koz-1;
        }
        else b1min=b1koz+1;
    }
    b1=b1max;
    cout<<"! "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<a1<<" "<<b1<<" "<<a2<<" "<<b2<<endl;
    fflush(stdout);
    return 0;
}