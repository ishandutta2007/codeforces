#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long v[100005], t[100005], p[100005], a[100005], s[100005];

int lb(long long x)
{
    int l = 0;
    int r = n;
    int m;
    while(l != r)
    {
        m = (l+r)/2+1;
        if(p[m] <= x)
            l = m;
        else
            r = m-1;
    }
    //cout<<"!"<<x<<" "<<p[r]<<" "<<r<<endl;
    return r;
}

void vypis()
{
    for(int i = 1; i <= n; i++)
        cout<<p[i]<<" ";
    cout<<endl;
    for(int i = 1; i <= n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    for(int i = 1; i <= n; i++)
        cout<<s[i]<<" ";
    cout<<endl;
}

int main()
{
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>v[i];
    for(int i = 1; i <= n; i++)
    {
        cin>>t[i];
        p[i] = p[i-1]+t[i];
    }
    long long pr = 0;
    for(int i = 1; i <= n; i++)
    {
        //vypis();
        int l = lb(v[i]+p[i-1]);
        int x = v[i]+p[i-1]-p[l];
        a[l+1] += x;
        s[l+1]++;
        pr -= s[i]-1;
        cout<<t[i]*pr+a[i]<<" ";
    }
    cout<<endl;
    return 0;
}