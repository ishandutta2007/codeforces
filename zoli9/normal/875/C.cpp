#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> szavak[100009];
vector<int> G[100009];
vector<int> valtozik;
bool valt[100009];
int ans;
void dfs(int x)
{
    ans++;
    valt[x]=true;
    for(int sz: G[x])
    {
        if(!valt[sz]) dfs(sz);
    }
}
int main() {
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        int hossz;
        cin>>hossz;
        for(int j=0; j<hossz; j++)
        {
            int betu;
            cin>>betu;
            szavak[i].push_back(betu);
        }
        if(i==1) continue;
        int j;
        for(j=0; j<szavak[i].size(); j++)
        {
            if(szavak[i-1].size()-1<j)
            {
                break;
            }
            if(szavak[i][j]==szavak[i-1][j]) continue;
            if(szavak[i][j]<szavak[i-1][j])
            {
                valtozik.push_back(szavak[i-1][j]);
                break;
            }
            else
            {
                G[szavak[i][j]].push_back(szavak[i-1][j]);
                break;
            }
        }
        if(j==szavak[i].size())
        {
            if(szavak[i-1].size()>szavak[i].size())
            {
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    for(int i=0; i<valtozik.size(); i++)
    {
        if(!valt[valtozik[i]]) dfs(valtozik[i]);
    }
    for(int i=2; i<=n; i++)
    {
        //cout<<i<<endl;
        int index=0;
        while(index<szavak[i-1].size() && index<szavak[i].size())
        {
            if(szavak[i][index]==szavak[i-1][index])
            {
                index++;
                continue;
            }
            break;
        }
        if(index==szavak[i-1].size())
        {
            continue;
        }
        if(index==szavak[i].size())
        {
            cout<<"No"<<endl;
            return 0;
        }
        if(valt[szavak[i][index]]==valt[szavak[i-1][index]])
        {
            if(szavak[i][index]<szavak[i-1][index])
            {
                cout<<"No"<<endl;
                return 0;
            }
        }
        else if(valt[szavak[i][index]])
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    cout<<ans<<endl;
    for(int i=1; i<=m; i++)
    {
        if(valt[i]) cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}