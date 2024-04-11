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

bool cp[10009];

string s;
int n;

int solve(int i, int cnt, int num)
{
    if(cnt==0)
    {
        if(cp[num]) return num;
        else return 0;
    }
    if(i>=n) return 0;
    int res=solve(i+1, cnt, num);
    if(res>0) return res;
    num*=10;
    num+=(s[i]-'0');
    return solve(i+1, cnt-1, num);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cp[1]=true;
    for(int i=2; i<=10000; i++)
    {
        if(cp[i]) continue;
        for(int j=2*i; j<=10000; j+=i)
        {
            cp[j]=true;
        }
    }
    int test;
    cin>>test;
    while(test--)
    {
        cin>>n;
        cin>>s;
        for(int x=1; x<=3; x++)
        {
            int ans=solve(0, x, 0);
            if(ans>0)
            {
                cout<<x<<'\n';
                cout<<ans<<'\n';
                break;
            }
        }
    }
    return 0;
}