#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int n;
bool a[100009];
bool b[100009];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            a[i]=false;
            b[i]=false;
        }
        for(int i=1; i<=n; i++)
        {
            int m;
            cin>>m;
            for(int j=1; j<=m; j++)
            {
                int x;
                cin>>x;
                if(!a[i] && !b[x])
                {
                    a[i]=true;
                    b[x]=true;
                }
            }
        }
        int a1=0;
        int b1=0;
        for(int i=1; i<=n; i++)
        {
            if(!a[i]) a1=i;
            if(!b[i]) b1=i;
        }
        if(a1==0) cout<<"OPTIMAL"<<'\n';
        else
        {
            cout<<"IMPROVE"<<'\n';
            cout<<a1<<" "<<b1<<'\n';
        }
    }


    return 0;
}