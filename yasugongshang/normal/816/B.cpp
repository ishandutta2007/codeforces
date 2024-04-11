
 #include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring> 
const int N=2000005;
int k,q,zs[N],sum,m,a[N],ans,t,s1,s2,ss,n,c[N],i;
using namespace std;
inline int lowbit(int x){
	return x&(-x);
}
inline void change(int i,int de){
	int j=i;
	while (j<=n){
		c[j]+=de;
		j+=lowbit(j);
	}
}
inline int getsum(int i){
	int zs=0; int j=i;
	while (j){
		zs+=c[j]; //out<<j<<endl;
		j-=lowbit(j);
	}
	return zs;
}
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
inline void write(int a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
int main(){
	m=read(); k=read(); q=read(); n=200000;
	while(m--){
		int l=read(),r=read();
		zs[l]++; zs[r+1]--;
	}
	for(i=1;i<=n;i++){
		sum+=zs[i]; 
		a[i]=(sum>=k);//if(i==92)cout<<a[i]<<endl;
	}
	for(int i=1;i<=n;i++)change(i,a[i]);
	while(q--){
		int l=read(),r=read();
		writeln(getsum(r)-getsum(l-1));
	}
}