#include <bits/stdc++.h>
using namespace std;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=107;
int n;
char s[N];
inline void work(){
	n=read(),scanf("%s",s+1);
	int pos=0;
	for(int i=1;i<=n;i++)
		if(isalpha(s[i])){pos=i;break;}
	if(!pos)pos=1,s[1]='B';
	for(int i=pos-1;i;i--)
		if(!isalpha(s[i]))
			s[i]=s[i+1]=='B'?'R':'B';
	for(int i=pos+1;i<=n;i++)
		if(!isalpha(s[i]))
			s[i]=s[i-1]=='B'?'R':'B';
	for(int i=1;i<=n;i++)putchar(s[i]);
	putchar('\n');
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}