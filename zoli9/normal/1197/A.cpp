#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
int test;
int n;
vector<int> d;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n;
        d.resize(n);
        for(int i=0; i<n; i++)
        {
            cin>>d[i];
        }
        sort(d.begin(), d.end());
        int ans=0;
        for(int i=0; i<n-1; i++)
        {
            if(d[n-2]>=i+1) ans=max(ans, i);
        }
        cout<<ans<<endl;
    }


    return 0;
}