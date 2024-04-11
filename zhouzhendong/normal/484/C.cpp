#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define kill _z_kill
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
#define User_Time ((double)clock()/CLOCKS_PER_SEC)
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
template <class T> void ckmax(T &x,T y){
	if (x<y)
		x=y;
}
template <class T> void ckmin(T &x,T y){
	if (y<x)
		x=y;
}
//int Pow(int x,int y){
//	int ans=1;
//	for (;y;y>>=1,x=(LL)x*x%mod)
//		if (y&1)
//			ans=(LL)ans*x%mod;
//	return ans;
//}
//void Add(int &x,int y){
//	if ((x+=y)>=mod)
//		x-=mod;
//}
//void Del(int &x,int y){
//	if ((x-=y)<0)
//		x+=mod;
//}
//int Add(int x){
//	return x>=mod?x-mod:x;
//}
//int Del(int x){
//	return x<0?x+mod:x;
//}
const int N=1e6+6;
namespace bru{
int n;
int a[N];
int b[N];
void shuffle(int *a,int k,int d){
	int cnt=0;
	For(i,0,d-1)
		for (int j=i;j<k;j+=d)
			b[cnt++]=a[j];
	/*
		t=k/d,r=k%d;
		j:
		j%d<r: j%d*(t+1)+j/d
		else : j%d*(t+1)+j/d-(j%d-r)
		 -1
		-1 -> -1;
	*/
		int t=k/d,r=k%d;
	For(i,0,k-1){
		int x=i%d*(t+1)+i/d-max(i%d-r,0);
		assert(b[x]==a[i]);
	}
	For(i,0,k-1)
		a[i]=b[i];
}
int main(){
	n=read();
	For(i,0,n-1)
		a[i]=i;
	int k=read(),d=read();
	For(i,0,n-k){
		shuffle(a+i,k,d);
	}
	outarr(a,0,n-1);
	return 0;
}
}


int n,m;
char a[N],b[N];
int nxt[N][20];
int main(){
	scanf("%s",a);
	n=strlen(a);
	m=read();
	while (m--){
		int k=read(),d=read();
		int t=k/d,r=k%d,sp=k;
		For(i,0,k-1){
			nxt[i][0]=i%d*(t+1)+i/d-max(i%d-r,0);
			nxt[i][0]-=1;
			if (nxt[i][0]==-1)
				nxt[i][0]=sp;
		}
		nxt[sp][0]=sp;
		For(j,1,19)
			For(i,0,k)
				nxt[i][j]=nxt[nxt[i][j-1]][j-1];
		For(i,0,n-1){
			int timein,inpos,timeall;
			if (i<k){
				timein=0,inpos=i,timeall=n-k+1-timein;
			}
			else {
				timein=i-k+1,inpos=k-1,timeall=n-k+1-timein;
			}
			int now=inpos,timeused=0;
			Fod(i,19,0)
				if (timeused+(1<<i)<=timeall&&nxt[now][i]!=sp)
					now=nxt[now][i],timeused+=1<<i;
			if (timeused<timeall){
				timeused++;
				now=-1;
				b[timein+now+timeused]=a[i];
			}
			else {
				b[timein+now+timeused]=a[i];
			}
		}
		For(i,0,n-1)
			swap(a[i],b[i]);
		For(i,0,n-1)
			putchar(a[i]);
		puts("");
	}
	return 0;
}