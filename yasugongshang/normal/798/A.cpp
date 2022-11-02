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
inline bool check(string x){//cout<<x<<endl;
	for(int i=0;i<x.length();i++){
		if(x[i]!=x[x.length()-i-1])return false;
	}
	return true;
}
string ch;
int main(){
	cin>>ch;
	for(int i=0;i<ch.length();i++){
		for(int j=0;j<26;j++)if(ch[i]!='a'+j){
			string zs=ch;
			zs[i]='a'+j;
			if(check(zs)){
				puts("YES"); return 0;
			}
		}
	}
	puts("NO");
}