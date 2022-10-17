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
const int M=(1<<12)+10,B=(1<<8),Q=(1<<16);
int n,q,a[M],tot,X[M*B*4],Y[M*B*4],p[M],ans[Q];
int merge(int x,int y){
	if (!x || !y) return x|y;
	int nx=++tot;
	X[nx]=x; Y[nx]=y;
	return nx;	
}
struct segment{
	int sz;
	vector<int> t; vector<vector<int> > id;
	void init(int x){
		t.resize(x);
		sz=x;
		id.resize(x);
		F(i,0,x-1) id[i].resize(x);
	}
	segment (int x=0){
		if (x){
			init(1);
			t[0]=p[x];
			id[0][0]=p[x];
		}
	}
	int ask(int l,int r){
		if (!sz || r<t.front() || l>t.back()) return 0;
		l=lower_bound(t.begin(),t.end(),l)-t.begin();
		r=upper_bound(t.begin(),t.end(),r)-t.begin()-1;
		return (l<=r ? id[l][r] : 0);
	}
}t[M/B];
segment mg(segment A,segment B){
	segment C;
	C.init(A.sz+B.sz);			
	merge(A.t.begin(),A.t.end(),B.t.begin(),B.t.end(),C.t.begin());
	F(i,0,SZ(C.t)){
		F(j,i,SZ(C.t)){	
			C.id[i][j]=merge(A.ask(C.t[i],C.t[j]),B.ask(C.t[i],C.t[j]));
		}
	}
	return C;
}
segment solve(int l,int r){
	if (l==r) return (l);
	int mid=(l+r>>1);
	return mg(solve(l,mid),solve(mid+1,r));
}
void init(){
	F(i,1,n) p[a[i]]=i;
	F(i,0,(n-1)/B){
		int l=i*B+1,r=l+B-1;
		r=min(r,n);	
		t[i]=solve(l,r);		
	}
}
int main(){
	n=read(); q=read();
	F(i,1,n) a[i]=read();
	tot=n;
	init();
	F(i,1,q){
		int l=read(),r=read();
		F(j,0,n/B){
			int tl=j*B+1,tr=tl+B-1;
			tr=min(tr,n);
//			if (r<tl || l>tr) continue;//?
			ans[i]=merge(ans[i],t[j].ask(l,r));
		}
//		if (!ans[i]){
//			cout<<l<<" "<<r<<"  !!!\n";	
//			assert(ans[i]);
//
//		}
	}
	cout<<tot<<'\n';
	F(i,n+1,tot){
		cout<<X[i]<<" "<<Y[i]<<"\n"; 
	}
	F(i,1,q){
		assert(ans[i]);
		cout<<ans[i]<<"\n";
	}
	return 0;
}