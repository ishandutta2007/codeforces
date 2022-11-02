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
        if(n==1)
        {
            cout<<1<<'\n';
            continue;
        }
        if(n==2)
        {
            cout<<-1<<'\n';
            continue;
        }
        int d=1;
        vector<vi> answer(n+1, vi(n+1, 0));
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if((i+j)%2==0)
                {
                    answer[i][j]=d;
                    d++;
                }
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if((i+j)%2==1)
                {
                    answer[i][j]=d;
                    d++;
                }
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                cout<<answer[i][j]<<" ";
            }
            cout<<'\n';
        }
    }
    return 0;
}