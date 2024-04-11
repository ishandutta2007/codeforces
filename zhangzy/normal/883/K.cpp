#include<bits/stdc++.h>
using namespace std;

map<int,int>mp;
map<int,int>::iterator it;

int n,a[202000],b[202000],ans[202000];
struct L{
	int st,en,id;
}l[202000];
long long tot=0;

void doit(L the){
	int pos=the.id;
	it=mp.lower_bound(pos);
	int p1,p2=it->first;
	it--; p1=it->first;
	ans[pos]=the.en;
	if (p1) ans[pos]=min(ans[pos],ans[p1]+abs(pos-p1));
	if (p2!=n+1) ans[pos]=min(ans[pos],ans[p2]+abs(pos-p2));
	if (ans[pos]<the.st) exit(0*printf("-1"));
	mp[pos]=1;
}

bool cmp(L l1,L l2){
	return l1.en<l2.en;
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
		b[i]+=a[i];
		l[i]=(L){a[i],b[i],i};
	}
	sort(l+1,l+n+1,cmp);
	mp.clear(); mp[0]=mp[n+1]=1;
	for (int i=1;i<=n;i++){
		doit(l[i]);
	}
	for (int i=1;i<=n;i++)
		tot+=ans[i]-a[i];
	cout<<tot<<endl;
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
}