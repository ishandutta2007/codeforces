#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int test;
ll n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n;
        ll h=2;
        while(h*(h-1)/2<=n) h++;
        h--;
        ll het=n-h*(h-1)/2;
        cout<<"133";
        for(int i=1; i<=het; i++) cout<<"7";
        for(int i=1; i<=h-2; i++) cout<<"3";
        cout<<"7"<<endl;
    }

    return 0;
}