#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=5007;
int n,a[N],cnt[N],f[N];
vector<int>vec[N];
bool ok[N][N];
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)vec[i]={0};
	for(int i=1;i<=n;i++)a[i]=read(),vec[a[i]].push_back(i);
	for(int i=1;i<=n;i++)vec[i].push_back(n+1);
	for(int l=1;l<=n;l++){
		fill(cnt+1,cnt+n+1,0),ok[l][l-1]=true;
		int mx=0;
		for(int r=l;r<=n;r++){
			mx=max(mx,++cnt[a[r]]);
			ok[l][r]=(r-l+1)%2==0 && mx*2<=r-l+1;	
		}
	}
	ok[n+1][n]=true;
	int ans=0;
	for(int x=1;x<=n;x++){
		for(int i=1;i<(int)vec[x].size();i++){
			int p=vec[x][i];f[p]=-1e9;
			for(int j=0;j<i;j++){
				int q=vec[x][j];
				if(ok[q+1][p-1])f[p]=max(f[p],f[q]+1);	
			}
		}
		ans=max(ans,f[n+1]-1);
	}
	cout<<ans<<endl;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	int test=read();
	while(test--)work();
	return 0;
}