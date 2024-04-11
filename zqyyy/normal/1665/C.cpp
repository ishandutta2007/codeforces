#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int n,m,cnt[N],deg[N];
inline bool check(int mid){
	priority_queue<int>q;
	for(int i=1;i<=m;i++)q.push(cnt[i]);
	int cnt=mid;
	for(int i=1;i<=mid;i++){
		int x=q.top();q.pop(),x-=cnt-i+1;
		if(x>0){
			mid-=x;
			if(i>mid)return 0;
		}
		if(q.empty())return 1;
	}
	return 0;		
}	
inline void work(){
	n=read(),m=0;
	for(int i=1;i<=n;i++)deg[i]=0;
	for(int i=2;i<=n;i++)deg[read()]++;
	cnt[m=1]=1;
	for(int i=1;i<=n;i++)
		if(deg[i])cnt[++m]=deg[i];
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;	
	}
	printf("%d\n",l);
}
int main(){
	int test=read();
	while(test--)work();
	return 0;
}