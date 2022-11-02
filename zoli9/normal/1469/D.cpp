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

int ce(int x, int y)
{
    if(x%y==0) return x/y;
    else return x/y+1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        vpii ans;
        int i=n-1;
        int x=n;
        while(i>1)
        {
            int z=x/i;
            if(x%i!=0) z++;
            while(z>=i)
            {
                ans.push_back({n, i});
                x=z;
                z=x/i;
                if(x%i!=0) z++;
            }
            if(i>2) ans.push_back({i, n});
            if(i==2)
            {
                ans.push_back({n, 2});
                break;
            }
            i--;
        }
        cout<<ans.size()<<'\n';
        for(pii p: ans) cout<<p.F<<" "<<p.S<<'\n';
        vi w(n+1);
        for(int j=1; j<=n; j++) w[j]=j;
        for(pii p: ans)
        {
            w[p.F]=ce(w[p.F], w[p.S]);
        }
        /*int db1=0;
        int db2=0;
        for(int j=1; j<=n; j++)
        {
            if(w[j]==1) db1++;
            else if(w[j]==2) db2++;
        }
        if(db1==n-1 && db2==n-2)
        {
            cout<<"TEST OK"<<'\n';
        }
        else
        {
            cout<<"db1: "<<db1<<" db2: "<<db2<<'\n';
        }*/
    }
    return 0;
}