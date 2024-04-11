#include<bits/stdc++.h>
const int N=300005,mo=1000000007;
int fac[N],vf[N],inv[N],n,i,j,C[2][2];
char a[N],b[N];
inline int cc(int y,int x){
	if(x<0)return 1;
	return 1ll*fac[y]*vf[x]%mo*vf[y-x]%mo;
}
inline int work(int l,int lst){
	if(l!=C[0][0]+C[0][1]+C[1][0]+C[1][1]+(lst!=0))return 0;
	if(l==0)return 1;
	int ans=0,i,j;
	for(i=0;i<2;++i){
		if(lst==0){
			if(C[0][i]==0)continue;
			--C[0][i];
		}
		for(j=0;j<2;++j){
			if(i==j && C[1][0]!=C[0][1])continue;
			if(i!=j && C[i][j]!=C[j][i]+1)continue;
			int ccc[2];
			if(i==j)ccc[i]=C[0][1]+1,ccc[i^1]=C[0][1];
				else ccc[i]=ccc[j]=C[i][j];
			if(ccc[0]==0 && C[0][0])
				continue;
			if(ccc[1]==0 && C[1][1])continue;
			ans=(ans+1ll*cc(ccc[0]+C[0][0]-1,ccc[0]-1)*cc(ccc[1]+C[1][1]-1,ccc[1]-1))%mo;
		}
		if(lst==0)++C[0][i];
	}
	return ans;
}
bool FL;
inline int calc(char*c){
	int i,j,n=strlen(c+1),ans=0,s=FL;
	if(n==1)return s;
	for(i=2;i<=n;++i){
		if(i>1)--C[c[i-2]-'0'][c[i-1]-48];
		for(int j=0;j<2;++j)for(int k=0;k<2;++k)if(C[j][k]<0)return ans;
		if(c[i]=='1'){
			if(!C[c[i-1]-48][0])continue;
			--C[c[i-1]-48][0];
			ans=(ans+work(n-i,i==1?-1:0))%mo;
			++C[c[i-1]-48][0];
		}
	}
	--C[c[i-2]-'0'][c[i-1]-'0'];
	for(i=0;i<2;++i)for(j=0;j<2;++j)if(C[i][j])s=0;
	return ans+s;
}
int main(){
	//freopen("s","r",stdin);
	static int c[2][2];
	for(i=2,*fac=fac[1]=*vf=vf[1]=inv[1]=1;i<N;++i){
		fac[i]=1ll*fac[i-1]*i%mo;
		inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
		vf[i]=1ll*vf[i-1]*inv[i]%mo;
	}
	scanf("%s%s",a+1,b+1);
	int tot=1,la=strlen(a+1),lb=strlen(b+1);
	for(i=0;i<2;++i)for(j=0;j<2;++j)scanf("%d",c[i]+j),tot+=c[i][j];
	if(la>tot || lb<tot)return puts("0"),0;
	if(la<tot){
		for(i=2;i<=tot;++i)a[i]='0';a[i]=0;a[1]='1';
	}
	if(lb>tot){
		for(i=1;i<=tot;++i)b[i]='1';b[i]=0;
	}
/*
	int bl=strlen(b+1);
	for(i=bl;b[i]=='1';--i)b[i]='0';
	if(!i){
		b[1]='1';
		memset(b+2,'0',bl);
	}else b[i]='1';
*/
	memcpy(C,c,sizeof c);FL=0;
	int x=calc(a);
	memcpy(C,c,sizeof c);FL=1;
	int y=calc(b);
	printf("%d\n",(y+mo-x)%mo);
	return 0;
}