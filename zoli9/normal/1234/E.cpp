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
ll cum[200009];
ll t[200009];
ll gl;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int elozo;
    int uj;
    for(int i=1; i<=m; i++)
    {
        cin>>uj;
        if(i>=2)
        {
           int a=min(uj, elozo);
           int b=max(uj, elozo);
           if(a==b)
           {
               elozo=uj;
               continue;
           }
           gl+=(b-a);
           cum[a+1]--;
           cum[b]++;
           t[a]-=(b-a);
           t[a]+=(b-1);
           t[b]-=(b-a);
           t[b]+=a;
        }
        elozo=uj;
    }
    for(int i=1; i<=n; i++)
    {
        cum[i]+=cum[i-1];
        cout<<cum[i]+t[i]+gl<<" ";
    }
    cout<<endl;

    return 0;
}