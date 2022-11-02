#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long LL;
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
int n,a[155][155],b[155][155];
int main(){
	n=read();
	a[0][0]=1;
	for(int i=1;i<=n;i++){
		int flag=0;
		for(int j=0;j<i;j++)a[i][j+1]=b[i][j]=a[i-1][j];
		for(int j=0;j<=i;j++){
			a[i][j]+=b[i-1][j]; a[i][j]%=2;
			if(abs(a[i][j])>=2)flag=1;
		}
	}
	if(a[n][n]<0){
		for(int i=0;i<=n;i++){
			a[n][i]=-a[n][i]; b[n][i]=-b[n][i];
		}
	}
	cout<<n<<endl;
	for(int i=0;i<=n;i++)cout<<a[n][i]<<" "; puts("");
	cout<<n-1<<endl;
	for(int i=0;i<n;i++)cout<<b[n][i]<<" ";
}
/*
-1 0
-x -1
x^2-1 x
x^3 -x^2-1
x^3+x^2-1 x^3

*/