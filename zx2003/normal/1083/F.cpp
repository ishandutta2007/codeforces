#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=450;
int n,k,Q,a[N],aa[N],b[N],oa[N],ob[N],i,j,x,y;
struct opt{int i,j,v;};
vector<opt>ve[N];
int ans1[N],ans2[N];
struct BS{
	int bl,bs,bel[N],be[M],en[M],buc[M][16399],a[N],ps[M],tot,n;
	inline void ini(int n,int*aa){
		int i,j;
		this->n=n;memcpy(a+1,aa+1,n<<2);
		bl=sqrt(n);
		for(i=1;i<=n;++i)bel[i]=(i-1)/bl+1;bs=bel[n];
		for(i=1;i<=n;++i)en[bel[i]]=i;for(i=n;i;--i)be[bel[i]]=i;
		for(i=1;i<=bs;++i)for(j=be[i]+1;j<=en[i];++j)a[j]^=a[j-1];
		for(i=1;i<=n;++i)++buc[bel[i]][a[i]];
		for(i=1;i<=bs;++i)ps[i]=ps[i-1]^a[en[i]];
		tot=0;for(i=1;i<=bs;++i)tot+=buc[i][ps[i-1]];
	}
	inline void mdy(int x,int v){
		int i,z=bel[x];
		for(i=x;i<=en[z];++i)--buc[z][a[i]],++buc[z][a[i]^=v];
		for(i=z;i<=bs;++i)ps[i]^=v;
		tot=0;for(i=1;i<=bs;++i)tot+=buc[i][ps[i-1]];
	}
	inline void clear(){
		for(int i=1;i<=n;++i)buc[bel[i]][a[i]]=0;
		memset(ps+1,0,bs<<2);
	}
}B;
int main(){
	scanf("%d%d%d",&n,&k,&Q);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;i<=n;++i)scanf("%d",b+i);
	memcpy(oa+1,a+1,n<<2);
	memcpy(ob+1,b+1,n<<2);
	for(i=1;i<=Q;++i){
		char c[9];
		scanf("%s%d%d",c,&x,&y);int&oy=*c=='a'?a[x]:b[x];
		ve[x%k].push_back((opt){i,(x+k-1)/k,y^oy});
		ve[(x+1)%k].push_back((opt){i,(x+k)/k,y^oy});
		oy=y;
	}
	for(i=1;i<=n+1;++i)oa[i]^=ob[i];for(i=n+1;i;--i)oa[i]^=oa[i-1];
	for(i=0;i<k;++i){
		x=0;for(j=i==0?k:i;j<=n+1;j+=k)aa[++x]=oa[j];
		B.ini(x,aa);
		auto mdy=[&](int l,int r){
			if(B.ps[B.bs]!=0)++ans2[l],--ans2[r];
				else ans1[l]+=B.n-B.tot,ans1[r]-=B.n-B.tot;
		};
		int lst=0;
		for(j=0;j<ve[i].size();++j){
			mdy(lst,ve[i][j].i);
			B.mdy(ve[i][j].j,ve[i][j].v);lst=ve[i][j].i;
		}
		mdy(lst,Q+1);
		B.clear();
	}
	for(i=1;i<=Q;++i)ans1[i]+=ans1[i-1],ans2[i]+=ans2[i-1];
	for(i=0;i<=Q;++i)printf("%d\n",ans2[i]?-1:ans1[i]);
}