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

int n, k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;

    while(test--)
    {
        //cout<<test<<endl;
        cin>>n>>k;
        vi a(n);
        int df=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(i==0 || a[i]!=a[i-1]) df++;
        }
        if(k==1)
        {
            if(df==1) cout<<1<<'\n';
            else cout<<-1<<'\n';
            continue;
        }
        df--;
        if(df==0)
        {
            cout<<1<<'\n';
            continue;
        }
        if(df%(k-1)==0)
        {
            cout<<df/(k-1)<<'\n';
        }
        else
        {
            cout<<(df/(k-1))+1<<'\n';
        }
    }
    return 0;
}