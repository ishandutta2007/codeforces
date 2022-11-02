#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
                    For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
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
const int N=2000006;
const LL INF=4.5e18;
void NO(){
	puts("NO");
	exit(0);
}
void ckmin(LL &a,LL b){
	if (a>b)
		a=b;
}
void ckmax(LL &a,LL b){
	if (a<b)
		a=b;
}
int n,L;
struct Node{
	LL t,x,y,p;
}a[N];
bool cmp(Node a,Node b){
	return a.p<b.p;
}
LL U(LL a,LL b){
	return a>=0?(a+b-1)/b:a/b;
}
LL D(LL a,LL b){
	return a>=0?a/b:(a-b+1)/b;
}
char res[N];
int cly=0;
int main(){
	n=read(),L=read();
	if (n==1000&&L==2000000)
		cly=1;
	For(i,1,n){
		a[i].t=read(),a[i].x=read(),a[i].y=read();
		a[i].p=a[i].t%L;
		if ((a[i].x+a[i].y+a[i].t)%2!=0)
			NO();
	}
	++n,a[n].t=a[n].x=a[n].y=a[n].p=0;
	++n,a[n]=a[n-1],a[n].p=L;
	sort(a+1,a+n+1,cmp);
	LL minp=-L,maxp=L,minm=-L,maxm=L;
	For(i,1,n-1){
		LL dx=a[i+1].x-a[i].x,dy=a[i+1].y-a[i].y;
		LL k=((a[i+1].t-a[i+1].p)-(a[i].t-a[i].p))/L;
		LL t=a[i+1].p-a[i].p;
		if (k<0)
			k=-k,dx=-dx,dy=-dy;
		if (k!=0){
			ckmax(minp,U(dx+dy-t,k));
			ckmin(maxp,D(dx+dy+t,k));
			ckmax(minm,U(dx-dy-t,k));
			ckmin(maxm,D(dx-dy+t,k));
		}
		else {
			if (t<abs(dx)+abs(dy))
				NO();
		}
	}
	LL dx,dy;
	int flag=0;
	for (LL i=minp;!flag&&i<=maxp;i++)
		if ((i+L)%2==0)
			for (LL j=minm;!flag&&j<=maxm;j++){
				LL x=i+j,y=i-j;
				if (x%2==0&&y%2==0)
					flag=1,dx=x/2,dy=y/2;
			}
	if (!flag)
		NO();
	For(i,1,n){
		LL k=(a[i].t-a[i].p)/L;
		a[i].x-=k*dx,a[i].y-=k*dy;
	}
	For(i,1,n-1){
		int t0=a[i].p,t1=a[i+1].p;
		LL x=a[i+1].x-a[i].x,y=a[i+1].y-a[i].y;
		assert(t1-t0>=abs(x)+abs(y));
		while (x>0)
			res[t0++]='R',x--;
		while (x<0)
			res[t0++]='L',x++;
		while (y>0)
			res[t0++]='U',y--;
		while (y<0)
			res[t0++]='D',y++;
		while (t0<t1)
			res[t0++]='L',res[t0++]='R';
		assert(t0==t1);
	}
	puts(res);
	return 0;
}