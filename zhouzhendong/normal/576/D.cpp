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
const int N=155,M=155;
int n,m;
struct Mat{
	bitset <N> v[N];
	Mat(){}
	Mat(int x){
		For(i,1,n)
			v[i].reset();
		if (x)
			For(i,1,n)
				v[i][i]=1;
	}
	friend Mat operator * (Mat a,Mat b){
		Mat c(0);
		For(i,1,n)
			For(k,1,n)
				if (a.v[i][k])
					c.v[i]|=b.v[k];
		return c;
	}
	void Out(){
		printf("Matrix {\n");
		For(i,1,n){
			printf("    ");
			For(j,1,n)
				putchar('0'+v[i][j]);
			puts("");
		}
		puts("}\n");
	}
}pre,mat(0),st[35];
struct Edge{
	int x,y,d;
}e[M];
bool cmp(Edge a,Edge b){
	return a.d<b.d;
}
int main(){
	n=read(),m=read();
	pre=Mat(1);
	For(i,1,m)
		e[i].x=read(),e[i].y=read(),e[i].d=read();
	m++;
	e[m].x=n,e[m].y=n,e[m].d=0;
	m++;
	e[m].x=n,e[m].y=n,e[m].d=1.05e9;
	sort(e+1,e+m+1,cmp);
	int now=0;
//	pre.Out(),mat.Out();
	For(i,1,m){
		int x=e[i].x,y=e[i].y,d=e[i].d;
		if (d==now){
			mat.v[x][y]=1;
			continue;
		}
		int c=0;
		st[c]=mat;
		while ((1<<(c+1))<=d)
			c++,st[c]=st[c-1]*st[c-1];
		int ans=d+1;
		Fod(i,c,0){
			if (now+(1<<i)>d)
				continue;
			Mat tmp=pre*st[i];
			if (tmp.v[1][n])
				ans=min(ans,now+(1<<i));
			else {
				now+=1<<i;
				pre=tmp;
			}
		}
		if (ans<=d)
			return printf("%d\n",ans),0;
		mat.v[x][y]=1;
//		outval(x),outval(y),outval(d),outval(c),outval(now);
//		outval(ans);
//		pre.Out(),mat.Out();
	}
	puts("Impossible");
	return 0;
}