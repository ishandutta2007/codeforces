#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline LL read(){
	char ch=getchar(); LL w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const LL inf=2e18;
const int M=2e5+10;
struct Item{
	LL num,w,v;
	int id;
}a[M];
bool cmp(Item A,Item B){
	return A.v==B.v ? A.w<B.w : A.v>B.v; 
}
LL ans,now,br;
struct SGT{
	LL sm[M<<2],bg[M<<2],sv[M<<2];
	int lim;
	#define lc (x<<1)
	#define rc (x<<1|1)
	#define mid (l+r>>1)
	void mk(int x,Item A){
		sm[x]=sv[x]=0; bg[x]=inf;
		if (A.w<=lim){
			sv[x]=A.num*A.v;
			sm[x]=A.num*A.w;
		}
		else{
			if (A.w<=lim*2 && A.num) bg[x]=A.w;
		}
	}
	void pu(int x){
		sm[x]=sm[lc]+sm[rc];
		sv[x]=sv[lc]+sv[rc];
		bg[x]=min(bg[lc],sm[lc]+bg[rc]);
	}
	void build(int x,int l,int r){
		if (l==r){
			mk(x,a[l]);
			return ;
		}
		build(lc,l,mid);
		build(rc,mid+1,r);
		pu(x);
	}
	void upd(int x,int l,int r,int p){
		if (l==r){
			mk(x,a[l]);
			return ;
		}
		if (p<=mid) upd(lc,l,mid,p);
		else upd(rc,mid+1,r,p);
		pu(x);
	}
	void query(int x,int l,int r,int ll,int rr){
		if (now<lim || rr<l || ll>r) return ;
		if (ll<=l && r<=rr){
			if (l==r){
				LL cs=min(a[l].num,now/a[l].w);
				now-=cs*a[l].w;
				ans+=cs*a[l].v;
				br=l;
				return ;
			}
			if (now>=bg[x]){
				query(lc,l,mid,ll,rr);
				query(rc,mid+1,r,ll,rr);
				return ;
			}
			if (now>=sm[x]){
				now-=sm[x],ans+=sv[x];
				br=r;
				return ;
			}
			if (now>=sm[lc]){
				now-=sm[lc],ans+=sv[lc];
				br=mid;
				query(rc,mid+1,r,ll,rr);
			}
			else query(lc,l,mid,ll,rr);
			return ;
		}
		query(lc,l,mid,ll,rr);
		query(rc,mid+1,r,ll,rr);
	}
}t[20];
int n,L,p[M];
int main(){
	n=read(); int m=read();
	LL mx=0;
	F(i,1,n){
		a[i]=(Item){read(),read(),read(),i};
		mx=max(mx,a[i].w);
	}
	sort(a+1,a+n+1,cmp);
	F(i,1,n) p[a[i].id]=i;
	while (mx) L++,mx>>=1;
	F(i,0,L){
		t[i].lim=(1<<i);
		t[i].build(1,1,n);
	}
	while (m--){
		int op=read();
		if (op<=2){
			int y=read(),x=read();
			x=p[x];
			y=(op==1 ? y : -y);
			a[x].num+=y;
			F(i,0,L) t[i].upd(1,1,n,x);
		}
		else{
			now=read(); ans=0; br=0;
			DF(i,L,0){
				t[i].query(1,1,n,br+1,n);
				if (br==n) break;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/