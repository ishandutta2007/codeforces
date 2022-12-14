#include<bits/stdc++.h>
using namespace std;

const int maxn = 100010<<1,sigma = 26;
int last,sz,link[maxn],len[maxn],nxt[maxn][sigma],cnt[maxn],suf[maxn];
void init(){
	for(int i=0;i<sz;i++)
		memset(nxt[i],0,sizeof nxt[i]),cnt[i]=0;
	len[0]=last=0;
	link[0]=-1;sz=1;
}
void insert(int c){
	int cur=sz++,p=last;
	len[cur]=len[last]+1;
	cnt[cur]=1;
	while(p!=-1&&!nxt[p][c]){
		nxt[p][c]=cur;
		p=link[p];
	}
   	if(p==-1)	link[cur]=0;
   	else{
   		int q=nxt[p][c];
   		if(len[p]+1==len[q])
   			link[cur]=q;
   		else{
   			int clone=sz++;
   			memcpy(nxt[clone],nxt[q],sizeof nxt[q]);
			len[clone]=len[p]+1;
			link[clone]=link[q];
			link[q]=link[cur]=clone;
   			while(p!=-1&&nxt[p][c]==q){
   				nxt[p][c]=clone;
   				p=link[p];
   			}
   		}
   	}
   	last=cur;
}

vector<int> e[maxn];

void dfs(int x){
	for(int it:e[x]){
		dfs(it);
		cnt[x]+=cnt[it];
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	init();
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		insert(s[i]-'A');
	for(int i=sz-1;i>0;i--)
		e[link[i]].emplace_back(i);
	for(int i=last;i;i=link[i])
		suf[i]=1;
	dfs(0);
	int now=0;
	vector<int> ans;
	for(int i=0;i<s.size();i++){
		now=nxt[now][s[i]-'A'];
		if(suf[now])
			ans.emplace_back(i+1),ans.emplace_back(cnt[now]);
	}
	cout<<ans.size()/2<<'\n';
	for(int i=0;i<ans.size();i+=2)
		cout<<ans[i]<<' '<<ans[i+1]<<'\n';
}