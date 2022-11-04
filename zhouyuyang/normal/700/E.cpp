#include<cstdio>
#include<map>
#include<vector>
#define ll long long
#define mk make_pair
#define pb push_back
using namespace std;
const int N=2e5+5;
const int Mo=1e9+713,Base=317;
map<pair<int,int>,vector<int> >f[N];
int n,i,j,ans,q[N];char s[N];
int pow[N],num[N];
int Hash(int l,int r){
	return (num[r]-(ll)num[l-1]*pow[r-l+1]%Mo+Mo)%Mo;
}
int main(){
	scanf("%d%s",&n,s+1);
	pow[0]=1;
	for (pow[0]=1,i=1;i<=n;i++){
		num[i]=((ll)num[i-1]*Base+s[i])%Mo;
		pow[i]=(ll)pow[i-1]*Base%Mo;
	}
	for (i=1;i<=n;i++) f[1][mk(s[i],1)].pb(i);
	for (i=1;i<=n;i++) if (!f[i].empty()){ans=i;
		map<pair<int,int>,vector<int> >::iterator it;
		for (it=f[i].begin();it!=f[i].end();it++){
			int len=it->first.second;
			vector<int>a=it->second;int m=a.size()-1;
			for (j=0;j<m;j++)
				q[j]=Hash(a[j]+len,a[j+1]-1);
			for (int l=0,r=1;l<m;l=r,r++){
				for (;r<m&&q[r-1]==q[r];r++);
				f[i+r-l][mk(Hash(a[l],a[r]+len-1),a[r]-a[l]+len)].pb(a[l]);
			}
		}
	}
	printf("%d",ans);
}