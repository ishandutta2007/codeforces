#include <cstring>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>
#include <cctype>
#include <ctime>
#include <cstdio>
#include <set>
#define rep(i,n) for(int i=0;i<n;i++)
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();e++)
using namespace std;
typedef long long int64;

const int MAX_N=100;
int lcm[MAX_N][MAX_N];
int gcd[MAX_N][MAX_N];
int n,m;
set<int> divs;

int Min[MAX_N][MAX_N];
int Max[MAX_N][MAX_N];
int ans[MAX_N];

int get(int a,int x){
	int cnt=0;
	while(a%x==0)cnt++,a/=x;
	return cnt;
}

bool failed=false;
int val[MAX_N];

void dfs(int u){
	if(failed)return;
	rep(v,n)if(Min[u][v]!=-1){
		if(val[u]==Min[u][v]){
			if(val[v]!=-1&&val[v]!=Max[u][v]){
				failed=true;
				return;
			}
			if(val[v]!=-1)continue;
			val[v]=Max[u][v];
			dfs(v);
		} else if(val[u]==Max[u][v]){
			if(val[v]!=-1&&val[v]!=Min[u][v]){
				failed=true;
				return;
			}
			if(val[v]!=-1)continue;
			val[v]=Min[u][v];
			dfs(v);
		} else {
			failed=true;
			return;
		}
	}
}

int main(){
	cin>>n>>m;
	memset(lcm,-1,sizeof lcm);
	memset(gcd,-1,sizeof gcd);
	rep(i,m){
		int a,b,l,g;
		cin>>a>>b>>g>>l;
		--a;--b;
		lcm[a][b]=lcm[b][a]=l;gcd[a][b]=gcd[b][a]=g;
		if(l%g!=0){
			printf("NO\n");
			return 0;
		}
		int x=l;
		for(int i=2;i*i<=x;i++)
			if(x%i==0){
				divs.insert(i);
				while(x%i==0)x/=i;
			}
		if(x>1)divs.insert(x);
	}
	fill(ans,ans+n,1);

	foreach(e,divs){
		int it=*e;
		memset(Max,-1,sizeof Max);
		memset(Min,-1,sizeof Min);
		rep(i,n)rep(j,n)if(lcm[i][j]!=-1){
			Max[i][j]=get(lcm[i][j],it);
			Min[i][j]=get(gcd[i][j],it);
		}
		memset(val,-1,sizeof val);
		int oldVal[MAX_N];
		failed=false;
		rep(i,n)if(val[i]==-1){
			rep(j,n)if(Min[i][j]!=-1){
				memcpy(oldVal,val,sizeof val);
				val[i]=Min[i][j];
				dfs(i);
				if(!failed)continue;
				failed=false;
				memcpy(val,oldVal,sizeof val);
				val[i]=Max[i][j];
				dfs(i);
				break;
			}
			if(val[i]==-1){
				val[i]=0;
			}
			if(failed)
				break;
		}
		if(failed){
			puts("NO");
			return 0;
		}

		rep(i,n){
			rep(j,val[i])
				ans[i]*=it;
		}
	}

	puts("YES");
	rep(i,n)printf("%d ",ans[i]);
	cout<<endl;
}