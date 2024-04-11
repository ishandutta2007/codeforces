#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,K;
char s[100100],ti[100100];
pii pre[2][100100][2];
void Draw(){
	puts("once again");
	exit(0);
}
void No(){
	puts("quailty");
	exit(0);
}
void Yes(){
	puts("tokitsukaze");
	exit(0);
}
pii mer(pii a,pii b){
	return pii(max(a.first,b.first),min(a.second,b.second));
}
int chk(pii a){
	return a.first-a.second+1<=K;
}
int main(){
	scanf("%d%d",&n,&K);
	scanf("%s",s+1);
	int flg0=0,flg1=0;
	pre[0][0][0]=pii(-1e9,1e9);
	pre[0][0][1]=pii(-1e9,1e9);
	for(int j=1;j<=n;++j){
		flg0|=s[j]=='0';
		flg1|=s[j]=='1';
		for(int k=0;k<2;++k)pre[0][j][k]=pre[0][j-1][k];
		pre[0][j][s[j]-'0']=mer(pre[0][j-1][s[j]-'0'],pii(j,j));
	}
	pre[1][n+1][0]=pii(-1e9,1e9);
	pre[1][n+1][1]=pii(-1e9,1e9);
	for(int j=n;j>=1;--j){
		for(int k=0;k<2;++k)pre[1][j][k]=pre[1][j+1][k];
		pre[1][j][s[j]-'0']=mer(pre[1][j+1][s[j]-'0'],pii(j,j));
	}
	//if(!flg0||!flg1)No();
	if(pre[0][n][0].first-pre[0][n][0].second+1<=K||pre[0][n][1].first-pre[0][n][1].second+1<=K)Yes();
	else {
		int flg=0;
		for(int i=1;i<=n-K+1;++i){
			int z=0;
			for(int j=0;j<2;++j){
				pii A0=mer(pre[0][i-1][0],pre[1][i+K][0]);
				if(j==0)A0=mer(A0,pii(i+K-1,i));
				pii A1=mer(pre[0][i-1][1],pre[1][i+K][1]);
				if(j==1)A1=mer(A1,pii(i+K-1,i));
//				printf("<%d>[%d,%d](%d,%d)\n",j,A0.first,A0.second
//				,A1.first,A1.second);
				if(chk(A0)||chk(A1))z++;
			}
			flg+=z==2;
		}
		if(flg==n-K+1)No();
	} 
	Draw();
}