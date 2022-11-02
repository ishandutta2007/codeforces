#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cin>>s;
    int ans=0;
    int sum=0;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='(')
        {
            sum++;
            if(sum<=0) ans++;
        }
        else
        {
            sum--;
            if(sum<0) ans++;
        }
    }
    if(sum==0) cout<<ans<<endl;
    else cout<<-1<<endl;


    return 0;
}