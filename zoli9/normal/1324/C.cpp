#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>s;
        int h=s.size();
        int last=h;
        int maxi=1;
        for(int i=h-1; i>=0; i--)
        {
            if(s[i]=='R')
            {
                maxi=max(maxi, last-i);
                last=i;
            }
        }
        maxi=max(maxi, last+1);
        cout<<maxi<<'\n';
    }


    return 0;
}