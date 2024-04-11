#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n,t; long long Ans;
int q[N],a[N],la[N][40],o[N][40],tot[N];
int main(){
	scanf("%d",&n);
	t=1; q[1]=0; a[0]=2e9;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		tot[i]=1;
		la[i][1]=i;
		int tmp=o[i][1]=a[i];
		for (int j=1;j<=tot[i-1];j++){
			tmp|=o[i-1][j];
			if (tmp!=o[i][tot[i]])
				o[i][++tot[i]]=tmp;
			la[i][tot[i]]=la[i-1][j];
		}
		for (;t&&a[q[t]]<=a[i];t--);
		q[++t]=i;
		for (int j=1;j<=tot[i];j++){
			int l=1,r=t,ans=0;
			while (l<=r){
				int mid=(l+r)/2;
				if (a[q[mid]]>=o[i][j])
					ans=mid,l=mid+1;
				else r=mid-1;
			}
			if (!ans) continue;
			l=la[i][j]; r=j==1?i:la[i][j-1]-1;
			Ans+=max(0,r-max(q[ans]+1,l)+1);
		}
	} 
	printf("%lld",Ans);
}