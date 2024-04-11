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
const int N=1000005;
char a[N],b[N],c[N];
int pos,tong[N],n;
int main(){
	scanf("%s",&a); 
	int len=strlen(a); for(int i=0;i<len;i++)tong[a[i]]=1;
	scanf("%s",&b); len=strlen(b); int flag=0;
	for(int i=0;i<len;i++)if(b[i]=='*'){
		flag=1; pos=i; break;
	}
	n=read();
	while(n--){
		scanf("%s",&c);
		int l=strlen(c); 
		int fff=0;
		if(flag){
			for(int i=pos;i<=pos+l-len;i++)if(tong[c[i]])fff=1;
		}
		if(l==len){
			for(int i=0;i<l;i++){if(b[i]!='?'&&b[i]!='*'){
				if(c[i]!=b[i]){
					fff=1; break;
				}
			}else if(b[i]=='?'){
				if(!tong[c[i]]){
					fff=1; break;
				}
			}}
		}else if(l+1==len&&flag){
			for(int i=0;i<l;i++)if(b[i+(i>=pos?1:0)]!='?'&&b[i+(i>=pos?1:0)]!='*'){
				if(c[i]!=b[i+(i>=pos?1:0)]){
					fff=1; break;
				}
			}else if(b[i+(i>=pos?1:0)]=='?'){
				if(!tong[c[i]]){
					fff=1; break;
				}
			}
		}else if(l>len&&flag){
			for(int i=0;i<l;i++)if(b[i-(i>pos?l-len:0)]!='?'&&b[i-(i>pos?l-len:0)]!='*'){
				if(c[i]!=b[i-(i>pos?l-len:0)]){
					fff=1; break;
				}
			}else if(b[i-(i>pos?l-len:0)]=='?'){
				if(!tong[c[i]]){
					fff=1; break;
				}
			}else i+=l-len;
		}else fff=1;
		if(fff)puts("NO"); else puts("YES");
	}
}/*
abc
abc*abc
100
abcdefabc*/