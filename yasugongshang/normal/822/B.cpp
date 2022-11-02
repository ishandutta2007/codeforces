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
inline void write(long long a){
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
const int N=100005;
int n,m,ans,sum,que[N];
char a[N],b[N];
int main(){
	n=read(); m=read();
	scanf("%s%s",&a,&b); sum=n+1;
	for(int i=0;i<=m-n;i++){
		ans=0;
		for(int j=i;j<i+n;j++){
			if(a[j-i]!=b[j])ans++;
		}
		if(ans<sum){sum=0;
			for(int j=i;j<i+n;j++)if(a[j-i]!=b[j])que[++sum]=j-i;
		}
	}
	writeln(sum);
	for(int i=1;i<=sum;i++){
		write(que[i]+1); putchar(' ');
	}
}