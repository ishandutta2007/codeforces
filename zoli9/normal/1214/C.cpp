#include <bits/stdc++.h>
using namespace std;

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
    int cnt=0;
    int mini=0;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='(') cnt++;
        else cnt--;
        mini=min(mini, cnt);
    }
    if(cnt==0 && mini>=-1) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;


    return 0;
}