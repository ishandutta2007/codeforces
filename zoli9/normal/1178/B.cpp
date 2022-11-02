#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
string s;
int ww=0;
vector<ll> a;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    ll vcnt=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='v')
        {
            if(i>0 && s[i-1]=='v')
            {
                vcnt++;
            }
        }
        else
        {
            a.push_back(vcnt);
        }
    }
    ll ans=0;
    for(ll aa: a)
    {
        ans+=(aa*(vcnt-aa));
    }
    cout<<ans<<endl;

    return 0;
}