#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200009];
int mag[200009];
int m;
vector<pair<long long, pair<int, int> > > elek;
int apa[200009];
int holvan(int x)
{
    if(apa[x]==-1) return x;
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
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        apa[i]=-1;
        mag[i]=1;
    }
    int minhely=1;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        if(a[i]<a[minhely]) minhely=i;
    }
    for(int i=1; i<=n; i++)
    {
        if(minhely==i) continue;
        elek.push_back({a[minhely]+a[i], {minhely, i}});
    }
    for(int i=1; i<=m; i++)
    {
        int aa, bb;
        long long cc;
        cin>>aa>>bb>>cc;
        elek.push_back({cc, {aa, bb}});
    }
    long long ans=0;
    sort(elek.begin(), elek.end());
    int reszek=n;
    for(int i=0; i<elek.size(); i++)
    {
        int h1=holvan(elek[i].second.first);
        int h2=holvan(elek[i].second.second);
        if(h1==h2) continue;
        ans+=elek[i].first;
        unio(h1, h2);
        reszek--;
        if(reszek==1) break;
    }
    cout<<ans<<endl;

    return 0;
}