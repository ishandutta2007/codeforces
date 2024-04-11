#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define fr first
#define sc second

const int INF=1000000000;

int n,s;
int a[2002];

pair<int,pair<int,int>> dp[2002][2002];

int dist(int from,int to,int dir){
	if(dir==0){
		int x=to-from;
		if(x<0)x+=n;
		return x;
	}
	else {
		int x=from-to;
		if(x<0)x+=n;
		return x;
	}
}

int main(){
	scanf("%d%d",&n,&s); s--;
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	
	int k;
	if(1){
		vector<int> vec;
		for(int i=0;i<n;i++)vec.push_back(a[i]);
		sort(vec.begin(),vec.end());
		vec.erase(unique(vec.begin(),vec.end()),vec.end());
		for(int i=0;i<n;i++){
			a[i]=lower_bound(vec.begin(),vec.end(),a[i])-vec.begin();
		}
		k=vec.size();
	}
	
	vector<int> ids[2002];
	ids[0].push_back(s);
	for(int i=0;i<n;i++){
		ids[a[i]+1].push_back(i);
	}
	for(int i=0;i<2002;i++){
		for(int j=0;j<2002;j++){
			dp[i][j]=mp(INF,mp(-1,-1));
		}
	}
	dp[0][s]=mp(0,mp(-1,-1));
	for(int i=0;i<k;i++){
		for(int x: ids[i]){
			for(int j=0;j<ids[i+1].size();j++){
				int y=ids[i+1][j];
				int pre=j-1; if(pre==-1)pre=ids[i+1].size()-1;
				int z=ids[i+1][pre];
				if(dist(x,z,0)+dist(z,y,0)==dist(x,y,0)){
					dp[i+1][y]=min(dp[i+1][y],mp(dp[i][x].fr+dist(x,z,0)+dist(z,y,1),mp(x,0)));
				}
				else if(x!=y) {
					dp[i+1][y]=min(dp[i+1][y],mp(dp[i][x].fr+dist(x,y,1),mp(x,0)));
				}
				else {
					dp[i+1][y]=min(dp[i+1][y],mp(dp[i][x].fr+n,mp(x,0)));
				}
				int nex=j+1; if(nex==ids[i+1].size())nex=0;
				int w=ids[i+1][nex];
				if(dist(x,w,1)+dist(w,y,1)==dist(x,y,1)){
					dp[i+1][y]=min(dp[i+1][y],mp(dp[i][x].fr+dist(x,w,1)+dist(w,y,0),mp(x,1)));
				}
				else if(x!=y) {
					dp[i+1][y]=min(dp[i+1][y],mp(dp[i][x].fr+dist(x,y,0),mp(x,1)));
				}
				else {
					dp[i+1][y]=min(dp[i+1][y],mp(dp[i][x].fr+n,mp(x,1)));
				}
			}
		}
	}
	
	/*for(int i=0;i<=k;i++){
		for(int x: ids[i]){
			cout<<i<<" "<<x<<" "<<dp[i][x].fr<<" "<<dp[i][x].sc.fr<<" "<<dp[i][x].sc.sc<<endl;
		}
	}*/
	
	vector<int> ret;
	pair<int,int> loc;
	if(1){
		pair<int,int> p(INF,-1);
		for(int i=0;i<n;i++){
			p=min(p,mp(dp[k][i].fr,i));
		}
		loc=mp(k,p.sc);
		printf("%d\n",p.fr);
	}
	while(1){
		if(loc.fr==0){
			ret.push_back(loc.sc);
			break;
		}
		auto pre=dp[loc.fr][loc.sc].sc;
		if(pre.sc==0){
			for(int x: ids[loc.fr]){
				if(x>=loc.sc)ret.push_back(x);
			}
			for(int x: ids[loc.fr]){
				if(x<loc.sc)ret.push_back(x);
			}
		}
		else {
			for(int i=ids[loc.fr].size()-1;i>=0;i--){
				int x=ids[loc.fr][i];
				if(x<=loc.sc)ret.push_back(x);
			}
			
			for(int i=ids[loc.fr].size()-1;i>=0;i--){
				int x=ids[loc.fr][i];
				if(x>loc.sc)ret.push_back(x);
			}
		}
		loc.fr--;
		loc.sc=pre.fr;
	}
	reverse(ret.begin(),ret.end());
	for(int i=0;i+1<ret.size();i++){
		int d[2];
		for(int j=0;j<2;j++)d[j]=dist(ret[i],ret[i+1],j);
		if(d[0]<d[1]){
			printf("+%d\n",d[0]);
		}
		else {
			printf("-%d\n",d[1]);
		}
	}
}