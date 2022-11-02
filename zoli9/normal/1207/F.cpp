#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int q;
int a[500009];
int ans[800][800];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>q;
    int limit=707;
    for(int tt=1; tt<=q; tt++)
    {
        int tip, x, y;
        cin>>tip>>x>>y;
        if(tip==1)
        {
            a[x]+=y;
            for(int i=1; i<=limit; i++)
            {
                ans[i][x%i]+=y;
            }
        }
        else
        {
            if(x<=limit)
            {
                cout<<ans[x][y]<<endl;
            }
            else
            {
                int cans=0;
                for(int i=y; i<=500000; i+=x) cans+=a[i];
                cout<<cans<<endl;
            }
        }
    }

    return 0;
}