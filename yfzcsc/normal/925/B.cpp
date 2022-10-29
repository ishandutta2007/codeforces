#include<bits/stdc++.h>
#define maxn 300100
using namespace std;
typedef long long ll;
int n,x1,x2,id[maxn],a[maxn];
vector<int>s1,s2;
vector<int>a1,a2;
void sol(int i1,int l1,int i2,int l2){
	for(int i=n;i>=1&&(i1||i2);--i){
		if((!i2||l1>l2)&&i1)a1.push_back(id[i]),i1--;
		else a2.push_back(id[i]),i2--;
	}
	puts("Yes");
	printf("%d %d\n",a1.size(),a2.size());
	for(auto p:a1)printf("%d ",p);puts("");
	for(auto p:a2)printf("%d ",p);
	exit(0);
}
int main(){
	scanf("%d%d%d",&n,&x1,&x2);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),id[i]=i;
	sort(id+1,id+n+1,[&](int x,int y){return a[x]<a[y];});
	for(int i=1,p=n;i<=n;++i){
		while(p>=1&&(ll)a[id[p]]*i>=x1)p--;
		s1.push_back(p+1);
	}
	for(int i=1,p=n;i<=n;++i){
		while(p>=1&&(ll)a[id[p]]*i>=x2)p--;
		s2.push_back(p+1);
	}
	int f1=n+1,f2=n+1,i1=0,i2=0;
	for(int i=1;i<=n&&f1==n+1;++i)if(n+1-s1[i-1]>=i)f1=s1[i-1],i1=i;
	for(int i=1;i<=n&&f2==n+1;++i)if(n+1-s2[i-1]>=i)f2=s2[i-1],i2=i;
	if(f1==n+1||f2==n+1)return puts("No"),0;
	for(int i=1;i<=n;++i)if(n+1-s1[i-1]>=i&&n+1-min(f2,s1[i-1])>=i+i2)sol(i,s1[i-1],i2,f2);
	for(int i=1;i<=n;++i)if(n+1-s2[i-1]>=i&&n+1-min(f1,s2[i-1])>=i+i1)sol(i1,f1,i,s2[i-1]);
	puts("No");
}