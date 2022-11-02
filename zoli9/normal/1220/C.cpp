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
    cin>>s;
    cout<<"Mike"<<'\n';
    char best=s[0];
    for(int i=1; i<s.size(); i++)
    {
        if(best<s[i]) cout<<"Ann"<<'\n';
        else cout<<"Mike"<<'\n';
        best=min(best, s[i]);
    }


    return 0;
}