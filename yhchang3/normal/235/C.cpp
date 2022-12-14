#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000005<<1,sigma = 26;
int last,sz,link[maxn],len[maxn],nxt[maxn][sigma],cnt[maxn];
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

int fail[maxn];//the max length in 0~i that prefix==suffix
//indicate the place to go when mismatching
void FailureFunction(string& pattern){
   fail[0]=0;
   for(int i=1;i<pattern.size();i++){
      fail[i]=fail[i-1];
      while(fail[i]>0&&pattern[fail[i]]!=pattern[i])
         fail[i]=fail[fail[i]-1];
      if(pattern[fail[i]]==pattern[i]) fail[i]++;
   }
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	init();
	for(int i=0;i<s.size();i++)
		insert(s[i]-'a');
	vector<pair<int,int> > v;
	for(int i=1;i<sz;i++)
		v.emplace_back(make_pair(len[i],i));
	sort(v.begin(),v.end(),greater<pair<int,int> > ());
	for(auto it:v)	cnt[link[it.second]]+=cnt[it.second];
	int T;
	cin>>T;
	while(T--){
		cin>>s;
		int ans=0,n=s.size();;
		FailureFunction(s);
		int repeat;
		if(n%(n-fail[n-1]))
			repeat=n;
		else
			repeat=n-fail[n-1];
		int now=0,l=0;
		for(int i=0;i<n;i++){
			int c=s[i]-'a';
			while(now!=-1&&!nxt[now][c])
				now=link[now],l=len[now];
			if(now==-1)	now=0;
			else	now=nxt[now][c],l++;
		}
		if(l==n)	ans+=cnt[now];
		for(int i=0;i<repeat-1;i++){
			if(l==n){
				l--;
				if(l<=len[link[now]])
					now=link[now],l=len[now];
			}
			int c=s[i]-'a';
			while(now!=-1&&!nxt[now][c])
				now=link[now],l=len[now];
			if(now==-1)	now=0;
			else	now=nxt[now][c],l++;
			if(l==n)	ans+=cnt[now];
		}
		cout<<ans<<'\n';
	}	
}