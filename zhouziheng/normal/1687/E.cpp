#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> dv[2000000];
vector<int> P,VAL;
bool in_P[200000],in_val[2000000];

bool is_prm[2000000];int prm_lst[2000000],pcnt;

int pw[200000],pos[2];

int cntbit[1<<16];

void init(int n)
{
	for(int i=2;i<=n;i++)is_prm[i]=1;
	for(int i=2;i<=n;i++)
	{
		if(is_prm[i]){prm_lst[++pcnt]=i,dv[i].push_back(i);}
		for(int j=1;prm_lst[j]*i<=n;j++)
		{
			int u=prm_lst[j];is_prm[u*i]=0;
			dv[u*i]=dv[i];
			if(i%u==0)
			{
				break;
			}
			dv[u*i].push_back(u);
		}
	}
}

long long gcd(long long x,long long y){return y?gcd(y,x%y):x;}

int a[200000];
long long calc_ans(vector<int> P)
{
	long long ret=0;for(int i=0;i<P.size();i++)for(int j=i+1;j<P.size();j++)ret=gcd(ret,(long long)a[P[i]]*a[P[j]]);
	return ret;
}


int main()
{
	init(1000000);
	int n=0;scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n<=14)
	{
		for(int i=1;i<=n;i++)P.push_back(i);
	}
	else
	{
		for(int i=0;i<dv[a[1]].size();i++)
		{
			int p=dv[a[1]][i];int cnt=0;
			for(int j=1;j<=n;j++)if(a[i]%p==0)cnt++;
			if(cnt>=n-1)VAL.push_back(p),in_val[p]=1;
		}
		for(int i=0;i<dv[a[2]].size();i++)
		{
			int p=dv[a[2]][i];int cnt=0;
			for(int j=1;j<=n;j++)if(a[i]%p==0)cnt++;
			if(cnt>=n-1)VAL.push_back(p),in_val[p]=1;
		}
		//for(int i=1;i<=10;i++)printf("%d",(int)in_val[i]);puts("");
		sort(VAL.begin(),VAL.end());VAL.erase(unique(VAL.begin(),VAL.end()),VAL.end());
		//for(int i=0;i<VAL.size();i++)printf("%d ",VAL[i]);puts("");
		pw[0]=100;
		for(int i=0;i<VAL.size();i++)
		{
			pos[0]=pos[1]=0;
			for(int j=1;j<=n;j++)
			{
				int x=a[j];pw[j]=0;while(x%VAL[i]==0){x/=VAL[i],pw[j]++;}
				if(pw[j]<pw[pos[0]]){pos[1]=pos[0];pos[0]=j;}
				else if(pw[j]<pw[pos[1]])pos[1]=j;
			}
			P.push_back(pos[0]),P.push_back(pos[1]);in_P[pos[0]]=in_P[pos[1]]=1;
		}
		sort(P.begin(),P.end());P.erase(unique(P.begin(),P.end()),P.end());
		//for(int i=0;i<P.size();i++)printf("%d ",P[i]);puts("");
		
		for(int i=2;i<=1000000;i++)
		{
			if(!is_prm[i])continue;
			if(in_val[i])continue;
			//printf("%d\n",i);
			int cnt=P.size();
			for(int j=0;j<P.size();j++)if(a[P[j]]%i==0)cnt--;
			while(cnt<2)
			{
				for(int j=1;j<=n;j++)
				{
					if(!in_P[j]&&a[j]%i!=0)
					{
						in_P[j]=1,P.push_back(j);break;
					}
				}
				cnt++;
			}
			sort(P.begin(),P.end());P.erase(unique(P.begin(),P.end()),P.end());
			
		}
		while(P.size()>14)
		{
			for(int j=0;j<P.size();j++)
			{
				vector<int> Q;for(int k=0;k<P.size();k++)if(k!=j)Q.push_back(P[k]);
				if(calc_ans(P)==calc_ans(Q)){P=Q;break;}
			}
		}
	}
	//printf("%d\n",P.size());return 0;
	vector<pair<int,int> > ans;
	int m=P.size();
	for(int i=1;i<(1<<m);i++)cntbit[i]=cntbit[i>>1]+(i&1);
	//for(int i=1;i<(1<<m);i++)printf("%d ",cntbit[i]);puts("");
	for(int i=1;i<(1<<m);i++)
	{
		int x=0;if(cntbit[i]&1)x=2-cntbit[i];else x=cntbit[i]-2;
		if(x>=0){for(int j=1;j<=x;j++)ans.push_back(make_pair(0,i));}
		else{for(int j=-1;j>=x;j--)ans.push_back(make_pair(1,i));}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
	{
		printf("%d ",ans[i].first);int u=ans[i].second;
		printf("%d ",cntbit[u]);
		for(int j=0;j<m;j++)if(u&(1<<j)){printf("%d ",P[j]);}
		puts("");
	}
}