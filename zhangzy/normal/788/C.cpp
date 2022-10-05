#include<bits/stdc++.h>
using namespace std;

int x,bas,n,a[1010],m=1000,ze=1005;
bitset<2020>b[2];

int main(){
	scanf("%d%d",&bas,&n);
	for (;n--;) scanf("%d",&x), a[x]=1;
	if (a[bas]) return 0*puts("1");
	b[0][ze]=1;
	for (int ans=1;;++ans){
		if (clock()>900) return 0*puts("-1");
		b[1].reset();
		for (int i=0;i<=m;++i) if (a[i]){
			if (i>bas)
				b[1]|=b[0]>>(i-bas);
			else
				b[1]|=b[0]<<(bas-i);
		}
		if (b[1][ze]) return 0*printf("%d",ans);
		b[0]=b[1];
	}
}