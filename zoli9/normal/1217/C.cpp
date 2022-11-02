#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int test;
string s;
int t[200009];
int elozo[200009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>s;
        int n=s.size();
        int el=0;
        for(int i=0; i<n; i++)
        {
            t[i+1]=s[i]-'0';
            if(t[i+1]==1)
            {
                elozo[i+1]=el;
                el=i+1;
            }
        }
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            if(t[i]==0) continue;
            int maxhely=i-elozo[i];
            int ertek=1;
            int j=i;
            while(j<=n && ertek<=maxhely)
            {
                ans++;
                j++;
                ertek*=2;
                ertek+=t[j];
                maxhely++;
            }
        }
        cout<<ans<<endl;
    }


    return 0;
}