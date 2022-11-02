#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
int n, m;
map<int, int> w;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    queue<int> q;
    for(int i=1; i<=n; i++)
    {
        int aa;
        cin>>aa;
        q.push(aa);
        w[aa]=0;
    }
    int found=0;
    ll ans=0;
    vi answer;
    ll d=1;
    while(1)
    {
        int akt=q.front();
        //cout<<akt<<" :"<<endl;
        q.pop();
        if(w.find(akt+1)==w.end())
        {
            w[akt+1]=w[akt]+1;
            ans+=((ll)(w[akt+1]));
            q.push(akt+1);
            answer.push_back(akt+1);
            found++;
            if(found==m) break;
        }
        if(w.find(akt-1)==w.end())
        {
            w[akt-1]=w[akt]+1;
            ans+=((ll)(w[akt-1]));
            q.push(akt-1);
            answer.push_back(akt-1);
            found++;
            if(found==m) break;
        }
    }
    cout<<ans<<endl;
    for(int i=1; i<=m; i++)
    {
        cout<<answer[i-1]<<" ";
    }
    cout<<endl;
    return 0;
}