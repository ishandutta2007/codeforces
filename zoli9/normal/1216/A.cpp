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
string ans="";
int a;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cin>>s;
    for(int i=0; i<n; i+=2)
    {
        if(s[i]==s[i+1])
        {
            ans+="ab";
            a++;
        }
        else
        {ans+=s[i];
        ans+=s[i+1];
        }
    }
    cout<<a<<endl;
    cout<<ans<<endl;


    return 0;
}