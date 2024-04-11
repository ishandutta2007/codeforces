#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
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
const int N=20005;
int n,k,p,sum[N],dq[51][100],ans;
int main(){
	n=read(); k=read(); p=read();
	for(int i=1;i<=n;i++)sum[i]=(sum[i-1]+read())%p;
	for(int i=0;i<=k;i++)for(int j=0;j<p;j++)dq[i][j]=-1e9; dq[0][0]=0;
	for(int i=1;i<=n;i++){
		dq[1][sum[i]]=sum[i];
		for(int j=2;j<=k;j++){
			for(int l=0;l<p;l++){
				int t=(sum[i]+p-l)%p;
				int zs=dq[j-1][l]+t;
				//if(i==4&&l==4&&j==3)cout<<zs<<" xjoa"<<t<<" "<<sum[i]<<" "<<l<<endl;
				if(i==n)ans=max(ans,zs);
				dq[j][sum[i]]=max(dq[j][sum[i]],zs);
			}
		}
	}
	cout<<ans<<endl;
}