#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,x1,x2,x11,x22,i,j,c[N],p,q,r,s;
bool fl;
vector<int>ans1,ans2;
pair<int,int>a[N],b[N];
int xba,xbb;
map<int,vector<int> >mp;
void OK(){
	puts("Yes");
	if(p<r)for(i=p;i<r;++i)ans1.push_back(i);
		else for(i=r;i<p;++i)ans2.push_back(i);
	i=max(p,r);
	for(;i<=n && ans1.size()<q;++i)ans1.push_back(i);
	for(;i<=n && ans2.size()<s;++i)ans2.push_back(i);
	for(;ans1.size()>q;ans1.pop_back());
	for(;ans2.size()>s;ans2.pop_back());
	printf("%d %d\n",int(ans1.size()),int(ans2.size()));
	for(i=0;i<ans1.size();++i){
		int x=c[ans1[i]];
		printf("%d ",mp[x].back());
		mp[x].pop_back();
	}
	puts("");
	for(i=0;i<ans2.size();++i){
		int x=c[ans2[i]];
		printf("%d ",mp[x].back());
		mp[x].pop_back();
	}
	puts("");
	exit(0);
}
int main(){
	scanf("%d%d%d",&n,&x1,&x2);
	for(i=1;i<=n;++i)scanf("%d",c+i),mp[c[i]].push_back(i);
	sort(c+1,c+n+1);
	i=1;x11=x1-1;x22=x2-1;p=q=1;
	for(;i<=x11;i=j+1){
		j=x11/(x11/i);
		r=(x1+i-1)/i;
		for(;p<=n && c[p]<i;++p);
		if(p<=n && n-p+1>=r)a[++xba]=make_pair(p,r);
	}
	for(;p<=n && c[p]<x1;++p);
	if(p<=n)a[++xba]=make_pair(p,1);
	for(i=1;i<=x22;i=j+1){
		j=x22/(x22/i);
		s=(x2+i-1)/i;
		for(;q<=n && c[q]<i;++q);
		if(q<=n && n-q+1>=s)b[++xbb]=make_pair(q,s);
	}
	for(;q<=n && c[q]<x2;++q);
	if(q<=n)b[++xbb]=make_pair(q,1);
	if(!xba || !xbb){
		return puts("No"),0;
	}
	for(i=1;i<=xba;++i){
		p=a[i].first,q=a[i].second;
		r=b[xbb].first,s=b[xbb].second;
		if(n-min(p,r)+1>=q+s)OK();
	}
	for(i=1;i<=xbb;++i){
		p=a[xba].first,q=a[xba].second;
		r=b[i].first,s=b[i].second;
		if(n-min(p,r)+1>=q+s)OK();
	}
	puts("No");
	return 0;
}