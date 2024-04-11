#include<bits/stdc++.h>
using namespace std;

int T,n;

string s;

int cnt[2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>s;
        cnt[0]=cnt[1]=0;
        for(auto x:s)
            cnt[x-'0']++;
        cout<<min(cnt[0],cnt[1])-(cnt[0]==cnt[1])<<"\n";
    }
}