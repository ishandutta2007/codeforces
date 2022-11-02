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

const int maxi=1e7;

bool cp[maxi+9];
ll d[maxi+9];
ll mind[maxi+9];
int factout[maxi+9];
vi ans(maxi+1, -1);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    d[1]=1;
    mind[1]=1;
    factout[1]=1;
    for(int i=2; i<=maxi; i++)
    {
        if(cp[i]) continue;
        for(int j=i; j<=maxi; j+=i)
        {
            if(!cp[j])
            {
                cp[j]=true;
                if(j%(i*i)==0)
                {
                    mind[j]=mind[j/i]*i+1;
                    factout[j]=factout[j/i];
                }
                else
                {
                    mind[j]=i+1;
                    factout[j]=j/i;
                }
            }
        }
    }

    for(int i=1; i<=maxi; i++)
    {
        d[i]=mind[i]*d[factout[i]];
        if(d[i]<=maxi && ans[d[i]]==-1) ans[d[i]]=i;
    }

    int test;
    cin>>test;
    while(test--)
    {
        int x;
        cin>>x;
        cout<<ans[x]<<'\n';
    }
    return 0;
}