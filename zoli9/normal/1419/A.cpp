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
        bool rg=false;
        bool bg=false;
        for(int i=0; i<n; i++)
        {
            if(i%2==0)
            {
                if((s[i]-'0')%2==1) rg=true;
            }
            else
            {
                if((s[i]-'0')%2==0) bg=true;
            }
        }
        if((n%2==1 && rg) || (n%2==0 && (!bg))) cout<<1<<'\n';
        else cout<<2<<'\n';
    }
    return 0;
}