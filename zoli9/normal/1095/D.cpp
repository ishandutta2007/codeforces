#include <bits/stdc++.h>
using namespace std;
int n;
int t[200009][2];
bool metszet(int x, int y)
{
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            if(t[x][i]==t[y][j]) return true;
        }
    }
    return false;
}
vector<int> ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i][0]>>t[i][1];
    }
    if(n==3)
    {
        cout<<"1 2 3"<<endl;
        return 0;
    }
    ans.push_back(1);
    int curr=1;
    for(int kor=2; kor<=n; kor++)
    {
        if(metszet(curr, t[curr][0]))
        {
            curr=t[curr][0];
        }
        else
        {
            curr=t[curr][1];
        }
        ans.push_back(curr);
    }
    for(int ss: ans) cout<<ss<<" ";
    cout<<endl;
    return 0;
}