#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
vector<pair<long long, pair<int, int> > > t;
int n, m;
int mag[200009];
int apa[200009];
bool complete[200009];
long long ans=0;
int holvan(int x)
{
    if(apa[x]==x) return x;
    return apa[x]=holvan(apa[x]);
}
void unio(int x, int y)
{
    if(mag[x]<mag[y]) apa[x]=y;
    else if(mag[x]>mag[y]) apa[y]=x;
    else
    {
        apa[x]=y;
        mag[y]++;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        apa[i]=i;
        mag[i]=1;
    }
    for(int i=1; i<=m; i++)
    {
        long long a, b, c;
        cin>>a>>b>>c;
        t.push_back({c, {a, b}});
    }
    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());
    for(int i=0; i<t.size(); i++)
    {
        long long penz=t[i].F;
        int h1=holvan(t[i].S.F);
        int h2=holvan(t[i].S.S);
        if(h1==h2)
        {
            if(complete[h1]) continue;
            complete[h1]=true;
            ans+=penz;
            continue;
        }
        if(complete[h1] && complete[h2]) continue;
        if(!complete[h1] && !complete[h2])
        {
            ans+=penz;
            unio(h1, h2);
            continue;
        }
        complete[h1]=true;
        complete[h2]=true;
        unio(h1, h2);
        ans+=penz;
    }
    cout<<ans<<endl;
    return 0;
}