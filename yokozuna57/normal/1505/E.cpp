#include <bits/stdc++.h>
using namespace std;

int main(){
	int h,w;
	char c[6][6];
	scanf("%d%d",&h,&w);
	for(int i=0;i<h;i++){
		scanf("\n");
		for(int j=0;j<w;j++)scanf("%c",&c[i][j]);
	}
	
	int ret=0;
	int i=0,j=0;
	while(1){
		pair<int,pair<int,int>> nex=make_pair(100,make_pair(-1,-1));
		for(int x=i;x<h;x++){
			for(int y=j;y<w;y++){
				if(c[x][y]=='*'){
					nex=min(nex,make_pair(x-i+y-j,make_pair(x,y)));
				}
			}
		}
		if(nex.first==100)break;
		ret++;
		i=nex.second.first;
		j=nex.second.second;
		c[i][j]='.';
	}
	/*while(i<h-1||j<w-1){
		if(c[i][j]=='*'){
			ret++;
			c[i][j]='.';
		}
		int cnt[2]={};
		if(c[i][j+cnt[0]]=='.'&&j+cnt[0]+1<w-1)cnt[0]++;
		if(c[i][j+cnt[0]]=='.')cnt[0]=100;
		if(c[i+cnt[1]][j]=='.'&&i+cnt[1]+1<h-1)cnt[1]++;
		if(c[i+cnt[1]][j]=='.')cnt[1]=100;
		if(cnt[0]==100&&cnt[1]==100){
			if(j==w-1)break;
			else j++;
		}
		else if(cnt[0]<cnt[1]){
			j+=cnt[0];
		}
		else i+=cnt[1];
	}*/
	cout<<ret<<endl;
}