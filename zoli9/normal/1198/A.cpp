#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;

int n, I;
vector<int> v;
vector<int> db;
int maxdb;
int maxtipus;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>I;
    maxdb=8*I/n;
    maxtipus=1;
    for(int i=1; i<=maxdb; i++)
    {
        maxtipus*=2;
        if(maxtipus>=n) break;
    }
    v.resize(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    int cnt=1;
    for(int i=1; i<n; i++)
    {
        if(v[i]==v[i-1]) cnt++;
        else
        {
            db.push_back(cnt);
            cnt=1;
        }
    }
    db.push_back(cnt);
    //for(int ii: db) cout<<ii<<endl;
    int osszesen=0;
    int ans=n;
    maxtipus=min(maxtipus, (int)db.size());
    for(int i=0; i<maxtipus-1; i++) osszesen+=db[i];
    ans=min(ans, n-osszesen);
    for(int i=maxtipus-1; i<db.size(); i++)
    {
        osszesen+=db[i];
        ans=min(ans, n-osszesen);
        osszesen-=db[i-maxtipus+1];
    }
    cout<<ans<<endl;
    return 0;
}