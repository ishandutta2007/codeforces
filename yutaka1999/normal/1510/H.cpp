#include <bits/stdc++.h>
#define SIZE 2005
#define INF 1000000000
using namespace std;
typedef pair <int,int> P;
typedef pair <P,P> PP;

int L[SIZE],R[SIZE];
vector <int> vec[SIZE];
int dp[SIZE][2][2][SIZE];
P nxt[SIZE][2][2][SIZE];
int nd[SIZE];
int lx[SIZE],rx[SIZE];
vector < vector <int> > dp2[SIZE][2][2];
vector < vector <PP> > back[SIZE][2][2];
int la[SIZE],ra[SIZE];
int n;
void dfs(int v){
	for(int x=0;x<2;x++){
		for(int y=0;y<2;y++){
			dp2[v][x][y].resize(vec[v].size());
			back[v][x][y].resize(vec[v].size());
			for(int i=0;i<vec[v].size();i++){
				dp2[v][x][y][i].resize(n+1,-INF);
				back[v][x][y][i].resize(n+1,PP(P(-1,-1),P(-1,-1)));
			}
			for(int i=0;i<=n;i++) dp[v][x][y][i]=-INF;
		}
	}
	lx[v]=L[v],rx[v]=R[v];
	nd[v]=0;
	for(int i=0;i<vec[v].size();i++){
		int to=vec[v][i];
		dfs(to);
		if(i==0){
			lx[v]=lx[to];
			for(int j=0;j<=nd[to];j++){
				for(int x=0;x<2;x++){
					for(int y=0;y<2;y++){
						dp2[v][x][y][i][j]=dp[to][x][y][j];
					}
				}
			}
		} else{
			for(int j=0;j<=nd[v];j++){
				for(int k=0;k<=nd[to];k++){
					for(int x=0;x<2;x++){
						for(int y=0;y<2;y++){
							if(dp2[v][x][y][i-1][j]<0) continue;
							for(int z=0;z<2;z++){
								for(int w=0;w<2;w++){
									if(dp[to][z][w][k]<0) continue;
									int sum=dp2[v][x][y][i-1][j]+dp[to][z][w][k];
									if(dp2[v][x][w][i][j+k]<sum){
										dp2[v][x][w][i][j+k]=sum;
										back[v][x][w][i][j+k]=PP(P(j,k),P(y,z));
									}
									if(y==0&&z==0){
										sum+=lx[to]-rx[v];
										if(dp2[v][x][w][i][j+k+1]<sum){
											dp2[v][x][w][i][j+k+1]=sum;
											back[v][x][w][i][j+k+1]=PP(P(j,k),P(y,z));
										}
									}
								}
							}
						}
					}
				}
			}
		}
		nd[v]+=nd[to];
		rx[v]=rx[to];
	}
	if(vec[v].size()==0){
		dp[v][0][0][0]=R[v]-L[v];
		nxt[v][0][0][0]=P(-1,-1);
	} else{
		int e=vec[v].size()-1;
		for(int x=0;x<2;x++){
			for(int y=0;y<2;y++){
				for(int i=0;i<=nd[v];i++){
					dp[v][x][y][i]=dp2[v][x][y][e][i+1];
					nxt[v][x][y][i]=P(x,y);
					if(dp[v][x][y][i]<dp2[v][x][y][e][i]){
						dp[v][x][y][i]=dp2[v][x][y][e][i];
						nxt[v][x][y][i]=P(-1,-1);
					}
					if(x==1&&dp2[v][0][y][e][i]>=0){
						int w=dp2[v][0][y][e][i]+lx[v]-L[v];
						if(dp[v][x][y][i]<w){
							dp[v][x][y][i]=w;
							nxt[v][x][y][i]=P(0,y);
						}
					}
					if(y==1&&dp2[v][x][0][e][i]>=0){
						int w=dp2[v][x][0][e][i]+R[v]-rx[v];
						if(dp[v][x][y][i]<w){
							dp[v][x][y][i]=w;
							nxt[v][x][y][i]=P(x,0);
						}
					}
				}
			}
		}
	}
	nd[v]++;/*
	printf("%d : %d %d\n",v,L[v],R[v]);
	for(int x=0;x<2;x++){
		for(int y=0;y<2;y++) printf("%d ",dp[v][x][y][0]);
		puts("");
	}*/
}
stack <int> st;
void recover(int v,int x,int y,int z){
	if(vec[v].size()==0){
		la[v]=L[v],ra[v]=R[v];
		return;
	}
	P p=nxt[v][x][y][z];
	//printf("%d : %d %d %d : %d %d\n",v,x,y,z,p.first,p.second);
	if(p==P(-1,-1)){
		la[v]=ra[v]=-1;
	} else if(p==P(x,y)){
		z++;
		st.push(v);
	} else{
		if(x!=p.first){
			la[v]=L[v],ra[v]=lx[v];
			x=0;
		} else{
			la[v]=rx[v],ra[v]=R[v];
			y=0;
		}
	}
	for(int i=vec[v].size()-1;i>=0;i--){
		int to=vec[v][i];
		if(i>0){
			int bef=vec[v][i-1];
			P p=back[v][x][y][i][z].first;
			P q=back[v][x][y][i][z].second;
			if(p.first+p.second<z){
				int u=st.top();st.pop();
				la[u]=rx[bef],ra[u]=lx[to];
				recover(to,0,y,p.second);
				y=0,z=p.first;
			} else{
				recover(to,q.second,y,p.second);
				y=q.first,z=p.first;
			}
		} else{
			recover(to,x,y,z);
		}
	}
}
int main(){
	scanf("%d",&n);
	vector <P> dat;
	for(int i=0;i<n;i++){
		scanf("%d%d",&L[i],&R[i]);
		dat.push_back(P(R[i]-L[i],i));
	}
	sort(dat.begin(),dat.end());
	vector <int> rem;
	for(int i=0;i<n;i++){
		int v=dat[i].second;
		vector <int> rem2;
		rem2.push_back(v);
		vector <P> vx;
		for(int j=0;j<rem.size();j++){
			if(L[v]<=L[rem[j]]&&R[rem[j]]<=R[v]){
				vx.push_back(P(L[rem[j]],rem[j]));
			} else{
				rem2.push_back(rem[j]);
			}
		}
		sort(vx.begin(),vx.end());
		for(int j=0;j<vx.size();j++) vec[v].push_back(vx[j].second);
		rem=rem2;
	}
	int sum=0;
	for(int i=0;i<rem.size();i++){
		int rt=rem[i];
		dfs(rt);
		int a=0,b=0;
		for(int x=0;x<2;x++){
			for(int y=0;y<2;y++){
				if(dp[rt][a][b][0]<dp[rt][x][y][0]){
					a=x,b=y;
				}
			}
		}
		recover(rt,a,b,0);
		sum+=dp[rt][a][b][0];
	}
	printf("%d\n",sum);
	for(int i=0;i<n;i++){
		int v=dat[i].second;
		if(la[v]==-1&&ra[v]==-1){
			for(int j=i+1;j<n;j++){
				int u=dat[j].second;
				if(la[u]==-1) continue;
				if(L[v]<=la[u]&&ra[u]<=R[v]){
					la[v]=la[u],ra[v]=ra[u];
					la[v]=ra[v]=-1;
					continue;
				}
				if(L[v]<ra[u]&&ra[u]<=R[v]){
					ra[v]=ra[u];
					la[v]=L[v];
					ra[u]=L[v];
					break;
				}
				if(L[v]<=la[u]&&la[u]<R[v]){
					la[v]=la[u];
					ra[v]=R[v];
					la[u]=R[v];
					break;
				}
			}
		}
	}
	for(int i=0;i<n;i++) printf("%d %d\n",la[i],ra[i]);
}