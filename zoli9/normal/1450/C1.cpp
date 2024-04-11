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

char b[309][309];

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
        vi db(3, 0);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>b[i][j];
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(b[i][j]=='X')
                {
                    db[(i+j)%3]++;
                }
            }
        }
        int maxi=0;
        if(db[1]<db[maxi]) maxi=1;
        if(db[2]<db[maxi]) maxi=2;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(b[i][j]=='X')
                {
                    if((i+j)%3==maxi) cout<<'O';
                    else cout<<'X';
                }
                else
                {
                    cout<<'.';
                }
            }
            cout<<endl;
        }
    }
    return 0;
}