#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned uint;
typedef long double LD;
typedef vector <int> vi;
typedef pair <int,int> pii;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=2e6+5;
int n,m;
char a[N],b[N],s[N];
int va[N],vb[N];
void getext(char *a,int *ext,int n){
	For(i,0,n)
		ext[i]=0;
	ext[1]=n;
	int L=0,R=0;
	For(i,2,n){
		ext[i]=max(0,min(R-i+1,ext[i-L+1]));
		while (i+ext[i]<=n&&a[i+ext[i]]==a[1+ext[i]])
			ext[i]++;
		if (i+ext[i]-1>=R)
			L=i,R=i+ext[i]-1;
	}
//	cout<<a+1<<endl;
//	outarr(ext,1,n);
}
void calc_a(){
	static char sa[N];
	static int ext[N];
	For(i,1,m)
		sa[i]=s[i];
	For(i,1,n)
		sa[i+m]=a[i];
	getext(sa,ext,n+m);
	For(i,1,n)
		va[i]=min(ext[i+m],m-1);
}
void calc_b(){
	static char sb[N];
	static int ext[N];
	For(i,1,m)
		sb[i]=s[m-i+1];
	For(i,1,n)
		sb[i+m]=b[n-i+1];
	getext(sb,ext,n+m);
	For(i,1,n)
		vb[n-i+1]=min(ext[i+m],m-1);
}
LL c0[N],c1[N];
void add(int x,LL v0,LL v1){
	for (;x;x-=x&-x)
		c0[x]+=v0,c1[x]+=v1;
}
pair <LL,LL> ask(int x){
	pair <LL,LL> ans=mp(0,0);
	for (;x<=m+1;x+=x&-x)
		ans.fi+=c0[x],ans.se+=c1[x];
	return ans;
}
int main(){
	n=read(),m=read();
	scanf("%s%s%s",a+1,b+1,s+1);
	calc_a(),calc_b();
//	outarr(va,1,n);outarr(vb,1,n);
	LL ans=0;
	Fod(i,n,1){
		add(vb[i]+1,vb[i],1);
		if (i+m-1<=n)
			add(vb[i+m-1]+1,-vb[i+m-1],-1);
		pair <LL,LL> now=ask(1+max(0,-(va[i]-m+1)));
		ans+=now.se*(va[i]-m+1)+now.fi;
	}
	cout<<ans<<endl;
	return 0;
}