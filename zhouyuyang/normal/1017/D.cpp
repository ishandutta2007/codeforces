#include<bits/stdc++.h>
using namespace std;

int n,m,q;
int a[4096],w[20];
int b[4096][105],d[4096];
char s[20];
int get(){
	scanf("%s",s); int ans=0;
	for (int i=n-1;i>=0;i--) ans=ans*2+(s[i]=='1');
	return ans;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for (int i=0;i<n;i++) scanf("%d",&w[i]);
	while (m--) a[get()]++;
	for (int i=0;i<1<<n;i++)
		for (int j=0;j<n;j++) 
			if (!((i>>j)&1)) d[i]+=w[j];
	for (int i=0;i<1<<n;i++){
		for (int j=0;j<1<<n;j++)
			if (d[i^j]<101) b[i][d[i^j]]+=a[j];
		for (int j=1;j<101;j++) b[i][j]+=b[i][j-1];
	}
	while (q--){
		int i=get(),j; scanf("%d",&j);
		printf("%d\n",b[i][j]);
	}
}