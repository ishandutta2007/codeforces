#include<bits/stdc++.h>
using namespace std;
int n,m,t,mn;
char d[3005][3005];
struct LZH{
	int x,y;
	bool operator <(const LZH &lzh)const{
		return x!=lzh.x?x<lzh.x:y<lzh.y;
	}
}a[3005];
int main(){
	scanf("%d%d",&m,&n); mn=1e9;
	for (int i=1;i<=m;i++) a[i].y=i;
	for (int i=m-n+1;i<=m;i++){
		scanf("%d",&a[i].x);
		t+=a[i].x; mn=min(mn,a[i].x);
	}
	if (t>m*(m-1))
		return puts("no"),0;
	t=m*(m-1)-t;
	for (int i=1;i<=m-n;i++)
		a[i].x=t/(m-n)+(i<=t%(m-n));
	if (m-n&&a[1].x>mn)
		return puts("no"),0;
	sort(a+1,a+m+1);
	t=0;
	for (int i=1;i<=m;i++){
		t+=a[i].x;
		if (t<i*(i-1))
			return puts("no"),0;
	}
	for (int i=1;i<=m;i++)
		d[i][i]='X';
	for (int i=m;i;i--){
		sort(a+1,a+i+1);
		int t=a[i].x;
		for (int j=1;j<i;j++)
			if (t>1){
				t-=2;
				d[a[i].y][a[j].y]='W';
				d[a[j].y][a[i].y]='L';
			}
			else if (t==1){
				t--;
				d[a[i].y][a[j].y]='D';
				d[a[j].y][a[i].y]='D';
				a[j].x--;
			}
			else{
				a[j].x-=2;
				d[a[i].y][a[j].y]='L';
				d[a[j].y][a[i].y]='W';
			}
	}
	puts("yes");
	for (int i=1;i<=m;i++){
		for (int j=1;j<=m;j++)
			printf("%c",d[i][j]);
		puts("");
	}
}