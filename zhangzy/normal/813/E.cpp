#include<bits/stdc++.h>
#define N 101000
#define MX 1010
#define sz 100
using namespace std;

int T,n,k,a[N],val[MX][MX],cnt[N],an,bel[N],tot,L[MX],R[MX];
struct B{
	int id,aa;
}b[N];
int pos[N],st[N],en[N],las=0;

int que(int l,int r,int v){
	int p1,p2;
	p1=lower_bound(pos+st[v],pos+en[v]+1,l)-pos;
	p2=lower_bound(pos+st[v],pos+en[v]+1,r+1)-pos;
	return max(p2-p1,0);
}

bool cmp(B b1,B b2){
	return b1.aa==b2.aa? b1.id<b2.id: b1.aa<b2.aa;
}

int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		b[i]=(B){i,a[i]};
	}
	sort(b+1,b+n+1,cmp);
	for (int i=1;i<=n;i++){
		pos[i]=b[i].id;
		if (!st[b[i].aa]) st[b[i].aa]=i;
		en[b[i].aa]=i;
	}
	
	for (int i=1;i<=n;i++){
		tot=bel[i]=(i-1)/sz;
	}
	for (int i=0;i<=tot;i++){
		L[i]=i*sz+1;
		R[i]=(i+1)*sz;
	}
	R[tot]=n;
	
	int now;
	for (int u=0;u<=tot;u++){
		now=L[u];
		memset(cnt,0,sizeof cnt);
		an=0;
		for (int v=u;v<=tot;v++){
			for (;now<=R[v];now++){
				if (cnt[a[now]]<k){
					cnt[a[now]]++;
					an++;
				}
			}
			val[u][v]=an;
		}
	}
	
	memset(cnt,0,sizeof cnt);
	int l,r,b1,b2,p1,p2;
	for (scanf("%d",&T);T--;printf("%d\n",las)){
		scanf("%d%d",&l,&r);
		l=(l+las)%n+1; r=(r+las)%n+1;
		if (l>r) swap(l,r);
		
		b1=bel[l]; b2=bel[r];
		if (b1==b2){
			las=0;
			p1=l; p2=l-1;
		}else{
			las=val[b1+1][b2-1];
			p1=L[b1+1]; p2=R[b2-1];
		}
		for (;p1>l;p1--) if (que(p1,p2,a[p1-1])<k) las++;
		for (;p2<r;p2++) if (que(p1,p2,a[p2+1])<k) las++;
	}
}