#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;


int main() {
	int H,W;cin>>H>>W;
	vector<vector<int>>field(H,vector<int>(W));
	for(int i=0;i<H;++i){
		for(int j=0;j<W;++j){
			cin>>field[i][j];
		}
	}
	vector<pair<int,int>>anss;
	bool flag=true;
	int minc=-1;
	int minl=-1;
	{
		int num=1000;
		for(int y=0;y<H;++y){
			if(num>field[y][0]){
				num=field[y][0];
				minl=y;
			}
		}
		for(int y=0;y<H;++y){
			if(y!=minl){
				int dif=field[y][0]-num;
				for(int x=0;x<W;++x){
					if(dif!=field[y][x]-field[minl][x]){
						flag=false;
					}
				}
				for(int i=0;i<dif;++i){
					anss.emplace_back(0,y);
				}
			}
		}
	}
	{
		int num=1000;
		for(int x=0;x<W;++x){
			if(num>field[0][x]){
				num=field[0][x];
				minc=x;
			}
		}
		for(int x=0;x<W;++x){
			if(x!=minc){
				int dif=field[0][x]-num;
				for(int y=0;y<H;++y){
					if(dif!=field[y][x]-field[y][minc]){
						flag=false;
					}
				}
				for(int i=0;i<dif;++i){
					anss.emplace_back(1,x);
				}
			}
		}
	}	
	if(H<W){
		for(int y=0;y<H;++y){
			for(int i=0;i<field[minl][minc];++i){
			anss.emplace_back(0,y);
			}
		}
	}else{
		for(int x=0;x<W;++x){
			for(int i=0;i<field[minl][minc];++i){
			anss.emplace_back(1,x);
			}
		}
	}
	if(flag){
		cout<<anss.size()<<endl;
		for(auto ans:anss){
			if(ans.first)cout<<"col ";
			else cout<<"row ";
			cout<<ans.second+1<<endl;
		}
	}else{
		cout<<-1<<endl;
	}
	
	
	return 0;
}