#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
vector<pair<pii, pii> > ans;
int n;
int t[2009];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=2*n; i++)
    {
        cin>>t[i];
    }
    sort(t+1, t+2*n+1);
    if(t[1]==t[2*n]) cout<<-1<<endl;
    else
    {
        for(int i=1; i<=2*n; i++) cout<<t[i]<<" ";
    }
    cout<<endl;

    return 0;
}