#include <bits/stdc++.h>
using namespace std;
string s;
int db=0;
long long ans=1;
long long MOD=1000000007;
int main()
{
    cin>>s;
    for(int i=0; i<s.size(); i++)
    {
        int bi;
        if('0'<=s[i] && s[i]<='9') bi=s[i]-'0';
        else if('A'<=s[i] && s[i]<='Z') bi=s[i]-'A'+10;
        else if('a'<=s[i] && s[i]<='z') bi=s[i]-'a'+36;
        else if(s[i]=='-') bi=62;
        else bi=63;
        for(int j=1; j<=6; j++)
        {
            if(bi%2==0) db++;
            bi/=2;
        }
    }
    for(int i=1; i<=db; i++)
    {
        ans*=3;
        ans%=MOD;
    }
    cout<<ans;
    return 0;
}