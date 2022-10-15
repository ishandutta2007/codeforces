#include<bits/stdc++.h>
using namespace std;
#define re register int
#define Fr(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
char a[303000],b[303000];
int n,m,r[303000],pos,ans,p;
int main(){
	scanf("%s %s",a+1,b+1);
	n=strlen(a+1);
	m=strlen(b+1);
	r[m+1]=n+1;
	FOR(i,m,1){
		pos=r[i+1]-1;
		while(a[pos]!=b[i])pos--;
		r[i]=pos;
	}
	pos=1;ans=0;
	Fr(i,1,n){
		p=r[pos]-1;
		ans=max(ans,p-i+1);
		if(a[i]==b[pos])pos++;
	}
	cout<<ans;
    return 0;
}