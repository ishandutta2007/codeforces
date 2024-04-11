#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin>>n>>m;
    if(n>m || (n-m)%2)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    if(n==m)
    {
        if(n==0) cout<<"0"<<endl;
        else cout<<"1"<<endl<<n<<endl;
        return 0;
    }
    ll x=(m-n)/2;
    if((x^(n+x))==n)
    {
        cout<<"2"<<endl;
        cout<<x<<" "<<n+x<<endl;
        return 0;
    }
    cout<<"3"<<endl;
    cout<<n<<" "<<x<<" "<<x<<endl;
    return 0;
}