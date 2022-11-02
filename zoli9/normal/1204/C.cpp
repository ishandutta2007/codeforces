#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int infi=1000009;
int d[109][109];
vector<int> ans, ansind;
int h;
vector<int> t;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            char ccc;
            cin>>ccc;
            if(ccc=='1') d[i][j]=1;
            else d[i][j]=infi;
        }
        d[i][i]=0;
    }
    cin>>h;
    t.resize(h);
    for(int i=0; i<h; i++) cin>>t[i];
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
    ans.push_back(t[0]);
    ansind.push_back(0);
    for(int i=2; i<h; i++)
    {
        if(d[ans.back()][t[i]]<i-ansind.back())
        {
            ans.push_back(t[i-1]);
            ansind.push_back(i-1);
        }
    }
    ans.push_back(t.back());
    cout<<ans.size()<<endl;
    for(int i: ans) cout<<i<<" ";
    cout<<endl;

    return 0;
}