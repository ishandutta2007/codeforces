#include <bits/stdc++.h>
using namespace std;
int deg[1009];
vector<int> G[1009];
vector<int> suly[1009];
int e1[1009];
int e2[1009];
int e3[1009];
int apa[1009];
int n;
vector<int> gyerekek[1009];
int aleaf[1009];
bool bejar[1009];
int start;
vector<pair<pair<int, int>, int> > ans;
void dfs(int x)
{
    bejar[x]=true;
    for(int sz: G[x])
    {
        if(!bejar[sz])
        {
            apa[sz]=x;
            gyerekek[x].push_back(sz);
            dfs(sz);
        }
    }
    if(gyerekek[x].size()==0) aleaf[x]=x;
    else aleaf[x]=aleaf[gyerekek[x][0]];
}
void qu(int x, int y, int va)
{
    if(x==0) return;
    ans.push_back({{x, y}, va});
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<n; i++)
    {
        int a, b, cost;
        cin>>a>>b>>cost;
        e1[i]=a;
        e2[i]=b;
        e3[i]=cost;
        G[a].push_back(b);
        G[b].push_back(a);
        suly[a].push_back(cost);
        suly[b].push_back(cost);
        deg[a]++;
        deg[b]++;
    }
    for(int i=1; i<=n; i++)
    {
        if(deg[i]==2)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(deg[i]==1)
        {
            start=i;
            dfs(i);
            break;
        }
    }
    for(int i=1; i<n; i++)
    {
        int gy=e1[i];
        int a=e2[i];
        if(apa[gy]!=a) swap(a, gy);
        if(a==start && deg[gy]==1)
        {
            qu(a, gy, e3[i]);
            continue;
        }
        if(a==start)
        {
            int leaf1=aleaf[gyerekek[gy][0]];
            int leaf2=aleaf[gyerekek[gy][1]];
            qu(a, leaf1, e3[i]/2);
            qu(a, leaf2, e3[i]/2);
            qu(leaf1, leaf2, -e3[i]/2);
            continue;
        }
        if(deg[gy]==1)
        {
            int masikgyerek=gyerekek[a][0];
            if(masikgyerek==gy)
            {
                masikgyerek=gyerekek[a][1];
            }
            int apaleaf=aleaf[masikgyerek];
            qu(start, gy, e3[i]/2);
            qu(apaleaf, gy, e3[i]/2);
            qu(apaleaf, start, -e3[i]/2);
            continue;
        }
        int masikgyerek=gyerekek[a][0];
        if(masikgyerek==gy)
        {
            masikgyerek=gyerekek[a][1];
        }
        int apaleaf=aleaf[masikgyerek];
        int leaf1=aleaf[gyerekek[gy][0]];
        int leaf2=aleaf[gyerekek[gy][1]];
        qu(start, leaf1, e3[i]/2);
        qu(apaleaf, leaf2, e3[i]/2);
        qu(start, apaleaf, -e3[i]/2);
        qu(leaf1, leaf2, -e3[i]/2);
    }
    cout<<"YES"<<'\n';
    cout<<ans.size()<<'\n';
    for(pair<pair<int, int>, int> pp: ans)
    {
        cout<<pp.first.first<<" "<<pp.first.second<<" "<<pp.second<<'\n';
    }
    return 0;
}