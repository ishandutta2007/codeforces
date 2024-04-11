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
int n,k,tong[100005],t[10005],kind;
char ch[1000005];
int main(){
	n=read(); k=read();
	scanf("%s",&ch);
	int len=strlen(ch);
	for(int i=len;i>=0;i--){
		if(!tong[ch[i]])tong[ch[i]]=i;
	}//cout<<tong['A']<<" "<<tong['B']<<endl;
	for(int i=0;i<len;i++){
		if(!t[ch[i]]++)kind++; if(kind>k){
			puts("YES"); return 0;
		}
		if(tong[ch[i]]==i){
			kind--;
		}
		//cout<<i<<" "<<kind<<endl;
	}
	puts("NO");
}