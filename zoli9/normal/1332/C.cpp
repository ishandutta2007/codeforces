#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
string s;
int n, k;
int db[200009][26];
bool was[200009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        cin>>n>>k;
        cin>>s;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<26; j++)
            {
                db[i][j]=0;
            }
            was[i]=false;
        }
        int ans=0;
        for(int i=0; i<k; i++)
        {
            if(was[i]) continue;
            for(int j=i; j<n; j+=k)
            {
                db[i][s[j]-'a']++;
                was[j]=true;
            }
            int last=n-i-1;
            if(!was[last])
            {
                for(int j=last; j>=0; j-=k)
                {
                    db[i][s[j]-'a']++;
                    was[j]=true;
                }
            }
            int ossz=0;
            int maxi=0;
            for(int j=0; j<26; j++)
            {
                ossz+=db[i][j];
                maxi=max(maxi, db[i][j]);
            }
            ans+=(ossz-maxi);
            //cout<<ans<<'\n';
        }
        cout<<ans<<'\n';
    }


    return 0;
}