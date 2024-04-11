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
        string a, b;
        cin>>a;
        cin>>b;
        int ans=a.size()+b.size();
        for(int a1=0; a1<a.size(); a1++)
        {
            for(int a2=a1; a2<a.size(); a2++)
            {
                for(int b1=0; b1<b.size(); b1++)
                {
                    for(int b2=b1; b2<b.size(); b2++)
                    {
                        if(a.substr(a1, a2-a1+1)==b.substr(b1, b2-b1+1))
                        {
                            int cur=a.size()+b.size();
                            cur-=(a2-a1+1);
                            cur-=(b2-b1+1);
                            ans=min(ans, cur);
                        }
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}