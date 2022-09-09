#include<bits/stdc++.h>
using namespace std;
const int N=205,mo=1e4+7;
typedef vector<int>V;
inline void add(int&x,int y){x=(x+y)%mo;}
inline int poww(int x,int y){int ans=1;for(;y;y>>=1,x=1ll*x*x%mo)if(y&1)ans=1ll*ans*x%mo;return ans;}
inline V divmod(V a,V b){
	if(a.size()<b.size())return a;
	for(int i=a.size()-1,j,x;i>=(int)b.size()-1;--i)
		for(j=0,x=a[i];j<b.size();++j)a[i-j]=(a[i-j]+(mo-x)*b[b.size()-1-j])%mo;
	return V(a.begin(),a.begin()+b.size()-1);
}
inline V mul(V a,V b){
	V c;c.resize(a.size()+b.size()-1);
	for(int i=0;i<a.size();++i)for(int j=0;j<b.size();++j)c[i+j]=(c[i+j]+a[i]*b[j])%mo;
	return c;
}
inline V BM(V a){
	V ans,oa,lst;int i,j,x,z,y,ldt,best=-mo;
	for(i=0;i<a.size();++i){
		x=(mo-a[i])%mo;for(j=0;j<ans.size();++j)x=(x+1ll*ans[j]*a[i-1-j])%mo;if(x==0)continue;
		oa=ans;
		if(ans.empty())ans.resize(i+1);else{
			if(ans.size()<i-best)ans.resize(i-best);
			y=1ll*(mo-x)*ldt%mo;z=i-best-lst.size();
			for(j=0;j<lst.size();++j)ans[z+j]=(ans[z+j]+1ll*lst[j]*y)%mo;
		}
		if(i-(int)oa.size()>best)best=i-(int)oa.size(),lst=oa,lst.insert(lst.begin(),mo-1),ldt=poww(x,mo-2);
	}
	return ans;
}
inline int calc(V a,int n){
	V M=BM(a),A={1},B={0,1};
	if(M==V{})return 0;
	reverse(M.begin(),M.end());for(int&x:M)x=(mo-x)%mo;M.push_back(1);
	for(;n;n>>=1,B=divmod(mul(B,B),M))
		if(n&1)A=divmod(mul(A,B),M);
	int ans=0,i;for(i=0;i<a.size() && i<A.size();++i)ans=(ans+1ll*a[i]*A[i])%mo;
	return ans;
}
char c[N];
int f[2][N][N],i,j,k,ans,a[N*4],b[N*4],nw,n,nn;
int main(){
	scanf("%s%d",c+1,&nn);n=strlen(c+1);
	nw=0;f[0][0][n+1]=1;
	for(k=1;k<=n*4;++k){
		memset(f[nw^=1],0,sizeof f[0]);
		for(i=n+1;i>1;--i)for(j=0;j+i<=n+1;++j){
			int l=j,r=j+i,x=f[!nw][l][r];
			if(c[l+1]==c[r-1])add(f[nw][l+1][r-1],x),add(f[nw][l][r],x*25);
				else add(f[nw][l+1][r],x),add(f[nw][l][r-1],x),add(f[nw][l][r],x*24);
		}
		for(i=0;i<=n;++i)add(a[k],f[nw][i][i+1]);
		for(i=1;i<=n;++i)add(a[k],f[nw][i][i]),add(b[k],f[nw][i][i]);
	}
	for(i=2;i<=n*4;++i)add(a[i],a[i-1]*26);
	int ans=calc(V(a,a+n*4+1),nn+n>>1);
	if((nn+n)&1)ans=(ans*26+calc(V(b,b+n*4+1),nn+n+1>>1))%mo;
	printf("%d\n",ans);
	return 0;
}