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
char ss[5]={'a','A','C','G','T'},ch[1000005];
int s[5];
int main(){scanf("%s",&ch);
	scanf("%s",&ch);
	int len=strlen(ch); if(len%4){
		puts("==="); return 0;
	}
	for(int i=0;i<len;i++){
		if(ch[i]=='A')s[1]++; else if(ch[i]=='C')s[2]++; else if(ch[i]=='G')s[3]++; else if(ch[i]=='T')s[4]++;
	}
	for(int i=1;i<=4;i++)if(s[i]>len/4){
		puts("==="); return 0;
	}else s[i]=len/4-s[i];
	for(int i=0;i<len;i++)if(ch[i]=='?'){
		for(int j=1;j<=4;j++)if(s[j]){
			ch[i]=ss[j]; s[j]--;break; 
		}
	}
	cout<<ch<<endl;
}