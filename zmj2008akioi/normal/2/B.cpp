#include <cstdio>
#include <cstdlib>
#include <cstring>
const int start=2000;
int n,x,y,posx,posy,num,cnt,cnt2,cnt5,dp2[1010][1010],dp5[1010][1010],map2[1010][1010],map5[1010][1010],lst2[1010][1010],lst5[1010][1010];
char str[2010];
inline int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d",&n);
	for(register int i=1;i<=n;++i){
		for(register int j=1;j<=n;++j){
			scanf("%d",&num);
			cnt2=cnt5=0;
			if(!num){posx=i,posy=j;continue;}
			while(num%2==0)num/=2,++cnt2;
			while(num%5==0)num/=5,++cnt5;
			map2[i][j]=cnt2,map5[i][j]=cnt5;
		}
	}
	memset(dp2,0x7f,sizeof(dp2)),memset(dp5,0x7f,sizeof(dp5));
	dp2[1][1]=map2[1][1],dp5[1][1]=map5[1][1];
	for(register int i=1;i<=n;++i){
		for(register int j=1;j<=n;++j){
			if(dp2[i-1][j]<dp2[i][j-1])lst2[i][j]=1,dp2[i][j]=min(dp2[i][j],dp2[i-1][j]+map2[i][j]);
			else lst2[i][j]=2,dp2[i][j]=min(dp2[i][j],dp2[i][j-1]+map2[i][j]);
			if(dp5[i-1][j]<dp5[i][j-1])lst5[i][j]=1,dp5[i][j]=min(dp5[i][j],dp5[i-1][j]+map5[i][j]);
			else lst5[i][j]=2,dp5[i][j]=min(dp5[i][j],dp5[i][j-1]+map5[i][j]);
		}
	}
	if(min(dp2[n][n],dp5[n][n])>1&&posx!=0&&posy!=0){
		printf("1\n");
		for(register int i=1;i<posx;++i)putchar('D');
		for(register int i=1;i<posy;++i)putchar('R');
		for(register int i=posx;i<n;++i)putchar('D');
		for(register int i=posy;i<n;++i)putchar('R');
		return 0;
	}
	printf("%d\n",min(dp2[n][n],dp5[n][n]));
	x=y=n,cnt=start;
	if(dp2[n][n]<dp5[n][n]){
		while(x!=1||y!=1){
			if(lst2[x][y]==1)str[--cnt]='D',--x;
			else str[--cnt]='R',--y;
		}
	}
	else{
		while(x!=1||y!=1){
			if(lst5[x][y]==1)str[--cnt]='D',--x;
			else str[--cnt]='R',--y;
		}
	}
	printf("%s",str+cnt);
	return 0;
}