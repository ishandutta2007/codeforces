#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long LL;
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc() {
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read() {
	int x=0;
	char ch=gc();
	bool positive=1;
	for (; !isdigit(ch); ch=gc())if(ch=='-')positive=0;
	for (; isdigit(ch); ch=gc())x=x*10+ch-'0';
	return positive?x:-x;
}
inline void write(int a) {
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a) {
	if(a<0) {
		a=-a;
		putchar('-');
	}
	write(a);
	puts("");
}
const int N=1000;
int n,ans,x[N],y[N],xx,yy;
char s[N][N];
void calc() {
	xx=yy=0;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			if (s[i][j]=='0'^(i&1)^(j&1))xx++;
			else yy++;
}
signed main() {
	n=read();
	for (int i=1; i<=n; i++)scanf("%s",s[i]+1);
	calc();
	x[1]=xx;
	y[1]=yy;
	for (int i=1; i<=n; i++)scanf("%s",s[i]+1);
	calc();
	x[2]=xx;
	y[2]=yy;
	for (int i=1; i<=n; i++)scanf("%s",s[i]+1);
	calc();
	x[3]=xx;
	y[3]=yy;
	for (int i=1; i<=n; i++)scanf("%s",s[i]+1);
	calc();
	x[4]=xx;
	y[4]=yy;
	if (n%2==1) {
		ans=x[1]+x[2]+x[3]+x[4];
		y[1]-=x[1];
		y[2]-=x[2];
		y[3]-=x[3];
		y[4]-=x[4];
		sort(y+1,y+5);
		ans+=y[1];
		ans+=y[2];
		writeln(ans);
	} else writeln(min(x[1]+x[2]+x[3]+x[4],y[1]+y[2]+y[3]+y[4]));
}