#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
int n, k;
int db[509];
int w[509];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    int maxi=0;
    for(int i=1; i<=k+1; i++)
    {
        cout<<"?";
        for(int j=1; j<=k+1; j++)
        {
            if(i==j) continue;
            cout<<" "<<j;
        }
        cout<<endl;
        fflush(stdout);
        int ansi, X;
        cin>>ansi>>X;
        db[ansi]++;
        w[ansi]=X;
        if(X>w[maxi]) maxi=ansi;
    }
    cout<<"! "<<db[maxi]<<endl;
    fflush(stdout);
    return 0;
}