#include <iostream>
#define ll long long

using namespace std;

ll gcd_gate(ll,ll);
ll gcd(ll,ll);

int main()
{
    ll n,m,k; cin>>n>>m>>k;
    bool flag=!(k%2);
    if(flag) k/=2;
    int g=gcd_gate(n,k);
    n/=g; k/=g;
    if(m%k)
    {
        cout<<"NO";
        return 0;
    }
    m/=k;
    if(!flag)
    {
        (g>2)?(n*=2):(m*=2);
    }
    cout<<"YES"<<endl;
    cout<<"0 0"<<endl;
    cout<<n<<" 0"<<endl;
    cout<<"0 "<<m<<endl;
    return 0;
}

ll gcd_gate(ll x,ll y)
{
    if(x>y) return gcd(x,y);
    else return gcd(y,x);
}

ll gcd(ll x,ll y)
{
    if(y==0) return x;
    return gcd(y,x%y);
}