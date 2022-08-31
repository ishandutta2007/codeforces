#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define INF 1000000000
#define SIZE 200005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

vector <int> vec[SIZE];
vector <int> vx;
P pos[SIZE];
ll ans[SIZE];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		pos[i]=P(y,x);
		vx.push_back(x+1);
		vx.push_back(x-k+1);
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	sort(pos,pos+n);
	for(int i=0;i<n;i++)
	{
		P p=pos[i];
		int l=lower_bound(vx.begin(),vx.end(),p.second-k+1)-vx.begin();
		int r=lower_bound(vx.begin(),vx.end(),p.second+1)-vx.begin();
		for(int j=l;j<r;j++) vec[j].push_back(p.first);
	}
	for(int i=0;i+1<vx.size();i++)
	{
		if(vec[i].empty()) continue;
		//printf("[%d %d]\n",vx[i],vx[i+1]);
		//for(int j=0;j<vec[i].size();j++) printf("%d ",vec[i][j]);puts("");
		int now=vec[i][0]-k+1,nm=0;
		int l=0,r=0;
		while(l<r||r<vec[i].size())
		{
			while(r<vec[i].size()&&now+k-1>=vec[i][r]) r++,nm++;
			while(l<r&&vec[i][l]<now) l++,nm--;
			int L=INF;
			if(l<r) L=min(L,vec[i][l]-now+1);
			if(r<vec[i].size()) L=min(L,vec[i][r]-(now+k)+1);
			if(nm>0) ans[nm-1]+=(ll) L*(ll) (vx[i+1]-vx[i]);
			//printf("%d %d %d * %d %d\n",now,l,r,L,nm);
			now+=L;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(i!=0) printf(" ");
		printf("%lld",ans[i]);
	}puts("");
	return 0;
}