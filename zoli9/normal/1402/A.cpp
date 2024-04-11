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
    ll n;
    cin>>n;
    vll a(n);
    for(int i=0; i<n; i++)
    {
      cin>>a[i];
    }
    if(n==1)
    {
      cout<<"1 1"<<'\n';
      cout<<-a[0]<<'\n';
      cout<<"1 1"<<'\n';
      cout<<0<<'\n';
      cout<<"1 1"<<'\n';
      cout<<0<<'\n';
      return 0;
    }
    vll a1, a2, a3;
    a1.push_back(-n*a[0]);
    a2.push_back((n-1)*a[0]);
    for(int i=1; i+1<n; i++)
    {
      a1.push_back(-n*a[i]);
      a2.push_back((n-1)*a[i]);
      a3.push_back(0);
    }
    a1.push_back(-n*a[n-1]);
    a3.push_back((n-1)*a[n-1]);
    cout<<1<<" "<<n<<'\n';
    for(ll x: a1) cout<<x<<" ";
    cout<<'\n';
    cout<<1<<" "<<n-1<<'\n';
    for(ll x: a2) cout<<x<<" ";
    cout<<'\n';
    cout<<2<<" "<<n<<'\n';
    for(ll x: a3) cout<<x<<" ";
    cout<<'\n';
    


    return 0;
}