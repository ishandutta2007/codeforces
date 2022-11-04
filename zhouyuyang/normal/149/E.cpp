#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
char a[100005],b[1005];
int n,la,lb,ans;
int pos1[1005],pos2[1005],nxt[1005];
void getnxt(){
	nxt[1]=0;
	for (int i=2,j=0;i<=lb;i++){
		for (;j&&b[j+1]!=b[i];) j=nxt[j];
		if (b[j+1]==b[i]) j++;
		nxt[i]=j;
	}
}
void find(int* pos){
	for (int i=1;i<=lb;i++) pos[i]=1e9;
	pos[0]=0;
	for (int i=1,j=0;i<=la;i++){
		for (;j&&a[i]!=b[j+1];) j=nxt[j];
		if (a[i]==b[j+1]) j++;
		if (pos[j]>=1e9) pos[j]=i;
	}
}
int main(){
	scanf("%s%d",a+1,&n);
	la=strlen(a+1);
	for (int i=1;i<=n;i++){
		scanf("%s",b+1);
		lb=strlen(b+1);
		if (lb==1) continue;
		getnxt();
		find(pos1);
		for (int j=1,k=la;j<k;j++,k--)
			swap(a[j],a[k]);
		for (int j=1,k=lb;j<k;j++,k--)
			swap(b[j],b[k]);
		getnxt();
		find(pos2);
		//for (int j=0;j<=lb;j++)
		//	printf("%d %d\n",pos1[j],pos2[j]);
		for (int j=0;j<=lb;j++)
			if (pos1[j]+pos2[lb-j]<=la){
				ans++; break;
			}
		for (int j=1,k=la;j<k;j++,k--)
			swap(a[j],a[k]);
	}
	printf("%d\n",ans);
}