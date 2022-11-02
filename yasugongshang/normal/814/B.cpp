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
const int N=1005;
int n,a[N],b[N],r,que[N],flag,tong[N];
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=1;i<=n;i++)if(a[i]!=b[i]){
		que[++r]=i;
	}
	for(int i=1;i<=n;i++)if(a[i]==b[i])tong[a[i]]++;
	if(r==2){
	    if(tong[a[que[1]]]==0&&tong[b[que[2]]]==0)a[que[2]]=b[que[2]]; else a[que[1]]=b[que[1]];
	}else if(r==1){
		for(int i=1;i<=n;i++)if(a[i]==b[i])tong[a[i]]=true;
		for(int i=1;i<=n;i++)if(a[i]!=b[i]){
			for(int j=1;j<=n;j++)if(!tong[j]){
				a[que[1]]=j; break;
			}
		}
	}else{
		for(int i=1;i<=n;i++)if(!tong[i])flag=i;
		for(int i=1;i<=n;i++)if(tong[a[i]]>1){
			a[i]=flag; break;
		}
	}
	for(int i=1;i<=n;i++){
		write(a[i]); putchar(' ');
	}
}