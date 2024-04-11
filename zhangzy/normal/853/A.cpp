#include<bits/stdc++.h>
#define ll long long
using namespace std;

map<int,int>mp;
map<int,int>::iterator it;
int n,k,tim[301000];
struct P{
	int id,val;
}p[301000];
ll ans=0;

bool cmp(P p1,P p2){
	return p1.val>p2.val;
}

int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%d",&p[i].val);
		p[i].id=i;
	}
	sort(p+1,p+n+1,cmp);
	mp.clear();
	for (int i=k+1;i<=k+n;i++){
		mp[i]=1;
	}
	int x;
	for (int i=1;i<=n;i++){
		it=mp.lower_bound(p[i].id);
		x=it->first;
		mp.erase(x);
		ans+=(ll)p[i].val*(x-p[i].id);
		tim[p[i].id]=x;
	}
	cout<<ans<<endl;
	for (int i=1;i<=n;printf("%d ",tim[i++]));
}