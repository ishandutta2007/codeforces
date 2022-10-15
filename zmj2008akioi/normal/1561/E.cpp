#include <cstdio>
int t,n,cnt,arr[3010],rev[3010],ord[10010];
bool tag;
void reverse(int r){
	ord[++cnt]=r;
	for(register int i=1;i<=r;++i)rev[r+1-i]=arr[i];
	for(register int i=1;i<=r;++i)arr[i]=rev[i];
}
int main(){
	scanf("%d",&t);
	for(register int i=0;i<t;++i){
		scanf("%d",&n);
		tag=true,cnt=0;
		for(register int i=1;i<=n;++i){
			scanf("%d",&arr[i]);
			if(i%2!=arr[i]%2)tag=false;
		}
		if(!tag){
			printf("-1\n");
			continue;
		}
		for(register int i=n;i>1;i-=2){
			int odd,even;
			for(register int j=1;j<=i;++j){
				if(arr[j]==i)odd=j;
				if(arr[j]==i-1)even=j;
			}
			if(odd>even)reverse(odd),even=odd+1-even,odd=1;
			else if(odd!=1)reverse(odd),odd=1;
			reverse(even-1),odd=even-1;
			reverse(even+1),odd=3,even=2;
			reverse(3),reverse(i);
		}
		printf("%d\n",cnt);
		for(register int i=1;i<=cnt;++i)printf("%d ",ord[i]);
		putchar('\n');
	}
	return 0;
}
/*
1
7
1 4 7 6 5 2 3
*/