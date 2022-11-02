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
int n;
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        cin>>n;
        cin>>s;
        bool done=false;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='0')
            {
                if(i<n/2)
                {
                    cout<<i+1<<" "<<n<<" "<<i+2<<" "<<n<<'\n';
                    done=true;
                    break;
                }
                else
                {
                    cout<<1<<" "<<i+1<<" "<<1<<" "<<i<<'\n';
                    done=true;
                    break;
                }
            }
        }
        if(done) continue;
        int x=n/2;
        cout<<1<<" "<<2*x<<" "<<1<<" "<<x<<'\n';
    }
    return 0;
}