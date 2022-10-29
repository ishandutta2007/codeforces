#include<bits/stdc++.h>
#define maxn 1001000
using namespace std;
int n,a[maxn],tr[maxn];
void add(int x){for(;x<=n;x+=x&-x)tr[x]++;}
int qry(int x){int ans=0;for(;x;x-=x&-x)ans+=tr[x];return ans;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	int ans=0;
	for(int i=1;i<=n;++i)ans+=qry(n+1-a[i]),add(n+1-a[i]);
	if(~(n^ans)&1)puts("Petr");
	else puts("Um_nik");
}