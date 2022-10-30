#include <cstring>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>
#include <cctype>
#include <ctime>
#include <cstdio>
#define rep(i,n) for(int i=0;i<n;i++)
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();e++)
using namespace std;
typedef long long int64;

int k,n,m;
bool v[20][20][20]={};
char map[20][20][20];
int cnt=0;

void dfs(int x,int y,int z){
	if(v[x][y][z])return;
	v[x][y][z]=true;cnt++;
	rep(dx,3)rep(dy,3)rep(dz,3)
		if(((dx==1)+(dy==1)+(dz==1))==2){
			int nx=x+dx-1,ny=y+dy-1,nz=z+dz-1;
			if(nx>=0&&nx<k&&ny>=0&&ny<n&&nz>=0&&nz<m)
				if(map[nx][ny][nz]=='.')
					dfs(nx,ny,nz);
		}
}
int main(){
	cin>>k>>n>>m;
	rep(a,k)rep(b,n)rep(c,m){
		scanf(" ");
		scanf("%c",&map[a][b][c]);
	}
	int x,y;cin>>x>>y;
	dfs(0,--x,--y);
	cout<<cnt<<endl;
}