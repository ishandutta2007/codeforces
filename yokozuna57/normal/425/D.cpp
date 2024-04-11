#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;

vector<int> Y[100010];
bool cnt(int x,int y){
	return binary_search(Y[x].begin(),Y[x].end(),y);
}

int main(){
	int n,ret=0;
	static int x[100010],y[100010];
	static vector<int> v[4][200010];
	
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&x[i],&y[i]);
//cout<<0;
		Y[x[i]].push_back(y[i]);
//cout<<1;
		v[0][x[i]].push_back(y[i]);
//cout<<2;
		v[1][y[i]].push_back(x[i]);
//cout<<3;
		v[2][x[i]-y[i]+100000].push_back(x[i]);
//cout<<4;
		v[3][x[i]+y[i]].push_back(x[i]);
	}

	for(int i=0;i<100001;i++)sort(Y[i].begin(),Y[i].end());

	int S[4]={0};
	for(int i=0;i<4;i++){
		for(int j=0;j<200010;j++){
			if(v[i][j].size()>S[i])S[i]=v[i][j].size();
		}
	}
	int m=min(min(S[0],S[1]),min(S[2],S[3]));
	int t=-1;
	for(int i=0;i<4;i++)if(S[i]==m)t=i;

//cout<<t<<endl;

	for(int i=0;i<200010;i++){
		int s=v[t][i].size();
		for(int j=0;j<s;j++){
			for(int k=j+1;k<s;k++){
				int X1,Y1,X2,Y2;
				if(t==0){
					X1=i;
					Y1=v[t][i][j];
					Y2=v[t][i][k];
					if(Y1>Y2)swap(Y1,Y2);
					X2=X1+Y2-Y1;
					if(cnt(X2,Y1)&&cnt(X2,Y2))ret++;
				}
				else if(t==1){
					Y1=i;
					X1=v[t][i][j];
					X2=v[t][i][k];
					if(X1>X2)swap(X1,X2);
					Y2=Y1+X2-X1;
					if(cnt(X1,Y2)&&cnt(X2,Y2))ret++;
				}
				else if(t==2){
					X1=v[t][i][j];
					Y1=X1-i+100000;
					X2=v[t][i][k];
					Y2=X2-i+100000;
					if(cnt(X1,Y2)&&cnt(X2,Y1))ret++;
				}
				else if(t==3){
					X1=v[t][i][j];
					Y1=i-X1;
					X2=v[t][i][k];
					Y2=i-X2;
					if(cnt(X1,Y2)&&cnt(X2,Y1))ret++;
				}
			}
		}
	}

	printf("%d\n",ret);
}