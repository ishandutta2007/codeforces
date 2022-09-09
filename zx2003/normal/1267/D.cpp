#include<bits/stdc++.h>
const int N=269;
int n,s1[N],s2[N],i,j,x,a[8],cnt,u[N],v[N],xb,tp[N];
bool b[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)for(j=0;j<3;++j)scanf("%d",&x),s1[i]|=x<<j;
	for(i=1;i<=n;s2[i]&=s1[i],++i)for(j=0;j<3;++j)scanf("%d",&x),s2[i]|=x<<j;
	a[7]=1;b[1]=1;cnt=1;
	for(;cnt<n;cnt++){
		for(i=1;i<=n;++i)if(!b[i]){
			if(s1[i]==0 && a[0])break;
			if(s1[i]==1 && a[1])break;
			if(s1[i]==2 && a[2])break;
			if(s1[i]==3 && (a[3] || (a[1] && a[2])))break;
			if(s1[i]==4 && a[4])break;
			if(s1[i]==5 && (a[5] || (a[1] && a[4])))break;
			if(s1[i]==6 && (a[6] || (a[2] && a[4])))break;
			if(s1[i]==7)break;
		}
		if(i>n){puts("Impossible");return 0;}
		if(a[s1[i]])u[++xb]=a[s1[i]],v[xb]=i;
			else if(s1[i]==3)u[++xb]=a[1],v[xb]=i,u[++xb]=a[2],v[xb]=i;
				else if(s1[i]==5)u[++xb]=a[1],v[xb]=i,u[++xb]=a[4],v[xb]=i;
					else u[++xb]=a[2],v[xb]=i,u[++xb]=a[4],v[xb]=i;
		a[a[s1[i]]?tp[i]=1,s2[i]:s1[i]]=i;b[i]=1;
	}
	puts("Possible");
	for(i=1;i<=n;++i)printf("%d ",tp[i]);printf("\n%d\n",xb);
	for(i=1;i<=xb;++i)printf("%d %d\n",u[i],v[i]);
	return 0;
}