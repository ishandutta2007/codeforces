#include<bits/stdc++.h>
using namespace std;

const int maxn = 10010<<1,sigma = 27;
int last,sz,link[maxn],len[maxn],nxt[maxn][sigma],cnt[maxn],suf[maxn],w[maxn];
void init(){
	for(int i=0;i<sz;i++)
		memset(nxt[i],0,sizeof nxt[i]),cnt[i]=0;
	len[0]=last=0;
	link[0]=-1;sz=1;
}
void insert(int c,int from){
	int cur=sz++,p=last;
	len[cur]=len[last]+1;
	cnt[cur]=1;
	w[cur]=from;
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
		w[x]|=w[it];
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	init();
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		insert(s[i]-'a',1);
	insert(26,0);
	cin>>s;
	for(int i=0;i<s.size();i++)
		insert(s[i]-'a',2);
	for(int i=sz-1;i>0;i--)
		e[link[i]].emplace_back(i);
	dfs(0);
	int ans=1000000;
	for(int i=1;i<sz;i++)
		if(cnt[i]==2&&w[i]==3)
			ans=min(ans,len[link[i]]+1);
	if(ans==1000000)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;
}