#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> G[109];
vector<int> suly[109];
vector<int> hagy;
bool bejar[109];
bool nyero[109][109][30];
//int sorszam[109];
void dfs(int x)
{
    bejar[x]=true;
    for(int sz: G[x]) if(!bejar[sz]) dfs(sz);
    hagy.push_back(x);
    //sorszam[x]=hagy.size()-1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int a, b;
        char c;
        cin>>a>>b>>c;
        G[a].push_back(b);
        suly[a].push_back((c-'a')+1);
    }
    hagy.push_back(0);
    for(int i=1; i<=n; i++)
    {
        if(!bejar[i]) dfs(i);
    }
    /*for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            for(int u=0; u<30; u++)
            {
                nyero[i][j][u]=true;
            }
        }
    }*/
    for(int osszeg=2; osszeg<=2*n; osszeg++)
    {
        for(int id1=1; id1<min(osszeg, n+1); id1++)
        {
            int id2=osszeg-id1;
            if(id2<1 || id2>n) continue;
            for(int utolso=0; utolso<=26; utolso++)
            {
                //cout<<utolso<<"!"<<endl;
                for(int u=0; u<G[hagy[id1]].size(); u++)
                {
                    int sz=G[hagy[id1]][u];
                    if(suly[hagy[id1]][u]>=utolso)
                    {
                        if(!nyero[hagy[id2]][sz][suly[hagy[id1]][u]])
                        {
                            nyero[hagy[id1]][hagy[id2]][utolso]=true;
                            break;
                        }
                    }
                }
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(nyero[i][j][0]) cout<<"A";
            else cout<<"B";
        }
        cout<<endl;
    }
    return 0;
}