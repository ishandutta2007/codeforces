#include<bits/stdc++.h>
const int N=3605,mo=998244353;
int H,W,n,i,j,ch,cw,r1,c1,r2,c2,fh[N][N],fw[N][N],gh[N][N],gw[N][N],C[N][N],fac[N],ans;
bool bh[N],bw[N];
int main(){
	for(i=**C=1;i<N;++i)for(j=*C[i]=1;j<=i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
	for(i=*fac=1;i<N;++i)fac[i]=1ll*fac[i-1]*i%mo;
	scanf("%d%d%d",&H,&W,&n);ch=H;cw=W;
	for(i=1;i<=n;++i){
		scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
		for(j=r1;j<=r2;++j)bh[j]=1,--ch;
		for(j=c1;j<=c2;++j)bw[j]=1,--cw;		
	}
	fh[0][0]=1;
	for(i=1;i<=H;++i){
		memcpy(fh[i],fh[i-1],H+1<<2);
		if(i>1 && !bh[i] && !bh[i-1])for(j=0;j<H;++j)fh[i][j+1]=(fh[i][j+1]+fh[i-2][j])%mo;
	}
	for(i=0;i*2<=ch;++i)for(j=0;j<=ch-i*2;++j)gh[i][j]=1ll*fh[H][i]*C[ch-i*2][j]%mo;
	fw[0][0]=1;
	for(i=1;i<=W;++i){
		memcpy(fw[i],fw[i-1],H+1<<2);
		if(i>1 && !bw[i] && !bw[i-1])for(j=0;j<W;++j)fw[i][j+1]=(fw[i][j+1]+fw[i-2][j])%mo;
	}
	for(i=0;i*2<=cw;++i)for(j=0;j<=cw-i*2;++j)gw[i][j]=1ll*fw[W][i]*C[cw-i*2][j]%mo;
	for(i=0;i<N;++i)for(j=0;j<N;++j)ans=(ans+1ll*gh[i][j]*gw[j][i]%mo*fac[i]%mo*fac[j])%mo;
	printf("%d\n",ans);
	return 0;
}