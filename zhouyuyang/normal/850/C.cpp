#include<bits/stdc++.h>
using namespace std;
map<int,int> mp,f;
int a[10005],n,cnt,ans;
int dfs(int x){
	if (f.find(x)!=f.end()) return f[x];
	int b[40],l=0,k=0;
	for (;(1<<k)<=x;k++);
	for (int i=1;i<k;i++){
		int y=0;
		for (int j=0;j<k;j++)
			if ((x>>j)&1)
				if (j>=i) y|=1<<(j-i);
				else y|=1<<j;
		b[++l]=dfs(y);
	}
	sort(b+1,b+l+1);
	l=unique(b+1,b+l+1)-b-1;
	for (int i=1;i<=l;i++)
		if (b[i]!=i-1) return f[x]=i-1;
	return f[x]=l;
}
void insert(int x,int s){
	if (!mp[x]) mp[x]=++cnt;
	a[mp[x]]|=1<<s;
} 
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x; scanf("%d",&x);
		for (int j=2;j*j<=x;j++)
			if (x%j==0){
				int tmp=0;
				for (;x%j==0;x/=j,tmp++);
				insert(j,tmp);
			}
		if (x!=1) insert(x,1);
	}
	for (int i=1;i<=cnt;i++) ans^=dfs(a[i]);
	puts(ans?"Mojtaba":"Arpa");
}