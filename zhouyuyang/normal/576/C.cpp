#include<bits/stdc++.h>
using namespace std;
int n,x,flag;
struct jdb{int y,id;}a;
bool cmp(jdb a,jdb b){
	return a.y<b.y;
}
vector<jdb> vec[1005];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&x,&a.y);
		a.id=i; vec[x/1000].push_back(a);
	}
	for (int i=0;i<=1000;i++){
		sort(vec[i].begin(),vec[i].end(),cmp);
		int xuzheandalao=vec[i].size();
		if (xuzheandalao){
			if (!flag)
				for (int j=0;j<xuzheandalao;j++)
					printf("%d ",vec[i][j].id);
			else
				for (int j=xuzheandalao-1;j>=0;j--)
					printf("%d ",vec[i][j].id);
			flag^=1;
		}
	}
}