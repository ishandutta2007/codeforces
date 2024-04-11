#include<cstdio>
#include<map>
#include<cstring>

using namespace std;

struct p
{
	int x,y,d;
	p(int xx=0,int yy=0,int dd=0):x(xx),y(yy),d(dd){}//d: 0 down 1:right
};
bool operator<(p a,p b){if(a.x!=b.x)return a.x<b.x;if(a.y!=b.y)return a.y<b.y;return a.d<b.d;}

char s[200000];
map<p,bool> mp;

int main()
{
	int t=0;scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);int n=strlen(s+1);
		int x=0,y=0;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int dx=0,dy=0,d=0;
			switch(s[i])
			{
				case 'S':
					dx=x,dy=y;
					d=0;
					y--;
					break;
				case 'N':
					y++;
					dx=x,dy=y;
					d=0;
					break;
				case 'W':
					x--;
					dx=x,dy=y;
					d=1;
					break;
				case 'E':
					dx=x,dy=y;
					x++;
					d=1;
					break;
			}
			p tmp(dx,dy,d);
			if(mp[tmp]){ans++;}
			else {ans+=5;mp[tmp]=true;}
		}
		mp.clear();
		printf("%d\n",ans);
	}
	return 0;
}