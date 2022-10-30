#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int getid[200009];
int n;

bool cmp(pii x, pii y)
{
    if(x.F==y.F)
    {
        return x.S>y.S;
    }
    return x.F<y.F;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        cin>>n;
        vpii a(n);
        vi coordinates;
        for(int i=0; i<n; i++)
        {
            cin>>a[i].F>>a[i].S;
            coordinates.push_back(a[i].F);
            coordinates.push_back(a[i].S);
        }
        sort(coordinates.begin(), coordinates.end());
        int id=0;
        for(int i=0; i<coordinates.size(); i++)
        {
            if(i==0 || coordinates[i]!=coordinates[i-1])
            {
                id++;
                getid[coordinates[i]]=id;
            }
        }
        for(pii & p: a)
        {
            p.F=getid[p.F];
            p.S=getid[p.S];
        }
        sort(a.begin(), a.end(), cmp);
        vi nxt(n, -1);
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(a[i].S<a[j].F)
                {
                    nxt[i]=j;
                    break;
                }
            }
        }
        vector<vi> dp(n, vi(id+1, 0));
        for(int i=n-1; i>=0; i--)
        {
            for(int ed=1; ed<=id; ed++)
            {
                if(i==n-1)
                {
                    if(a[i].S<=ed) dp[i][ed]=1;
                    continue;
                }

                dp[i][ed]=dp[i+1][ed];
                if(a[i].S>ed)
                {
                    continue;
                }
                int newDp=1+dp[i+1][a[i].S];
                if(nxt[i]>=0) newDp+=dp[nxt[i]][ed];
                dp[i][ed]=max(dp[i][ed], newDp);
            }
        }
        cout<<dp[0][id]<<'\n';
    }
}