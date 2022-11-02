#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef int LL;
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
const int N=200005;
int ttt[N],ans,pos,dp[N],tong[N],vis[N],tot,ztzt,zt[N],n,m,q[N],last[N],nxt,heshu[N];
vector<int> v[N],e[N];
inline void exgcd(int a,int b,int &x,int &y){
	if(!b)x=1,y=0;
	else exgcd(b,a%b,y,x),y-=x*(a/b);
}
inline int ni(int a,int p){
	int x,y; exgcd(a,p,x,y);
	x=(x%p+p)%p;
	return x==0?p:x;
}
inline void dfs(int p,int sum){
	if(m%sum)return;
	if(p>tot){
		zt[++ztzt]=sum;
		return;
	}
	for(long long i=sum;i<m;i*=q[p]){
		dfs(p+1,i);
	}
}
inline void out(int a,int b){
	int t=__gcd(__gcd(a,b),m);
	a/=t; b/=t;
	//cout<<b*t<<" "<<a*t<<" "<<b*ni(a,m/t)%m<<" "<<endl;
	write((long long)b*ni(a,m/t)%m); putchar(' ');
}
inline void print(int pos){
	if(!pos)return; 
	print(last[pos]);
	for(int i=0;i<v[pos].size();i++){
		//cout<<v[pos][i]<<" ";
		out(nxt,v[pos][i]); nxt=v[pos][i];
	}
}
int main(){
	n=read(); m=read();
	for(int i=2;i<m;i++)if(!heshu[i]){
		for(int j=i+i;j<m;j+=i){
			heshu[j]=1; 
		}
	}
	for(int i=2;i<m;i++)if(!heshu[i]&&m%i==0){
		q[++tot]=i; vis[i]=1;
	}
	for(int i=0;i<m;i++)tong[i]=1;
	for(int i=1;i<=n;i++)tong[read()]=0;
	dfs(1,1);
	sort(&zt[1],&zt[ztzt+1]);
	for(int i=1;i<=ztzt;i++)ttt[zt[i]]=i;
	for(int i=ztzt;i;i--){
		for(int j=zt[i];j<m;j+=zt[i]){
			if(tong[j]){
				tong[j]=0; v[i].push_back(j);
			}
			//cout<<zt[i]<<" "<<j<<endl;
			if(vis[j/zt[i]])e[i].push_back(ttt[j]);
		}
	}
	for(int i=1;i<=ztzt;i++){
		dp[i]=max(dp[i],(int)v[i].size());
		if(dp[i]>ans){
			ans=dp[i]; pos=i;
		}
		for(int j=0;j<e[i].size();j++)if(dp[i]+v[e[i][j]].size()>dp[e[i][j]]){
			dp[e[i][j]]=dp[i]+v[e[i][j]].size();
			last[e[i][j]]=i;
		}
	}
	cout<<ans+tong[0]<<endl; nxt=1;
	print(pos);
	if(tong[0])puts("0");
}
//3 7 6 4 8
//3 9 8 8 8