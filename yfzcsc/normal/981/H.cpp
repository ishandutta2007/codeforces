#include<bits/stdc++.h>
#define mod 998244353
#define maxn 540000
using namespace std;
typedef long long ll;
namespace FFT{
	int bh[maxn],tmpA[maxn],tmpB[maxn],tmp[maxn],lim=maxn,w[2][maxn];
	int qpow(int a,int b){
		int ans=1,tmp=a;
		for(;b;b>>=1,tmp=1ll*tmp*tmp%mod)
			if(b&1)ans=1ll*ans*tmp%mod;
		return ans;
	}
	void init(int b){
		for(int i=1;i<(1<<b);i<<=1){
			int wn=qpow(3,(mod-1)/(i<<1));
			for(int j=0;j<i;++j)w[1][i+j]=(j?1ll*wn*w[1][i+j-1]%mod:1);
			wn=qpow(3,mod-1-(mod-1)/(i<<1));
			for(int j=0;j<i;++j)w[0][i+j]=(j?1ll*wn*w[0][i+j-1]%mod:1);
		}
	}
	void fft(int h[],int len,int flag){
		if(flag==-1)flag=0;
		for(int i=0,j=0;i<len;++i){
			if(i<j)swap(h[i],h[j]);
			for(int k=len>>1;(j^=k)<k;k>>=1);
		}
		for(int i=1;i<len;i<<=1)
			for(int j=0;j<len;j+=(i<<1))
				for(int k=0;k<i;++k){
					int x=h[j+k],y=1ll*h[j+k+i]*w[flag][i+k]%mod;
					h[j+k]=(1ll*x+y)%mod;
					h[j+k+i]=(1ll*x-y+mod)%mod;
				}
		if(flag==0){
			int x=qpow(len,mod-2);
			for(int i=0;i<len;++i)
				h[i]=1ll*h[i]*x%mod;
		}
	}
	void poly_mul(const int A[],int lenA,const int B[],int lenB,int C[],int lenc){
		int l=1,k=0,L=min(lenA,lenc)+min(lenB,lenc)+1;
		while(l<L)l<<=1,k++;
		memset(tmpA,0,l<<2);
		memset(tmpB,0,l<<2);
		memcpy(tmpA,A,min(lenA,lenc)<<2);
		memcpy(tmpB,B,min(lenB,lenc)<<2);
		fft(tmpA,l,1),fft(tmpB,l,1);
		for(int i=0;i<l;++i)tmpA[i]=1ll*tmpA[i]*tmpB[i]%mod;
		fft(tmpA,l,-1);
		for(int i=0;i<lenc&&i<L;++i)C[i]=tmpA[i];
		for(int i=L;i<lenc;++i)C[i]=0;
	}
	void poly_inv(int n,const int a[],int C[]){
		if(n==1){
			C[0]=qpow(a[0],mod-2);
			return ;
		}
		static int A[maxn];
		A[0]=qpow(a[0],mod-2);
		int m=(n+1)/2,len=1,k=0;
		poly_inv(m,a,C);
		while(len<n+n)len<<=1,k++;
		memcpy(A,a,n<<2);
		memset(A+n,0,(len-n)<<2);
		memset(C+m,0,(len-m)<<2);
		fft(A,len,1),fft(C,len,1);
		for(int i=0;i<len;++i)C[i]=1ll*(2ll-1ll*A[i]*C[i]%mod+mod)*C[i]%mod;
		fft(C,len,-1);
	}
	
