#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=5e5+10;
int n,a[M],pre[M],ml[M],mr[M],val[M],pos[M],ty[M];
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
int mn[M<<3],tg[M<<3];
void pu(int x){
	mn[x]=min(mn[lc],mn[rc])-tg[x];
}
void build(int x,int l,int r){
	tg[x]=0;
	if (l==r){
		mn[x]=val[l];
		return ;
	}
	build(lc,l,mid); build(rc,mid+1,r);
	pu(x); 
}
void upd(int x,int l,int r,int ll,int rr){
	if (ll>rr) return;
	if (l==ll && r==rr){
		tg[x]++; mn[x]--;
		return;
	}
	if (rr<=mid) upd(lc,l,mid,ll,rr);
	else if (ll>mid) upd(rc,mid+1,r,ll,rr);
	else upd(lc,l,mid,ll,mid),upd(rc,mid+1,r,mid+1,rr);
	pu(x);
}
void clr(){
	F(i,0,n) pre[i]=ty[i]=ml[i]=mr[i]=pos[i]=0;
}
void solve(){
	clr();
	n=read();
	F(i,1,n){
		a[i]=read();
		pre[i]=pre[i-1]+(!a[i]);
	}
	int cz=pre[n];
	if (cz<=1){
		cout<<"0\n";
		return ;
	}
	F(i,1,n){
		ty[i]=(pre[i]<=cz/2 ? 1 : 2);
	}
//	return ;
	F(i,1,n) ml[i]=mr[i]=-1;
	F(i,1,n) if (ty[i]==1) ml[a[i]]=i;
	DF(i,n,1) if (ty[i]==2) mr[a[i]]=i;
	int totcol=0;
	F(i,1,n) if (ml[i]!=-1 || mr[i]!=-1) totcol++;
	int numr=0;
	val[0]=totcol;
	DF(i,n,1){
		if (ty[i]==2){
			if (!a[i]){
				numr++;
				val[numr]=numr+totcol;	
			}
			pos[i]=numr;
//			cout<<i<<" "<<numr<<"   hhh\n";
		}
	}
//	return ; 
	build(1,0,numr);
	
	F(i,1,n) if (ml[i]==-1 && mr[i]!=-1) 
	upd(1,0,numr,pos[mr[i]],numr);
	pu(1);
//	return ;
	int ans=min(cz/2,mn[1]),now=0;
	F(i,1,n){
		if (ty[i]==1){
			if (a[i]){
				if (ml[a[i]]==i){
					if (mr[a[i]]!=-1){
						int x=pos[mr[a[i]]];
						upd(1,0,numr,x,numr);
					}
					else now--;
				}
			}
			else now++;
		}
		pu(1);
		ans=min(ans,now+mn[1]);
	}
	cout<<ans<<"\n";
}
int main(){
	int T=read();
	while (T--) solve();
	return 0;
}
/*
1
40
6 0 0 0 0 0 0 0 30 0 0 0 0 38 0 13 1 0 8 10 0 32 30 0 34 22 0 0 0 0 0 25 33 34 0 6 0 33 0 0

12
*/