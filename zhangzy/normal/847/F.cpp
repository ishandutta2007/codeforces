#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

int n,k,m,p,now,pos,tid;

struct A{
	int cnt,las,id;
}a[233],b[233];

bool cmp(A a1,A a2){
	return a1.cnt==a2.cnt? a1.las<a2.las: a1.cnt>a2.cnt;
}

int doit(){
	for (int i=1;i<=n;i++) b[i]=a[i];
	for (pos=1;b[pos].id!=now;pos++);
	b[pos].cnt+=p;if (p) b[pos].las=(tid=m)+p;
	sort(b+1,b+n+1,cmp);
	for (pos=1;b[pos].id!=now;pos++);
	if (pos>k||b[pos].cnt==0) return 0*printf("3 ");
	
	for (int i=1;i<=n;i++) b[i]=a[i];
	for (pos=1;b[pos].id!=now;pos++);
	for (int l=p,the=pos+1;l&&the<=n;the++){
		for (;l&&(b[the].cnt==b[pos].cnt? b[the].las>=b[pos].las: b[the].cnt<b[pos].cnt);l--){
			b[the].cnt++;b[the].las=++tid;
		}
	}
	sort(b+1,b+n+1,cmp);
	for (pos=1;b[pos].id!=now;pos++);
	if (pos>k||b[pos].cnt==0) return 0*printf("2 ");
	
	printf("1 ");
}

int main(){
	Sleep(970);
	cin>>n>>k>>p>>m;
	p-=m;
	int x;
	for (int i=1;i<=m;i++){
		cin>>x;
		a[x].cnt++;
		a[x].las=i;
	}
	for (int i=1;i<=n;i++){
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	
	for (int i=1;i<=n;i++){
		now=i;
		doit();
	}
	while (clock()<1940);
}