#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#define SIZE 100005
#define M1 1000000007LL
#define M2 1000000009LL
#define B1 89723191LL
#define B2 197983LL

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

ll rt1[SIZE],rt2[SIZE];
void make()
{
	rt1[0]=rt2[0]=1;
	for(int i=1;i<SIZE;i++)
	{
		rt1[i]=rt1[i-1]*B1%M1;
		rt2[i]=rt2[i-1]*B2%M2;
	}
}
struct Hash
{
	ll h1,h2;
	Hash(ll h1=0,ll h2=0):h1(h1),h2(h2){}
	Hash operator+(const Hash&l) const
	{
		return Hash((h1+l.h1)%M1,(h2+l.h2)%M2);
	}
	void shift(int t)
	{
		h1=h1*rt1[t]%M1;
		h2=h2*rt2[t]%M2;
	}
	bool operator==(const Hash&l) const
	{
		return l.h1==h1&&l.h2==h2;
	}
};
char str[SIZE];
Hash hs[SIZE],ht[SIZE];
int cnt[SIZE],KMP[SIZE];

int main()
{
	make();
	scanf("%s",&str);
	string S=str;
	scanf("%s",&str);
	string T=str;
	for(int i=0;i<S.size();i++)
	{
		hs[i]=Hash(S[i]-'a'+1,S[i]-'a'+1);
		if(i>0)
		{
			Hash h=hs[i-1];
			h.shift(1);
			hs[i]=hs[i]+h;
		}
	}
	for(int i=0;i<T.size();i++)
	{
		ht[i]=Hash(T[i]-'a'+1,T[i]-'a'+1);
		if(i>0)
		{
			Hash h=ht[i-1];
			h.shift(1);
			ht[i]=ht[i]+h;
		}
	}
	for(int i=0;i<S.size();i++)
	{
		int l=0,r=T.size();
		while(r-l>1)
		{
			int d=(l+r)/2;
			if(i+d>=S.size()) r=d;
			else
			{
				Hash h=hs[i];
				h.shift(d);
				h=h+ht[d-1];
				if(h==hs[i+d]) l=d;
				else r=d;
			}
		}
		cnt[r]++;
	}
	for(int i=1;i<=T.size();i++) cnt[i]+=cnt[i-1];
	ll ret=0;
	for(int i=0;i<T.size();i++)
	{
		if(i==0) KMP[i]=-1;
		else
		{
			int t=KMP[i-1];
			while(1)
			{
				if(T[t+1]==T[i])
				{
					KMP[i]=t+1;
					break;
				}
				else
				{
					if(t==-1)
					{
						KMP[i]=-1;
						break;
					}
					else t=KMP[t];
				}
			}
		}
		if(KMP[i]==-1) ret+=S.size();
		else ret+=cnt[i-KMP[i]];
	}
	printf("%lld\n",ret);
	return 0;
}