#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<ctime>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define PI pair<int,int>
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
char ch[N],ans[N];
int n;
bitset<N> dp[N];
int main(){
	scanf("%s",ch+1);
	n=strlen(ch+1); int x=log2(n),t=1<<x,lim=n-t+1;
	dp[1][0]=1;
	for(int i=1;i<=lim;i++){
		ans[i]=127;
		for(int j=0;j<t;j++)if(dp[i][j]){
			ans[i]=min(ans[i],ch[i+j]);
			for(int k=0;k<x;k++)dp[i][j|(1<<k)]=1;
		}
		for(int j=0;j<t;j++)if(dp[i][j]){
			if(ch[i+j]==ans[i])dp[i+1][j]=1;
		}
		//write(ans[i]); putchar(' ');
	}
	cout<<(ans+1)<<endl;
}