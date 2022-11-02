#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
inline void write(int a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
inline int	read()// 
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
const int N=200005;
int n,k,a[N],que[N],r,zs,ans;
int main(){
	n=read(); k=read(); int flag=0;
	for(int i=1;i<=n;i++)a[i]=(read()>=0);
	for(int i=1;i<=n;i++)if(!a[i]){
		k--; if(!zs||(flag==0&&a[1])){flag=1; zs=0;continue;} que[++r]=zs; zs=0;
	} else{
		zs++;
	}zs=0;
	for(int i=1;i<=n;i++)if(!a[i]){
		if(!zs){continue;} ans+=2;zs=0;
	} else{
		zs++;
	}
	if(k<0){
		puts("-1"); return 0;
	}int sum2=0;
	for(int i=n;i;i--)if(a[i])sum2++; else break;
	ans+=2*(!a[1])-(!a[n]); 
	sort(&que[1],&que[r+1]);
	for(int i=1;i<=r;i++)if(k-que[i]>=0){
		k-=que[i]; ans-=2; 
	}else break;
	flag=0; for(int i=1;i<=n;i++)if(!a[i])flag=1;
	if(k>=sum2&&a[n]&&flag)ans--;
	writeln(ans);
}