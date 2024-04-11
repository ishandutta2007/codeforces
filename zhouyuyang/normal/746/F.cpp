#include<bits/stdc++.h>
#define N 200005
#define int long long
#define pa pair<int,int>
using namespace std;
int n,mx,k,allt,halft,top,cnt1,ans;
int a[N],b[N],bel[N];
struct cmp {
	bool operator ()(const int &x,const int &y) {
		return a[x]!=a[y]?a[x]>a[y]:x<y;
	}
};
set<int,cmp> s1,s2;
signed main() {
	scanf("%lld%lld%lld",&n,&mx,&k);
	for (int i=1; i<=n; i++)
		scanf("%lld",&b[i]),b[i]+=b[i-1];
	for (int i=1; i<=n; i++)
		scanf("%lld",&a[i]);
	top=1;
	for (int i=1; i<=n; i++) {
		s1.insert(i);
		cnt1++;
		bel[i]=1;
		allt+=a[i];
		halft+=a[i]/2;;
		if (cnt1>mx) {
			set<int,cmp>::iterator it=s1.end();
			int y=*(--it);
			s1.erase(it);
			s2.insert(y);
			bel[y]=2;
			halft-=a[y]/2;
			cnt1--;
		}
		for (;!s1.empty()&&allt-halft>k;){
			//if (i>=40000)
			//	printf("%d %d %d %d %d\n",i,top,allt,halft,bel[12266]);
			//if (s1.find(12266)==s1.end()) puts("233");
			if (bel[top]==1)
				s1.erase(s1.find(top)),halft-=a[top]/2,cnt1--;
			else s2.erase(s2.find(top));
			allt-=a[top];
			top++;
			if (cnt1<mx&&!s2.empty()) {
				int y=*s2.begin();
				bel[y]=1;
				halft+=a[y]/2;
				s2.erase(s2.find(y));
				s1.insert(y);
				cnt1++;
			}
		}
		if (allt-halft<=k)
			ans=max(ans,b[i]-b[top-1]);
	}
	printf("%lld",ans);
}