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
int n,ans=0;
char ch[1005];
int main(){
	n=read();
	while(scanf("%s",&ch)==1){
		int len=strlen(ch);
		int an=0;
		for(int i=0;i<len;i++)if(ch[i]>='A'&&ch[i]<='Z')an++;
		ans=max(an,ans);
	}
	writeln(ans);
}