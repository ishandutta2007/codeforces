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
inline bool check(int a,int b){
	if(a%10==b/10&&b%10==a/10)return true; else return false;
}
int main(){
	int s1,s2;
	scanf("%d:%d",&s1,&s2);
	int ans=0; 
	while(!check(s1,s2)){
		ans++; s2++; if(s2==60){
			s2=0; s1++;
		}
		if(s1==24)s1=0;
	}
	writeln(ans);
}