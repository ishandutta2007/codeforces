#include <bits/stdc++.h>
using namespace std;
const int N=15;
int n;
char a[N][N],b[N][N],c[N][N];
bool cmp(){
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if (a[i][j]!=b[i][j])
				return 0;
	return 1;
}
void pt(char ch[N][N]){
	for (int i=0;i<n;i++)
		printf("%s\n",ch[i]);
	puts("");
}
bool solve(){
	for (int cc=0;cc<4;cc++){
		if (cmp())
			return 1;
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				c[j][n-i-1]=b[i][j];
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				b[i][j]=c[i][j];
	}
	for (int i=0;i<n;i++)
		for (int j=0;j<n/2;j++)
			swap(b[i][j],b[i][n-j-1]);
	for (int cc=0;cc<4;cc++){
		if (cmp())
			return 1;
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				c[j][n-i-1]=b[i][j];
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				b[i][j]=c[i][j];
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%s",&a[i]);
	for (int i=0;i<n;i++)
		scanf("%s",&b[i]);
	puts("");
	puts(solve()?"Yes":"No");
	return 0;
}