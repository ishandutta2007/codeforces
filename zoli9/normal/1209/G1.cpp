#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, q;
int db[200009];
int cm[200009];
int id[200009];
int t[200009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
        if(id[t[i]]==0)
        {
            cm[i]++;
        }
        id[t[i]]=i;
        db[t[i]]++;
    }
    for(int i=1; i<=200000; i++)
    {
        if(id[i]>0)
        {
            cm[id[i]]--;
        }
    }
    int last=0;
    int best=0;
    int sum=0;
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        sum+=cm[i];
        best=max(best, db[t[i]]);
        if(sum==0)
        {
            ans+=(i-last-best);
            last=i;
            best=0;
        }
    }
    cout<<ans<<endl;
    return 0;
}