#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n,m;
    cin >>n >> m;
    int c[n],a[m];
    for (int i=0;n>i;i++) cin>>c[i];
    for (int i=0;m>i;i++) cin >> a[i];
    int ptr=0;
    int ans=0;
    for (int i=0;m>i;i++)
    {
        while (ptr < n && c[ptr] > a[i]) ptr++;
        if (ptr == n) break;
        ++ans;
        ++ptr;
    }
    cout<<ans<<endl;
}