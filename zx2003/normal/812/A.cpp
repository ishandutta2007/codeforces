#include <iostream> 
#include <cstdio>
using namespace std;
int i,j,a[6][6];
bool f,b[6];
int main(){
	for(i=0;i<4;++i)
		for(j=1;j<=4;++j)cin>>a[i][j];
	for(i=0;i<4;++i){
		if(a[i][1])b[(i+3)%4]=1,b[i]=1;
		if(a[i][2])b[(i+2)%4]=1,b[i]=1;
		if(a[i][3])b[(i+1)%4]=1,b[i]=1;
	}
	for(i=0;i<4;++i)
		if(b[i] && a[i][4]){
			puts("YES");
			return 0;
		}
	puts("NO");
	return 0;
}