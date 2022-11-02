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
        vll a(n+2);
        ll sum=0;
        for(int i=0; i<n+2; i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        sort(a.begin(), a.end());
        ll w=a[n+1];
        ll x=sum-2*w;
        int xid=-1;
        for(int i=0; i<n+1; i++)
        {
            if(a[i]==x)
            {
                xid=i;
                break;
            }
        }
        if(xid>=0)
        {
            for(int i=0; i<n+1; i++)
            {
                if(i==xid) continue;
                cout<<a[i]<<" ";
            }
            cout<<'\n';
            continue;
        }

        w=a[n];
        if(a[n+1]==sum-2*w)
        {
            for(int i=0; i<n; i++)
            {
                cout<<a[i]<<" ";
            }
            cout<<'\n';
            continue;
        }
        cout<<-1<<'\n';
    }
    return 0;
}