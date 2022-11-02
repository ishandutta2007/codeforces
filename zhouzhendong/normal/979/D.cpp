#include <bits/stdc++.h>
using namespace std;
const int N=100005*20*20;
int n,cnt;
struct Trie{
	int Next[2],Min;
}t[N];
void build(int rt,int v){
	int x;
	for (int i=16;i>=0;i--){
		x=(v>>i)&1;
		if (!t[rt].Next[x])
			t[rt].Next[x]=++cnt,t[cnt].Min=100001;
		t[rt].Min=min(t[rt].Min,v);
		rt=t[rt].Next[x];
	}
	t[rt].Min=min(t[rt].Min,v);
}
int solve(int a,int b,int c){
	int rt=b,x,ans=0;
	for (int i=16;i>=0;i--){
		x=(c>>i)&1;
		int y=t[rt].Next[x^1];
		if (y>0&&t[y].Min<=a){
			ans|=(x^1)<<i;
			rt=y;
			continue;
		}
		y=t[rt].Next[x];
		if (y>0&&t[y].Min<=a){
			ans|=x<<i;
			rt=y;
			continue;
		}
		return -1;
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	cnt=100000;
	for (int i=1;i<=n;i++)
		t[i].Min=100001;
	while (n--){
		int opt,a,b,c;
		scanf("%d",&opt);
		if (opt==1){
			scanf("%d",&a);
			for (int i=1;i*i<=a;i++)
				if (a%i==0){
					build(i,a);
					build(a/i,a);
				}
		}
		else {
			scanf("%d%d%d",&c,&b,&a);
			a-=c;
			if (c%b!=0){
				puts("-1");
				continue;
			}
			printf("%d\n",solve(a,b,c));
		}
	}
	return 0;
}