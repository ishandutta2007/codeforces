#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main(){
	ios::sync_with_stdio(0);cin.tie(0);

	int t;cin>>t;
	while(t--){
		string s;cin>>s;
		int x=0,y=0;

		int flg=0;
		for(auto &it:s){
			if(it=='U') y++;
			if(it=='D') y--;
			if(it=='L') x--;
			if(it=='R') x++;

			if(x==0&&y==0) continue;

			int nowx=0,nowy=0;
			for(auto &it2:s){
				if(it2=='U'&&!(x==nowx&&y==nowy+1)) nowy++;
				if(it2=='D'&&!(x==nowx&&y==nowy-1)) nowy--;
				if(it2=='L'&&!(x==nowx-1&&y==nowy)) nowx--;
				if(it2=='R'&&!(x==nowx+1&&y==nowy)) nowx++;
			}
			if(nowx==0&&nowy==0){
				flg=1;
				break;
			}
		}
		if(flg){
			cout<<x<<" "<<y<<endl;
		}
		else cout<<"0 0"<<endl;
	}
}