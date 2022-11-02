#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
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
int n,ans;
char s[2000],ch;
int main(){
	n=read();
	map<char,int>M;
	M['T']=4; M['C']=6; M['O']=8; M['D']=12; M['I']=20;
	for(int i=1;i<=n;i++){
		scanf("\n%c",&ch); gets(s);
		ans+=M[ch];
	}
	writeln(ans);
}