#include<bits/stdc++.h>
#define maxn 100100
using namespace std;
int n,nxt[100],used[100],ed[100],vis[100],bg[100],cnt;
string str;
int main(){
	scanf("%d",&n);
	memset(nxt,-1,sizeof(nxt));
	for(int i=1;i<=n;++i){
		cin>>str;
		for(int j=0;j<str.length();++j)
			used[str[j]-'a']=1;
		bg[str[0]-'a']=1;
		for(int j=0;j<str.length()-1;++j){
			int c=str[j]-'a',d=str[j+1]-'a';
			if(nxt[c]>=0&&nxt[c]!=d)return puts("NO"),0;
			else nxt[c]=d,ed[d]=1;
		}
	}
	str="";
	for(int i=0;i<26;++i)cnt+=used[i];
	for(int i=0;i<26;++i)if(!ed[i]&&bg[i]&&!vis[i]){
		str+=i+'a',vis[i]=1;
		for(int j=nxt[i];j!=-1;j=nxt[j]){
			if(vis[j])return puts("NO"),0;
			else str+=j+'a',vis[j]=true;
		}
	}
	if(str.length()!=cnt)return puts("NO"),0;
	cout<<str;
}