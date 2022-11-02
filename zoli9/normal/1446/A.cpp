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
        ll W;
        cin>>n;
        cin>>W;
        ll half = W/2;
        if(W%2) half++;
        vector<pair<ll, ll> > a(n);
        int solution=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i].F;
            a[i].S=i+1;
            if(half<=a[i].F && a[i].F<=W)
            {
                solution=i+1;
            }
        }
        if(solution>0)
        {
            cout<<1<<'\n';
            cout<<solution<<'\n';
            continue;
        }
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        ll sum=0;
        vi sol;
        for(int i=0; i<n; i++)
        {
            if(a[i].F>W) continue;
            else
            {
               sum+=a[i].F;
               sol.push_back(a[i].S);
               if(sum>=half) break;
            }
        }
        if(sum>=half && sum<=W)
        {
            cout<<sol.size()<<'\n';
            for(int x: sol)
            {
                cout<<x<<" ";
            }
            cout<<'\n';
        }
        else
        {
            cout<<-1<<'\n';
        }
    }
    return 0;
}