#include <cstdio>
const int PW=20,N=3e5+10;
int T,n,a[N],num[N],rev[N],mn[PW][N],mx[PW][N];
inline int md(int x,int y){return (x+y)>>1;}
inline int min(int x,int y){return x<y?x:y;}
inline int max(int x,int y){return x>y?x:y;}
int gmin(int l,int r){
	int p=num[r-l+1];
	return min(mn[p][l],mn[p][r-(1<<p)+1]);
}
int gmax(int l,int r){
	int p=num[r-l+1];
	return max(mx[p][l],mx[p][r-(1<<p)+1]);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);int ans=0;
		for(int i=1;i<=n;++i){
			num[i]=num[i-1];
			if(i==(1<<(num[i]+1)))++num[i];
		}
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),rev[a[i]]=i,mn[0][i]=mx[0][i]=a[i];
		for(int i=1;i<PW;++i)for(int j=1;j+(1<<i)-1<=n;++j)mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<(i-1))]),mx[i][j]=max(mx[i-1][j],mx[i-1][j+(1<<(i-1))]);
		for(int p=1;p!=n;){
			++ans;
			if(a[p+1]>a[p]){
				int mid,L=p+1,R=n;
				while(L!=R){
					mid=md(L,R+1);
					if(gmin(p,mid)<a[p])R=mid-1;
					else L=mid;
				}
				p=rev[gmax(p,L)];
			}
			else{
				int mid,L=p+1,R=n;
				while(L!=R){
					mid=md(L,R+1);
					if(gmax(p,mid)>a[p])R=mid-1;
					else L=mid;
				}
				p=rev[gmin(p,L)];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}