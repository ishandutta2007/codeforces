#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int k=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){k=k*10+ch-'0';ch=getchar();}
	return k*f;
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
int n,r,a[1010];
double b[1010];
inline double sqr(double x){return x*x;}
int main(){
	n=read();r=read();
	for(int i=1;i<=n;i++){
		a[i]=read(); b[i]=r;
		for(int j=1;j<i;j++)if(a[i]-a[j]<=2*r)
		b[i]=max(b[i],b[j]+2*sqrt(sqr(r)-sqr((double)(a[i]-a[j])/2)));
		printf("%.8lf ",b[i]);
	}
}