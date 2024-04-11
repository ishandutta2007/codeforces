#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX_N = 102;

int pos[MAX_N][MAX_N];

struct DATA {
	int a;
	int i;
	int j;
	int k;
} data[MAX_N*MAX_N];

DATA Data(int a,int i,int j,int k) {
	DATA tmp;
	tmp.a=a;
	tmp.i=i;
	tmp.j=j;
	tmp.k=k;
	return tmp;
}

int main () {
	int n,m,q;
	while (scanf("%d %d %d",&n,&m,&q) != EOF) {
		memset(pos,0,sizeof(pos));
		for (int xx=1;q>=xx;xx++) {
			int a;
			scanf("%d",&a);
			if (a==3) {
				int i,j,k;
				scanf("%d %d %d",&i,&j,&k);
				data[xx]=Data(a,i,j,k);
				pos[i][j]=k;
			}
			else if (a==1) {
				int i;
				scanf("%d",&i);
				data[xx]=Data(a,i,0,0);
				int tmp=pos[i][1];
				for (int x=1;m>x;x++) pos[i][x]=pos[i][x+1];
				pos[i][m]=tmp;
			}
			else if (a==2) {
				int i;
				scanf("%d",&i);
				data[xx]=Data(a,i,0,0);
				int tmp=pos[1][i];
				for (int x=1;n>x;x++) pos[x][i]=pos[x+1][i];
				pos[n][i]=tmp;
			}
		}
//		puts("Final : \n");
//		for (int x=1;n>=x;x++) {
//			for (int y=1;m>=y;y++) {
//				if (y!=1) printf(" ");
//				printf("%d",pos[x][y]);
//			}
//			puts("");
//		}
//		puts("");
		for (int xx=q;xx>=1;xx--) {
			int a=data[xx].a;
			int i=data[xx].i;
			int j=data[xx].j;
			int k=data[xx].k;
			if (a==1) {
				int tmp=pos[i][m];
				for (int x=m-1;x>=1;x--) pos[i][x+1]=pos[i][x];
				pos[i][1]=tmp;
			}
			else if (a==2) {
				int tmp=pos[n][i];
				for (int x=n-1;x>=1;x--) pos[x+1][i]=pos[x][i];
				pos[1][i]=tmp;
			}
		}
//		puts("Final : \n");
		for (int x=1;n>=x;x++) {
			for (int y=1;m>=y;y++) {
				if (y!=1) printf(" ");
				printf("%d",pos[x][y]);
			}
			puts("");
		}
//		puts("");
	}
}