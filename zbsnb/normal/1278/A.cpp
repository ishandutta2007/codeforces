#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define vc vector
#define pb push_back
#define pii pair<int,int>
#define pll pait<ll,ll>
#define ft first
#define sd second
// #define int long long

ll mypow(ll a,ll b,ll mod){
    ll ret=1;
    while(b){
        if(b&1)ret=ret*a%mod;
        a=a*a%mod;b>>=1;
    }
    return ret;
}

char s1[1000],s2[1000];
int cnt1[26],cnt2[26];
signed main(){
    int t;cin>>t;
    while(t--){
        cin>>s1>>s2;
        int m=strlen(s1);
        int n=strlen(s2);
        int flg=1;
        for(int b=0;b<n;b++){
            for(int i=0;i<26;i++)cnt1[i]=cnt2[i]=0;
            for(int i=0;s1[i];i++){
                cnt1[s1[i]-'a']++;
            }
            for(int i=b;i<b+m&&s2[i];i++){
                cnt2[s2[i]-'a']++;
            }

            flg=1;
            for(int i=0;i<26;i++){
                if(cnt1[i]!=cnt2[i]){
                    flg=0;
                    break;
                }
            }
            if(flg){
                cout<<(flg?"YES":"NO")<<endl;
                break;
            }
        }
        if(!flg)cout<<"NO"<<endl;
    }
}