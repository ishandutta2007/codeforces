
 #include<bits/stdc++.h>
#define N 100005
using namespace std;
char s[N];int deep[N],id[N];
int son[N][26],ed[N],n,tot,ans;
multiset<int>S[N];
void Insert(char *cur){
	int p=1;
	for (int i=0;cur[i];i++){
		if (!son[p][cur[i]-'a'])
			son[p][cur[i]-'a']=++tot;
		p=son[p][cur[i]-'a'];
	}
	ed[p]=1;
}
int Union(int x,int y){
	if (S[x]<S[y]) swap(x,y);
	for (auto it:S[y]) S[x].insert(it);
	return x;
}
void DP(int x){
	//printf("%d\n",x);
	for (int i=0;i<26;i++)
		if (son[x][i])
			deep[son[x][i]]=deep[x]+1,DP(son[x][i]);
	id[x]=x;
	for (int i=0;i<26;i++)
		if (son[x][i])
			id[x]=Union(id[x],id[son[x][i]]);
	if (ed[x]){
		ans+=deep[x];
		S[id[x]].insert(deep[x]);
	}
	else if (!S[id[x]].empty()){
		int val=*(--S[id[x]].end());
		S[id[x]].erase(--S[id[x]].end());
		ans-=val-deep[x];
		S[id[x]].insert(deep[x]);
	}
}
int main(){
	scanf("%d",&n);ed[tot=1]=1;
	for (int i=1;i<=n;i++){
		scanf("%s",s);
		Insert(s);
	}
	DP(1);
	printf("%d\n",ans);
}