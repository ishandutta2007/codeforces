#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int a,v,f,k,las,ans=0;
int main(){
	cin>>a>>v>>f>>k;
	if (v<max(f,a-f)) return 0*puts("-1");
	las=v-f;
	for (int i=1;i<k;i++){
		if (las<0) return 0*puts("-1");
		if (i&1){
			if (las<(a-f)*2){
				ans++;
				las=v;
			}
			las-=(a-f)*2;
		}else{
			if (las<f*2){
				ans++;
				las=v;
			}
			las-=f*2;
		}
	}
	if (las<0) return 0*puts("-1");
	if (k&1){
		if (las<a-f) ans++;
	}else{
		if (las<f) ans++;
	}
	cout<<ans;
}