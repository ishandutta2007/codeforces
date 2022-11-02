#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
int n, x, y;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>x>>y;
    cin>>s;
    reverse(s.begin(), s.end());
    int ans=0;
    for(int i=0; i<x; i++)
    {
        int d=s[i]-'0';
        if(i==y)
        {
            if(d==0) ans++;
        }
        else
        {
            if(d==1) ans++;
        }
    }
    cout<<ans<<endl;

    return 0;
}