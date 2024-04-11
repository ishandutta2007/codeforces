#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n, k;
int maxi;
vi v[200009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        int szam;
        cin>>szam;
        maxi=max(maxi, szam);
        int c=0;
        while(szam>0)
        {
            v[szam].push_back(c);
            c++;
            szam/=2;
        }
        v[0].push_back(c);
    }
    int ans=-1;
    for(int i=0; i<=maxi; i++)
    {
        sort(v[i].begin(), v[i].end());
        if(v[i].size()<k) continue;
        int kell=0;
        for(int j=0; j<k; j++) kell+=v[i][j];
        if(ans==-1 || kell<ans) ans=kell;
    }
    cout<<ans<<endl;


    return 0;
}