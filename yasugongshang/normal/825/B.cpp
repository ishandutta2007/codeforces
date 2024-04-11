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
char ch[11][11];
int n,s1[8]={1,-1,0,0,1,1,-1,-1},s2[8]={0,0,1,-1,1,-1,1,-1};
inline bool check(int a,int b){
	ch[a][b]='X';
	for(int x=1;x<=n;x++)for(int y=1;y<=n;y++)if(ch[x][y]=='X')for(int i=0;i<8;i++){
		if(x-s1[i]*4<=n&&x-s1[i]*4>0&&y-s2[i]*4>0&&y-s2[i]*4<=n){
			int flag=1;
			for(int j=x-4*s1[i],k=y-4*s2[i];j!=x||k!=y;j+=s1[i],k+=s2[i]){
				if(ch[j][k]!='X'){
					flag=0; break;
				}
			}
			
			if(flag)return 1;
		}
	}
	ch[a][b]='.';
	return 0;
}
int main(){
	n=10;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)scanf("\n%c",&ch[i][j]);
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(ch[i][j]=='.'&&check(i,j)){
		puts("YES");return 0;
	}
	puts("NO");
}