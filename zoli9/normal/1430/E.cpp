#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//(double)clock() / CLOCKS_PER_SEC;

vi pos[26];
int goal[200009];
int n;
string s;

int m[2000009];

void add1(int cs, int k, int v, int x)
{
    if(x<k || v<x) return;
    m[cs]++;
    if(k==v) return;
    add1(2*cs, k, (k+v)/2, x);
    add1(2*cs+1, (k+v)/2+1, v, x);
}

int ask(int cs, int k, int v, int x, int y)
{
    if(y<k || v<x) return 0;
    if(x<=k && v<=y) return m[cs];
    int r1=ask(2*cs, k, (k+v)/2, x, y);
    int r2=ask(2*cs+1, (k+v)/2+1, v, x, y);
    return r1+r2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cin>>s;
    for(int i=0; i<n; i++)
    {
        pos[s[i]-'a'].push_back(i);
    }
    for(int i=0; i<26; i++)
    {
        int psi=pos[i].size();
        for(int j=0; j<pos[i].size(); j++)
        {
            goal[pos[i][j]]=n-1-pos[i][psi-j-1];
        }
    }
    ll ans=0;
    for(int i=0; i<n; i++)
    {
        ans+=ask(1, 0, n-1, goal[i], n-1);
        add1(1, 0, n-1, goal[i]);
    }
    cout<<ans<<endl;

    return 0;
}