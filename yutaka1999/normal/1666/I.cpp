#include <bits/stdc++.h>
using namespace std;

bool dig(int r,int c){
	printf("DIG %d %d\n",r+1,c+1);
	fflush(stdout);
	int t;
	scanf("%d",&t);
	return t;
}
int scan(int r,int c){
	printf("SCAN %d %d\n",r+1,c+1);
	fflush(stdout);
	int t;
	scanf("%d",&t);
	return t;
}
void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	int s1=scan(0,0),s2=scan(n-1,0);
	int y=(s1+s2)/2-(n-1);
	int x=(s1-s2)/2+(n-1);
	int s3=scan(x/2,0);
	int dx=s3-y;
	int s4=scan(0,y/2);
	int dy=s4-x;
	vector <int> vx{(x+dx)/2,(x-dx)/2};
	vector <int> vy{(y+dy)/2,(y-dy)/2};
	if(dig(vx[0],vy[0])){
		dig(vx[1],vy[1]);
	} else{
		dig(vx[0],vy[1]);
		dig(vx[1],vy[0]);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
}