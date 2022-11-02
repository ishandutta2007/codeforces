#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const int N=110000;
int a[N],wei[N],r1,r2;
bool can[N],ans[N];
int n,m;
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);n--;
		rep(i,1,m){
			scanf("%d",&a[i]);wei[i]=a[i];ans[i]=0;can[i]=1;
		}
		r1=r2=0;int shiwang=0;
		rep(i,1,n){
			int x,y;scanf("%d%d",&x,&y);
			if(y==1){
				if(!shiwang)shiwang=i;
			}
			
			if(!shiwang&&x==0)r1++;
			if(x==0)r2++;
			
			if(shiwang)can[x]=0;
			
			a[x]--;
			if(!shiwang)wei[x]--;
		}
		if(!shiwang){
			rep(i,1,m)if(a[i]<=r2)printf("Y");else printf("N");printf("\n");
		}
		else{
			int lu=0;
			rep(i,1,m)if(can[i]&&wei[i]<=r1){
				ans[i]=1;if(r2-wei[i]>lu)lu=r2-wei[i];
			}
			rep(i,1,m){
				if(a[i]<=lu)ans[i]=1;
				if(ans[i])printf("Y");else printf("N");
			}
			printf("\n");
		}
	}
	return 0;
}