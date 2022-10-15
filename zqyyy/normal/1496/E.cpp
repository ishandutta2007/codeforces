#include <bits/stdc++.h>
using namespace std;
#define GG puts("0"),exit(0)
inline int read(){
    int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=505;
int n,m;
char s[N][N];
inline void work(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	if(n%3==1 || n%3==2){
		for(int i=1;i<=n;i+=3)
			for(int j=1;j<=m;j++)
				s[i][j]='X';
		for(int i=3;i<=n;i+=3){
			bool flg=0;
			for(int j=1;j<=m;j++)
				if(s[i][j]=='X' || s[i-1][j]=='X')
					if(!flg){
						flg=1;
						s[i][j]=s[i-1][j]='X';
						break;
					}
			if(!flg)s[i][1]=s[i-1][1]='X';
		}
	}else{
		for(int i=2;i<=n;i+=3)
			for(int j=1;j<=m;j++)
				s[i][j]='X';
		for(int i=4;i<=n;i+=3){
			bool flg=0;
			for(int j=1;j<=m;j++)
				if(s[i][j]=='X' || s[i-1][j]=='X')
					if(!flg){
						flg=1;
						s[i][j]=s[i-1][j]='X';
						break;
					}
			if(!flg)s[i][1]=s[i-1][1]='X';
		}
	}
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=m;j++)
			putchar(s[i][j]);
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}