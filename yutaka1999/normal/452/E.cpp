#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#define SIZE 300005
#define MOD 1000000007

using namespace std;
typedef pair <int,int> P;
typedef pair <P,P> PP;
typedef long long int ll;

char A[SIZE],B[SIZE],C[SIZE];
int rA[SIZE],rB[SIZE],rC[SIZE];
int tp[SIZE],pos[SIZE];
int lcp[SIZE];
int sumA[SIZE],sumB[SIZE],sumC[SIZE];
PP tmp[SIZE];
ll ans[SIZE];

int main()
{
	scanf("%s",&A);
	scanf("%s",&B);
	scanf("%s",&C);
	int sa=strlen(A),sb=strlen(B),sc=strlen(C);
	for(int i=0;i<sa;i++) rA[i]=A[i]-'a';
	for(int i=0;i<sb;i++) rB[i]=B[i]-'a';
	for(int i=0;i<sc;i++) rC[i]=C[i]-'a';
	for(int k=1;k<=max(sa,max(sb,sc));k<<=1)
	{
		int sz=0;
		for(int i=0;i<sa;i++)
		{
			tmp[sz++]=PP(P(rA[i],i+k<sa?rA[i+k]:-1),P(i,0));
		}
		for(int i=0;i<sb;i++)
		{
			tmp[sz++]=PP(P(rB[i],i+k<sb?rB[i+k]:-1),P(i,1));
		}
		for(int i=0;i<sc;i++)
		{
			tmp[sz++]=PP(P(rC[i],i+k<sc?rC[i+k]:-1),P(i,2));
		}
		sort(tmp,tmp+sz);
		bool up=k*2>max(sa,max(sb,sc));
		for(int i=0;i<sz;)
		{
			P f=tmp[i].first;
			int s=i;
			for(;i<sz&&tmp[i].first==f;i++)
			{
				P p=tmp[i].second;
				if(p.second==0) rA[p.first]=up?i:s;
				else if(p.second==1) rB[p.first]=up?i:s;
				else rC[p.first]=up?i:s;
			}
		}
	}
	for(int i=0;i<sa;i++)
	{
		pos[rA[i]]=i;
		tp[rA[i]]=0;
	}
	for(int i=0;i<sb;i++)
	{
		pos[rB[i]]=i;
		tp[rB[i]]=1;
	}
	for(int i=0;i<sc;i++)
	{
		pos[rC[i]]=i;
		tp[rC[i]]=2;
	}
	int h=0,all=sa+sb+sc;
	for(int i=0;i<sa;i++)
	{
		if(h>0) h--;
		if(rA[i]+1==all) continue;
		int tg=pos[rA[i]+1];
		if(tp[rA[i]+1]==0)
		{
			while(i+h<sa&&tg+h<sa)
			{
				if(A[i+h]==A[tg+h]) h++;
				else break;
			}
		}
		else if(tp[rA[i]+1]==1)
		{
			while(i+h<sa&&tg+h<sb)
			{
				if(A[i+h]==B[tg+h]) h++;
				else break;
			}
		}
		else
		{
			while(i+h<sa&&tg+h<sc)
			{
				if(A[i+h]==C[tg+h]) h++;
				else break;
			}
		}
		lcp[rA[i]]=h;
	}
	h=0;
	for(int i=0;i<sb;i++)
	{
		if(h>0) h--;
		if(rB[i]+1==all) continue;
		int tg=pos[rB[i]+1];
		if(tp[rB[i]+1]==0)
		{
			while(i+h<sb&&tg+h<sa)
			{
				if(B[i+h]==A[tg+h]) h++;
				else break;
			}
		}
		else if(tp[rB[i]+1]==1)
		{
			while(i+h<sb&&tg+h<sb)
			{
				if(B[i+h]==B[tg+h]) h++;
				else break;
			}
		}
		else
		{
			while(i+h<sb&&tg+h<sc)
			{
				if(B[i+h]==C[tg+h]) h++;
				else break;
			}
		}
		lcp[rB[i]]=h;
	}
	h=0;
	for(int i=0;i<sc;i++)
	{
		if(h>0) h--;
		if(rC[i]+1==all) continue;
		int tg=pos[rC[i]+1];
		if(tp[rC[i]+1]==0)
		{
			while(i+h<sc&&tg+h<sa)
			{
				if(C[i+h]==A[tg+h]) h++;
				else break;
			}
		}
		else if(tp[rC[i]+1]==1)
		{
			while(i+h<sc&&tg+h<sb)
			{
				if(C[i+h]==B[tg+h]) h++;
				else break;
			}
		}
		else
		{
			while(i+h<sc&&tg+h<sc)
			{
				if(C[i+h]==C[tg+h]) h++;
				else break;
			}
		}
		lcp[rC[i]]=h;
	}
	for(int i=0;i<all;i++)
	{
		sumA[i]=sumB[i]=sumC[i]=0;
		if(tp[i]==0) sumA[i]++;
		else if(tp[i]==1) sumB[i]++;
		else sumC[i]++;
		if(i>0)
		{
			sumA[i]+=sumA[i-1];
			sumB[i]+=sumB[i-1];
			sumC[i]+=sumC[i-1];
		}
	}
	lcp[all-1]=-1;
	stack <P> st;
	for(int i=0;i<all;i++)
	{
		int last=i;
		while(!st.empty()&&st.top().first>lcp[i])
		{
			P p=st.top();st.pop();
			last=p.second;
			int low=max((st.empty()?0:st.top().first),lcp[i])+1;
			ll a=sumA[i]-(last==0?0:sumA[last-1]);
			ll b=sumB[i]-(last==0?0:sumB[last-1]);
			ll c=sumC[i]-(last==0?0:sumC[last-1]);
			ll gt=a*b%MOD*c%MOD;
			ans[low]+=gt;
			if(ans[low]>=MOD) ans[low]-=MOD;
			ans[p.first+1]+=MOD-gt;
			if(ans[p.first+1]>=MOD) ans[p.first+1]-=MOD;
		}
		if(st.empty()||st.top().first<lcp[i])
		{
			st.push(P(lcp[i],last));
		}
	}
	for(int i=1;i<=min(sa,min(sb,sc));i++)
	{
		ans[i]+=ans[i-1];
		if(ans[i]>=MOD) ans[i]-=MOD;
		if(i!=1) printf(" ");
		printf("%I64d",ans[i]);
	}
	puts("");
	return 0;
}