#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int test;
int kezd[300009];
int veg[300009];
vector<int> best;
int infi=100000009;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n;
        best.clear();
        for(int i=1; i<=n; i++)
        {
            kezd[i]=0;
            veg[i]=0;
        }
        for(int i=1; i<=n; i++)
        {
            int szam;
            cin>>szam;
            if(kezd[szam]==0)
            {
                kezd[szam]=i;
                veg[szam]=i;
            }
            else
            {
                veg[szam]=i;
            }
        }
        int db=0;
        int elozo=0;
        int cnt=0;
        int maxcnt=0;
        for(int i=1; i<=n; i++)
        {
            if(kezd[i]==0) continue;
            db++;
            if(kezd[i]>elozo)
            {
                cnt++;
                maxcnt=max(maxcnt, cnt);
                elozo=veg[i];
            }
            else
            {
                cnt=1;
                elozo=veg[i];
            }
        }
        cout<<db-maxcnt<<endl;
    }


    return 0;
}