#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//(double)clock() / CLOCKS_PER_SEC;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        int db[2];
        db[0]=0;
        db[1]=0;
        for(int i=0; i<n; i++)
        {
            int x;
            cin>>x;
            db[x-1]++;
        }
        bool ok=true;
        if(db[0]%2==1) ok=false;
        if(db[0]==0 && db[1]%2==1) ok=false;
        if(ok) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    return 0;
}