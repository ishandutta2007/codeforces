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

char s[100010],t[100010];
int nxt[100010][26];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int T;cin>>T;
    while(T--){
        cin>>s>>t;
        int n1=strlen(s);
        int n2=strlen(t);
        int now[26];
        for(int i=0;i<26;i++)now[i]=n1;

        for(int i=n1;i>=0;i--){
            if(i!=n1)now[s[i]-'a']=i;
            for(int j=0;j<26;j++)nxt[i][j]=now[j];//,cout<<now[j]<<" ";cout<<endl;
        }
        
        int ans=1;
        int now1=-1;
        for(int i=0;i<n2;i++){
            if(nxt[0][t[i]-'a'] == n1){
                ans=-1;
                break;
            }

            int tmp=nxt[now1+1][t[i]-'a'];
            if(tmp == n1){
                ans++;
                now1=nxt[0][t[i]-'a'];
            }
            else now1 = tmp;
        }
        cout<<ans<<endl;

    }
}