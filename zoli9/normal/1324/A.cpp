#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n;
        bool ptl=false;
        bool ps=false;
        for(int i=1; i<=n; i++)
        {
            int a;
            cin>>a;
            if(a%2) ptl=true;
            else ps=true;
        }
        if(ptl && ps) cout<<"NO"<<'\n';
        else cout<<"YES"<<'\n';
    }


    return 0;
}