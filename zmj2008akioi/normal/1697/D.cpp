#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
const int G=30,N=1e3+10;
int n;
char s[N];
bool vis[N];
std::vector<int> vec;
inline int md(int x,int y){return (x+y)>>1;}
inline int idx(char c){return c-'a';}
char query1(int x){
	char res;
	printf("? 1 %d\n",x),fflush(stdout);
	scanf(" %c",&res);return res;
}
int query2(int l,int r){
	int res;
	printf("? 2 %d %d\n",l,r),fflush(stdout);
	scanf("%d",&res);return res;
}
int main(){
	scanf("%d",&n);
	vec.resize(N);
	for(int i=1;i<=n;++i){
		memset(vis,0,sizeof(vis));int cnt=0;
		for(int j=1;j<i;++j){
			if(!vis[idx(s[j])])vec[++cnt]=j;
			vis[idx(s[j])]=true;
		}
		int nw=query2(1,i);
		if(nw>cnt)s[i]=query1(i);
		else{
			memset(vis,0,sizeof(vis));
			int mid,l=1,r=cnt,rec=cnt;
			for(int j=i-1;j;--j){
				if(!vis[idx(s[j])])vec[cnt--]=j;
				vis[idx(s[j])]=true;
			}
			while(l!=r){
				mid=md(l,r+1);
				if(query2(vec[mid],i)<rec-mid+2)l=mid;
				else r=mid-1;
			}
			s[i]=s[vec[l]];
		}
	}
	printf("! %s\n",s+1),fflush(stdout);
	return 0;
}
//10 aecbbedaeb