#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#define re register
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
int n,a[26];
char s[1001];
inline void work(){
	n=read();
	for(re int i=0;i<26;i++)a[i]=0; 
	for(re int j=1;j<=n;j++){
		scanf("%s",s);
		for(re int i=0;i<strlen(s);i++)a[s[i]-'a']++;
	}
	for(re int i=0;i<26;i++)
		if(a[i]%n)return puts("NO"),void();
	puts("YES"); 
}
int main(){
	int t=read();while(t--)work();
	return 0;
}