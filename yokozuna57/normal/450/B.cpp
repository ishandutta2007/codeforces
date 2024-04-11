#include<iostream>
using namespace std;

const int M=1000000007;

int main(){
	int x,y,n;
	scanf("%d%d%d",&x,&y,&n);

	int f[10];
	f[1]=(x+M)%M;
	f[2]=(y+M)%M;
	for(int i=3;i<6;i++){
		f[i]=(f[i-1]-f[i-2]+M)%M;
	}
	f[0]=(f[5]-f[4]+M)%M;

	printf("%d\n",f[n%6]);
}