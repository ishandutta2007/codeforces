#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct limit{
	int tp,a,b,c;
};
vector<limit> lim;

bool ok(int rt,int msk1,int child,int msk2){
	for (int i=0;i<lim.size();i++){
		limit tmp=lim[i];
		if (!(msk1&(1<<tmp.a))||!(msk1&(1<<tmp.b))) continue;
		if (((msk2>>tmp.a)&1)==((msk2>>tmp.b)&1)) continue;
		if (tmp.tp==0){
			if (tmp.b==rt) swap(tmp.a,tmp.b);
			if (tmp.a!=rt||tmp.b!=child) return 0;
		}
		else if (tmp.c!=rt) return 0;
	}
	return 1;
}

int n,m,q;
ll dp[1<<13][13];

int main(){

	scanf("%d%d%d",&n,&m,&q);
	
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		lim.push_back((limit){0,x-1,y-1,0});
	}
	
	for (int i=1;i<=q;i++){	
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if (x==y&&x!=z)
			return printf("0\n"),0;
		lim.push_back((limit){1,x-1,y-1,z-1});
	}
	
	for (int i=0;i<n;i++)
		dp[1<<i][i]=1;
	for (int msk=1;msk<(1<<n);msk++)
		for (int rt=0;rt<n;rt++)
			if (msk&(1<<rt)){
				int high=-1;
				for (int i=0;i<n;i++)
					if ((msk&(1<<i))&&i!=rt) high=i;
				if (high==-1) continue;
				int sub=(msk-1)&msk;
				for (;sub;sub=(sub-1)&msk)
					if ((sub&(1<<high))&&!(sub&(1<<rt)))
						for (int i=0;i<n;i++)
							if (sub&(1<<i))
								if (ok(rt,msk,i,sub))
									dp[msk][rt]+=dp[msk^sub][rt]*dp[sub][i];
			}
			
	printf("%lld\n",dp[(1<<n)-1][0]);
}