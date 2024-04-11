#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        ll s, e, i;
        cin>>s>>i>>e;
        if(i>=s)
        {
            e-=((i+1)-s);
            if(e<0)
            {
                cout<<0<<endl;
                continue;
            }
            if(e%2==0)
            {
                cout<<(e/2+1)<<endl;
                continue;
            }
            else
            {
                cout<<(e/2+1)<<endl;
                continue;
            }
        }
        else
        {
            ll csokken=s-1-i;
            ll mini=0;
            ll e2=e;
            e-=csokken;
            if(e>0)
            {
                if(e%2)
                {
                    mini=e/2+1;
                }
                else
                {
                    mini=e/2;
                }
                cout<<(e2-mini+1)<<endl;
            }
            else cout<<e2+1<<endl;
        }
    }


    return 0;
}