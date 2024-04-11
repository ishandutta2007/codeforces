#include <bits/stdc++.h>
using namespace std;
int test;
vector<long long> v;
vector<long long> f;
int n;
vector<int> fff[200009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n;
        v.assign(n, 0);
        f.assign(n, 0);
        for(int i=0; i<n; i++)
        {
            fff[i].clear();
            int szam, fval;
            cin>>szam>>fval;
            v[szam-1]++;
            f[szam-1]+=fval;
        }
        fff[n].clear();
        for(int i=0; i<n; i++)
        {
            fff[v[i]].push_back(f[i]);
        }
        int ans1=0;
        int ans2=0;
        priority_queue<int> qp;
        for(int c=n; c>=1; c--)
        {
            for(int u: fff[c]) qp.push(u);
            if(!qp.empty())
            {
                ans1+=c;
                ans2+=min(qp.top(), c);
                qp.pop();
            }
        }

        cout<<ans1<<" "<<ans2<<endl;
    }

    return 0;
}