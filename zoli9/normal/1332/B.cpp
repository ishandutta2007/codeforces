#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

vi primes={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

int color[19];
int colcnt;
int ans[1009];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    int n;
    while(test--)
    {
        for(int i=0; i<11; i++) color[i]=0;
        colcnt=0;
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            int x;
            cin>>x;
            for(int j=0; j<11; j++)
            {
                if(x%primes[j]==0)
                {
                    if(color[j]==0)
                    {
                        colcnt++;
                        color[j]=colcnt;
                    }
                    ans[i]=color[j];
                    break;
                }
            }
        }
        cout<<colcnt<<'\n';
        for(int i=1; i<=n; i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<'\n';
    }


    return 0;
}