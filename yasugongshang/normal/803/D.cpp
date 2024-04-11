#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
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
int k,n,a[1000005],last,l,r,mid;
char s[1000005];
inline bool check(int x){
	int zs=0,sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]>x)return false;
		sum+=a[i];
		if(sum>x){
			sum=a[i]; if(++zs>=k)return false;
		}
	}
	return true;
}
int main(){
	scanf("%d",&k); scanf("\n"); last=-1;
	gets(s); s[strlen(s)]='-'; int len=strlen(s); 
	for(int i=0;i<len;i++){
		if(s[i]=='-'||s[i]==' '){
			a[++n]=i-last; last=i;
		}
	}a[n]--;
	l=len/k-1; r=len;
	while(l<r){
		mid=(l+r)>>1; 
		if(check(mid))r=mid; else l=mid+1;
	}cout<<l<<endl;
}