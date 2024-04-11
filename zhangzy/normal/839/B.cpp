#include<bits/stdc++.h>
using namespace std;
int n,k,cnt[5]={0},x;

void doit(){
	scanf("%d",&x);
	while (x>=4&&cnt[4]){
		x-=4;cnt[4]--;
	}
	while (x>=2&&cnt[2]){
		x-=2;cnt[2]--;
	}
	while (x==1&&cnt[1]){
		x--;cnt[1]--;
	}
	while (x>0&&cnt[4]&&x>2){
		x-=4;cnt[4]--;
	}
	while (x>0&&cnt[4]&&x>1){
		x-=2;cnt[1]++;cnt[4]--;
	}
	while (x>0&&cnt[4]){
		x--;cnt[2]++;cnt[4]--;
	}
	while (x>0&&cnt[1]){
		x--;cnt[1]--;
	}
	while (x>0&&cnt[2]){
		x-=2;cnt[2]--;
	}
	if (x>0){
		printf("NO");
		exit(0);
	}
}

int main(){
	scanf("%d%d",&k,&n);
	cnt[4]=k;
	cnt[2]=k<<1;
	while (n--){
		doit();
	}
	printf("YES");
}