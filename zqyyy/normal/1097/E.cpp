#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=1e5+7;
int n,tot,len,f[N],lst[N],F[N],pre[N];
vector<int>ans[N];
bool vis[N];
inline void get_lis(vector<int>a){
	for(int i=1;i<=len;i++)f[i]=-1;
	len=0;
	for(int i=0;i<n;i++){
		int p=lower_bound(f+1,f+len+1,a[i])-f;
		lst[a[i]]=f[p],f[p]=a[i],pre[a[i]]=f[p-1];
		if(p>len)len++;
	}
}
inline void solve(vector<int>a){
	n=a.size(),get_lis(a);
	if(len<=F[n]){
		for(int i=1;i<=len;i++){
			vector<int>res;int x=f[i];
			while(~x)res.push_back(x),x=lst[x];
			reverse(res.begin(),res.end()),ans[++tot]=res;
		}
		return;
	}
	for(int x:a)vis[x]=0;
	vector<int>res;int x=f[len];
	while(~x)res.push_back(x),vis[x]=1,x=pre[x];
	reverse(res.begin(),res.end()),ans[++tot]=res;
	vector<int>b;
	for(int x:a)if(!vis[x])b.push_back(x);
	solve(b);
}
inline void work(){
	n=read();vector<int>a(n);
	for(int i=0;i<n;i++)a[i]=read();
	solve(a);
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++){
		printf("%lu ",ans[i].size());
		for(int x:ans[i])printf("%d ",x);
		puts(""),ans[i].clear();
	}
	tot=0;
}
int main(){
	for(int k=1,n=1;n<=1e5;n++){
		while(k*(k+1)/2<=n)k++;
		F[n]=--k;	
	}
	memset(f,-1,sizeof(f));
	int test=read();
	while(test--)work();
    return 0;
}