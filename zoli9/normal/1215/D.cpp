#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
string s;
int a, b;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cin>>s;
    for(int i=0; i<n/2; i++)
    {
        if(s[i]!='?')
        {
            int x=s[i]-'0';
            x*=2;
            x-=9;
            a+=x;
        }
    }
    for(int i=n/2; i<n; i++)
    {
        if(s[i]!='?')
        {
            int x=s[i]-'0';
            x*=2;
            x-=9;
            b+=x;
        }
    }
    //cout<<a<<" "<<b<<endl;
    if(a==b) cout<<"Bicarp"<<endl;
    else cout<<"Monocarp"<<endl;


    return 0;
}