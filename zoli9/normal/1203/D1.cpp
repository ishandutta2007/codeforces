#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll g=-1;
int eleje[200009];
int vege[200009];
string s, t;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s>>t;
    int hs=s.size();
    int ht=t.size();
    int cnt=0;
    for(int i=0; i<ht; i++)
    {
        while(s[cnt]!=t[i]) cnt++;
        eleje[i]=cnt;
        cnt++;
    }
    cnt=hs-1;
    for(int i=ht-1; i>=0; i--)
    {
        while(s[cnt]!=t[i]) cnt--;
        vege[i]=cnt;
        cnt--;
    }
    int ans=hs-eleje[ht-1]-1;
    ans=max(ans, vege[0]);
    for(int i=0; i<ht-1; i++)
    {
        int cans=vege[i+1]-eleje[i]-1;
        ans=max(ans, cans);
    }
    cout<<ans<<endl;
    return 0;
}