#include<bits/stdc++.h>
using namespace std;
const int N=150005;
typedef long long ll;
int n,i,x,a[N],ia[N];ll ans;
struct atom{int m0,m1,c;};
inline atom operator+(atom A,atom B){
	if(A.m0<B.m0)swap(A,B);
	return A.m0==B.m0?(atom){A.m0,max(A.m1,B.m1),A.c+B.c}:(atom){A.m0,max(A.m1,B.m0),A.c};
}
struct T{
int bi[N];
inline void add(int x){for(;x<=n;x+=x&-x)++bi[x];}
inline int ask(int x){int ans=0;for(;x;x-=x&-x)ans+=bi[x];return ans;}
static const int M=N<<2;
atom t[M];int ov[M];
inline void fix(int x,int y){if(t[x].m0>t[y].m0)t[x].m0=t[y].m0;}
inline void pushdown(int i){if(ov[i]>t[i].m0)fix(i<<1,i),fix(i<<1|1,i),ov[i]=t[i].m0;}
inline void upd(int i){t[i]=t[i<<1]+t[i<<1|1];ov[i]=t[i].m0;}
void mdy(int i,int l,int r,int ql,int qr,int v){
	int m=l+r>>1;
	if(ql<=l && r<=qr){
		if(v>=t[i].m0)return;
		if(v<t[i].m1)pushdown(i),mdy(i<<1,l,m,ql,qr,v),mdy(i<<1|1,m+1,r,ql,qr,v),upd(i);
			else ans-=1ll*t[i].c*(ask(t[i].m0)-ask(v)),t[i].m0=v;
		return;
	}
	pushdown(i);if(ql<=m)mdy(i<<1,l,m,ql,qr,v);if(qr>m)mdy(i<<1|1,m+1,r,ql,qr,v);upd(i);
}
void set(int i,int k,int l,int r){
	if(l==k && r==k){t[i]=(atom){n,0,1};return;}
	int m=l+r>>1;pushdown(i);if(k<=m)set(i<<1,k,l,m);else set(i<<1|1,k,m+1,r);upd(i);
}
}A,B;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;for(i=1;i<=n;++i)cin>>a[i],ia[a[i]]=i;
	for(i=1;i<T::M;++i)A.ov[i]=B.ov[i]=N;
	for(i=1;i<=n;++i){
		x=ia[i];if(x>1)A.mdy(1,1,n,1,x-1,x-1);if(x<n)B.mdy(1,1,n,1,n-x,n-x);
		A.add(x);B.add(n-x+1);A.set(1,x,1,n);B.set(1,n-x+1,1,n);
		ans+=i;cout<<ans<<'\n';
	}
	return 0;
}