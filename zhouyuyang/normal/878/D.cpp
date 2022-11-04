#include<bits/stdc++.h>
using namespace std;
int n,m,k,q,tp,x,y,ans;
int b[13][100005],c[100005][13];
bitset<4100> a[100100];
int main(){
	scanf("%d%d%d",&n,&k,&q);
	for (int i=0;i<k;i++){
		for (int j=0;j<n;j++)
			scanf("%d",&b[i][j]);
		for (int p=0;p<(1<<k);p++)
			a[i][p]=(p>>i)&1;
	}
	for (int i=0;i<k;i++)
		for (int j=0;j<n;j++)
			for (int p=0;p<k;p++)
				if (b[p][j]>=b[i][j])
					c[j][i]|=1<<p;
	m=k;
	for (int i=1;i<=q;i++){
		scanf("%d%d%d",&tp,&x,&y);
		--x;--y;
		if (tp==1) a[m++]=a[x]|a[y];
		else if (tp==2) a[m++]=a[x]&a[y];
		else{
			ans=0;
			for (int j=0;j<k;j++)
				if (a[x][c[y][j]])
					ans=max(ans,b[j][y]);
			printf("%d\n",ans); 
		}
	}
}