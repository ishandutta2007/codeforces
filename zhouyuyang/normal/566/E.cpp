#include<bits/stdc++.h>
const int N=1005;
using namespace std;
bitset<N> s[N];
#define pa pair<int,int>
vector<pa > e[N];
int fa[N*2],n;
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void merge(int x,int y){
	fa[get(x)]=get(y);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int cnt,x;
		scanf("%d",&cnt);
		for (int j=1;j<=cnt;j++){
			scanf("%d",&x);
			s[x][i]=1;
		}
	}
	for (int i=1;i<=2*n;i++) fa[i]=i;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++){
			int cnt=(s[i]&s[j]).count();
			if (cnt==1){
				merge(i,j);
				merge(i+n,j+n);
			}
			else if (cnt==2&&n>2){
				merge(i,j+n);
				merge(i+n,j);
			}
			else{
				e[cnt].push_back(pa(i,j));
			}
		}
	if (e[n].size()==n*(n-1)/2){
		for (int i=2;i<=n;i++)
			printf("1 %d\n",i);
	}
	else if (e[n].size()==1){
		int u=-1,v=-1;
		for (int i=1;i<=n;i++)
			if (s[i].count()==n){
				if (u==-1) u=i;
				else v=i;
			}
		printf("%d %d\n",u,v);
		for (int i=1;i<=n;i++)
			if (i!=u&&i!=v){
				if (get(i)==get(u)){
					printf("%d %d\n",i,v);
					merge(i,v+n); merge(i+n,v);
				}
				else{
					printf("%d %d\n",i,u);
					merge(i,u+n); merge(i+n,u);
				}
			}
	}
	else{
		for (int i=n;i;i--)
			for (int j=0;j<e[i].size();j++){
				int u=e[i][j].first,v=e[i][j].second;
				if (get(u)==get(v)) continue;
				printf("%d %d\n",u,v);
				merge(u,v+n); merge(v,u+n);
			}
	}
}