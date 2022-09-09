#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#include<deque>
using namespace std;
map<int,deque<int> > m;
map<int,deque<int> >::iterator it;
const int N=100005;
int n,w,h,i,X[N],Y[N],b[N];
struct node{
	int g,p,t,id;
	bool operator<(const node&rhs)const{
		return p<rhs.p;
	}
}a[N];
int main(){
	scanf("%d%d%d",&n,&w,&h);
	for(i=1;i<=n;++i)scanf("%d%d%d",&a[i].g,&a[i].p,&a[i].t),a[i].id=i;
	sort(a+1,a+n+1);
	//x
	for(i=1;i<=n;++i)if(a[i].g&1)m[a[i].t-a[i].p].push_back(i);
	for(i=1;i<=n;++i)
		if(a[i].g&2){
			it=m.find(a[i].t-a[i].p);
			if(it==m.end() || it->second.empty())b[i]=i;
				else b[i]=it->second.back(),it->second.pop_back(),it->second.push_front(i);
		}
	m.clear();
	//y
	for(i=1;i<=n;++i)if(a[i].g&2)m[a[i].t-a[i].p].push_back(i);
	for(i=1;i<=n;++i)
		if(a[i].g&1){
			it=m.find(a[i].t-a[i].p);
			if(it==m.end() || it->second.empty())b[i]=i;
				else b[i]=it->second.back(),it->second.pop_back(),it->second.push_front(i);
		}
	//end
	for(i=1;i<=n;++i)
		if(a[i].g&1)X[a[b[i]].id]=a[i].p,Y[a[b[i]].id]=h;
			else X[a[b[i]].id]=w,Y[a[b[i]].id]=a[i].p;
	for(i=1;i<=n;++i)printf("%d %d\n",X[i],Y[i]);
	return 0;
}