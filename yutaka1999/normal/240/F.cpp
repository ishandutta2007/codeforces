#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 100005
#define BT 1024*128*2

using namespace std;

struct segtree//C all 0 , all 1 , count 1
{
	int seg[BT*2];
	bool up[BT*2];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		memset(seg,0,sizeof(seg));
		memset(up,false,sizeof(up));
	}
	void pass(int k)
	{
		if(up[k])
		{
			up[k]=false;
			up[k*2+1]=up[k*2+2]=true;
			seg[k*2+1]=seg[k*2+2]=seg[k]/2;
		}
	}
	void make(int k)
	{
		up[k]=false;
		seg[k]=seg[k*2+1]+seg[k*2+2];
	}
	void updata(int a,int b,int k,int l,int r,int v)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b)
		{
			seg[k]=v*(r-l);
			up[k]=true;
		}
		else
		{
			pass(k);
			updata(a,b,k*2+1,l,(l+r)/2,v);
			updata(a,b,k*2+2,(l+r)/2,r,v);
			make(k);
		}
	}
	void fill(int a,int b)
	{
		updata(a,b,0,0,mum,1);
	}
	void rem(int a,int b)
	{
		updata(a,b,0,0,mum,0);
	}
	int sum(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return 0;
		if(a<=l&&r<=b) return seg[k];
		else
		{
			pass(k);
			int vl=sum(a,b,k*2+1,l,(l+r)/2);
			int vr=sum(a,b,k*2+2,(l+r)/2,r);
			return vl+vr;
		}
	}
	int sum(int a,int b)
	{
		return sum(a,b,0,0,mum);
	}
};
segtree seg[26];
char str[SIZE];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	scanf("%s",&str);
	for(int i=0;i<26;i++) seg[i].init(n+2);
	for(int i=0;i<n;i++)
	{
		int a=str[i]-'a';
		seg[a].fill(i,i+1);
	}
	for(int i=0;i<m;i++)
	{
		int a,b;//[a,b)
		scanf("%d %d",&a,&b);a--;
		int cnt=0;
		for(int j=0;j<26;j++) cnt+=seg[j].sum(a,b)%2;
		if(cnt<2)
		{
			int l=a,r=b,pos=-1;//[l,r)
			for(int j=0;j<26;j++)
			{
				int num=seg[j].sum(a,b);
				if(num==0||num==b-a) continue;
				if(num%2==1) pos=j;
				num/=2;
				seg[j].rem(a,b);
				seg[j].fill(l,l+num);
				seg[j].fill(r-num,r);
				l+=num;
				r-=num;
			}
			if(cnt) seg[pos].fill(l,r);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<26;j++)
		{
			if(seg[j].sum(i,i+1)==1)
			{
				printf("%c",'a'+j);
				break;
			}
		}
	}
	puts("");
	return 0;
}