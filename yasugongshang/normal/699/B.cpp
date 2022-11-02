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
inline int read()// 
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
const int N=1005;
char ch[N][N];
int n,m,sum1[N],sum2[N],ans,ans1,sum3[N],sum4[N];
int main(){
	n=read(); m=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){scanf("\n%c",&ch[i][j]); if(ch[i][j]=='*'){
		sum3[i]++; sum4[j]++;
	}}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)sum1[j]=sum3[j]; for(int j=1;j<=m;j++)sum2[j]=sum4[j];
		for(int j=1;j<=m;j++){
			if(ch[i][j]=='*')sum2[j]--;
		}ans=0;
		for(int j=1;j<=m;j++)if(sum2[j]){
			ans++; ans1=j; if(ans>1)break;
			for(int k=1;k<=n;k++)if(ch[k][j]=='*'&&k!=i)sum1[k]--;
		}
		if(ans>1){continue;}int flag=0;
		for(int j=1;j<=n;j++)if(i!=j&&sum1[j]){flag=1;break;}
		if(flag)continue;
		puts("YES"); if(!ans1)ans1=1;
		cout<<i<<" "<<ans1<<endl; return 0;
	}
	puts("NO");
	return 0;
}