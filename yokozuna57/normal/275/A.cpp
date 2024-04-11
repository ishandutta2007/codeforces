#include<iostream>
using namespace std;
int l[5][5];
int a[5][5];

void f(int x,int y){
	l[x][y]=(l[x][y]+1)%2;
	l[x+1][y]=(l[x+1][y]+1)%2;
	l[x][y+1]=(l[x][y+1]+1)%2;
	l[x-1][y]=(l[x-1][y]+1)%2;
	l[x][y-1]=(l[x][y-1]+1)%2;
}

int main(){
	for(int i=0;i<5;i++)for(int j=0;j<5;j++)l[i][j]=1;
	for(int i=1;i<4;i++){
		for(int j=1;j<4;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]%2==1)f(i,j);
		}
	}
	for(int i=1;i<4;i++){for(int j=1;j<4;j++)printf("%d",l[i][j]); printf("\n");}
}