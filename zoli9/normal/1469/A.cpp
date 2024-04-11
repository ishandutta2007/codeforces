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

string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        cin>>s;
        int n=s.size();
        if(n%2==1)
        {
            cout<<"NO"<<'\n';
            continue;
        }
        int d1=0;
        int d2=0;
        int x=0;
        bool ok=true;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(')
            {
                d1=i;
            }
            else if(s[i]==')')
            {
                d2=i;
            }
        }
        if(d2==0 || d1==n-1)
        {
            cout<<"NO"<<'\n';
            continue;
        }
        cout<<"YES"<<'\n';
    }
    return 0;
}