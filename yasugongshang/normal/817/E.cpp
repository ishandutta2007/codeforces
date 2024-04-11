#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct data{
	int nexta[2]; int countx;
}f[3000000];
int cnt=1,sum,hi=28,ycl[30];
inline void zero(int x){
	memset(f[x].nexta,0,sizeof(f[x].nexta));
	f[x].countx=0;
}
inline void build(int x,int zs){
	int p=0,t; sum+=zs;
	for (int i=hi;i>=0;i--) {
		t=x&ycl[i]; if(t)t=1;//cout<<p<<" "<<t<<" "<<f[p].nexta[t]<<endl;
		if (f[p].nexta[t]==0){
			f[p].nexta[t]=cnt;
			zero(cnt);cnt++;
		}
		p=f[p].nexta[t];
		f[p].countx+=zs;
	}
}
inline int findx(int x,int di){
	int p=0,t,sum=0;
	for (int i=hi;i>=0;i--){
		t=x&ycl[i]; if(t)t=1;if(di&ycl[i])t^=1; else if(f[p].nexta[t^1])sum+=f[f[p].nexta[t^1]].countx; //cout<<sum<<" "<<p<<" "<<i<<" "<<t<<" "<<f[p].nexta[t^1]<<endl;
		p=f[p].nexta[t];
		if (p==0) return sum;
	}//
	return sum+f[p].countx;
}
inline void write(int a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
inline int	read(){
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
int main(){
	zero(0); ycl[0]=1; for(int i=1;i<=hi;i++)ycl[i]=ycl[i-1]<<1;
	int q=read();
	while(q--){
		int s1=read();
		if(s1<3)build(read(),s1==1?1:-1); else{
			int zs=read(); //cout<<sum<<endl;
			writeln(sum-findx(zs,read()));
		}
	}
}