#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(j);i<=(k);i++)
#define N 405 
using namespace std;
char s[N];
int n,m,r,c;
bitset<2*N> a[26][N],ans[N];
int main(){
	scanf("%d%d",&n,&m);
	For(i,0,n-1){
		scanf("%s",s);
		For(j,0,m-1){
			a[s[j]-'a'][i][j]=1;
			a[s[j]-'a'][i][j+m]=1;
			ans[i][j]=1;
		}
	}
	scanf("%d%d",&r,&c);
	For(i,0,r-1){
		scanf("%s",s);
		For(j,0,c-1){
			if (s[j]=='?') continue;
			For(p,0,n-1)
				ans[p]&=(a[s[j]-'a'][(p+i)%n]>>(j%m));
		}
	}
	For(i,0,n-1){
		For(j,0,m-1)
			printf("%d",ans[i][j]?1:0);
		puts("");
	}
}