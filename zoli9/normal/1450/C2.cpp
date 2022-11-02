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
        vector<vi> db(3, vi(3, 0));
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
                    db[(i+j)%3][(i+j+1)%3]++;
                    db[(i+j)%3][(i+j+2)%3]++;
                }
                else if(b[i][j]=='O')
                {
                    db[(i+j+1)%3][(i+j)%3]++;
                    db[(i+j+2)%3][(i+j)%3]++;
                }
            }
        }
        int m1=0;
        int m2=1;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(i==j) continue;
                if(db[i][j]<db[m1][m2])
                {
                    m1=i;
                    m2=j;
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(b[i][j]=='X')
                {
                    if((i+j)%3==m1) cout<<'O';
                    else cout<<'X';
                }
                else if(b[i][j]=='O')
                {
                    if((i+j)%3==m2) cout<<'X';
                    else cout<<'O';
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