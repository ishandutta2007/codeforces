#include<bits/stdc++.h>
using namespace std;
int a[25],b[25],c[25];
int mp[25][25],n,m;
int e[25][25];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		mp[x][y]=mp[y][x]=1;
	}
	for (int i=1;i<=n;i++)
		a[i]=i;
	c[0]=1e9;
	for (int i=1;i<=80000;i++){
		int x=rand()%n+1;
		int y=rand()%n+1;
		swap(a[x],a[y]);
		int flag=1;
		for (int k=1;k<=n;k++)
			for (int l=1;l<=n;l++)
				e[k][l]=mp[k][l];
		for (int k=1;k<=n;k++)
			for (int l=1;l<=n;l++)
				if (k!=l) flag&=e[k][l];
		if (flag){
			c[0]=0;
			break;
		}
		int j;
		for (j=1;j<=n&&j<=c[0];j++){
			int tot=0;
			for (int k=1;k<=n;k++)
				if (k!=a[j]&&e[a[j]][k])
					b[++tot]=k;
			for (int k=1;k<=tot;k++)
				for (int l=1;l<=tot;l++)
					e[b[k]][b[l]]=1;
			flag=1;
			for (int k=1;k<=n;k++)
				for (int l=1;l<=n;l++)
					if (k!=l) flag&=e[k][l];
			if (flag){
				memcpy(c,a,sizeof(c));
				c[0]=j;
				break;
			}
		}
		if (j>c[0])
			swap(a[x],a[y]);
		//if (c[0]==1)
		//	printf("%d\n",i);
	}
	if (c[0]>1e8)
		return puts("-1"),0;
	printf("%d\n",c[0]);
	for (int i=1;i<=c[0];i++)
		printf("%d\n",c[i]);
}