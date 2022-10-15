#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=123,M=1007,mod=12345;
struct Mat{
	int n,m,a[N][N];
	int* operator [](int i){return a[i];}
	Mat(int _n=0,int _m=0){
		n=_n,m=_m;
		for(int i=0;i<n;i++)
			fill(a[i],a[i]+m,0);
	}
	Mat operator *(Mat q){
		assert(m==q.n);Mat res(n,q.m);
		for(int i=0;i<n;i++)
			for(int k=0;k<q.m;k++)
				for(int j=0;j<m;j++)
					res[i][k]=(res[i][k]+(ll)a[i][j]*q[j][k])%mod;
		return res;
	}
};
ll n;
int m,K,mul[M],cnt[M];
vector<int>vec[26];
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read(),m=read(),mul[0]=1;
	for(int i=1;i<=m;i++){
		char ch;while(!isalpha(ch=getchar()));
		int c=ch-65;cnt[i]=read();
		vec[c].push_back(i),mul[i]=mul[i-1]*cnt[i];
	}
	K=mul[m];
	Mat A(K,K);
	for(int i=0;i<K;i++)
		for(int k=0;k<26;k++){
			if(vec[k].empty())continue;
			int j=i;
			for(int l:vec[k]){
				int p=j%mul[l]/mul[l-1];
				j=j/mul[l]*mul[l]+j%mul[l-1]+mul[l-1]*((p+1)%cnt[l]);
			}
			A[i][j]++;
		}
	Mat ans(1,K);ans[0][0]=1;
	for(;n;n>>=1,A=A*A)if(n&1)ans=ans*A;
	int res=0;
	for(int i=0;i<K;i++){
		bool ok=1;
		for(int j=0;j<26;j++){
			if(vec[j].empty())continue;
			bool fl=0;
			for(int l:vec[j])fl|=i%mul[l]/mul[l-1]==0;
			if(!fl){ok=0;break;}
		}
		if(ok)(res+=ans[0][i])%=mod;
	}
	printf("%d\n",res);
	return 0;
}