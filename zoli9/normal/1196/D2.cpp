#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
int test;
int n, k;
string s;
int tipus[200009];
int darab[3];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n>>k;
        cin>>s;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='R')
            {
                tipus[i]=i%3;
            }
            else if(s[i]=='G')
            {
                tipus[i]=(i+2)%3;
            }
            else
            {
                tipus[i]=(i+1)%3;
            }
        }
        for(int i=0; i<3; i++)
        {
            darab[i]=0;
        }
        int ans=n;
        for(int i=0; i<k; i++)
        {
            darab[tipus[i]]++;
            ans=min(ans, k-darab[tipus[i]]);
        }
        for(int i=k; i<n; i++)
        {
            darab[tipus[i]]++;
            darab[tipus[i-k]]--;
            ans=min(ans, k-darab[tipus[i]]);
        }
        cout<<ans<<endl;
    }
    return 0;
}