#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline LL read(){
	char ch=getchar(); LL w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2e5+10;
int lg[M]; 
LL a[M],st[20][M];
LL qry(int l,int r){
	int len=lg[r-l+1];
	return __gcd(st[len][l],st[len][r-(1<<len)+1]);	
}
int n;
void work(){
	n=read();
	F(i,2,n) lg[i]=lg[i>>1]+1;
	F(i,1,n) a[i]=read(),st[0][i-1]=abs(a[i]-a[i-1]);
	F(i,1,lg[n]){
		F(j,1,n-1-(1<<i)+1){
			st[i][j]=__gcd(st[i-1][j],st[i-1][j+(1<<i-1)]);
		}
	}
//	cout<<st[0][1]<<" "<<st[0][2]<<" ?? \n";
	int ans=1;
	F(i,1,n-1){
		int l=i,r=n-1,ret=l-1;
		while (l<=r){
			int mid=(l+r>>1);
//			cout<<"? "<<i<<" "<<mid<<" "<<qry(i,mid)<<"   ooo\n";
			if (qry(i,mid)>1) ret=mid,l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,ret-i+2);
	}
	cout<<ans<<"\n";
}
int main(){
	int T=read();
	while (T--) work();
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
1
4 
8 2 5 10
*/