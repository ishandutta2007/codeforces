#include<bits/stdc++.h>
using namespace std;


string ss="LRUD";
int cnt[4];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		for(int i=0;i<4;i++)
			cnt[i]=0;
		for(char c:s)
			for(int j=0;j<4;j++)
				if(c==ss[j])
					cnt[j]++;
		int r=min(cnt[0],cnt[1]),u=min(cnt[2],cnt[3]);
		if(r==0){
			u=min(u,1);
			cout<<(u<<1)<<'\n';
			if(u)
				cout<<"UD"<<'\n';
		}
		else if(u==0){
			r=min(r,1);
			cout<<(r<<1)<<'\n';
			if(r)
				cout<<"LR"<<'\n';
		}
		else{
			cout<<2*(r+u)<<'\n';
			for(int i=0;i<r;i++)
				cout<<'L';
			for(int i=0;i<u;i++)
				cout<<'U';
			for(int i=0;i<r;i++)
				cout<<'R';
			for(int i=0;i<u;i++)
				cout<<'D';
			cout<<'\n';
		}
			
	}
}