#include<bits/stdc++.h>
const int S=65539,mo=1e9+7;
char c[505];
int xb,f[505][S],i,j,len,ans,nn,aa[19],bb[19];
inline void red(int&a){a+=a>>31&mo;}
inline void out(int*a){for(int j=0;j<65536;++j)if(a[j])printf("%d ",j);puts("hufikdshuyisfdauhyijklsdfakjhsdfhjklsdfhjkul");}
inline void orr(int*a,int*b,int*c){
	static int A[S],B[S],C[S];int i,j,k,m;
	memcpy(A,a,65536<<2);memcpy(B,b,65536<<2);
	for(i=2;i<=65536;i<<=1)for(j=0,m=i>>1;j<65536;j+=i)
		for(k=0;k<m;++k)red(A[j+k+m]+=A[j+k]-mo),red(B[j+k+m]+=B[j+k]-mo);
	for(i=0;i<65536;++i)C[i]=1ll*A[i]*B[i]%mo;
	for(i=2;i<=65536;i<<=1)for(j=0,m=i>>1;j<65536;j+=i)
		for(k=0;k<m;++k)red(C[j+k+m]-=C[j+k]);
	for(i=0;i<65536;++i)red(c[i]+=C[i]-mo);
}
inline void andd(int*a,int*b,int*c){
	static int A[S],B[S],C[S];int i,j,k,m;
	memcpy(A,a,65536<<2);memcpy(B,b,65536<<2);
	for(i=2;i<=65536;i<<=1)for(j=0,m=i>>1;j<65536;j+=i)
		for(k=0;k<m;++k)red(A[j+k]+=A[j+k+m]-mo),red(B[j+k]+=B[j+k+m]-mo);
	for(i=0;i<65536;++i)C[i]=1ll*A[i]*B[i]%mo;
	for(i=2;i<=65536;i<<=1)for(j=0,m=i>>1;j<65536;j+=i)
		for(k=0;k<m;++k)red(C[j+k]-=C[j+k+m]);
	for(i=0;i<65536;++i)red(c[i]+=C[i]-mo);
}
int dfs(int l,int r){
	int i,s=0,id=++xb;
	if(l==r){
		int y=c[l]<'a',z=y?c[l]-'A':c[l]-'a';
		if(c[l]=='?'){
			for(y=0;y<2;++y)for(z=0;z<4;++z)
				for(i=0;i<65536;++i){
					for(j=0;j<16;++j)if((j>>z&1)^1^((i>>j&1)^y))break;
					if(j==16)f[xb][i]++;
				}
		}else for(i=0;i<65536;++i){
			for(j=0;j<16;++j)if((j>>z&1)^1^((i>>j&1)^y))break;
			if(j==16)f[xb][i]++;
		}
		return xb;
	}
	for(i=l;i<=r;++i){
		if(c[i]=='(')++s;
		if(c[i]==')')--s;
		if(!s)break;
	}
	int lc=dfs(l+1,i-1),rc=dfs(i+3,r-1);
	if(c[i+1]!='&')orr(f[lc],f[rc],f[id]);
	if(c[i+1]!='|')andd(f[lc],f[rc],f[id]);
	return id;
}
int main(){
	scanf("%s",c+1);len=strlen(c+1);
	dfs(1,len);
	scanf("%d",&nn);
	for(i=1;i<=nn;++i){
		int x;
		for(j=0;j<4;++j)scanf("%d",&x),aa[i]|=x<<j;
		scanf("%d",bb+i);
	}
	for(i=0;i<65536;++i){
		for(j=1;j<=nn;++j)if((i>>aa[j]&1)!=bb[j])break;
		if(j>nn)red(ans+=f[1][i]-mo);
	}
	printf("%d\n",ans);
	return 0;
}