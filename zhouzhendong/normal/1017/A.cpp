#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1005;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x;
}
int n;
struct Node{
	int id,s;
}a[N];
bool cmp(Node a,Node b){
	if (a.s==b.s)
		return a.id<b.id;
	return a.s>b.s;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++)
		a[i].s=read()+read()+read()+read(),a[i].id=i;
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++)
		if (a[i].id==1){
			printf("%d",i);
			return 0;
		}
	return 0;
}