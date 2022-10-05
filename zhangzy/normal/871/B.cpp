#include<bits/stdc++.h>
using namespace std;
int tot=0,ans[5500],a[5500],b[5050],c[5500],pos[5500],n,w0;

int que(int x,int y){
	printf("? %d %d\n",x,y);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}

int used[5500];

bool C(){
	memset(used,0,sizeof used);
	for (int i=0;i<n;i++){
		a[i]=c[i]^w0;
		if (a[i]>=n) return 0;
		if (used[a[i]]) return 0;
		used[a[i]]=1;
	}
	for (int i=0;i<n;i++){
		b[i]=pos[i]^a[0];
		if (b[i]>=n) return 0;
		if (a[b[i]]!=i) return 0;
	}
	return 1;
}

int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		c[i]=que(i,0);
		if (i) pos[i]=que(0,i);
		else pos[i]=c[i];
	}
	for (w0=0;w0<n;w0++){
		if (C()){
			memcpy(ans,a,sizeof a);
			tot++;
		}
	}
	printf("!\n%d\n",tot);
	for (int i=0;i<n;i++) printf("%d ",ans[i]);
}