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
int x1,Y1,x2,y2,x,y;
int main(){
	x1=read(); Y1=read(); x2=read(); y2=read();
	x=read(); y=read();
	if((x2-x1)%x==0&&(y2-Y1)%y==0&&((abs(x2-x1)/x)&1)==((abs(y2-Y1)/y)&1))puts("YES"); else puts("NO");
}