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
        vector<vector<char> > a(n, vector<char>(n));
        set<int> r, c;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>a[i][j];
                if(a[i][j]=='*')
                {
                    r.insert(i);
                    c.insert(j);
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            if(r.size()==2) break;
            r.insert(i);
        }
        for(int i=0; i<n; i++)
        {
            if(c.size()==2) break;
            c.insert(i);
        }
        for(int x: r)
        {
            for(int y: c)
            {
                a[x][y]='*';
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<a[i][j];
            }
            cout<<'\n';
        }
    }
    return 0;
}