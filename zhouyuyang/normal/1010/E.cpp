#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define CLR(a,v) memset(a,v,sizeof(a));
using namespace std;
const int N=100005;
int n,m,Q,tot;
int xmn,ymn,zmn;
int xmx,ymx,zmx;
struct que{
	int tp,x,y,z;
}q[N*2],q2[N*2];
bool cmp(que a,que b){
	if (a.x!=b.x) return a.x<b.x;
	return a.tp<b.tp;
}
int ans[N];
int chk(int x,int l,int r,int tp){
	if (tp) return max(-1,r-x);
	return max(-1,x-l);
}
int t[N];
void change(int x,int v){
	for (;x<N;x+=x&(-x)) t[x]=min(t[x],v);
}
int ask(int x){
	int ans=1e9;
	for (;x;x-=x&(-x)) ans=min(ans,t[x]);
	return ans;
}
int main(){
	scanf("%*d%*d%*d%d%d%d",&n,&m,&Q);
	xmn=ymn=zmn=1e9;
	For(i,1,n){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		xmn=min(xmn,x); xmx=max(xmx,x);
		ymn=min(ymn,y); ymx=max(ymx,y);
		zmn=min(zmn,z); zmx=max(zmx,z);
	}
	For(i,1,m){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if (xmn<=x&&x<=xmx)
			if (ymn<=y&&y<=ymx)
				if (zmn<=z&&z<=zmx)
					return puts("INCORRECT"),0;
		q[++tot]=(que){0,x,y,z};
	}
	puts("CORRECT");
	For(i,1,Q){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if (xmn<=x&&x<=xmx)
			if (ymn<=y&&y<=ymx)
				if (zmn<=z&&z<=zmx){
					ans[i]=-1; continue;
				}
		q[++tot]=(que){i,x,y,z};
	}
	For(tpx,0,1) For(tpy,0,1) For(tpz,0,1){
		int tot2=0; CLR(t,100);
		For(i,1,tot){
			if (chk(q[i].x,xmn,xmx,tpx)==-1) continue;
			if (chk(q[i].y,ymn,ymx,tpy)==-1) continue;
			if (chk(q[i].z,zmn,zmx,tpz)==-1) continue;
			q2[++tot2].tp=q[i].tp;
			q2[tot2].x=chk(q[i].x,xmn,xmx,tpx);
			q2[tot2].y=chk(q[i].y,ymn,ymx,tpy);
			q2[tot2].z=chk(q[i].z,zmn,zmx,tpz);
		}
		sort(q2+1,q2+tot2+1,cmp);
		For(i,1,tot2)
			if (!q2[i].tp) change(q2[i].y+1,q2[i].z);
			else ans[q2[i].tp]|=(ask(q2[i].y+1)<=q2[i].z);
	} 
	For(i,1,Q)
		if (ans[i]==-1) puts("OPEN");
		else if (!ans[i]) puts("UNKNOWN");
		else puts("CLOSED");
}