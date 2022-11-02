#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

vi c;
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        cin>>n;
        c.resize(n);
        bool eD=false;
        bool eS=false;
        cin>>c[0];
        for(int i=1; i<n; i++)
        {
            cin>>c[i];
            if(c[i]!=c[i-1]) eD=true;
            if(c[i]==c[i-1]) eS=true;
        }
        if(c[n-1]!=c[0]) eD=true;
        if(c[n-1]==c[0]) eS=true;
        if(!eD)
        {
            cout<<1<<'\n';
            for(int i=1; i<=n; i++) cout<<1<<" ";
            cout<<'\n';
            continue;
        }
        if(n%2==0)
        {
            cout<<2<<'\n';
            for(int i=1; i<=n; i++)
            {
                if(i%2) cout<<1<<" ";
                else cout<<2<<" ";
            }
            cout<<'\n';
            continue;
        }
        if(eS)
        {
            bool sw=false;
            int last=1;
            cout<<2<<'\n';
            cout<<1<<" ";
            for(int i=1; i<n; i++)
            {
                if(sw || c[i]!=c[i-1])
                {
                    last=3-last;
                    cout<<last<<" ";
                    continue;
                }
                sw=true;
                cout<<last<<" ";
            }
            cout<<'\n';
            continue;
        }
        else
        {
            cout<<3<<'\n';
            for(int i=1; i<n; i++)
            {
                if(i%2) cout<<1<<" ";
                else cout<<2<<" ";
            }
            cout<<3<<" ";
            cout<<'\n';
            continue;
        }
    }


    return 0;
}