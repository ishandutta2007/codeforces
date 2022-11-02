#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<vector>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;
inline void write(long long a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(long long a){
	write(a); puts("");
}
inline long long read()// 
{
	long long x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
const int N=5005;
int n,a[N],last[N],tong[N],dp[N],nextt[N];
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read(); last[i]=tong[a[i]]; tong[a[i]]=i; if(!last[i])last[i]=i;
	}memset(tong,0,sizeof(tong));
	for(int i=n;i;i--){
		nextt[i]=tong[a[i]]; tong[a[i]]=i; if(!nextt[i])nextt[i]=i;
	}
	for(int i=1;i<=n;i++){dp[i]=dp[i-1];memset(tong,0,sizeof(tong));
		for(int j=i,sum=0,t=i;j;j--){
			t=min(t,last[j]); if(nextt[j]>i)break;
			if(!tong[a[j]]){tong[a[j]]=1;sum^=a[j];}
			if(j==t)dp[i]=max(dp[i],dp[j-1]+sum);
		}
	//cout<<dp[i]<<" "<<i<<endl;
	}
	writeln(dp[n]);
}