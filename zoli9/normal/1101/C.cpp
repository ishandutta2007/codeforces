#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
int test;
int n;
bool elso[100009];
vector<pair<pair<int, int>, int > > v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        v.clear();
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            elso[i]=false;
        }
        for(int i=1; i<=n; i++)
        {
            int kk, vv;
            cin>>kk>>vv;
            v.push_back({{kk, vv}, i});
        }
        sort(v.begin(), v.end());
        int tart=v[0].F.S;
        elso[v[0].S]=true;
        bool joo=false;
        for(int i=1; i<n; i++)
        {
            if(v[i].F.F>tart)
            {
                joo=true;
                break;
            }
            tart=max(tart, v[i].F.S);
            elso[v[i].S]=true;
        }
        if(joo)
        {
            for(int i=1; i<=n; i++)
            {
                if(elso[i]) cout<<"1 ";
                else cout<<"2 ";
            }
            cout<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
    }
    return 0;
}