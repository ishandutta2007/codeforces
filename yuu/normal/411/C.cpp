#include <bits/stdc++.h>
using namespace std;
int a[4];
int b[4];
int get(int x, int y, int z, int t){
	if((a[z]>b[x])&&(b[t]>a[y])) return 2;
	if((a[z]<b[x])&&(b[t]<a[y])) return 0;
	return 1;
}
int get(int x, int y){
	return 2-max(get(x, y, 2, 3), get(x, y, 3, 2));
}
int main(){
	for(int i=0; i<4; i++) cin>>a[i]>>b[i];
	int res=max(get(0, 1), get(1, 0));
	if(res==0) cout<<"Team 2\n";
	else if(res==2) cout<<"Team 1\n";
	else cout<<"Draw\n";
}