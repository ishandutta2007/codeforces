#include<bits/stdc++.h>
const int N=3e3+5;
int r,c,n,K,xx[N],yy[N],i,j,k,l,L[N],R[N],s[N],w[N],x,c2[N],su;
long long ans;
std::vector<int>a[N];
int main(){
	scanf("%d%d%d%d",&r,&c,&n,&K);--K;
	for(i=1;i<=n;++i)scanf("%d%d",xx+i,yy+i),a[xx[i]].push_back(yy[i]);
	for(i=1;i<N;++i)c2[i]=i*(i+1)>>1;
	for(i=1;i<=r;++i){
		memset(s+1,0,c<<2);su=0;
		for(j=1;j<=n;++j)if(xx[j]>=i)++s[yy[j]];
		x=0;for(j=1;j<=c+1;++j)if(s[j] || j==c+1)R[x]=j,L[j]=x,x=j;
		for(j=R[0];su+=c2[j-L[j]-1],j!=c+1;j=R[j]);
		for(j=k=R[0],x=s[j];j!=c+1;j=R[j],x+=s[j]){
			for(;k<j && x>K;x-=s[k],k=R[k]);
			w[j]=x<=K?(R[j]-j)*(j-L[k]):0;su+=w[j];
		}
		for(l=r;l>=i;--l){
			ans+=su;
			for(int u:a[l]){
				if(!--s[u])su+=(u-L[u])*(R[u]-u)-w[u],j=L[u]?L[u]:R[u],L[R[u]]=L[u],R[L[u]]=R[u];else j=u;
				x=s[j];for(k=j;L[k] && x<=K;k=L[k],x+=s[k]);
				for(;j!=c+1;j=R[j],x+=s[j]){
					for(;k<j && x>K;x-=s[k],k=R[k]);
					su-=w[j];w[j]=x<=K?(R[j]-j)*(j-L[k]):0;su+=w[j];
					if(L[k]>u)break;
				}
			}
		}
	}
	ans=1ll*c2[r]*c2[c]-ans;
	std::cout<<ans<<'\n';
	return 0;
}