#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string s;
vector<char> ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    int i=0;
    int j=s.size();
    j--;
    while(i+3<=j)
    {
        if(s[i]==s[j])
        {
            ans.push_back(s[i]);
        }
        else if(s[i+1]==s[j])
        {
            ans.push_back(s[i+1]);
        }
        else if(s[i]==s[j-1])
        {
            ans.push_back(s[i]);
        }
        else
        {
            ans.push_back(s[i+1]);
        }
        i+=2;
        j-=2;
    }
    for(char cc: ans) cout<<cc;
    if(i<=j) cout<<s[i];
    reverse(ans.begin(), ans.end());
    for(char cc: ans) cout<<cc;
    cout<<endl;

    return 0;
}