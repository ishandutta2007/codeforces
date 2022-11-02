#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
const int N=150005;
int n,m,fa[N],id[N];
LL v[N];
int getf(int k){
	return fa[k]==k?k:fa[k]=getf(fa[k]);
}
bool cmp(int a,int b){
	return getf(a)<getf(b);
}
bool find(LL x){
	int L=1,R=m,mid;
	while (L<=R){
		mid=(L+R)>>1;
		if (v[mid]==x)
			return 1;
		if (x<v[mid])
			R=mid-1;
		else
			L=mid+1;
	}
	return 0;
}
LL HASH(int a,int b){
	if (a>b)
		swap(a,b);
	return 1LL*a*n+b;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		fa[i]=id[i]=i;
	for (int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[i]=HASH(a,b);
		a=getf(a),b=getf(b);
		fa[a]=b;
	}
	sort(v+1,v+m+1);
	sort(id+1,id+n+1,cmp);
	int last=1;
	for (int i=1;i<=n;i++)
		if (i==n||getf(id[i])!=getf(id[i+1])){
			for (int x=last;x<=i;x++)
				for (int y=x+1;y<=i;y++)
					if (!find(HASH(id[x],id[y]))){
						puts("NO");
						return 0;
					}
			last=i+1;
		}
	puts("YES");
	return 0;
}