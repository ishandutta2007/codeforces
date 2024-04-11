#include<bits/stdc++.h>
using namespace std;
int n,a[1111],b[1111][1111],p,tp,t,u,v;
struct O{
	int u,v;
}st[1001000];
void add(int x,int y){
	st[++tp]=(O){x,y};
	b[x][y]=1; swap(a[x],a[y]);
}
vector<int>vec;
void dfs(int x,int las){
	//printf("(%d,%d)\n",x,las);
	if (x==n){
		for (int i=1;i<=tp;++i) printf("%d %d\n",st[i].u,st[i].v);
		exit(0);
	}
	for (int tim=50;tim--;){
		for (;tp>las;--tp){
			swap(a[st[tp].u],a[st[tp].v]);
			b[st[tp].u][st[tp].v]=0;
		}
		vec.clear();
		for (int i=x+1;i<=n;++i) if (!b[x][i]) vec.push_back(i);
		random_shuffle(vec.begin(),vec.end());
		t=0;
		for (auto y:vec){
			if (!t){ t=y; continue; }
			add(x,y);
		}
		if (t){
			for (p=x;a[p]!=x;++p);
			if (p==x) continue;
			if (p!=t){
				u=min(p,t), v=max(p,t);
				if (b[u][v]) continue;
				add(u,v);
			}
			add(x,t);
		}
		if (a[x]==x) dfs(x+1,tp);
	}
}

int main(){
	srand(time(0));
	cin>>n; if (n%4>1) return 0*puts("NO");
	for (int i=1;i<=n;++i) a[i]=i;
	puts("YES"); dfs(1,0);
}