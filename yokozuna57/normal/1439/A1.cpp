#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define fr first
#define sc second

int n,m;
char a[102][102];

vector<pair<int,int>> ret[3];

void reg(int b,int c,int d,int e,int f,int g){
	ret[0].push_back(mp(b,c));
	ret[1].push_back(mp(d,e));
	ret[2].push_back(mp(f,g));
	a[b][c]='0'+'1'-a[b][c];
	a[d][e]='0'+'1'-a[d][e];
	a[f][g]='0'+'1'-a[f][g];
}
void solve(){
	cerr<<n<<" "<<m<<endl;
	if(n>2){
		if(a[n-1][0]=='1'){
			reg(n-1,0,n-2,0,n-2,1);
		}
		for(int i=1;i<m;i++){
			if(a[n-1][i]=='1'){
				reg(n-1,i,n-2,i-1,n-2,i);
			}
		}
		n--;
		solve();
	}
	else if(m>2){
		if(a[0][m-1]=='1'){
			if(a[1][m-1]=='1'){
				reg(0,m-1,1,m-1,0,m-2);
			}
			else {
				reg(0,m-1,0,m-2,1,m-2);
			}
		}
		else if(a[1][m-1]=='1'){
			reg(1,m-1,0,m-2,1,m-2);
		}
		m--;
		solve();
	}
	else {
		vector<pair<int,int>> vec[2];
		for(int i=0;i<2;i++)for(int j=0;j<2;j++){
			if(a[i][j]=='1')vec[0].push_back(mp(i,j));
			else vec[1].push_back(mp(i,j));
		}
		if(vec[0].size()==0){}
		else if(vec[0].size()==1){
			ret[0].push_back(vec[0][0]);
			ret[1].push_back(vec[1][0]);
			ret[2].push_back(vec[1][1]);
			ret[0].push_back(vec[0][0]);
			ret[1].push_back(vec[1][1]);
			ret[2].push_back(vec[1][2]);
			ret[0].push_back(vec[0][0]);
			ret[1].push_back(vec[1][2]);
			ret[2].push_back(vec[1][0]);
		}
		else if(vec[0].size()==2){
			ret[0].push_back(vec[0][0]);
			ret[1].push_back(vec[1][0]);
			ret[2].push_back(vec[1][1]);
			ret[0].push_back(vec[0][1]);
			ret[1].push_back(vec[1][0]);
			ret[2].push_back(vec[1][1]);
		}
		else if(vec[0].size()==3){
			for(int k=0;k<3;k++)ret[k].push_back(vec[0][k]);
		}
		else if(vec[0].size()==4){
			for(int k=0;k<4;k++){
				int t=0;
				for(int l=0;l<4;l++){
					if(l!=k)ret[t++].push_back(vec[0][l]);
				}
			}
		}
	}
}

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("\n");
			for(int j=0;j<m;j++){
				scanf("%c",&a[i][j]);
			}
		}
		for(int i=0;i<3;i++)ret[i].clear();
		solve();
		printf("%d\n",(int)ret[0].size());
		for(int i=0;i<ret[0].size();i++){
			for(int j=0;j<3;j++){
				printf("%d %d\%c",ret[j][i].fr+1,ret[j][i].sc+1,(j==2)?'\n':' ');
			}
		}
	}
}