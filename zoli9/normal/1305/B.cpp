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
    int h=s.size();
    int v=h-1;
    vi ans1;
    vi ans2;
    for(int i=0; i<h; i++)
    {
        if(v<i) break;
        if(s[i]!='(') continue;
        while(v>i && s[v]=='(') v--;
        if(v>i)
        {
            ans1.push_back(i+1);
            ans2.push_back(v+1);
            v--;
        }
        else break;
    }
    int a1=ans1.size();
    int a2=ans2.size();
    if(a1==0)
    {
        cout<<0<<'\n';
        return 0;
    }
    cout<<1<<'\n';
    cout<<a1+a2<<'\n';
    for(int i=0; i<a1; i++) cout<<ans1[i]<<" ";
    for(int i=a2-1; i>=0; i--) cout<<ans2[i]<<" ";
    cout<<'\n';
    return 0;
}