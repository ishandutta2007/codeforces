#include<bits/stdc++.h>
using namespace std;
typedef vector<int>V;
int n,k,i,j,l;
bool ask(int i){
	printf("? %d\n",i);fflush(stdout);
	char c[9];scanf("%s",c);return *c=='N';
}
void F(){
	puts("R");fflush(stdout);
}
bool b[1029];
void G(int i){if(!ask(i))b[i]=0;}
void H(int l,int r){for(int i=l;i<=r;++i)G(i);}
int main(){
	scanf("%d%d",&n,&k);
	if(k==1)k=2;
	if(n==1){puts("! 1");fflush(stdout);return 0;}
	memset(b+1,1,n);
	if(k==n)H(1,n);else{
		int m=n/(k/2);
		for(i=1;i<m;++i)for(j=1;j+i<=m && j<=i;++j,F())
			for(l=j;l<=m;l+=i)H((l-1)*(k/2)+1,l*(k/2));
	}
	int tot=0;
	for(i=1;i<=n;++i)tot+=b[i];
	printf("! %d\n",tot);fflush(stdout);
	return 0;
}