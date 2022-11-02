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
	long long x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
char ch[20];
int que[300005],r,t,zs,ans;
int main(){
	int n=read();
	for(int i=1;i<=n*2;i++){
		scanf("%s",&ch);
		if(ch[0]=='a'){
			que[++r]=read();
		}else{
			if(que[r]!=++zs&&t<r)ans++; //cout<<i<<" "<<ans<<" "<<que[r]<<" "<<zs<<endl;
			if(que[r]==zs){r--; t=min(t,r);} else t=--r;
		}
	}
	writeln(ans);
}