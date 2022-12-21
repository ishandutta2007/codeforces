#include<bits/stdc++.h>
using namespace std;
#define N 3005
struct pa {
	int l,r,i;
};
#define pb push_back
long long ans;
int a[N][N],b[N];
long long s[N];
int n,m;
vector<pa>A;
int tot;
vector<long long>f;
inline void work(int l,int r,vector<pa>v,vector<long long>f) {
    int mid=(l+r)>>1;
    vector<pa>L,R;
    for (auto p:v) {
        if ((p.l==l)&&(p.r==r)) {
            for (int j=m;j>=b[p.i];j--)
                f[j]=max(f[j],f[j-b[p.i]]+s[p.i]);
        }
        else if (p.r<=mid) L.push_back(p);
        else if (p.l>mid) R.push_back(p);
        else {
            L.push_back(pa{p.l,mid,p.i});
            R.push_back(pa{mid+1,p.r,p.i});    
        }    
    }
    if (l==r) {
    	long long sum=0;
    	for (int i=0;i<=min(m,b[l]);i++) {
    		sum+=a[l][i];
    		ans=max(ans,sum+f[m-i]);
    	}
        return;
    }
    work(l,mid,L,f);
    work(mid+1,r,R,f);
}
int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {
		int k;
		scanf("%d",&k);
		b[i]=min(k,m);
		for (int j=1;j<=b[i];j++) scanf("%d",&a[i][j]),s[i]+=a[i][j];
		for (int j=b[i]+1;j<=k;j++) {
			int x;
			scanf("%d",&x);
		}
		A.pb(pa{1,i-1,i});
		A.pb(pa{i+1,n,i});
	}
	for (int i=0;i<=m;i++) f.pb(0);
	work(1,n,A,f);
	printf("%lld\n",ans);
}