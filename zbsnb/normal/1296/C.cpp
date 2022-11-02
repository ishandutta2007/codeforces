#include<iostream>
#include<set>
#include<map>
using namespace std;
char s[200010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cin>>s+1;
        map<pair<int,int>,int> mp;
        pair<int,int> now={0,0};
        mp[now]=0;

        int minn=1e9;
        int l,r;
        for(int i=1;i<=n;i++){
            if(s[i]=='L')now.first--;
            if(s[i]=='R')now.first++;
            if(s[i]=='D')now.second--;
            if(s[i]=='U')now.second++;

            if(mp.find(now)!=mp.end()){
                int tmp=i-mp[now]+1;
                // cout<<tmp<<endl;
                if(tmp<minn){
                    l=mp[now];
                    r=i;
                    minn=tmp;
                }
            }

            mp[now]=i;
        }
        if(minn==1e9)cout<<"-1\n";
        else cout<<l+1<<" "<<r<<endl;
    }
}