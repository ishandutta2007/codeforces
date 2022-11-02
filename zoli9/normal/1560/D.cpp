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

vector<string> ss;
string s;

int dist(string& x, string& y)
{
    int j=0;
    int res=0;
    for(int i=0; i<x.size(); i++)
    {
        if(j<y.size() && x[i]==y[j])
        {
            j++;
        }
        else
        {
            res++;
        }
    }
    int si=y.size();
    return res+si-j;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(ll i=0; i<=62; i++)
    {
        ll x=((1LL)<<i);
        string s="";
        while(x>0)
        {
            s+=((char)((x%10)+'0'));
            x/=10;
        }
        reverse(s.begin(), s.end());
        ss.push_back(s);
    }
    int test;
    cin>>test;
    while(test--)
    {
        cin>>s;
        int ans=20;
        for(string z: ss)
        {
            //cout<<z<<endl;
            ans=min(ans, dist(s, z));
            if(dist(s, z)==2)
            {
                //cout<<s<<endl;
                //cout<<z<<endl;
                //cout<<"d: "<<dist(s, z)<<endl;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}