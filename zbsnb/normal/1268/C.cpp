#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define vc vector
#define pb push_back
#define sz(x) ((int)x.size())
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
 
ll h[200010],n;
#define lowb(x) ((x)&(-x))
void upd(int x){
    for(int i=x;i<=n;i+=lowb(i))h[i]++;
}
ll que(int x){
    ll ret=0;
    for(int i=x;i>=1;i-=lowb(i))ret+=h[i];
    return ret;
}
 
int pos[200010];
 
signed main(){

    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;;
    for(int i=1;i<=n;i++){
        int tmp;cin>>tmp;
        pos[tmp]=i;
    }
    ll ans=0;
    set<int> l;
    set<int> r;
    ll sum=0;
    for(int i=1;i<=n;i++){
        
        set<int>::reverse_iterator tmp1=l.rbegin();
        set<int>::iterator tmp2=r.begin();
 
 
        if(tmp1==l.rend()||tmp2==r.end()){
            if(tmp1==l.rend()){
                l.insert(pos[i]);
            }
            else{
                int lpos=*tmp1;
                // cout<<lpos<<" "<<pos[i]<<endl;
                if(pos[i]>lpos)
                    r.insert(pos[i]);
                else{
                    l.erase(lpos);
                    l.insert(pos[i]);
                    r.insert(lpos);
                }
                sum+=abs(pos[i]-lpos)-1;
            }
        }
        else{
            int lpos=*tmp1;
            int rpos=*tmp2;
 
            // cout<<i<<" "<<lpos<<" "<<rpos<<endl;
 
            if(l.size()<r.size()){
                if(pos[i]<rpos){
                    sum+=rpos-pos[i]-int(l.size())-1;
                    l.insert(pos[i]);
                }
                else{
                    sum+=pos[i]-rpos-int(r.size());
                    r.insert(pos[i]);
                    l.insert(rpos);
                    r.erase(rpos);
                }
            }
 
            else if(l.size()>r.size()){
                if(pos[i]>lpos){
                    sum+=pos[i]-lpos-int(r.size())-1;
                    r.insert(pos[i]);
                }
                else{
                    sum+=lpos-pos[i]-int(l.size());
                    l.insert(pos[i]);
                    l.erase(lpos);
                    r.insert(lpos);
                }
            }
 
            else{
                if(pos[i]<lpos){
                    sum+=lpos-pos[i]-int(l.size());
                    l.insert(pos[i]);
                }
                else if(pos[i]>rpos){
 
                    // cout<<pos[i]<<" "<<rpos<<endl;
 
                    sum+=pos[i]-rpos-int(r.size());
                    r.insert(pos[i]);
                }
                else {
                    sum-=int(l.size());
                    l.insert(pos[i]);
                }
            }
 
        }
 
        // cout<<"sum:"<<sum<<"xx"<<endl;
 
        ll tmp=que(pos[i]);
        ans+=i-1-tmp;
        cout<<ans+sum<<" ";
        upd(pos[i]);
    }
    cout<<endl;
}