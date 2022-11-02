#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int n, m, k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1; i<=2*k; i++)
    {
        int x, y;
        cin>>x>>y;
    }
    vector<char> ans;
    for(int i=1; i<=n-1; i++) ans.push_back('U');
    for(int i=1; i<=m-1; i++) ans.push_back('L');
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<m; j++)
        {
            if(i%2) ans.push_back('R');
            else ans.push_back('L');
        }
        if(i<n) ans.push_back('D');
    }
    cout<<ans.size()<<endl;
    for(char cc: ans) cout<<cc;
    cout<<endl;



    return 0;
}