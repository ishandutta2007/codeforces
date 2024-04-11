#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
bool z=false;
ll sum=0;
int n;
int par=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        ll a;
        cin>>a;
        if(a==0)
        {
            z=true;
            sum++;
        }
        else if(a>0) sum+=(a-1);
        else
        {
            par++;
            sum+=(-1-a);
        }
    }
    if(z) cout<<sum<<endl;
    else
    {
        if(par%2) cout<<sum+2<<endl;
        else cout<<sum<<endl;
    }

    return 0;
}