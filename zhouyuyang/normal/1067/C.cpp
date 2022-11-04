#include<bits/stdc++.h>
using namespace std;
int n;
void addP(int x,int y){
	printf("%d %d\n",x,y);
}
int main(){
	scanf("%d",&n);
	addP(0,0); n--;
	for (int i=1;n>0;i++){
		if ((n--)>0) addP(0,i);
		if ((n--)>0) addP(i,0);
		if ((n--)>0) addP(0,-i);
		if ((n--)>0) addP(-i,0);
	}
}