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
#define int long long
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
const int N=1005,M=300005;
int n,m,k,tong[N][N][26],sum[N][N],a[M],b[M],c[M],d[M],e[M],mi=4e18;
char ch[N][N];
signed main(){
	n=read(); m=read(); k=read();
	for(int i=1;i<=n;i++)scanf("%s",ch[i]+1);
	for(int i=1;i<=k;i++){
		a[i]=read(); b[i]=read(); c[i]=read(); d[i]=read(); e[i]=getchar()-'a';
		tong[c[i]][d[i]][e[i]]++; tong[a[i]-1][b[i]-1][e[i]]++;
		tong[c[i]][b[i]-1][e[i]]--; tong[a[i]-1][d[i]][e[i]]--;
	}
	for(int i=n;i;i--){
		for(int j=m;j;j--){
			ch[i][j]-='a';
			for(int k=0;k<26;k++){
				tong[i][j][k]+=tong[i+1][j][k]+tong[i][j+1][k]-tong[i+1][j+1][k];
				sum[i][j]+=tong[i][j][k];
			}
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		//cout<<sum[i][j]<<" "<<i<<" "<<j<<endl;
		tong[i][j][ch[i][j]]+=k-sum[i][j];
		sum[i][j]=0;
		for(int k=0;k<26;k++){
			sum[i][j]+=abs(ch[i][j]-k)*tong[i][j][k];
			tong[i][j][k]+=tong[i-1][j][k]+tong[i][j-1][k]-tong[i-1][j-1][k];
		}
		sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
	}
	for(int i=1;i<=k;i++){
		int ans=sum[n][m]-(sum[c[i]][d[i]]-sum[a[i]-1][d[i]]-sum[c[i]][b[i]-1]+sum[a[i]-1][b[i]-1]);
		for(int j=0;j<26;j++){
			//cout<<(tong[c[i]][d[i]][j]+tong[a[i]-1][b[i]-1][j]-tong[a[i]-1][d[i]][j]-tong[c[i]][b[i]-1][j])<<endl;
			ans+=(tong[c[i]][d[i]][j]+tong[a[i]-1][b[i]-1][j]-tong[a[i]-1][d[i]][j]-tong[c[i]][b[i]-1][j])*abs(e[i]-j);
		}
		mi=min(mi,ans);
	}
	cout<<mi<<endl;
}