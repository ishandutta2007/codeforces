#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

vector<pii> v[200009];
ll ans[200009];
int test;
int apa[200009];
int mag[200009];
ll darab[200009];
int maxi=0;
ll answer=0;
int holvan(int x)
{
    if(apa[x]==x) return x;
    return apa[x]=holvan(apa[x]);
}
void unio(int x, int y)
{
    answer+=(darab[x]*darab[y]);
    if(mag[x]<mag[y])
    {
        apa[x]=y;
        darab[y]+=darab[x];
    }
    else
    {
        apa[y]=x;
        mag[x]++;
        darab[x]+=darab[y];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n>>test;
    for(int i=1; i<=n; i++)
    {
        apa[i]=i;
        mag[i]=1;
        darab[i]=1;
    }
    for(int i=1; i<n; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        maxi=max(maxi, c);
        v[c].push_back({a, b});
    }
    for(int k=1; k<=200000; k++)
    {
        for(pii p: v[k])
        {
            int h1=holvan(p.F);
            int h2=holvan(p.S);
            unio(h1, h2);
        }
        ans[k]=answer;
    }
    for(int i=1; i<=test; i++)
    {
        int qu;
        cin>>qu;
        cout<<ans[qu]<<" ";
    }
    cout<<endl;


    return 0;
}