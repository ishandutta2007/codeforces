#include<bits/stdc++.h>
using namespace std;
int f[5202][33],n,m,t,q,l,a[520233],p1,p2,ans,cnt;
char c;

int gc(){
	while (1){
		c=getchar();
		if (c>='a'&&c<='z'){
			return c-'a';
		}
	}
}

int main(){
	memset(f,-1,sizeof(f));
	scanf("%d",&n);
	l=n<<1;
	for (int i=1;i<=n;i++){
		a[i]=gc();
	}
	scanf("%d",&q);
	while (q--){
		scanf("%d",&m);
		m=min(n,m);
		t=gc();
		if (f[m][t]<0){
			p1=p2=1;cnt=ans=0;
			for (;p1<=n;p1++){
				for (;cnt+(a[p2]==t?0:1)<=m&&p2<=n;){
					cnt+=(a[p2++]==t?0:1);
				}
				ans=max(ans,p2-p1);
				cnt-=(a[p1]==t?0:1);
			}
			f[m][t]=min(ans,n);
		}
		printf("%d\n",f[m][t]);
	}
}