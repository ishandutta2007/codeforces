#include <bits/stdc++.h>
using namespace std;
vector<int> G[1009];
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=2; i<=n; i++)
    {
        int aa;
        cin>>aa;
        G[aa].push_back(i);
    }
    bool jo=true;
    for(int i=1; i<=n; i++)
    {
        int lc=0;
        if(G[i].size()==0) continue;
        for(int j=0; j<G[i].size(); j++)
        {
            int sz=G[i][j];
            if(G[sz].size()==0) lc++;
        }
        if(lc<3)
        {
            jo=false;
            break;
        }
    }
    if(jo) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}