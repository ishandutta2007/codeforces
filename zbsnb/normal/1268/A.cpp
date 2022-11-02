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

char a[200010];
char now[200010];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,k;cin>>n>>k>>a;
    for(int i=0;i<k;i++){
        now[i]=a[i];
    }
    int flg=1;
    for(int i=0;i<n;i++){
        if(now[i%k]>a[i]){
           break;
        }
        if(now[i%k]<a[i]){
            flg=0;
            break;
        }
    }
    // now[k]=0;cout<<now<<endl;
    if(!flg){
        if(now[k-1]=='9'){
            now[k-1]='0';
            for(int i=k-2;i>=0;i--){
                if(now[i]=='9')now[i]='0';
                else{
                    now[i]++;
                    break;
                }
            }
        }
        else now[k-1]++;

    }
    // now[k]=0;cout<<now<<endl;
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        cout<<now[i%k];
    }
    cout<<endl;
}