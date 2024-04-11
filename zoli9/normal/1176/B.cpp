#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int test;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n;
        int x=0;
        int y=0;
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            int szam;
            cin>>szam;
            if(szam%3==0) ans++;
            else if(szam%3==1) x++;
            else y++;
        }
        int mi=min(x, y);
        ans+=mi;
        x-=mi;
        y-=mi;
        int z=max(x, y);
        ans+=(z/3);
        cout<<ans<<endl;

    }


    return 0;
}