#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> gr[200009];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    int g=1;
    for(int i=2; i<=n; i++)
    {
        gr[g].push_back(i);
        g++;
        if(g==k+1) g=1;
    }
    int ans=gr[1].size()+gr[2].size();
    cout<<ans<<endl;
    for(int i=1; i<=k; i++)
    {
        cout<<1<<" "<<gr[i][0]<<endl;
        for(int j=1; j<gr[i].size(); j++)
        {
            cout<<gr[i][j-1]<<" "<<gr[i][j]<<endl;
        }
    }
    return 0;
}