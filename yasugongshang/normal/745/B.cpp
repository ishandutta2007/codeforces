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
const int N=505;
char ch;
int n,tot,mix=10000,miy=10000,mxx,mxy,m;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		scanf("\n%c",&ch); if(ch=='X'){
			tot++;mix=min(mix,i);miy=min(miy,j);mxx=max(mxx,i);mxy=max(mxy,j);
		}
	}
	if((mxx-mix+1)*(mxy-miy+1)==tot){
		puts("YES");
	}else puts("NO");
}