	void poly_div(const int a[],int lena,const int b[],int lenb,int C[],int& plen){
		static int A[maxn],B[maxn];
		while(!a[lena-1]&&lena>=1)lena--;
		while(!b[lenb-1]&&lenb>=1)lenb--;
		if(lena<lenb){
			plen=1,C[0]=0;
			return ;
		}
		plen=lena-lenb+1;
		memcpy(A,a,lena<<2);
		memcpy(B,b,lenb<<2);
		reverse(A,A+lena);
		reverse(B,B+lenb);
		poly_inv(plen,B,tmp);
		poly_mul(tmp,plen,A,lena,C,plen);
		reverse(C,C+plen);
	}
	typedef vector<int> Poly;
	int SZ(const Poly& v){return v.size();}
	void upd(Poly& v){while(v.size()>1&&!v.back())v.pop_back();}
	Poly operator*(const Poly& a,const Poly& b){
		Poly ret(SZ(a)+SZ(b)-1);
		poly_mul(a.data(),SZ(a),b.data(),SZ(b),ret.data(),SZ(ret));
		upd(ret);
		return ret;
	}
	Poly operator/(const Poly& a,const Poly& b){
		int len;
		poly_div(a.data(),SZ(a),b.data(),SZ(b),tmp,len);
		Poly ret=Poly(tmp,tmp+len);
		upd(ret);
		return ret;
	}
	Poly operator-(const Poly& a,const Poly& b){
		Poly ret(max(SZ(a),SZ(b)));
		for(int i=0;i<SZ(ret);++i)
			ret[i]=(1ll*(i<SZ(a)?a[i]:0)-(i<SZ(b)?b[i]:0)+mod)%mod;
		upd(ret);
		return ret;
	}
	Poly operator+(const Poly& a,const Poly& b){
		Poly ret(max(SZ(a),SZ(b)));
		for(int i=0;i<SZ(ret);++i)
			ret[i]=(1ll*(i<SZ(a)?a[i]:0)+(i<SZ(b)?b[i]:0))%mod;
		upd(ret);
		return ret;
	}
	Poly operator%(const Poly& a,const Poly& b){
		int len;
		poly_div(a.data(),SZ(a),b.data(),SZ(b),tmp,len);
		poly_mul(b.data(),SZ(b),tmp,len,tmp,SZ(a));
		for(int i=0;i<SZ(a);++i)
			tmp[i]=(1ll*a[i]-tmp[i]+mod)%mod;
		for(len=SZ(a);len>1&&!tmp[len-1];len--);
		return Poly(tmp,tmp+len);
	}
	void print(const Poly& x){
		printf("\n[len=%d]",SZ(x));
		for(int i=0;i<SZ(x);++i)
			printf("%d ",x[i]);
		puts("");
	}
};
using namespace FFT;
int cas,n,wxh[maxn],akioi[maxn],lst[maxn],dp[maxn],ls[maxn],sz[maxn],ans,m;
vector<int>G[maxn];
Poly solve(int l,int r){
	if(l>r)return Poly{1};
	if(l==r)return Poly{1,wxh[l]};
	int mid=l+r>>1;
	return solve(l,mid)*solve(mid+1,r);
}
void dfs(int u,int f){
//	printf("{%d}",u);
	sz[u]=1;
	for(auto p:G[u])if(p!=f){
		dfs(p,u);
		ans=(ans+(ll)dp[u]*dp[p])%mod;
		dp[u]=(dp[u]+dp[p])%mod;
		sz[u]=(sz[u]+sz[p]);
	}
	int tp=0;
	for(auto p:G[u])if(p!=f)
		wxh[++tp]=sz[p];
	Poly ret=solve(1,tp);
	for(int i=0,z=1;i<=m&&i<ret.size();++i){
		dp[u]=(dp[u]+1ll*z*ret[i])%mod;
		z=1ll*(m-i)*z%mod;
	}
	if(u!=1){
		int p=n-sz[u];
		ret.push_back(0);
		for(int i=ret.size()-2;i>=0;--i)
			ret[i+1]=(ret[i+1]+1ll*p*ret[i])%mod;
	}
	cas++;
	for(auto p:G[u])if(p!=f){
		if(lst[sz[p]]!=cas){
			lst[sz[p]]=cas,akioi[sz[p]]=0;
			int iv=qpow(sz[p],mod-2),k=0,z=1;
			for(int i=ret.size()-1;i>=1;--i){
				int x=(ret[i]+k)%mod;
				int y=1ll*iv*x%mod;
				k=(mod-y)%mod,ls[i-1]=y;
			}
			for(int i=0,z=1;i<ret.size()-1&&i<=m;++i){
				akioi[sz[p]]=(akioi[sz[p]]+1ll*ls[i]*z)%mod;
				z=1ll*z*(m-i)%mod;
			}
		}
		ans=(ans+1ll*akioi[sz[p]]*dp[p])%mod;
	}
}
int main(){
	init(18);
	scanf("%d%d",&n,&m);
	if(m==1)return printf("%lld",(ll)n*(n-1)/2%mod),0;
	for(int i=2,u,v;i<=n;++i){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	printf("%d",ans);
}