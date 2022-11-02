#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!('0'<=ch&&ch<='9'))
		ch=getchar();
	while ('0'<=ch&&ch<='9')
		x=x*10+ch-48,ch=getchar();
	return x;
}
const int N=200005;
int n,m;
LL l[N],r[N];
struct Seg{
	LL L,R;
	int id,ans;
	Seg(){}
	Seg(LL a,LL b){L=a,R=b;}
	friend bool operator < (Seg a,Seg b){
		return a.R>b.R;
	}
}a[N],b[N];
priority_queue <Seg> Q;
bool cmpL(Seg a,Seg b){
	return a.L<b.L;
}
bool cmpans(Seg a,Seg b){
	return a.ans<b.ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		l[i]=read(),r[i]=read();
	n--;
	for (int i=1;i<=n;i++)
		b[i].L=l[i+1]-r[i],b[i].R=r[i+1]-l[i],b[i].id=i;
	for (int i=1;i<=m;i++)
		a[i].L=read(),a[i].id=i;
	sort(b+1,b+n+1,cmpL);
	sort(a+1,a+m+1,cmpL);
	while (!Q.empty())
		Q.pop();
	int cnt=0;
	for (int i=1,j=0;i<=m;i++){
		a[i].ans=n+1;
		while (j<n&&b[j+1].L<=a[i].L){
			j++;
			Q.push(b[j]);
		}
		if (Q.empty())
			continue;
		Seg now=Q.top();
		Q.pop();
		if (now.R<a[i].L){
			puts("No");
			return 0;
		}
		cnt++;
		a[i].ans=now.id;
	}
	if (cnt<n){
		puts("No");
		return 0;
	}
	puts("Yes");
	sort(a+1,a+m+1,cmpans);
	for (int i=1;i<=n;i++)
		printf("%d ",a[i].id);
	return 0;
}