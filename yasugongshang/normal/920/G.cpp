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
int f[1000005];
inline int check(int sum,int x,int p){
	int ans=0;
	for(int i=1;i*i<=p;i++)if(p%i==0){
		ans+=f[i]*(sum/i-x/i); if(i*i!=p)ans+=f[p/i]*(sum/(p/i)-x/(p/i));
	}
	return ans;
}
int main(){
	int t=read(); f[1]=1;
	for(int i=2;i<=1000000;i++){
		f[i]=-1;
		for(int j=2;j*j<=i;j++)if(i%j==0){int t=i/j; if(t%j==0){f[i]=0; break;} f[i]=-f[t]; break;}
	}
	while(t--){
		int x=read(),p=read(),k=read();
		int l=1,r=1e8;
		//cout<<check(9,x,p)<<endl;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(mid,x,p)<k)l=mid+1; else r=mid;
		}
		writeln(l);
	}
}