#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
int n;
int a[200009];
int x, y;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>x>>y;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<=n; i++)
    {
        int s=max(1, i-x);
        int e=min(n, i+y);
        bool ok=true;
        for(int j=s; j<=e; j++)
        {
            if(a[j]<a[i])
            {
                ok=false;
                break;
            }
        }
        if(ok)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}