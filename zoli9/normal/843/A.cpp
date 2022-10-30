#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<long long, long long> > t;
vector<vector<int> > ans;
vector<int> cur;
int jo[100009];
bool volt[100009];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        long long szam;
        cin>>szam;
        t.push_back({szam, i});
    }
    sort(t.begin(), t.end());
    for(int i=0; i<t.size(); i++)
    {
        jo[t[i].second]=i+1;
    }
    for(int i=1; i<=n; i++)
    {
        if(volt[i]) continue;
        int akt=i;
        cur.clear();
        cur.push_back(akt);
        volt[akt]=true;
        akt=jo[akt];
        while(akt!=i)
        {
            cur.push_back(akt);
            volt[akt]=true;
            akt=jo[akt];
        }
        ans.push_back(cur);
    }
    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i].size();
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<" "<<ans[i][j];
        }
        cout<<endl;
    }
    return 0;
}