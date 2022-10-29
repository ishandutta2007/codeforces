#include<bits/stdc++.h>
#define maxn 201000
using namespace std;
int sta[maxn],tp,nxt[maxn],vis[maxn],n;
char s[maxn];
vector<vector<int> >ans;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i)if(s[i]=='1'){
		if(tp)nxt[sta[tp--]]=i;
		else return puts("-1"),0;
	} else sta[++tp]=i;
	tp=0;
	for(int i=n;i>=1;--i)if(s[i]=='1'){
		if(tp)nxt[i]=sta[tp--];
		else return puts("-1"),0;
	} else sta[++tp]=i;
	for(int i=1;i<=n;++i)if(!vis[i]){
		vector<int>v;
		v.clear();
		for(int j=i;j;j=nxt[j])
			vis[j]=1,v.push_back(j);
		ans.push_back(v);
	}
	printf("%d",ans.size());
	for(auto v:ans){
		printf("\n%d ",v.size());
		for(auto p:v)printf("%d ",p);
	}
}