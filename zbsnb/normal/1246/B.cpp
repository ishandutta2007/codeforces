#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>

using namespace std;
#define ll long long
ll mypow(ll a,ll b,ll mod){
    ll ret=1;
    while(b){
        if(b)ret=ret*a%mod;
        a=a*a%mod;b>>=1;
    }
    return ret;
}
int a[100010];
typedef vector<pair<int,int> > vp; 
vp b[100010];
bool pd(vp a,int k){
    int ret=1;
    for(int i=0;i<a.size();i++){
        if(2*a[i].second%k!=0){
            ret=0;
            break;
        }
    }
    return ret;
}
map<vp, int> mp;
signed main(){
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        int tmp=a[i];
        for(int j=2;j<=400;j++){
            if(tmp%j==0){
                int cnt=0;
                while(tmp%j==0){
                    cnt++;
                    tmp/=j;
                }
                if(cnt%k!=0)b[i].push_back({j,cnt%k});
            }
        }
        if(tmp!=1){
            b[i].push_back({tmp,1});
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(b[i].size()!=0){
            mp[b[i]]++;
        }
        else cnt++;
    }
    ll ans=1ll*(cnt-1)*cnt;
    //cout<<ans<<endl;
    ll tcnt=0;
    for(int i=1;i<=n;i++){
        if(b[i].size()==0)continue;
        vp tmp;
        for(int j=0;j<b[i].size();j++){
            if(k-b[i][j].second!=k)
                tmp.push_back({b[i][j].first,k-b[i][j].second});
        }
        tcnt+=mp[tmp];
    }
    ans+=tcnt;
    //cout<<ans<<endl;
    for(int i=1;i<=n;i++){
        if(b[i].size()==0)continue;
        if(pd(b[i],k))ans--;
    }
    cout<<ans/2<<endl;
}