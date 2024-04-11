#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000005;
int n,a[N],q[N],zhan[N],top,oo=1000000005,f[N],g[N];
long long ans;
inline int read()// 
{
	int a=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	a=a*10+ch-'0';
	ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		a=a*10+ch-'0';
		ch=getchar();
	}
	return a;
}
inline void write(long long a)
{
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}top=1;
	zhan[top]=oo; q[1]=0; 
	for(int i=1;i<=n;i++){
		while(zhan[top]<=a[i]&&top)top--;
		f[i]=q[top];
		zhan[++top]=a[i]; q[top]=i;
	}
	top=1;
	zhan[top]=oo; q[1]=n+1; 
	for(int i=n;i;i--){
		while(zhan[top]<a[i]&&top)top--;
		g[i]=q[top];
		zhan[++top]=a[i]; q[top]=i;
	}
	for(int i=1;i<=n;i++)ans+=(long long)(i-f[i])*(g[i]-i)*a[i]; //cout<<ans<<endl;
	top=1;
	zhan[top]=0; q[1]=0; 
	for(int i=1;i<=n;i++){
		while(zhan[top]>=a[i]&&top)top--;
		f[i]=q[top];
		zhan[++top]=a[i]; q[top]=i;
	}
	top=1;
	zhan[top]=0; q[1]=n+1; 
	for(int i=n;i;i--){
		while(zhan[top]>a[i]&&top)top--;
		g[i]=q[top];
		zhan[++top]=a[i]; q[top]=i;
	}
	for(int i=1;i<=n;i++)ans-=(long long)(i-f[i])*(g[i]-i)*a[i];
	write(ans); puts("");
}