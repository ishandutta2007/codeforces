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
    int k;
    cin>>k;
    int masik=1;
    while(masik<=k) masik*=2;
    int nagy=k+masik;
    cout<<3<<" "<<3<<'\n';
    cout<<nagy<<" "<<k<<" "<<0<<'\n';
    cout<<masik<<" "<<nagy<<" "<<k<<'\n';
    cout<<0<<" "<<k<<" "<<k<<'\n';


    return 0;
}