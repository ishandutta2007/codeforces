#include<set>
#include<cstdio>
using std::set;
int i,j,k,l,n,x,a[55][55];
set<int> s[55][55];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			scanf("%d",&a[i][j]);
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			for(k=1;k<=n;++k)
				for(l=1;l<=n;++l)
					if(i!=k && j!=l){
						x=a[i][j]+a[k][l];
						s[i][l].insert(x);
						s[k][j].insert(x);
					}
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			if(a[i][j]>1 && s[i][j].find(a[i][j])==s[i][j].end())return puts("No"),0;
	return puts("Yes"),0;
}