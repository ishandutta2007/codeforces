#include<bits/stdc++.h>
#define N 200005
using namespace std;
struct LZH{
	int v,q;
	bool operator <(const LZH &b)const{
		if (q!=b.q)
			return q>b.q;
		return v<b.v;
	}
}p[N];
struct que{
	int b,id,ans;
	bool operator <(const que &a)const{
		return b<a.b;
	}
	bool operator <(const int &a)const{
		return b<a;
	}
}q[N];
struct wzp{
	int l,r,del,ans;
};
vector<wzp> v;
int n,k;
bool cmp(que a,que b){
	return a.id<b.id;
}
void rebuild(){
	for (int i=0;i<v.size();i++)
		for (int j=v[i].l;j<v[i].r;j++)
			q[j].ans+=v[i].ans,q[j].b-=v[i].del;
	sort(q,q+k); v.clear();
	v.push_back((wzp){0,k,0,0});
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d%d",&p[i].v,&p[i].q);
	sort(p,p+n);
	scanf("%d",&k);
	for (int i=0;i<k;i++)
		scanf("%d",&q[i].b),q[i].id=i;
	rebuild();
	for (int i=0;i<n;i++){
		int c=p[i].v;
		for (int j=0,sz=v.size();j<sz;j++)
			if (q[v[j].l].b-v[j].del>=c)
				v[j].del+=c,++v[j].ans;
			else if (q[v[j].r-1].b-v[j].del>=c){
				int pos=lower_bound(q+v[j].l,q+v[j].r,c+v[j].del)-q;
				v.push_back((wzp){pos,v[j].r,v[j].del+c,v[j].ans+1});
				v[j].r=pos;
			}
		if (v.size()>450)
			rebuild();
	}
	rebuild();
	sort(q,q+k,cmp);
	for (int i=0;i<k;i++)
		printf("%d ",q[i].ans);
}