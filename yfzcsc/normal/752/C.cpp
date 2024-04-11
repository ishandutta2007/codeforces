#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
typedef pair<int,int> data;
char s[200010];
char used[200],fan[200];
set<data>st;
int main(){
	int ans=0;
	fan['L']='R';fan['R']='L';
	fan['U']='D';fan['D']='U';
	int n,x=0,y=0;scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;++i){
		if(used[s[i]]){ans++;
			used['L']=used['R']=used['U']=used['D']=false,used[fan[s[i]]]=true;}
		else used[fan[s[i]]]=true;
	//	if(s[i]=='L')x++;if(s[i]=='R')x--;if(s[i]=='U')y++;if(s[i]=='D')y--;
	}ans++;
	printf("%d",ans);
}