#include<cstdio>
#include<cstring>
#include<set>
#include<bitset>
#include<utility>
using namespace std;
set<pair<int,int>> S;
bitset<2100> a[2100],cha[2100];
bool bobo[2100];
int main()
{
	int n,m,q;scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)S.insert({0,i});
	for(int i=1;i<=m;i++){cha[i]=cha[i-1];cha[i].set(i);}
	for(int i=1;i<=q;i++)
	{
		int x,l,r;scanf("%d%d%d",&x,&l,&r);
		auto it=S.find({a[x].count(),x});
		auto pred=it,succ=it;
		pred--;succ++;
		if(pred!=S.end()&&succ!=S.end())bobo[(*succ).second]=(a[(*pred).second]&~a[(*succ).second]).count();
		S.erase(it);
		a[x]^=cha[l-1];a[x]^=cha[r];
		it=S.insert({a[x].count(),x}).first;
		pred=it;succ=it;
		pred--;succ++;
		if(pred!=S.end())bobo[x]=(a[(*pred).second]&~a[x]).count();
		if(succ!=S.end())bobo[(*succ).second]=(a[x]&~a[(*succ).second]).count();
		bool bk=false;
		for(int j=1;j<=n;j++)
		{
			if(bobo[j]==true)
			{
				it=S.find({a[j].count(),j});
				if(it!=S.begin())
				{
					it--;
					bitset<2100> g=a[(*it).second]&~a[j];
					bitset<2100> gg=~a[(*it).second]&a[j];
					int k=g._Find_first();
					int kk=gg._Find_first();
					if(k>kk)k^=kk^=k^=kk;
					int x=(*it).second,y=j;
					if(x>y)x^=y^=x^=y;
					printf("%d %d %d %d\n",x,k,y,kk);
					bk=true;
					break;
				}
			}
		}
		if(bk==false)printf("-1\n");
	}
	return 0;
}