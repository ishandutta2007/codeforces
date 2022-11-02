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
const int N=1005;
int n,sum[N+1][1<<8],a[N],ans,tong[8][N+1];
int calc(int x){
	for(int i=1;i<=n;i++){
		for(int j=0;j<(1<<8);j++){
			sum[i][j]=sum[i-1][j];
					//if(i==n&&j+1==(1<<8))cout<<((tong[a[i]][i]))<<" "<<i<<" "<<tong[a[i]][i]<<endl;
			if((j&(1<<a[i]))&&tong[a[i]][i]>=x){
				int t=upper_bound(&tong[a[i]][1],&tong[a[i]][i],tong[a[i]][i]-x)-&tong[a[i]][1];
				sum[i][j]=max(sum[t][j^(1<<a[i])]+x,sum[i][j]);
				if(tong[a[i]][i]>x){
					t=upper_bound(&tong[a[i]][1],&tong[a[i]][i],tong[a[i]][i]-x-1)-&tong[a[i]][1]; 
					sum[i][j]=max(sum[t][j^(1<<a[i])]+x+1,sum[i][j]);
				}
				//if(sum[i][j]>0)cout<<sum[i][j]<<" "<<i<<" "<<j<<" "<<x<<endl;
			}
		}
	}
	if(x==0){
		int ans=0;
		for(int i=0;i<(1<<8);i++)ans=max(ans,sum[n][i]);
		return ans;
	}
	return sum[n][(1<<8)-1];
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read()-1;
	for(int i=1;i<(1<<8);i++)sum[0][i]=-1e9;
	for(int i=1;i<=n;i++){
		for(int j=0;j<8;j++)tong[j][i]=tong[j][i-1]+(a[i]==j);
	}
	//cout<<calc(0)<<endl; return 0;
	for(int i=0;i*8<n;i++)ans=max(ans,calc(i));
	cout<<ans<<endl;
}