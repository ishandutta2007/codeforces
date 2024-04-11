#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=3e5+10;
int fi[M][20],fx[M][20],a[M],lg[M];
bool ok[M][20];
int n;
int main(){
	n=read();
	int mi=1e9,mx=0;
	F(i,1,n) a[i]=read(),mi=min(mi,a[i]),mx=max(mx,a[i]);
	if (mi*2>=mx) {
		F(i,1,n) cout<<"-1 "; puts("");
		return 0;
	}
	F(i,1,n) a[i+n+n]=a[i+n]=a[i];
	n=3*n;
	F(i,1,n){
		fi[i][0]=fx[i][0]=a[i];
		if (i>=2) lg[i]=lg[i>>1]+1;
	}
	F(i,1,lg[n]){
		F(j,1,n-(1<<i)+1){
			ok[j][i]=(fi[j+(1<<i-1)][i-1]*2<fx[j][i-1])|ok[j][i-1]|ok[j+(1<<i-1)][i-1];
//			if (i==j && i==1) cout<<fi[j+(1<<i-1)][i-1]<<" "<<(fx[j][i-1]/2)<<"   mdzz\n";
			fi[j][i]=min(fi[j][i-1],fi[j+(1<<i-1)][i-1]);
			fx[j][i]=max(fx[j][i-1],fx[j+(1<<i-1)][i-1]);
		}
	}
//	cout<<ok[1][1]<<"\n";
	F(i,1,n/3){
		int mx=0,x=i;
		DF(j,lg[n],0){
			if (x+(1<<j)-1>n) continue;
			if (!ok[x][j] && fi[x][j]*2>=mx) {
				mx=max(mx,fx[x][j]);
				x+=(1<<j);
			}
		}
		cout<<x-i<<" ";
	}
    return 0;
}