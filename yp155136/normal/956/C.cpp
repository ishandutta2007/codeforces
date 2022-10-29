#include <bits/stdc++.h>
using namespace std;

const int N = 100006;

int a[N];
int premx[N];
int _[N];

int main ()
{
    int n;
    scanf("%d",&n);
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&a[i]);
        premx[i] = max(premx[i-1],a[i]);
    }
    long long ans = 0;
    for (int i=n;i>=1;i--)
    {
        _[i] = max(premx[i],_[i+1]-1);
    }
    for (int i=1;n>=i;i++)
    {
        ans += (_[i]-a[i]);
        //cout << _[i] << ' ';
    }
    cout<<ans;
    cout<<endl;
}