#include<bits/stdc++.h>
using namespace std;
typedef vector<int>V;
const int N=8005;
char ibuf[1<<24],*ih=ibuf;
inline void read(int&x){
	for(;!isdigit(*ih);++ih);
	for(x=0;isdigit(*ih);x=x*10+*ih++-48);
}
int n,i,j,k,x,ind[N];
bitset<N>b[N];
bool bb[N];
int main(){
	scanf("%d",&n);
	fread(ibuf,1,1<<24,stdin);
	for(i=1;i<=n;++i)for(j=0;j<n>>2;++j){
		for(;isspace(*ih);++ih);x=*ih++;x=isdigit(x)?x-'0':x-'A'+10;
		for(k=0;k<4;++k)b[i].set(1+(j<<2|3-k),x>>k&1);
	}
	vector<int>ve(n);for(i=0;i<n;++i)ve[i]=i+1;
	for(i=1;i<=n;++i)ind[i]=n-1-b[i].count();
	sort(ve.begin(),ve.end(),[&](int x,int y){return ind[x]>ind[y];});
	long long ans=0;
	memset(bb+1,1,n);
	for(;!ve.empty() && ind[ve.back()]==n-ve.size();)bb[ve.back()]=0,ve.pop_back(),ans+=(614ll*n+1)*ve.size();
	if(ve.empty()){printf("%lld\n",ans);return 0;}
	ans+=3ll*ve.size()*(ve.size()-1)>>1;
	V P,Q;
	x=ve.back();
	for(i=1;i<=n;++i)if(bb[i]){if(i==x || b[i][x])P.push_back(i);else Q.push_back(i);}
	auto cmp=[&](int x,int y){return b[x][y];};
	sort(P.begin(),P.end(),cmp);sort(Q.begin(),Q.end(),cmp);
	auto doo=[&](V P,V Q,bool fl){
		static int in[N];
		for(i=P.size()-1,j=Q.size()-1;i>=0;--i){
			for(;j>=0 && b[Q[j]][P[i]];--j);
			in[i]=Q.size()-j-1;
			if(j==-1 && fl)ans+=in[P.size()-1];
		}
		for(i=0;i<P.size();i=j){
			for(j=i;j<P.size() && in[i]==in[j];++j);
			ans+=1ll*(j-i)*(j-i-1)>>1;
		}
	};
	doo(P,Q,0);doo(Q,P,1);printf("%lld\n",ans);
}