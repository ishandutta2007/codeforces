#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=100+10;
int n,m;
bool swaped=false;
int res[MAX_N][MAX_N];
int per[MAX_N*MAX_N];
void printSol(){
	if(!swaped){
		for(int r=0;r<n;r++){
			for(int c=0;c<m;c++)
				printf("%d ",res[r][c]);
			printf("\n");
		}
	} else {
		for(int c=0;c<m;c++){
			for(int r=0;r<n;r++)
				printf("%d ",res[r][c]);
			printf("\n");
		}
	}
}
inline int Abs(int x){
	return x>0?x:-x;
}

void smallCase(){
	int ti=100000;
	for(int i=0;i<n*m;i++)
		per[i]=i+1;
	while(ti--){
		for(int i=0;i<n*m;i++)
			res[i/m][i%m]=per[i];
		bool ok=true;
		for(int r=0;r<n;r++)
			for(int c=0;c<m;c++)
				if(r+1<n&&Abs(res[r][c]-res[r+1][c])==1){
					ok=false;
					goto failed;
				} else if(c+1<m&&Abs(res[r][c]-res[r][c+1])==1){
					ok=false;
					goto failed;
				}
		failed:
		if(ok){
			printSol();
			return;
		}
		random_shuffle(per,per+n*m);
	}
	puts("-1");
}

int main(){
	cin>>n>>m;
	if(n>m){
		swap(n,m);
		swaped=true;
	}
	//n<=m
	if(m<=4){
		smallCase();
		return 0;
	}

	int c=0;
	for(int i=1;i<=m;i+=2)
		res[0][c++]=i;
	for(int i=2;i<=m;i+=2)
		res[0][c++]=i;
	for(int r=1;r<n;r++)
		for(int c=0;c<m;c++)
			res[r][c]=res[r-1][c]+m;
	printSol();
}