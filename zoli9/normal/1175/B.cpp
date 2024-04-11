#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
int n;
ll ans;
ll fr[100009];
string s[100009];
vector<ll> v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>s[i];
        if(s[i]=="for") cin>>fr[i];
    }
    ll tms=1;
    ll dbrossz=0;
    for(int i=1; i<=n; i++)
    {
        if(s[i]=="add")
        {
            if(dbrossz>0)
            {
                cout<<"OVERFLOW!!!"<<endl;
                return 0;
            }
            ans+=tms;
            if(ans>((1ll)<<(32))-1)
            {
                cout<<"OVERFLOW!!!"<<endl;
                return 0;
            }
        }
        else if(s[i]=="for")
        {
            if(dbrossz>0 || tms*fr[i]>((1ll)<<(32))-1)
            {
                dbrossz++;
            }
            else
            {
                tms*=fr[i];
                v.push_back(fr[i]);
            }
        }
        else
        {
            if(dbrossz>0) dbrossz--;
            else
            {
                tms/=v.back();
                v.pop_back();
            }
        }
    }
    cout<<ans<<endl;


    return 0;
}