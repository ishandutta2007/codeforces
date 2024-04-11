#include<bits/stdc++.h>
using namespace std;

int n,m,p,pos[101000],t;
map<int,map<int,int> >a;

void ok(){
	puts("YES");
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;++j)
			printf("%d ",p?a[j][i]%n*m+a[j][i]/n+1:a[i][j]+1);
		puts("");
	}
}
bool nea(int x,int y){
	return abs(x%m-y%m)+abs(x/m-y/m)<2;
}
bool pd(){
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j){
			if (i<n&&nea(a[i][j],a[i+1][j])) return 0;
			if (j<m&&nea(a[i][j],a[i][j+1])) return 0;
		}
	return 1;
}

int main(){
	cin>>n>>m; srand(time(0));
	if (max(n,m)<5){
		for (int i=1;i<=n;++i) for (int j=1;j<=m;++j) a[i][j]=t++;
		for (int tim=10000;tim--;){
			swap(a[rand()%n+1][rand()%m+1],a[rand()%n+1][rand()%m+1]);
			if (pd()) {ok();return 0;};
		}
		return 0*puts("NO");
	}
	if (n>m) p=1, swap(n,m);
	for (int j=1;j<=m;++j) pos[j]=j&1? j/2: j/2+(m-1)/2;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			a[i][(pos[j]+i%2)%m+1]=t++;
	if (p) swap(n,m);
	ok();
}