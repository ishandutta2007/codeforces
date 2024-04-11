#include<bits/stdc++.h>
#define pa pair<int,int>
#define mo 1000000007
#define ll long long
#define mk make_pair
#define fi first
#define se second 
using namespace std;
bool vis[1005][1005];
int f[1005][1005];
char s[1005];
int way[1005];
int n,k;
int dp(int len,int sum,bool up){
	if (!s[len]) return way[sum]+1==n?1:0;
	if (!up&&vis[len][sum]) return f[len][sum];
	int ans=0;
	for (int i=0;i<=(up?s[len]-'0':1);i++)
		ans=(ans+dp(len+1,sum+i,up&(i==s[len]-'0')))%mo;
	if (!up){
		vis[len][sum]=1;
		f[len][sum]=ans;
	}
	//printf("%d %d %d %d\n",len,sum,up?1:0,ans);
	return ans;
}
int main(){
	scanf("%s%d",s+1,&n);
	if (n==0)
		return printf("%d",1),0;
	int len=strlen(s+1);
	way[0]=1e9;
	for (int i=2;i<=len;i++){
		int sum=0;
		for (int j=i;j;j-=j&(-j)) sum++;
		way[i]=way[sum]+1;
	}
	printf("%d",(dp(1,0,1)+mo-(n==1?1:0))%mo);
}