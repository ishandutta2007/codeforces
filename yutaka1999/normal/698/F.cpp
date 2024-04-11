#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 1000005
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <vector <int>,vector <int> > P;
typedef pair <P,P> PP;
typedef pair <P,PP> PPP;

vector <int> dv[SIZE];
vector <int> start[SIZE];
vector <int> end[SIZE];
ll fac[SIZE];
bool ok[SIZE];
int mul[SIZE],cnt[SIZE];
int func[SIZE],nm[SIZE];
int per[SIZE];
int id[SIZE];
vector <int> a1,b1,c1,d1,e1,f1;
int sz;
int n;

void divide_vector(vector <int> &A,vector <int> &B,vector <int> &C,vector <int> &D)//A->B,C->D , sorted
{
	a1.clear();b1.clear();c1.clear();d1.clear();e1.clear();f1.clear();
	int to=0;
	for(int i=0;i<A.size();i++)
	{
		while(to<C.size()&&C[to]<A[i]) e1.push_back(C[to++]);
		if(A[i]==C[to])
		{
			a1.push_back(A[i]);
			to++;
		}
		else c1.push_back(A[i]);
	}
	while(to<C.size()) e1.push_back(C[to++]);
	to=0;
	for(int i=0;i<B.size();i++)
	{
		while(to<D.size()&&D[to]<B[i]) f1.push_back(D[to++]);
		if(B[i]==D[to])
		{
			b1.push_back(B[i]);
			to++;
		}
		else d1.push_back(B[i]);
	}
	while(to<D.size()) f1.push_back(D[to++]);
}
void make()
{
	for(int i=1;i<=n;i++) mul[i]=1;
	dv[1].push_back(1);
	func[1]=1;
	ok[1]=true;
	for(int i=2;i<=n;i++)
	{
		if(mul[i]!=1) continue;
		ok[i]=true;
		func[i]=n/i;
		for(int j=i;j<=n;j+=i)
		{
			mul[j]*=i;
			dv[j].push_back(i);
		}
	}
	fac[0]=1;
	for(int i=1;i<=n;i++)
	{
		cnt[mul[i]]++;
		id[i]=-1;
		fac[i]=fac[i-1]*(ll) i%MOD;
	}
	sz=0;
}
int main()
{
	scanf("%d",&n);
	make();
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&per[i]);
		if(per[i]!=0)
		{
			cnt[mul[i]]--;
			if(dv[per[i]].size()!=dv[i].size())
			{
				puts("0");
				return 0;
			}
			int now=0;
			for(int j=0;j<dv[per[i]].size();)
			{
				vector <int> f,s;
				int g=func[dv[per[i]][j]];
				for(;j<dv[per[i]].size()&&func[dv[per[i]][j]]==g;j++) f.push_back(dv[per[i]][j]);
				for(;now<dv[i].size()&&func[dv[i][now]]==g;now++) s.push_back(dv[i][now]);
				if(f.size()!=s.size())
				{
					puts("0");
					return 0;
				}
				//continue;
				//start->endf->sABTCYX20
				//Aiid[i](-1)
				for(int k=0;k<f.size();k++)
				{
					if(id[f[k]]==-1) continue;
					//id[f[k]]f
					int c=id[f[k]];
					divide_vector(start[c],end[c],f,s);
					if(a1.size()!=b1.size())
					{
						puts("0");
						return 0;
					}
					start[c]=a1;
					end[c]=b1;
					if(!c1.empty())
					{
						start[sz]=c1;
						end[sz++]=d1;
						for(int q=0;q<start[sz-1].size();q++) id[start[sz-1][q]]=sz-1;
					}
					f=e1;
					s=f1;
				}
				if(!f.empty())
				{
					for(int q=0;q<f.size();q++) id[f[q]]=sz;
					start[sz]=f;
					end[sz++]=s;
				}
			}
		}
	}
	ll ret=1;
	for(int i=1;i<=n;i++) if(cnt[i]!=0) ret=ret*fac[cnt[i]]%MOD;/*
	for(int i=0;i<sz;i++)
	{
		printf("* %d\n",start[i].size());
		for(int j=0;j<start[i].size();j++) printf("%d ",start[i][j]);puts("");
		for(int j=0;j<end[i].size();j++) printf("%d ",end[i][j]);puts("");
	}*/
	for(int i=0;i<sz;i++) ret=ret*fac[start[i].size()]%MOD;
	for(int i=1;i<=n;i++) if(ok[i]&&id[i]==-1) nm[func[i]]++;
	//for(int i=1;i<=n;i++) printf("%d ",nm[i]);puts("");
	for(int i=1;i<=n;i++) if(nm[i]!=0) ret=ret*fac[nm[i]]%MOD;
	printf("%lld\n",ret);
	return 0;
}