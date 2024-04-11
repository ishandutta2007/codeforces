
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define vc vector
#define pb push_back
#define pii pair<int,int>
#define pll pait<ll,ll>
#define ft first
#define sd second
#define up(it,vec) for(auto it=vec.begin();it!=vec.end();it++)
#define dn(it,vec) for(auto it=vec.rbegin();it!=vec.rend();it++)
// #define int long long
 
ll mypow(ll a,ll b,ll mod){
    ll ret=1;
    while(b){
        if(b&1)ret=ret*a%mod;
        a=a*a%mod;b>>=1;
    }
    return ret;
}
 
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int a,b;cin>>a>>b;
        char s[a+10][b+10];
        for(int i=1;i<=a;i++)cin>>s[i]+1;
        int cnt=0;
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                cnt+=s[i][j]=='A';
            }
        }
        if(cnt==0){
            cout<<"MORTAL\n";
            continue;
        }
        else if(cnt==a*b){
            cout<<"0\n";
            continue;
        }
        if(s[1][1]=='A'||s[a][1]=='A'||s[1][b]=='A'||s[a][b]=='A'){
 
            int now1=1,now2=1,now3=1,now4=1;
            for(int i=1;i<=a;i++){
                if(s[i][1]=='P')now1=0;
                if(s[i][b]=='P')now2=0;
            }
            for(int i=1;i<=b;i++){
                if(s[1][i]=='P')now3=0;
                if(s[a][i]=='P')now4=0;
            }
            int flg=now1|now2|now2|now3|now4;
 
            if(flg)cout<<"1\n";
            else cout<<"2\n";
        }
        else{
 
            int flg=0;
            for(int i=1;i<=a;i++){
                int now=1;
                for(int j=1;j<=b;j++){
                    if(s[i][j]=='P')now=0;
                }
                flg|=now;
            }
            for(int i=1;i<=b;i++){
                int now=1;
                for(int j=1;j<=a;j++){
                    if(s[j][i]=='P')now=0;
                }
                flg|=now;
            }
 
            int flg2=0;
            for(int i=1;i<=a;i++){
                flg2|=s[i][1]=='A';
                flg2|=s[i][b]=='A';
            }
            for(int i=1;i<=b;i++){
                flg2|=s[1][i]=='A';
                flg2|=s[a][i]=='A';
            }
 
            if(flg)cout<<"2\n";
            else if(flg2) cout<<"3\n";
            else cout<<"4\n";
 
        }
    }
}