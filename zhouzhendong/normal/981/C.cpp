#include <bits/stdc++.h>
using namespace std;
const int N=100005;
struct Gragh{
	int cnt,y[N*2],nxt[N*2],fst[N];
	void clear(){
		cnt=0;
		memset(fst,0,sizeof fst);
	}
	void add(int a,int b){
		y[++cnt]=b,nxt[cnt]=fst[a],fst[a]=cnt;
	}
}g;
int n,in[N],id[N];
bool cmp(int a,int b){
	return in[a]>in[b];
}
int main(){
	scanf("%d",&n);
	memset(in,0,sizeof in);
	for (int i=1,a,b;i<n;i++){
		scanf("%d%d",&a,&b);
		in[a]++,in[b]++;
//		g.add(a,b);
//		g.add(b,a);
	}
	for (int i=1;i<=n;i++)
		id[i]=i;
	sort(id+1,id+n+1,cmp);
	if (in[id[1]]>2&&in[id[2]]>2)
		puts("No");
	else {
		puts("Yes");
		int i,k;
		for (i=n;i>2&&in[id[i-1]]==1;i--);
		k=i;
		printf("%d\n",n-k+1);
		for (int i=k;i<=n;i++)
			printf("%d %d\n",id[1],id[i]);
	}
	return 0;
}