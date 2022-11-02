#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<complex>
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
const int N=5005;
char ch[N];
int ans,n,f[N][N],g[N][N];
int main(){
	scanf("%s",ch+1);
	n=strlen(ch+1);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){if(ch[j]=='?'){
			f[i][j]=f[i][j-1]+1; g[i][j]=max(g[i][j-1]-1,(j-i+1)&1);
		}else if(ch[j]=='('){
			f[i][j]=f[i][j-1]+1; g[i][j]=g[i][j-1]+1;
		}else if(ch[j]==')'){
			f[i][j]=f[i][j-1]-1; g[i][j]=max(g[i][j-1]-1,(j-i+1)&1);
		}if(f[i][j]<0)break; if(g[i][j]==0)ans++;}
	}
	cout<<ans<<endl;
}