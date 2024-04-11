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
        vi a(n+1);
        vi where(n+1);
        vi db(n+1, 0);
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            db[a[i]]++;
            where[a[i]]=i;
        }
        int maxi=n;
        for(int i=1; i<=n; i++)
        {
            if(db[i]==1) continue;
            if(db[i]==0)
            {
                maxi=i-1;
                break;
            }
            else if(db[i]>1)
            {
                maxi=i;
                break;
            }
        }
        vi ans(n+1, 0);
        if(maxi==n) ans[1]=1;
        vector<bool> w(n+2, false);
        int e1=1;
        int e2=n;
        for(int i=1; i<=maxi; i++)
        {
            if(e2-e1+1==n-i+1) ans[n-i+1]=true;
            else break;
            w[where[i]]=true;
            while(w[e1]) e1++;
            while(w[e2]) e2--;
        }
        for(int i=1; i<=n; i++) cout<<ans[i];
        cout<<endl;

    }
    return 0;
}