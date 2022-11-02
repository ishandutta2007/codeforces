#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n;
int db[10];
int rendes(int x)
{
    if(x==4) return 1;
    if(x==8) return 2;
    if(x==15) return 3;
    if(x==16) return 4;
    if(x==23) return 5;
    return 6;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        int szam;
        cin>>szam;
        szam=rendes(szam);
        if(szam==1) db[1]++;
        else
        {
            if(db[szam]==db[szam-1])
            {
                ans++;
            }
            else db[szam]++;
        }
    }
    for(int i=1; i<=5; i++)
    {
        ans+=(db[i]-db[6]);
    }
    cout<<ans<<endl;

    return 0;
}