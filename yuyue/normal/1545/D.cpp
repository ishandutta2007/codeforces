#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2020;
int m,K,a[M][M];
LL s[M],del[M];
map<LL,int> mp;
LL rl=0;
LL chs[M],t[M],hs[M];
LL suan(int x){
	LL ret=0;
	F(i,1,m) F(j,i+1,m) ret+=1ll*(a[x][j]-a[x][i])*(a[x][j]-a[x][i]);
	return ret;
}
int main(){
	m=read(); K=read();
	int mx=0;
	F(i,1,K){
		F(j,1,m) a[i][j]=read(),s[i]+=a[i][j];
		del[i]=s[i]-s[i-1];
		if (i>=2){
			mp[del[i]]++;
			if (mp[del[i]]>mx) mx=mp[del[i]],rl=del[i];
		}
	}
	int tim=0;
	LL ad=0;
	F(i,2,K){
		if (del[i]!=rl){
			tim=i;
			ad=rl-del[i];
			break;
		}
	}
	LL D=0;
	cout<<tim-1<<" ";
	DF(i,K-1,2){
		if (tim!=i && tim!=i-1 && tim!=i+1){
			D=suan(i+1)+suan(i-1)-suan(i)*2;
			break;
		}
	}
//	cout<<D<<"\n";
	LL X=suan(tim-1),Y=suan(tim),Z=suan(tim+1);
//	cerr<<ad<<"\n";
	F(i,1,m){
		int nw=a[tim][i]+ad;
		LL ty=Y;
		F(j,1,m){
			if (i==j) continue; 
			ty+=1ll*(nw-a[tim][j])*(nw-a[tim][j])-1ll*(a[tim][i]-a[tim][j])*(a[tim][i]-a[tim][j]);
		}
//		cerr<<X+Z-ty*2<<" ????????\n";
		if (X+Z-ty*2==D){
			cout<<nw<<"\n";
			return 0;
		}
	}
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/