#include <bits/stdc++.h>
using namespace std;
long long n, m, ans=0;
int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            int a, b;
            cin>>a>>b;
            if(a==1 || b==1) ans++;
        }
    }
    cout<<ans;
    return 0;
}