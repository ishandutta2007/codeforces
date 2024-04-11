#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n;
int test;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    int c, m, x;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>c>>m>>x;
        int ans=(c+m+x)/3;
        ans=min(ans, m);
        ans=min(ans, c);
        cout<<ans<<endl;
    }

    return 0;
}