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
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n;
        ll sum=0;
        for(int i=1; i<=n; i++)
        {
            ll sz;
            cin>>sz;
            if(sz<=2048) sum+=sz;
        }
        if(sum>=2048) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}