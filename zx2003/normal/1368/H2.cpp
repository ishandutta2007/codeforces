#include<bits/stdc++.h>
using namespace std;
inline void upi(int&a,const int&b){a>b?a=b:0;}
const int N=1e5+5;
int n,m,q,i,j,k,x,y;
char c[4][N],op[9];
struct mat{int a[2][2];};
inline mat operator*(const mat&A,const mat&B){
	static mat C;int i,j,k;memset(C.a,120,sizeof C.a);
	for(i=0;i<2;++i)for(j=0;j<2;++j)for(k=0;k<2;++k)upi(C.a[i][k],A.a[i][j]+B.a[j][k]);
	return C;
}
struct segtree{
	struct node{int l,r,m,s[2][2];bool r0,r1;mat p[2][2];}t[N*3];int O,L;
	inline void rev(int i,int o){
		for(j=0;j<2;++j)if(o==0)swap(t[i].p[0][j],t[i].p[1][j]);
			else swap(t[i].p[j][0],t[i].p[j][1]);
		swap(t[i].s[o][0],t[i].s[o][1]);
	}
	inline void upd(int i){
		for(j=0;j<2;++j)for(k=0;k<2;++k)t[i].s[j][k]=t[i<<1].s[j][k]+t[i<<1|1].s[j][k],
			t[i].p[j][k]=t[i<<1].p[j][k]*t[i<<1|1].p[j][k];
		if(t[i].r0)rev(i,0);if(t[i].r1)rev(i,1);
	}
	void build(int i,int l,int r,int z){
		t[i].l=l;t[i].r=r;t[i].m=l+r>>1;
		if(l==r){
			for(j=0;j<2;++j)for(k=0;k<2;++k)t[i].s[j][k]=(c[O+j][l]=='B')==k;
			for(j=0;j<2;++j)for(k=0;k<2;++k){
				int v=t[i].s[0][j]+t[i].s[1][k];
				t[i].p[j][k].a[0][0]=v;
				t[i].p[j][k].a[0][1]=2-v+L;
				t[i].p[j][k].a[1][0]=v+L;
				t[i].p[j][k].a[1][1]=2-v;
			}
if(l==4)
++l,--l;
			if(l==1){
				int z=0;
				for(x=1;x<=L;++x)z+=c[O^2][x]=='R';
				for(j=0;j<2;++j)for(k=0;k<2;++k)for(x=0;x<2;++x)for(y=0;y<2;++y)
					t[i].p[j][k].a[x][y]+=y==0?z:L-z;
			}
			if(r==n+m-L){
				int z=0;
				for(x=1;x<=L;++x)z+=c[O^3][x]=='R';
				for(j=0;j<2;++j)for(k=0;k<2;++k)for(x=0;x<2;++x)for(y=0;y<2;++y)
					t[i].p[j][k].a[x][y]+=y==0?z:L-z;
			}
			return;
		}
		build(i<<1,l,t[i].m,z);build(i<<1|1,t[i].m+1,r,z);upd(i);
	}
	void mdy(int i,int l,int r,int o){
		if(l<=t[i].l && t[i].r<=r)return (o==0?t[i].r0:t[i].r1)^=1,rev(i,o);
		if(l<=t[i].m)mdy(i<<1,l,r,o);if(t[i].m<r)mdy(i<<1|1,l,r,o);upd(i);
	}
	void mdy2(int i,int k,int dt){
		if(k==t[i].l && k==t[i].r){
			for(j=0;j<2;++j)for(k=0;k<2;++k)for(x=0;x<2;++x)for(y=0;y<2;++y)
				t[i].p[j][k].a[x][y]+=y==0?dt:-dt;
			return;
		}
		mdy2(i<<1|(k>t[i].m),k,dt);upd(i);
	}
}t[2];
inline void out(){
	int ans=1<<30;
	for(i=0;i<2;++i)for(j=0;j<2;++j)for(k=0;k<2;++k)upi(ans,t[i].t[1].p[0][0].a[j][k]);
	printf("%d\n",ans);
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(i=0;i<4;++i)scanf("%s",c[i]+1);
	for(j=0,i=1;i<=m;++i)j+=(c[2][i]=='R')+(c[3][i]=='R');
	t[0].O=0;t[0].L=m;t[0].build(1,1,n,j);
	for(j=0,i=1;i<=n;++i)j+=(c[0][i]=='R')+(c[1][i]=='R');
	t[1].O=2;t[1].L=n;t[1].build(1,1,m,j);
	out();
	for(;q--;){
		scanf("%s%d%d",op,&x,&y);
		if(*op=='L'){
			int ov=t[0].t[1].s[0][0];
			t[0].mdy(1,x,y,0);t[1].mdy2(1,1,t[0].t[1].s[0][0]-ov);
		}
		if(*op=='R'){
			int ov=t[0].t[1].s[1][0];
			t[0].mdy(1,x,y,1);t[1].mdy2(1,m,t[0].t[1].s[1][0]-ov);
		}
		if(*op=='U'){
			int ov=t[1].t[1].s[0][0];
			t[1].mdy(1,x,y,0);t[0].mdy2(1,1,t[1].t[1].s[0][0]-ov);
		}
		if(*op=='D'){
			int ov=t[1].t[1].s[1][0];
			t[1].mdy(1,x,y,1);t[0].mdy2(1,n,t[1].t[1].s[1][0]-ov);
		}
		out();
	}
}