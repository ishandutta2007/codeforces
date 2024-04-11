#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
inline int read(){
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
int ans,n,m,w,we[N],beau[N],dp[N][N],sum1[N],sum2[N],father[N];
#include<vector>
vector <int> v[N];
inline int getfather(int x){
	return father[x]==x?x:father[x]=getfather(father[x]);
}
int main(){
    n=read(); m=read(); w=read();
    for(int i=1;i<=n;i++)father[i]=i;
    for(int i=1;i<=n;i++)sum1[i]=we[i]=read();
    for(int i=1;i<=n;i++)sum2[i]=beau[i]=read();
    while(m--){
    	int t1=getfather(read()),t2=getfather(read());
    	if(t1==t2)continue;
    	father[t1]=t2; sum1[t2]+=sum1[t1]; sum2[t2]+=sum2[t1];
	}
	for(int i=1;i<=n;i++)v[getfather(i)].push_back(i);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=w;j++)dp[i][j]=dp[i-1][j];
		if(v[i].size()){
		   for(int j=0;j<v[i].size();j++){
		       int t=v[i][j];
			   for(int k=we[t];k<=w;k++){
			   	   dp[i][k]=max(dp[i-1][k-we[t]]+beau[t],dp[i][k]);
		       }
		   }
		   for(int j=sum1[i];j<=w;j++){
		   	   dp[i][j]=max(dp[i][j],dp[i-1][j-sum1[i]]+sum2[i]);
		   }
		}
	}
	ans=dp[n][w];
	for(int i=0;i<w;i++)ans=max(ans,dp[n][i]);
	writeln(ans);
}