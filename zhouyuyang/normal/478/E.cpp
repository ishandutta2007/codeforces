#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<climits>
#include<vector>
using namespace std;
long long n,k;
const long long Lim=1e14;
const long long M=1e7;
int flag[M],f[M];
#define MAXV 15
int b[MAXV];
vector<pair<int,int> >Q[MAXV][2];
inline int calc(int x,int flag,long long now,long long &k){
	if(now>=M)return -1;
	int st=lower_bound(Q[x][flag].begin(),Q[x][flag].end(),make_pair((int)now,0))-Q[x][flag].begin();
	int ed=lower_bound(Q[x][flag].begin(),Q[x][flag].end(),make_pair((int)now+1,0))-Q[x][flag].begin();
	if(ed-st<k){
		k-=ed-st;return -1;
	}for(int i=st;i<=Q[x][flag].size();i++){
		k--;if(!k)return Q[x][flag][i].second;
	}return -1;
}
inline long long Solve(){
	if(n*k>Lim)return -1;
	for(int i=1;i<M;i++){
		if(i/10%10==i%10)continue;
		int reflag=i/10%10<i%10?1:-1;
		if(i<10||flag[i/10]&&f[i/10]!=reflag){
			if(i<10)reflag=0;
			flag[i]=1;f[i]=reflag;
			if(i%n==0){
				if(--k==0)return i;
			}
		}
	}for(int i=1;i<M;i++){
		b[1]++;int now=1;for(;b[now]>=10;){
			b[now+1]+=b[now]/10;
			b[now]%=10;now++;
		}int flag=1;for(int j=2;j<=6;j++)
			if((b[j]-b[j-1])*(b[j]-b[j+1])<=0){
				flag=0;break;
			}
		if(!flag)continue;
		Q[b[7]][b[6]>b[7]?1:0].push_back(make_pair(i%n,i));
	}
	for(int i=0;i<=9;i++)
	    for(int j=0;j<=1;j++)
	        sort(Q[i][j].begin(),Q[i][j].end());
	for(int i=1;i<M;i++)if(flag[i]){
		int reflag=i/10%10<i%10?1:-1;
		if(i<10)reflag=0;long long now=1ll*n-(1ll*i*M)%n;
		if(now==n)now=0;if(reflag==1||reflag==0){
			for(int j=0;j<i%10;j++){
				int tmp=calc(j,1,now,k);
				if(tmp!=-1)return 1ll*i*M+1ll*tmp;
			}
		}if(reflag==-1||reflag==0){
			for(int j=i%10+1;j<=9;j++){
				int tmp=calc(j,0,now,k);
				if(tmp!=-1)return 1ll*i*M+1ll*tmp;
			}
		}
	}return -1;
}
int main(){
	scanf("%I64d%I64d",&n,&k);
	printf("%I64d\n",Solve());
}