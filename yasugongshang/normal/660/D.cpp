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
inline char gc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x=0; char ch=gc(); bool positive=1;
	for (;!isdigit(ch);ch=gc())if(ch=='-')positive=0;
	for (;isdigit(ch);ch=gc())x=x*10+ch-'0';
	return positive?x:-x;
}
inline void write(int a){
    if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	if(a<0){
		a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=2005;
long long ans;
int x[N],y[N],n;
map<pair<int,int>,int> M;
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		x[i]=read(); y[i]=read();
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int t1=x[i]-x[j],t2=y[i]-y[j];
			if(t1<0)t1=-t1,t2=-t2; else if(t1==0)t2=abs(t2);
			ans+=M[mp(t1,t2)];
			M[mp(t1,t2)]++;
		}
	}
	cout<<ans/2<<endl;
}