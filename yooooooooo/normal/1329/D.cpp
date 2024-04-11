#include<cstdio>
#include<set>
#include<algorithm>
#include<cstring>
using namespace std;
struct node
{
	int x,id;
	node(int nx=0,int nid=0){x=nx;id=nid;}
	bool operator<(const node&y)const{return x>y.x||(x==y.x&&id<y.id);}
}st[200005],a[200005];
multiset<node>stp;
multiset<node>::iterator it;
int T,n,cnt=0,tp=0,x,y,al,sum=0,ans,tot[26],hd;
bool ok;
char s[200005];
void init()
{
	stp.clear();
	cnt=0;tp=0;al=0;sum=0;ans=0;memset(tot,0,sizeof(tot));ok=true;
}
void mu(int id)
{
	stp.erase(node(tot[id],id));
	tot[id]--;
	stp.insert(node(tot[id],id));
}
void era(int x,int y)
{
	printf("%d %d\n",st[tp].x+1,x);
	sum+=x-st[tp].x;
	mu(y);mu(st[tp].id);
	al--;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s);
		n=strlen(s);
		init();
		for(int i=0;i<n-1;i++)
		{
			if(s[i]==s[i+1])
			{
				a[++cnt]=node(i+1,s[i]-'a');
				tot[s[i]-'a']++;
			}
		}
		ans=0;
		for(int i=0;i<26;i++)stp.insert(node(tot[i],i)),ans+=tot[i],al+=tot[i];
		ans=(ans+1)/2;al=(al+1)/2;
		if(stp.begin()->x>ans)ans=stp.begin()->x;
		ans++;
		printf("%d\n",ans);
		for(int i=1;i<=cnt;i++)
		{
			x=a[i].x-sum;y=a[i].id;
			if(tp>0&&st[tp].id!=y&&(ok||y==hd||st[tp].id==hd))era(x,y),tp--;
			else st[++tp]=node(x,y);
			if(ok&&stp.begin()->x>=al)ok=false,hd=stp.begin()->id;
		}
		hd=n-sum;
		while(tp)
		{
			printf("%d %d\n",st[tp].x+1,hd);
			hd=st[tp].x;
			tp--;
		}
		if(hd)printf("%d %d\n",1,hd);
	}
	return 0;
}