#include <cstdio>
#include <cstring>
const int N=2e3+10;
int T,n,f[N][N];char s[N];
int min(int x,int y){return x<y?x:y;}
void cmax(int &x,int y){if(x<y)x=y;}
int pick(int l,int r,int a,int b){
	char A,B;
	if(!a)A=s[l++];else A=s[r--];
	if(!b)B=s[l++];else B=s[r--];
	if(f[l][r])return f[l][r];
	else if(A<B)return 1;
	else if(A>B)return -1;
	else return 0;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1),n=strlen(s+1);
		for(int i=1;i<n;++i)f[i][i+1]=s[i]!=s[i+1];
		for(int t=4;t<=n;t+=2){
			for(int i=1;i+t-1<=n;++i){
				int l=i,r=i+t-1;f[l][r]=0;
				for(int a=0;a<2;++a)cmax(f[l][r],min(pick(l,r,a,0),pick(l,r,a,1)));
			}
		}
		if(f[1][n]==1)puts("Alice");
		if(f[1][n]==0)puts("Draw");
		if(f[1][n]==-1)puts("Bob");
	}
	return 0;
}