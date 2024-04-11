#include<bits/stdc++.h>
using namespace std;
int a[210],lef[110],rig[110],n,b[110][110],id[110];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n*2;++i){
		scanf("%d",&a[i]);
		if(!lef[a[i]])lef[a[i]]=i;
		else rig[a[i]]=i;
	}
	int ans=0;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j){
			int ni=i,nj=j;
			if(lef[ni]>lef[nj])swap(ni,nj);
			if(rig[ni]<lef[nj])ans+=0;
			else if(rig[ni]>rig[nj])ans+=2;
			else ans+=1;
		}
	printf("%d",ans);
}