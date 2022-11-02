#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
vector<pair<pii, pii> > ans;
int n;
int t[100009];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    bool ok=false;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
        if(t[i]%2!=t[1]%2) ok=true;
    }
    if(!ok)
    {
        for(int i=1; i<=n; i++) cout<<t[i]<<" ";
        cout<<endl;
        return 0;
    }
    sort(t+1, t+n+1);
    if(t[1]==t[2*n]) cout<<-1<<endl;
    for(int i=1; i<=n; i++) cout<<t[i]<<" ";
    cout<<endl;
    return 0;
}