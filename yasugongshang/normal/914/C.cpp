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
const int N=1005,mod=1000000007;
int dp[N][N],tong[N],ycl[N],yyy[N],k;
string n;
int dfs(int p,int dq,int flag){
	//cout<<p<<" "<<dq<<" "<<flag<<" "<<endl;
	if(p==n.length())return tong[dq];
	if(!flag&&dp[p][dq]!=-1)return dp[p][dq];
	int meiju=flag?n[p]-'0'+1:2,ans=0;
	for(int i=0;i<meiju;i++)ans+=dfs(p+1,dq+i,i==meiju-1&&flag);
	ans%=mod;
	if(!flag)dp[p][dq]=ans;
	return ans;
}
int main(){
	cin>>n; ycl[1]=1; k=read(); memset(dp,-1,sizeof(dp));
	if(k==0){
		puts("1"); return 0;
	}else if(k==1){
		cout<<n.length()-1<<endl; return 0;
	}
	for(int i=2;i<=1000;i++){
		ycl[i]=ycl[i>>1]+(i&1);
		yyy[i]=yyy[ycl[i]]+1;
		if(yyy[i]==k-1)tong[i]=1;
	}
	cout<<dfs(0,0,1)<<endl;
}