#include<iostream>
using namespace std;
#define ll long long
ll t[800010],laze[800010];
#define ls rt<<1
#define rs rt<<1|1
#define mid (l+r>>1)
void php(int rt){t[rt]=t[ls]+t[rs];}
void phd(int rt,int l,int r){
    if(laze[rt]==0)return;

    t[ls]+=laze[rt]*(mid-l+1);
    t[rs]+=laze[rt]*(r-mid);

    laze[ls]+=laze[rt];
    laze[rs]+=laze[rt];

    laze[rt]=0;
}
ll que(int rt,int l,int r,int x){
    if(l>r)return 0;
    if(l==r)return t[rt];
    phd(rt,l,r);
    if(x<=mid)return que(ls,l,mid,x);
    return que(rs,mid+1,r,x);
}
void upd(int rt,int l,int r,int x,int y,int val){
    if(l>r)return;
    if(x<=l&&r<=y){
        t[rt]+=val*(r-l+1);
        laze[rt]+=val;
        return;
    }
    phd(rt,l,r);
    if(x<=mid)upd(ls,l,mid,x,y,val);
    if(y>mid)upd(rs,mid+1,r,x,y,val);
    php(rt);
}
int a[200010];
int main(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++)cin>>a[i];
    ll sum=0;
    for(int i=1;i<m;i++){
        if(a[i]==a[i+1])continue;
        sum+=abs(a[i]-a[i+1]);
        if(a[i]<a[i+1]){
            upd(1,1,n,a[i],a[i],a[i]-1);
            upd(1,1,n,a[i+1],a[i+1],a[i]*2-a[i+1]);
        }
        else{
            upd(1,1,n,a[i],a[i],2*a[i+1]-a[i]);
            upd(1,1,n,a[i+1],a[i+1],a[i+1]-1);
        }
        upd(1,1,n,min(a[i],a[i+1])+1,max(a[i],a[i+1])-1,-1);
    }
    for(int i=1;i<=n;i++)cout<<sum+que(1,1,n,i)<<" ";cout<<endl;
}