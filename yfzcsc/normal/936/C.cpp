#include<bits/stdc++.h>
#define maxn 2010
using namespace std;
int n,a[maxn],cnt[maxn*3],b[maxn],tp;
char s1[maxn],s2[maxn];
vector<int>v[30];
int fnd(int x){
	for(int i=1;i<=n;++i)if(a[i]==x)
		return i;
}
void print(){
	for(int i=1;i<=n;++i)printf("[%d]",a[i]);
	puts("");
}
void rev(int x){
	if(!x)return ;
//	printf("{%d}",x);
	cnt[++tp]=x;
	for(int i=1;i<=n-x;++i)b[i+x]=a[i];
	for(int i=n-x+1;i<=n;++i)b[n-i+1]=a[i];
	for(int i=1;i<=n;++i)a[i]=b[i];
//	print();
}
int main(){
	scanf("%d%s%s",&n,s1+1,s2+1);
	for(int i=1;i<=n;++i)v[s2[i]-'a'].push_back(i);
	for(int i=1;i<=n;++i){
		if(v[s1[i]-'a'].empty())return puts("-1"),0;
		a[i]=v[s1[i]-'a'].back(),v[s1[i]-'a'].pop_back();
	}
//	print();
	if(n==1){
		printf("0");
		return 0;
	}
	int p1=fnd(1);
	rev(n-p1),rev(1);
	for(int i=2;i<=n;++i){
		int pos=fnd(i);
		int b=pos-i,c=n-pos;
		if(i&1){
			rev(c+1);
			rev(b);
			rev(i);
		} else {
			rev(b+c+1);
			rev(i-1+b);
			rev(1);
		}
//		puts("--------------");
	}
	if(n+1&1)rev(n);
	printf("%d\n",tp);
	for(int i=1;i<=tp;++i)printf("%d ",cnt[i]);
}