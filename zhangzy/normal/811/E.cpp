#include<bits/stdc++.h>
using namespace std;

struct V{
	int v[10];
}a[101000];
int n,m,T;

namespace tr{
	struct P{
		V le,ri;
		int ans,fa[20];
		int GF(int x){
			return x==fa[x]?x:fa[x]=GF(fa[x]);
		}
		void UN(int x,int y){
			if (GF(x)!=GF(y)) fa[fa[x]]=fa[y];
		}
	}p[404000];
	
	int Cnt(V x){
		int t=1;
		for (int i=1;i<m;i++) 
			t+=x.v[i]!=x.v[i-1];
		return t;
	}
	
	int f[44];
	int Gf(int x){
		return x==f[x]?x:f[x]=Gf(f[x]);
	}
	void un(int x,int y){
		if (Gf(x)!=Gf(y)) f[f[x]]=f[y];
	}
	
	P operator + (P p1,P p2){
		P res;
		res.le=p1.le;
		res.ri=p2.ri;
		res.ans=p1.ans+p2.ans;
		
		for (int i=0;i<20;i++) res.fa[i]=i;
		
		for (int i=0;i<20;i++){
			f[i]=p1.fa[i];
			f[i+20]=p2.fa[i]+20;
		}
		for (int i=0;i<m;i++){
			if (p1.ri.v[i]==p2.le.v[i]){
				if (Gf(i+10)!=Gf(i+20)){
					res.ans--;
					un(i+10,i+20);
				}
			}
		}
		
		for (int i=0;i<m;i++)
			for (int j=i+1;j<m;j++)
				if (Gf(i)==Gf(j))
					res.UN(i,j);
		for (int i=0;i<m;i++)
			for (int j=i+1;j<m;j++)
				if (Gf(i+30)==Gf(j+30))
					res.UN(i+10,j+10);
		
		for (int i=0;i<m;i++)
			for (int j=0;j<m;j++)
				if (Gf(i)==Gf(j+30))
					res.UN(i,j+10);
		
		return res;
	}
	
	void B(int x,int l,int r){
		if (l==r){
			p[x].le=p[x].ri=a[l];
			p[x].ans=Cnt(a[l]);
			for (int i=0;i<10;i++) p[x].fa[i]=i+10;
			for (int i=10;i<20;i++) p[x].fa[i]=i;
			for (int i=1;i<m;i++)
				if (a[l].v[i]==a[l].v[i-1])
					p[x].UN(i,i-1);
			return;
		}
		int mid=l+r>>1;
		B(x<<1,l,mid);
		B(x<<1|1,mid+1,r);
		p[x]=p[x<<1]+p[x<<1|1];
	}
	
	P Q(int x,int l,int r,int st,int en){
		if (l==st&&r==en) return p[x];
		int mid=l+r>>1;
		if (en<=mid) return Q(x<<1,l,mid,max(st,l),min(en,mid));
		if (st>mid) return Q(x<<1|1,mid+1,r,max(st,mid+1),min(en,r));
		return Q(x<<1,l,mid,max(st,l),min(en,mid))+Q(x<<1|1,mid+1,r,max(st,mid+1),min(en,r));
	}
}

int main(){
	scanf("%d%d%d",&m,&n,&T);
	for (int i=0;i<m;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&a[j].v[i]);
	tr::B(1,1,n);
	for (int x,y;T--;printf("%d\n",tr::Q(1,1,n,x,y).ans)) scanf("%d%d",&x,&y);
}