#include <bits/stdc++.h>
using namespace std;
bool osszetett[200009];
int a[200009];
vector<int> G[200009];
int n;
vector<int> primek;
unordered_map<int, int> h[200009];
int ans=1;
bool bejar[200009];
bool mindegy=true;
void dfs(int x)
{
    bejar[x]=true;
    for(int sz: G[x])
    {
        if(!bejar[sz])
        {
            dfs(sz);
            for(auto& it: h[x])
            {
                //cout<<"x: "<<x<<" "<<it.first<<" "<<it.second<<endl;
                int mennyi=h[sz][it.first];
                if(mennyi!=0)
                {
                    ans=max(ans, it.second+mennyi);
                    h[x][it.first]=max(it.second, 1+mennyi);
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cur=2;
    while(cur<=200000)
    {
        if(osszetett[cur])
        {
            cur++;
            continue;
        }
        for(int i=2*cur; i<=200005; i+=cur) osszetett[i]=true;
        cur++;
    }
    osszetett[1]=true;
    for(int i=1; i<=200000; i++)
    {
        if(!osszetett[i]) primek.push_back(i);
    }
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        if(a[i]!=1) mindegy=false;
        int z=a[i];
        for(int j=0; j<primek.size(); j++)
        {
            if(z%primek[j]==0)
            {
                h[i][primek[j]]=1;
                while(z%primek[j]==0) z/=primek[j];
            }
            if(primek[j]*primek[j]>z+1)
            {
                if(z>1) h[i][z]=1;
                break;
            }
        }
    }
    for(int i=1; i<n; i++)
    {
        int aa, bb;
        cin>>aa>>bb;
        G[aa].push_back(bb);
        G[bb].push_back(aa);
    }
    if(mindegy)
    {
        cout<<0<<endl;
        return 0;
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}