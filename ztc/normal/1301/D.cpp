#include<stdio.h>
#include<queue>
#define mp std::make_pair
int n,m,k,f=0;
std::queue<std::pair<int,int> >ans;
char c[6][4]={"R","D","DLR","L","U","U"};
int main(){
	scanf("%d%d%d",&n,&m,&k);n--;m--;n^=m^=n^=m;
	if(k>n*(m+1)*2+m*(n+1)*2)return printf("NO")&0;
	f=k&1;k=k+1>>1;
	puts("YES");
	if(k==1&&f&&k<=n)return printf("1\n1 R")&0;
	if(k<=n)return printf("2\n%d R\n%d L\n",k,k-f)&0;
	if(n==0){
		if(k==1&&f&&k<=m)return printf("1\n1 D")&0;
		if(k<=m)return printf("2\n%d D\n%d U\n",k,k-f)&0;
	}
	if(k==n+1&&f)return printf("3\n%d R\n%d L\n1 D",n,n)&0;
	if(k<=n+m)return printf("4\n%d R\n%d L\n%d D\n%d U\n",n,n,k-n,k-n-f)&0;
	ans.push(mp(n,0));k-=n; 
	for(int i=n;i>=1;i--){
		if(k>=m*2){
			ans.push(mp(m,2)),ans.push(mp(m,5)),k-=m*2;
			if(k>1)ans.push(mp(1,3));
			else{
				if(!(i==1&&k==0&&f==1))ans.push(mp(i-(k?0:f),3));
				break;
			}
		}
		else{
			int p=k>>1;k&=1;
			if(p)ans.push(mp(p,2));
			if(p)ans.push(mp(p,5));
			if(!(i==1&&k==0&&f==1))ans.push(mp(i-(k?0:f),3));break;
		}
	}if(k){
		ans.push(mp(k,1));
		if(k-f)ans.push(mp(k-f,4));
	}
	printf("%d\n",ans.size());
	while(!ans.empty())printf("%d %s\n",ans.front().first,c[ans.front().second]),ans.pop();
}