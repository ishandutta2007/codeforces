#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n;
vector<pair<ll, ll> > t;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    t.resize(n);
    for(int i=0; i<n; i++)
    {
        cin>>t[i].F>>t[i].S;
    }
    if(n%2==1)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    int fele=n/2;
    for(int i=1; i<fele; i++)
    {
        if(t[i].F-t[0].F!=t[fele].F-t[fele+i].F)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        if(t[i].S-t[0].S!=t[fele].S-t[fele+i].S)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}