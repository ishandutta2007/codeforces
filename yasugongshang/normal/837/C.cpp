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
const int N=205;
int n,a,b,x[N],y[N],nn,ans;
int main(){
	n=read(); a=read(); b=read();
	for(int i=1;i<=n;i++){
		x[i]=read(); y[i]=read(); x[n+i]=y[i]; y[n+i]=x[i];
	}
	nn=n<<1;
	for(int i=1;i<=nn;i++){
		for(int j=i+1;j<=nn;j++)if(i+n!=j){
			if((x[i]+x[j]<=a&&y[i]<=b&&y[j]<=b)||(y[i]+y[j]<=b&&x[i]<=a&&x[j]<=a)){
				ans=max(x[i]*y[i]+x[j]*y[j],ans);
			}
		}
	}
	writeln(ans);
}