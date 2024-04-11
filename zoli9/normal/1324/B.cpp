#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n;
int b[5009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n;
        bool ans=false;
        for(int i=1; i<=n; i++)
        {
            b[i]=0;
        }
        int last=0;
        for(int i=1; i<=n; i++)
        {
            int a;
            cin>>a;
            if(b[a]>1 || (b[a]==1 && last!=a))
            {
                ans=true;
            }
            b[a]++;
            last=a;
        }
        if(ans) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }


    return 0;
}