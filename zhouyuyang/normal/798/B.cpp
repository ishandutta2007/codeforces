#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
char a[55][55],st[55],tmp[55];
int n,len,ans,fl,sum;
void change(char c[]){
	for (int i=1;i<=len;i++)
		c[i-1]=c[i];
	c[len]=c[0];
}
int check(char a[],char b[]){
	for (int i=1;i<=len;i++)
		if (a[i]!=b[i]) return 0;
	return 1;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%s",a[i]+1);
	len=strlen(a[1]+1);
	for (int i=1;i<=len;i++) st[i]=a[1][i];
	ans=1000000;
	for (int i=1;i<=len;i++){
		int sum=0;
		for (int j=1;j<=n;j++){
			bool fl=1;
			for (int k=1;k<=len;k++)
				tmp[k]=a[j][k];
			for (int k=1;k<=len;k++){
				if (check(tmp,st)){
					fl=0;
					break;
				}
				sum++;
				change(tmp);
			}
			if (fl){
				sum=10000000;
				break;
			}
		}
		ans=min(ans,sum);
		change(st);
	} 
	if (ans<=100000) printf("%d",ans);
	else printf("-1");
}