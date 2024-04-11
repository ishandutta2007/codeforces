#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int x[667];
int y[667];
int a, b;
int c[2][2];
bool winable(){
	for(int i=1; i<=666; i++) if(abs(x[i]-a)<=1){
		a=x[i];
		return 1;
	}
	for(int i=1; i<=666; i++) if(abs(y[i]-b)<=1){
		b=y[i];
		return 1;
	}
	return 0;
}
int main(){
	cin>>a>>b;
	for(int i=1; i<=666; i++) cin>>x[i]>>y[i];
	bool centered=(a==500)&&(b==500);
	int cx=0, cy=0;
	while(!centered){
		if(winable()){
			cout<<a<<' '<<b<<'\n';
			fflush(stdout);
			return 0;
		}
		cx=500-a;
		if(cx) cx/=abs(cx);
		cy=500-b;
		if(cy) cy/=abs(cy);
		a+=cx;
		b+=cy;
		centered=(a==500)&&(b==500);
		cout<<a<<' '<<b<<'\n';
		fflush(stdout);
		int k, xx, yy;
		cin>>k>>xx>>yy;
		if(k<=0) return 0;
		x[k]=xx;
		y[k]=yy;
	}
	for(int i=1; i<=666; i++)	c[x[i]>a][y[i]>b]++;
	int px=0, py=0;
	for(int i=0; i<2; i++) for(int j=0; j<2; j++){
		if(c[i][j]<c[px][py]){
			px=i;
			py=j;
		}
	}		
	if(px) cx=-1;
	else cx=1;
	if(py) cy=-1;
	else cy=1;
	while(true){
		if(winable()){
			cout<<a<<' '<<b<<'\n';
			fflush(stdout);
			return 0;
		}
		a+=cx;
		b+=cy;
		cout<<a<<' '<<b<<'\n';
		fflush(stdout);
		int k, xx, yy;
		cin>>k>>xx>>yy;
		if(k<=0) return 0;
		x[k]=xx;
		y[k]=yy;
	}
}