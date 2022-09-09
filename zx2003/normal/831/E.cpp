#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=100010;
struct treearray{
	static const int maxn=510000;
	int a[maxn],l[maxn],n;
	void init(int x){
		n=x;
		for(int i=1;i<=x;i++){
			a[i]=0;
			l[i]=i&-i;
		}
	}
	void add(int x,int y){
		for(int i=x;i<=n;i+=l[i])a[i]+=y;
	}
	int query(int x){
		int ans=0;
		for(int i=x;i;i-=l[i])ans+=a[i];
		return ans;
	}
	int sum(int x,int y){
		return query(y)-query(x-1);
	}
}t;
int n,i,a[N],j,k,x,y;
pair<int,int> b[N];
long long ans;
int main(){
	scanf("%d",&n);
	t.init(n);
	for(i=1;i<=n;++i){
		scanf("%d",&a[i]);
		b[i]=make_pair(a[i],i);
		t.add(i,1);
	}
	sort(b+1,b+n+1);
	for(i=1;i<=n;i=k+1){
		x=0;
		for(k=i;b[k].first==b[i].first;++k)
			if(b[k].second>j){
				if(b[k].second-j>x)x=b[k].second-j,y=b[k].second;
			}else if(b[k].second+n-j>x)x=b[k].second+n-j,y=b[k].second;
		--k;
		if(y>j)ans+=t.sum(j+1,y);
			else ans+=t.sum(j+1,n)+t.sum(1,y);
		j=y;
		for(int j=i;j<=k;++j)t.add(b[j].second,-1);
	}
	cout<<ans<<endl;
	return 0;
}