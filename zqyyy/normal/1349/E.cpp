#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
    ll f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
#define pii pair<int,ll>
#define fi first
#define se second
const int N=2e5+7;
struct lr{int l,r,t;ll v;}b[N];
int n,m,cnt,typ,c[N],f[N][2];
ll t[N];bool flg[N];pii a[N];
inline ll Get(int l,int r){
    return 1ll*(l+r)*(r-l+1)/2;
}
inline bool ck(ll d,int l,int r){
    if(d<=0)return !d;
    int L=1,R=r-l+1;
    while(L<=R){
	int mid=(L+R)>>1;
	if(Get(l,l+mid-1)<=d)L=mid+1;
	else R=mid-1;
    }
    if(!R)return 0;
    return d<=Get(r-R+1,r);
}
int pre[N][2];
vector<int>num[N][2];
inline void upd(ll d,int k,int i,int j,int j1){
    f[i][j]=k,pre[i][j]=j1,num[i][j].clear();
    num[i][j].push_back(k);
    if(!d)return;
    int l=b[i].r+1,r=f[i-1][j1]-1,L=1,R=r-l+1;
    while(L<=R){
	int mid=(L+R)>>1;
	if(Get(l,l+mid-1)<=d)L=mid+1;
	else R=mid-1;
    }
    d-=Get(l,l+R-1);
    int tot=r-(l+R-1);
    for(int o=l+R-1;o>=l;o--)
	if(d>=tot)num[i][j].push_back(o+tot),d-=tot;
	else num[i][j].push_back(o+d),d=0;
}
int main(){
    n=read();
    for(int i=1;i<=n;i++){
	t[i]=read();
	if(t[i])a[++cnt]={n-i+1,t[i]},flg[n-i+1]=1;
    }
    reverse(a+1,a+cnt+1);
    a[cnt+1].se=1e18;
    for(int i=cnt;i;i--){
	if(a[i].se==a[i+1].se)b[m].l=a[i].fi,b[m].t=0;//c_l=0
	else if(a[i].se==a[i+1].se-1)b[m].l=a[i].fi,b[m].t=1,b[m].v--;//c_l=1
	else b[++m]={a[i].fi,a[i].fi,2,a[i].se};//c_l=0/1
    }
    b[m+1]={-1,-1,0,0};
    f[0][0]=-1,f[0][1]=n+1;
    for(int i=1;i<=m;i++){
	f[i][0]=f[i][1]=-1;
	for(int j=0;j<2;j++)
	    if(f[i-1][j]>b[i].r){
		if(!b[i].t || b[i].t==2){
		    ll d=b[i].v-1-(b[i-1].v-1+j);//d=t_{f_{i,j'}}-t_{f_{i+1,j}}
		    for(int k=b[i].l-1;k>b[i+1].r && k>f[i][0];k--)
			if(ck(d-k,b[i].r+1,f[i-1][j]-1)){upd(d-k,k,i,0,j);break;}
		}
		if((b[i].t==1 || b[i].t==2) && f[i][1]<0){
		    ll d=b[i].v-(b[i-1].v-1+j);
		    if(ck(d-b[i].l,b[i].r+1,f[i-1][j]-1))upd(d-b[i].l,b[i].l,i,1,j);
		}
	    }
    }
    if(f[m][0]<0 && f[m][1]<0){
	for(int j=0;j<2;j++)
	    if(f[m-1][j]>b[m].r){
		ll d=b[m].v-1-(b[m-1].v-1+j);
		for(int i=b[m].r;i>=b[m].l && i>f[m][0];i--){
		    if(flg[i])continue;
		    if(ck(d-i,b[m].r+1,f[m-1][j]-1)){upd(d-i,i,m,0,j);break;}
		}
	    }
    }
    int o=f[m][1]>0;
    for(int i=m;i;i--){
	for(int x:num[i][o])c[x]=1;
	o=pre[i][o];
    }
    for(int i=1;i<=n;i++)printf("%d",c[n-i+1]);
    return 0;	
}