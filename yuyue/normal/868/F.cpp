#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=1e5+7;
int a[M],b[M],n,k,L=1,R;
LL ans;
LL dp[21][M];
void add(int x){
	ans+=b[a[x]];
	b[a[x]]++;
}
void del(int x){
	b[a[x]]--;
	ans-=b[a[x]];
}
LL calc(int l,int r){
	while (L<l) del(L++);
	while (L>l) add(--L);
	while (R>r) del(R--);
	while (R<r) add(++R);
	return ans;
}
void solve(int t,int jl,int jr,int l,int r){

	if (jl>jr || l>r) return ;
	int mid=(l+r>>1);	//cout<<jl<<" "<<jr<<" "<<l<<" "<<r<<"\n";
	LL res=1e18; int opt;
	for (int i=jl;i<=jr;i++){
		LL tp=calc(i+1,mid);
		if (dp[t-1][i]+tp<res) res=dp[t-1][i]+tp,opt=i;
	}
//	cout<<"FUck\n";
	dp[t][mid]=res;
	solve(t,jl,opt,l,mid-1);
	solve(t,opt,jr,mid+1,r);
}
int main(){
	n=read(); k=read();
	for (int i=1;i<=n;i++){
		a[i]=read();
	}
	memset(dp,1,sizeof dp); dp[0][0]=0;
	for (int i=1;i<=k;i++){
		solve(i,0,n-1,1,n);
	}
	cout<<dp[k][n]<<"\n";
    return 0;
}