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
const int M=1e6+10,B=333;
struct Q{
	int op,l,r,x;
}b[M];
int n,m,a[M],ans[M];
int f[M],sz[M],rt[M],val[M];
int Fd(int x){
//	cerr<<x<<"\n";
	if (f[x]==x) return x;
	return f[x]=Fd(f[x]);
}
int tg,lim;
void build(int l,int r){
	lim=0;
	F(i,l,r) sz[i]=0,f[i]=i,lim=max(lim,a[i]);
	F(i,l,r){
		if (!rt[a[i]]) rt[a[i]]=i,val[i]=a[i];
		else f[i]=rt[a[i]];
		sz[f[i]]++;
	}
	tg=0;
}

void mg(int x,int y){//x->y
	if (!rt[y]) return swap(rt[x],rt[y]),val[rt[y]]=y,void();
//	cerr<<rt[y]<<" "<<Fd(rt[y])<<"   hh\n";
//	assert(rt[y]==Fd(rt[y]));
	sz[rt[y]]+=sz[rt[x]]; f[rt[x]]=rt[y]; 
	val[rt[x]]=sz[rt[x]]=0; rt[x]=0; val[rt[y]]=y; 
}

void zuo(int x){
	if (x>=lim) return ;
	if (2*x<=lim){
		DF(i,x,0) mg(i+tg,i+tg+x);
		tg+=x; lim-=x;
	}
	else{
		F(i,x+1,lim) mg(i+tg,i-x+tg);
		lim=x;
	}
}
void solve(int L,int R){
	F(i,0,100001) rt[i]=0;
	tg=0; build(L,R);
	F(o,1,m){
		
		int op=b[o].op,l=b[o].l,r=b[o].r,x=b[o].x;
		if (r<L || l>R) continue;
//		cerr<<op<<"    opop\n";
		if (op==1){
			if (l<=L && R<=r){
//				cerr<<x<<" "<<tg<<" "<<lim<<"  gan \n";
				zuo(x);
			}
			else{
				l=max(l,L); r=min(r,R);
				F(i,L,R) a[i]=val[Fd(i)],rt[a[i]]=sz[i]=0,a[i]-=tg; tg=0;
				F(i,l,r) if (a[i]>x) a[i]-=x;
				build(L,R);
			}
		}
		else{
			if (!rt[x+tg]) continue;
//			cerr<<L<<" "<<R<<"   qry\n";
			if (l<=L && R<=r){
				ans[o]+=sz[rt[x+tg]];
//				cout<<sz[rt[x+tg]]<<" "<<tg<<" "<<rt[x+tg]<<"\n";
			}
			else{
				l=max(l,L); r=min(r,R);
				F(i,l,r) if (val[Fd(i)]-tg==x) ans[o]++;
			}
		}
//		F(i,L,R){
//			cout<<val[Fd(i)]-tg<<" ";
//		}
//		cout<<"   seq \n";
	}
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	n=read(); m=read();
	F(i,1,n) a[i]=read();
	F(i,1,m){
		b[i]=(Q){read(),read(),read(),read()};
	}
//	solve(3,4);
	int l=0,r=0;
	while (1){
		l=r+1; r=min(n,l+B-1);
		solve(l,r);
		if (r==n) break;
//		cerr<<"   hh\n";
	}
	F(i,1,m){
		if (b[i].op==2){
//			cout<<ans[i]<<"\n";
			cout<<ans[i]<<"\n";
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
8 11
5 4 7 2 5 2 5 6 

1 3 7 3
1 4 8 2
1 1 5 3
1 2 6 6
1 1 5 9
1 2 5 1
1 3 8 9
1 3 7 4
1 2 7 10
2 6 6 2
2 4 6 8
*/