#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//(double)clock() / CLOCKS_PER_SEC;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        cin>>n;
        vi want(n+1, 0);
        vi gt(n+1, 0);
        vi whoh(n+1, 0);
        int ans=0;
        vector<bool> used(n+1, false);
        vi need;
        vi need2;
        for(int i=1; i<=n; i++)
        {
            cin>>want[i];
            if(!used[want[i]])
            {
                used[want[i]]=true;
                gt[i]=want[i];
                whoh[want[i]]=i;
                ans++;
            }
            else
            {
                need.push_back(i);
            }
        }
        for(int i=1; i<=n; i++)
        {
            if(!used[i]) need2.push_back(i);
        }
        if(need.size()==0)
        {
            cout<<ans<<'\n';
            for(int i=1; i<=n; i++) cout<<gt[i]<<" ";
            cout<<'\n';
            continue;
        }
        if(need.size()==1)
        {
            if(need[0]!=need2[0])
            {
                gt[need[0]]=need2[0];
            }
            else
            {
                int other=whoh[want[need[0]]];
                gt[need[0]]=want[need[0]];
                gt[other]=need[0];
            }
            cout<<ans<<'\n';
            for(int i=1; i<=n; i++) cout<<gt[i]<<" ";
            cout<<'\n';
            continue;
        }
        if(need[0]==need2[0])
        {
            swap(need2[0], need2[1]);
        }
        for(int i=1; i<need.size(); i++)
        {
            if(need[i]==need2[i])
            {
                swap(need[i], need[i-1]);
            }
        }
        for(int i=0; i<need.size(); i++)
        {
            gt[need[i]]=need2[i];
        }
        cout<<ans<<'\n';
        for(int i=1; i<=n; i++) cout<<gt[i]<<" ";
        cout<<'\n';
    }
    return 0;
}