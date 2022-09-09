#include<bits/stdc++.h>
const int U=2e6,mo=1e9+7;
int p[U/10],mn[U+5],pcnt,i,j,x,n,a[200005],c[U+5],c2[U+5],ans=1,zz;
bool b[U+5];
void ins(int x){
	bool fl=0;
	for(;x>1;){
		int y=mn[x],z=0;
		for(;x%y==0;x/=y,++z);
		if(z>c[y])c[y]=z,c2[y]=1,fl=1;else if(z==c[y])++c2[y];
	}
	if(!fl)zz=1;
}
bool ck(int x){
	bool fl=0;
	for(;x>1;){
		int y=mn[x],z=0;
		for(;x%y==0;x/=y,++z);
		if(z==c[y] && c2[y]==1)fl=1;
	}
	return fl;
}
int main(){
	for(i=2;i<=U;++i){
		if(!b[i])p[++pcnt]=i,mn[i]=i;
		for(j=1;j<=pcnt;++j){
			x=i*p[j];if(x>U)break;
			b[x]=1;mn[x]=p[j];if(i%p[j]==0)break;
		}
	}
	scanf("%d",&n);for(i=1;i<=n;++i)scanf("%d",a+i);
	std::sort(a+1,a+n+1);
	for(i=n;i;--i){
		if(c[a[i]])--a[i];
		ins(a[i]);
	}
	for(i=1;i<=n;++i)if(!ck(a[i]))zz=1;
	for(i=2;i<=U;++i)for(j=1;j<=c[i];++j)ans=1ll*ans*i%mo;
	printf("%d\n",(ans+zz)%mo);
	return 0;
}