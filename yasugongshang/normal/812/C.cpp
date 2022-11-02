#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
inline int	read()// 
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
const int N=100005;
int n,m,l,r,sum,an,a[N],b[N];
inline bool check(int x){
	for(int i=1;i<=n;i++){long long zs=a[i]+(long long)i*x; if(zs>m)zs=m+1; b[i]=(int)zs;}
	sort(&b[1],&b[n+1]);
	for(int i=1;i<=x;i++){sum+=b[i]; if(sum>m)return 0;}
	an=sum;
	return 1;
}
int main(){
	n=read(); m=read(); 
	for(int i=1;i<=n;i++)a[i]=read();
	l=0; r=n;
	while(l<r){
		int mid=(l+r)>>1;mid++; sum=0;
		if(check(mid))l=mid; else r=mid-1; //cout<<mid<<" "<<sum<<endl;
	}
	cout<<l<<" "<<an<<endl;
}