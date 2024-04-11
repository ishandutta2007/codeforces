#include<bits/stdc++.h>
#define N 100005
#define M 3000005
#define mo 1000000007
using namespace std;
int a[N],b[N],c[N],rt[N];
int wl[N],wr[N],ls[M],rs[M];
int n,sz,q,x,y,m,ans;
struct LZHAK{int w[3][3];}t[M];
void add(int x){
	for (;x<=m;x+=x&(-x)) c[x]++;
}
int ask(int x){
	int s=0;
	for (;x;x-=x&(-x)) s+=c[x];
	return s;
}
void pushup(int x){
	int l=ls[x],r=rs[x];
	for (int i=0;i<3;i++)
		for (int j=i;j<3;j++){
			t[x].w[i][j]=(t[l].w[i][j]+t[r].w[i][j])%mo;
			for (int k=i;k<j;k++)
				t[x].w[i][j]=(t[x].w[i][j]+1ll*t[l].w[i][k]*t[r].w[k+1][j])%mo;
		}
}
void upd(int &k,int l,int r,int x,int v){
	if (!k) k=++sz;
	if (l==r){
		t[k].w[0][0]=wl[x]*v;
		t[k].w[1][1]=v;
		t[k].w[2][2]=wr[x]*v;
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid) upd(ls[k],l,mid,x,v);
	else upd(rs[k],mid+1,r,x,v);
	pushup(k);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	m=unique(b+1,b+n+1)-b-1;
	for (int i=1;i<=n;i++) 
		a[i]=lower_bound(b+1,b+m+1,a[i])-b;
	for (int i=1;i<=n;i++)
		wl[i]=ask(a[i]),add(a[i]);
	memset(c,0,sizeof(c));
	for (int i=n;i;i--)
		wr[i]=ask(a[i]),add(a[i]);
	for (int i=1;i<=n;i++)
		upd(rt[a[i]],1,n,i,1);
	for (int i=1;i<=m;i++)
		ans=(ans+t[rt[i]].w[0][2])%mo;
	scanf("%d",&q);
	while (q--){
		scanf("%d%d",&x,&y);
		ans=(ans-t[rt[a[y]]].w[0][2]+mo)%mo;
		if (x==2) upd(rt[a[y]],1,n,y,1);
		else upd(rt[a[y]],1,n,y,0);
		ans=(ans+t[rt[a[y]]].w[0][2])%mo;
		printf("%d\n",ans);
	}
}