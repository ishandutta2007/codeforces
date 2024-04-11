#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
char c[101000]; 
int n,m;
int main(){
scanf("%s",c+1);
if(c[1]=='0'){
	cout<<"0";
	return 0;
}
n=strlen(c+1)-1;
m=n>>1;
if(!n){
	cout<<"0";
	return 0;
}
if(n&1){
	cout<<m+1;
}
else {
	F(i,2,n+1){
		if(c[i]=='1'){
			m++;
			break;
		}
	}
	cout<<m;
}
    return 0;
}