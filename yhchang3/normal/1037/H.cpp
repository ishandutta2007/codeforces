#include<bits/stdc++.h>
using namespace std;

const int maxn = 100010<<1,sigma = 26;
int last,sz,link[maxn],len[maxn],nxt[maxn][sigma],cnt[maxn],root[maxn];

const int M = 4000010;

int seg;
int ls[M],rs[M];
int n;
void update(int &u,int l,int r,int p){
	if(!u)	u=++seg;
	if(l==r)	return;
	int mid=(l+r)>>1;
	if(p<=mid)	update(ls[u],l,mid,p);
	else	update(rs[u],mid+1,r,p);
}

int merge(int x,int y,int l,int r){
	if(!x||!y)	return x+y;
	int res=++seg,mid=(l+r)>>1;
	if(l!=r){
		ls[res]=merge(ls[x],ls[y],l,mid);
		rs[res]=merge(rs[x],rs[y],mid+1,r);
	}
	return res;
}

bool query(int u,int l,int r,int L,int R){
	if(u==0||r<L||R<l)	return false;
	if(L<=l&&r<=R)	return true;
	int mid=(l+r)>>1;
	return query(ls[u],l,mid,L,R)|query(rs[u],mid+1,r,L,R);
}

void init(){
	for(int i=0;i<sz;i++)
		memset(nxt[i],0,sizeof nxt[i]),cnt[i]=0;
	len[0]=last=0;
	link[0]=-1;sz=1;
}
void insert(int c,int idx){
	int cur=sz++,p=last;
	len[cur]=len[last]+1;
	cnt[cur]=1;
	update(root[cur],1,n,idx);
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
vector<int> edge[maxn];
void dfs(int x){
	for(int it:edge[x]){
		dfs(it);
		root[x]=merge(root[x],root[it],1,n);
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	init();
	string s;
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
		insert(s[i]-'a',i+1);
	int T;
	cin>>T;
	for(int i=sz-1;i>=1;i--)
		edge[link[i]].emplace_back(i);
	dfs(0);
	int L,R;
	while(T--){
		cin>>L>>R>>s;
		char ch=0;
		int now=0,pos;
		for(int i=0;i<=s.size();i++){
			int c=s.size()==i?(-1):(s[i]-'a');
			for(int j=c+1;j<sigma;j++)
				if(nxt[now][j]){
					int u=nxt[now][j];
					if(L+i<=R&&query(root[u],1,n,L+i,R)){
						ch=j+'a';pos=i;break;
					}
				}
			if(c==-1||!nxt[now][c])	break;
			now=nxt[now][c];
		}
		if(!ch)	cout<<-1<<'\n';
		else{
			for(int i=0;i<pos;i++)	cout<<s[i];
			cout<<ch;
			cout<<'\n';
		}
	}
}