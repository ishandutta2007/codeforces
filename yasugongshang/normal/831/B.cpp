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
char a[2700],b[25600],c[100005];
int flag,tong[10005];
int main(){
	cin>>a>>b>>c;
	for(int i=0;i<26;i++){
		tong[a[i]]=i;
	}
	int len=strlen(c);
	for(int i=0;i<len;i++){
		if((c[i]>='a'&&c[i]<='z')||(c[i]>='A'&&c[i]<='Z')){
		if(c[i]>='A'&&c[i]<='Z'){
			flag=1; c[i]+='a'-'A';
		}else flag=0;
		
		putchar(flag?b[tong[c[i]]]-('a'-'A'):b[tong[c[i]]]);
	}else putchar(c[i]);}
}