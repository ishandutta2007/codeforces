#include<bits/stdc++.h>
using namespace std;
map<int,int> m;
map<int,int>::iterator it;
const int N=200010;
struct seg{
	int l,r,c;
}a[N],b[N];
bool cmp1(const seg a,const seg b){
	return a.l<b.l;
}
bool cmp2(const seg a,const seg b){
	return a.r<b.r;
}
int n,i,j,x,ans=-1,y;
int main(){
	scanf("%d%d",&n,&x);
	for(i=1;i<=n;++i)scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].c),b[i]=a[i];
	sort(a+1,a+n+1,cmp1);
	sort(b+1,b+n+1,cmp2);
	for(i=j=1;i<=n;++i){
		for(;j<=n && b[j].r<a[i].l;++j)
			if(!m.count(b[j].r-b[j].l+1))m[b[j].r-b[j].l+1]=b[j].c;
				else{
					it=m.find(b[j].r-b[j].l+1);
					if(it->second>b[j].c)it->second=b[j].c;
				}
		y=a[i].r-a[i].l+1;
		if(m.count(x-y))if(ans==-1 || ans>a[i].c+m[x-y])ans=a[i].c+m[x-y];
	}
	printf("%d\n",ans);
	return 0;
}