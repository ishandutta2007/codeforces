#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define fr first
#define sc second

int n;
int p[1000010];

bool used[1000010];
int q[1000010];

void NG(){
	puts("-1");
	exit(0);
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&p[i]);
		p[i]--;
	}
	
	for(int i=0;i<n;i++)used[i]=false;
	vector<vector<int>> circ;
	for(int i=0;i<n;i++){
		if(used[i])true;
		vector<int> vec;
		int loc=i;
		while(!used[loc]){
			vec.push_back(loc);
			used[loc]=true;
			loc=p[loc];
		}
		circ.push_back(vec);
	}
	int k=circ.size();
	vector<pair<int,int>> vec;
	for(int i=0;i<k;i++){
		vec.push_back(mp(circ[i].size(),i));
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<k;i++){
		if(vec[i].fr%2==1){
			int t=vec[i].sc;
			int nex=(circ[t].size()+1)/2; nex%=circ[t].size();
			for(int j=0;j<circ[t].size();j++){
				q[circ[t][j]]=circ[t][nex];
				nex++; if(nex==circ[t].size())nex=0;
			}
		}
		else {
			if(i+1==k||vec[i+1].fr!=vec[i].fr)NG();
			int t=vec[i].sc, u=vec[i+1].sc;
			for(int j=0;j<circ[t].size();j++){
				q[circ[t][j]]=circ[u][j];
				q[circ[u][j]]=circ[t][(j+1)%circ[t].size()];
			}
			i++;
		}
	}
	for(int i=0;i<n;i++){
		printf("%d%c",q[i]+1,(i+1==n)?'\n':' ');
	}
}