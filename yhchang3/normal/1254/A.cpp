#include<bits/stdc++.h>
using namespace std;

pair<int,int> eval(int x,int c){
	if((x/c)&1)
		return make_pair(x/c,c-x%c-1);
	else
		return make_pair(x/c,x%c);
}

string g[100];
string m="QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890";
int tar[62];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int r,c,k;
		cin>>r>>c>>k;
		for(int i=0;i<k;i++)
			tar[i]=0;
		for(int i=0;i<r;i++)
			cin>>g[i];
		int now=0;
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				if(g[i][j]=='R'){
					tar[now]++;
					now=(now+1)%k;
				}
		now=0;
		for(int i=0;i<r*c;i++){
			int x=eval(i,c).first;
			int y=eval(i,c).second;
			char tmp=m[now];
			if(g[x][y]=='R')
				if(--tar[now]==0)
					now++;
			if(now==k)
				now--;
			g[x][y]=tmp;
		}
		for(int i=0;i<r;i++)
			cout<<g[i]<<'\n';
	
	}

}