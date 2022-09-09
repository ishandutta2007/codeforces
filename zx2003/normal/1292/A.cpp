#include<bits/stdc++.h>
const int N=1e5+5;
int n,q,r,c,i,zz;
bool b[2][N],b1[N],b2[N];
void upd1(int c){
	zz-=b1[c];
	b1[c]=b[0][c] && b[1][c];
	zz+=b1[c];
}
void upd2(int c){
	zz-=b2[c];
	b2[c]=(b[0][c-1] && b[1][c]) || (b[0][c] && b[1][c-1]);
	zz+=b2[c];
}
int main(){
	scanf("%d%d",&n,&q);
	for(;q--;){
		scanf("%d%d",&r,&c);b[r-1][c]^=1;
		upd1(c);if(c>1)upd2(c);if(c<n)upd2(c+1);
		puts(zz?"No":"Yes");
	}
	return 0;
}