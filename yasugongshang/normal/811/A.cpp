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
int a,b,t,flag;
int main(){
	cin>>a>>b; t=1;
	while(true){
		if(a<t){
			flag=1; break;
		}else a-=t++;
		if(b<t){
			flag=0; break;
		}else b-=t++;
	}
	if(flag)puts("Vladik"); else puts("Valera");
}