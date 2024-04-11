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
const int M=2e5+10,O=(1<<20)-1,N=M*60,Lg=19;
int s[N],tg[N],t0[N],t1[N],L[N],R[N];
int tot,n,m;
#define mid (l+r>>1)
void pu(int x){
	s[x]=s[L[x]]+s[R[x]];
	t0[x]=t0[L[x]]|t0[R[x]];
	t1[x]=t1[L[x]]|t1[R[x]];
}
void px(int x,int y,int k){
	tg[x]^=y;
	if (y>>k&1) swap(L[x],R[x]);
	int h0=t0[x],h1=t1[x];
	t0[x]=(h0&(y^O))|(h1&y);
	t1[x]=(h1&(y^O))|(h0&y);
}
void pd(int x,int k){
	if (tg[x]){
		px(L[x],tg[x],k-1);
		px(R[x],tg[x],k-1);
		tg[x]=0;
	}
}

void ins(int &x,int k,int z){
	if (!x) x=++tot;
	if (k==-1){
		s[x]=1; t0[x]=(z^O); t1[x]=z;
		return ;
	}
	(z>>k&1 ? ins(R[x],k-1,z) : ins(L[x],k-1,z));
	pu(x);
}
void split(int &x,int &y,int l,int r,int ll,int rr,int k){
	if (!x || ll>r || rr<l) return y=0,void();
	if (ll<=l && r<=rr){
		y=x; x=0;
		return ;
	}
	pd(x,k); y=++tot;
	split(L[x],L[y],l,mid,ll,rr,k-1);
	split(R[x],R[y],mid+1,r,ll,rr,k-1);
	pu(y); pu(x);
}
void merge(int &x,int y,int k){
	if (!x || !y) return x|=y,void();
	if (k==-1) return ;
	pd(x,k); pd(y,k);
	merge(L[x],L[y],k-1);
	merge(R[x],R[y],k-1);
	pu(x);
}

void po(int x,int y,int k){
	if (k==-1 || !x) return ;
	if (!(y&t0[x]&t1[x])){
		px(x,t0[x]&y,k);
		return ;
	}
	pd(x,k);
	if ((y>>k&1) && L[x]){
//		cout<<"   hh\n";
//		cout<<s[R[x]]<<" "<<s[L[x]]<<"   no \n";
		px(L[x],(1<<k),k-1);
		merge(R[x],L[x],k-1);
		L[x]=0;
//		cout<<s[R[x]]<<" "<<s[L[x]]<<"   no \n";
	}
	po(L[x],y,k-1);
	po(R[x],y,k-1);
	pu(x);
}
int main(){
	n=read(); m=read();
	int rt=0;
	F(i,1,n){
		int x=read();
		ins(rt,Lg,x);
	}
	F(i,1,m){
		int op=read(),x=read(),y=read();
		int now=0;
		split(rt,now,0,O,x,y,Lg);
		if (op==4){
			cout<<s[now]<<"\n";
		}
		else {
			int z=read();
			if (op==3){
				px(now,z,Lg);
			}
			if (op==2){
				po(now,z,Lg);
			}
			if (op==1){
				px(now,O,Lg); po(now,z^O,Lg); px(now,O,Lg);
			}
		}
		merge(rt,now,Lg);
	}
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
	
5 2
1 2 3 4 5
2 2 3 1
4 2 5
*/