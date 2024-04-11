#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005,mo=1000000007,inv2=(mo+1)>>1;
struct atom{
    int s1,s2,l;
    atom operator+(const atom&rhs){
        atom ans;
        ans.s1=(s1+rhs.s1)%mo;
        ans.s2=(s2+1ll*rhs.s1*l+rhs.s2)%mo;
        ans.l=l+rhs.l;
        return ans;
    }
};
ll a[N],w[N],ts[N<<2];
int ts2[N<<2];
atom T[N<<2];
int n,q,i,x,ans,m;ll y;
inline void maintain(int i){
    ts[i]=ts[i<<1]+ts[i<<1|1];ts2[i]=(ts2[i<<1]+ts2[i<<1|1])%mo;
    T[i]=T[i<<1]+T[i<<1|1];
}
void build(int i,int l,int r){
    if(l==r){ts[i]=w[l];ts2[i]=1ll*a[l]*w[l]%mo;T[i]=(atom){w[l],w[l],1};return;}
    int m=(l+r)>>1;
    build(i<<1,l,m);build(i<<1|1,m+1,r);
    maintain(i);
}
ll S,ss;
int query(int i,int rl,int rr,int l,int r,ll ps,ll ps2){
    if(rl==rr)return rl;
    int m=(rl+rr)>>1;
    if(r<=m)return query(i<<1,rl,m,l,r,ps,ps2);
        else if(l>m)return query(i<<1|1,m+1,rr,l,r,ps,ps2+ts[i<<1]);
                else{
                    ll ops=ps;
                    if(!ps)ps=ps2+ts[i<<1]-ss;else ps+=ts[i<<1];
                    if(ps<<1>=S)return query(i<<1,rl,m,l,m,ops,ps2);
                        else return query(i<<1|1,m+1,rr,m+1,r,ps,ps2+ts[i<<1]);
                }
}
ll sum1(int i,int rl,int rr,int l,int r){
    if(rl==l && rr==r)return ts[i];
    int m=(rl+rr)>>1;
    if(r<=m)return sum1(i<<1,rl,m,l,r);
        else if(l>m)return sum1(i<<1|1,m+1,rr,l,r);
                else return sum1(i<<1,rl,m,l,m)+sum1(i<<1|1,m+1,rr,m+1,r);
}
int sum(int i,int rl,int rr,int l,int r){
    if(rl==l && rr==r)return ts2[i];
    int m=(rl+rr)>>1;
    if(r<=m)return sum(i<<1,rl,m,l,r);
        else if(l>m)return sum(i<<1|1,m+1,rr,l,r);
                else return (sum(i<<1,rl,m,l,m)+sum(i<<1|1,m+1,rr,m+1,r))%mo;
}
void mdy(int i,int rl,int rr,int k,ll v){
    if(rl==rr){ts[i]=v;ts2[i]=1ll*v*a[rl]%mo;T[i]=(atom){v,v,1};return;}
    int m=(rl+rr)>>1;
    if(k>m)mdy(i<<1|1,m+1,rr,k,v);else mdy(i<<1,rl,m,k,v);
    maintain(i);
}
atom sum3(int i,int rl,int rr,int l,int r){
    if(rl==l && rr==r)return T[i];
    int m=(rl+rr)>>1;
    if(r<=m)return sum3(i<<1,rl,m,l,r);
        else if(l>m)return sum3(i<<1|1,m+1,rr,l,r);
                else return (sum3(i<<1,rl,m,l,m)+sum3(i<<1|1,m+1,rr,m+1,r));
}
int calc(int l,int r,ll id){
    atom gg=sum3(1,1,n,l,r);
    return (gg.s2+1ll*gg.s1*((id-1)%mo))%mo;
}
int main(){
    //freopen("s","r",stdin);freopen("3","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>q;
    for(i=1;i<=n;++i)cin>>a[i];
    for(i=1;i<=n;++i)cin>>w[i];
    build(1,1,n);
    while(q--){
        cin>>x>>y;
        if(x>0){
            if(x==y){cout<<"0\n";continue;}
            ss=x>1?sum1(1,1,n,1,x-1):0;S=sum1(1,1,n,x,y);
            int z=query(1,1,n,x,y,0,0);
            int ls=(calc(x,z,a[z]-(z-x))+mo-sum(1,1,n,x,z))%mo;
            int rs=z<y?(sum(1,1,n,z+1,y)+mo-calc(z+1,y,a[z]+1))%mo:0;
            ans=(ls+rs)%mo;
            cout<<ans<<'\n';
        }else{
            mdy(1,1,n,-x,y);
        }
    }
    return 0;
}