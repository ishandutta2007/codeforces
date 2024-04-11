#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n, m;
string s[1009];
int correct[1009];
int darab[5];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>s[i];
    }
    for(int i=0; i<m; i++)
    {
        cin>>correct[i];
    }
    int ans=0;
    for(int j=0; j<m; j++)
    {
        for(int k=0; k<5; k++) darab[k]=0;
        for(int i=1; i<=n; i++)
        {
            darab[s[i][j]-'A']++;
        }
        int maxi=0;
        for(int k=0; k<5; k++) maxi=max(maxi, darab[k]);
        ans+=(maxi*correct[j]);
    }
    cout<<ans<<endl;
    return 0;
}