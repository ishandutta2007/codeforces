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
const int N=805;
int n;
int Ask(vi p){
	printf("?");
	printf(" %u",p.size());
	for (auto i : p)
		printf(" %d",i);
	puts("");
	fflush(stdout);
	return read();
}
int a[N],p[N],odd[N];
void Answer(){
	printf("!");
	if (a[1]>n/2)
		For(i,1,n)
			a[i]=n-a[i]+1;
	For(i,1,n)
		printf(" %d",a[i]);
	puts("");
	fflush(stdout);
	exit(0);
}
pii GetST(vi p){
	vi res,x;
	For(i,0,(int)p.size()-1){
		x=p,swap(x[i],x.back()),x.pop_back();
		if (Ask(x))
			res.pb(p[i]);
	}
	return mp(res[0],res[1]);
}
vi allp;
void erase(vi &a,int v){
	For(i,0,(int)a.size()-1)
		if (a[i]==v){
			swap(a[i],a.back());
			a.pop_back();
			break;
		}
}
void Get1(){
	pii pr=GetST(allp);
	erase(allp,pr.fi);
	erase(allp,pr.se);
	a[pr.fi]=1,p[1]=pr.fi;
	a[pr.se]=n,p[n]=pr.se;
}
int Mod3(int i){
	int res=-1;
	if (Ask({p[1],p[2],i}))
		res=3;
	else if (Ask({p[1],p[3],i}))
		res=4;
	else
		res=5;
	return (3-res%3)%3;
}
int Mod5(int i){
	int res=-1;
	if (Ask({p[1],p[2],p[n],p[n-1],i}))
		res=3+n+n-1;
	else if (Ask({p[1],p[3],p[n],p[n-1],i}))
		res=4+n+n-1;
	else if (Ask({p[1],p[4],p[n],p[n-1],i}))
		res=5+n+n-1;
	else if (Ask({p[2],p[4],p[n],p[n-1],i}))
		res=6+n+n-1;
	else
		res=7+n+n-1;
	return (5-res%5)%5;
}
int Mod7(int i){
	int res=-1;
	if (Ask({p[1],p[2],p[3],p[n-3],p[n-2],p[n-1],i}))
		res=0+n+n+n;
	else if (Ask({p[1],p[2],p[4],p[n-3],p[n-2],p[n-1],i}))
		res=1+n+n+n;
	else if (Ask({p[1],p[3],p[4],p[n-3],p[n-2],p[n-1],i}))
		res=2+n+n+n;
	else if (Ask({p[2],p[3],p[4],p[n-3],p[n-2],p[n-1],i}))
		res=3+n+n+n;
	else if (Ask({p[2],p[3],p[4],p[n-3],p[n-2],p[n],i}))
		res=4+n+n+n;
	else if (Ask({p[2],p[3],p[4],p[n-3],p[n-1],p[n],i}))
		res=5+n+n+n;
	else
		res=6+n+n+n;
	return (7-res%7)%7;
}
int Mod4(int i){
	int res=-1;
	if (odd[i]){//4k+1 and 4k+3
		if (Ask({p[1],p[2],p[4],i}))
			res=1;
		else
			res=3;
	}
	else {//4k and 4k+2
		if (Ask({p[1],p[2],p[3],i}))
			res=2;
		else
			res=0;
	}
	return res;
}
int Mod8(int i){
	int res=-1;
	int m4=Mod4(i);
	if (m4==0){
		if (Ask({p[n],p[n-1],p[n-2],p[n-3],p[1],p[2],p[3],i}))
			res=0;
		else
			res=4;
	}
	else if (m4==3){
		if (Ask({p[n],p[n-1],p[n-2],p[n-3],p[1],p[2],p[4],i}))
			res=7;
		else
			res=3;
	}
	else if (m4==2){
		if (Ask({p[n],p[n-1],p[n-2],p[n-3],p[1],p[3],p[4],i}))
			res=6;
		else
			res=2;
	}
	else if (m4==1){
		if (Ask({p[n],p[n-1],p[n-2],p[n-3],p[2],p[3],p[4],i}))
			res=5;
		else
			res=1;
	}
	return res;
}
int Solve(int p){
	int m3=Mod3(p),m5=Mod5(p),m7=Mod7(p),m8=Mod8(p);
	For(i,1,n)
		if (i%3==m3&&i%5==m5&&i%7==m7&&i%8==m8){
			a[p]=i;
			return 1;
		}
	return 0;
}
int main(){
	n=read();
	For(i,1,n)
		allp.pb(i);
	Get1();
	for (auto i : allp)
		odd[i]=Ask({p[1],i});
	For(k,2,min(4,n/2)){
		pii pr=GetST(allp);
		erase(allp,pr.fi);
		erase(allp,pr.se);
		if (odd[pr.fi]==(~k&1))
			swap(pr.fi,pr.se);
		a[pr.fi]=k,p[k]=pr.fi;
		a[pr.se]=n-k+1,p[n-k+1]=pr.se;
	}
	if (allp.empty())
		Answer();
	for (auto i : allp)
		Solve(i);
	Answer();
	return 0;
}