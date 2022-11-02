#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    int n;
    while(test--)
    {
        cin>>n;
        vi a(n+1);
        vi ans;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
        }
        int i=1;
        while(i<=n)
        {
            if(a[i]==a[i+1])
            {
                ans.push_back(a[i]);
                ans.push_back(a[i+1]);
            }
            else ans.push_back(0);
            i+=2;
        }
        cout<<ans.size()<<'\n';
        for(int x: ans) cout<<x<<" ";
        cout<<'\n';
    }

    return 0;
}