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
        string s;
        cin>>n;
        cin>>s;
        vector<bool> w(26, false);
        int i=0;
        bool ans=true;
        while(i<n)
        {
            char ccc=s[i];
            if(w[ccc-'A'])
            {
                ans=false;
                break;
            }
            w[ccc-'A']=true;
            while(i<n && s[i]==ccc) i++;
        }
        if(ans) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    return 0;
}