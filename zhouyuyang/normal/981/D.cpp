#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int n,k;
bool f[55][55];
ll trans[55][55],a[55],ans;
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]),a[i]+=a[i-1];
	for (int i=0;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			trans[i][j]=a[j]-a[i];
	for (int i=60;i>=0;i--){
		ans+=1ll<<i;
		memset(f,0,sizeof(f));
		f[0][0]=1;
		for (int j=1;j<=k;j++)
			for (int p=0;p<=n;p++)
				if (f[j-1][p])
					for (int q=p+1;q<=n;q++)
						if ((trans[p][q]&ans)==ans)
							f[j][q]=1;
		if (!f[k][n]) ans-=1ll<<i;
	}
	printf("%lld\n",ans);
}