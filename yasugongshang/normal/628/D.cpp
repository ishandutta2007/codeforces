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
const int N=2005,mod=1000000007;
string a,b,quan;
int dp[N][N][2][2],d,m;
int dfs(int pos,int yu,bool flag,bool fff,bool fla){
	if(pos<0)return yu==0;
	if(!flag&&dp[pos][yu][fff][fla]!=-1)return dp[pos][yu][fff][fla];
	int meiju=flag?quan[quan.length()-pos-1]-'0':9,ans=0;
	if(!fla){
		for(int i=0;i<=meiju;i++)if(i!=d||(d==0&&!fff)){
			ans=(ans+dfs(pos-1,(yu*10+i)%m,flag&&i==meiju,fff||i,(fla^1)&&(fff||i)))%mod;
		}
		if(!flag)dp[pos][yu][fff][fla]=ans;
		return ans;
	}else{
		for(int i=0;i<=meiju;i++)if(i==d){
			ans=(ans+dfs(pos-1,(yu*10+i)%m,flag&&i==meiju,fff||i,(fla^1)&&(fff||i)))%mod;
		}
		if(!flag)dp[pos][yu][fff][fla]=ans;
		return ans;
	}
}
int calc(string x){
	quan=x; 
	memset(dp,-1,sizeof(dp));
	return dfs(x.length()-1,0,1,0,0);
}
int main(){
	m=read(); d=read();
	cin>>a>>b;
	for(int i=a.length()-1;;i--){
		if(a[i]=='0')a[i]='9'; else{
			a[i]--; break;
		}
	}
	if(a[0]=='0'&&a.length()>1)a.erase(a.begin());
	cout<<(calc(b)-calc(a)+mod)%mod<<endl;
}