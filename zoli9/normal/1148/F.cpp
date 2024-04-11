#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n;
ll va[300009];
ll ma[300009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    ll sum=0;
    for(int i=1; i<=n; i++)
    {
        cin>>va[i]>>ma[i];
        sum+=va[i];
    }
    if(sum<0)
    {
        for(int i=1; i<=n; i++)
        {
            va[i]=-va[i];
        }
    }
    ll answer=0;
    for(int j=0; j<62; j++)
    {
        ll sum=0;
        for(int i=1; i<=n; i++)
        {
            if(ma[i]==1)
            {
                sum+=va[i];
            }
        }
        if(sum>0)
        {
            answer+=(1ll<<j);
            for(int i=1; i<=n; i++)
            {
                if(ma[i]&1) va[i]=-va[i];
            }
        }
        for(int i=1; i<=n; i++) ma[i]/=2;
    }
    cout<<answer<<endl;
    return 0;
}