#include<cstdio>

using namespace std;

int group[20000],pos[2],qu[2],ans[20000];

int query(int x,int y,int z){printf("? %d %d %d\n",x,y,z);fflush(stdout);int ret=0;scanf("%d",&ret);return ret;}

void work(int b,int oppo,int val)
{
	int x=query(b*3-2,b*3-1,oppo);
	if(x==val){ans[b*3-2]=ans[b*3-1]=val;ans[b*3]=query(b*3,b*3-2,oppo);}
	else{ans[b*3]=val;ans[b*3-2]=query(b*3,b*3-2,oppo);ans[b*3-1]=ans[b*3-2]^1;}
}
int main()
{
	int TT=0;scanf("%d",&TT);
	while(TT--)
	{
		int n=0;scanf("%d",&n);pos[0]=pos[1]=0;
		
		for(int i=1;i<=n/3;i++){group[i]=query(3*i-2,3*i-1,3*i);if(!pos[group[i]])pos[group[i]]=i;}
		//printf("%d %d\n",pos[0],pos[1]);
		int x=query(3*pos[0]-2,3*pos[0]-1,3*pos[1]-2),
			y=query(3*pos[0]-2,3*pos[0]-1,3*pos[1]-1);
		if(x==0&&y==0)
		{
			ans[3*pos[0]-2]=ans[3*pos[0]-1]=0;work(pos[1],3*pos[0]-2,1);
			int p=ans[3*pos[1]-2]?3*pos[1]-2:3*pos[1]-1;
			ans[3*pos[0]]=query(3*pos[0],p,3*pos[0]-2);
		}
		else
		{
			ans[3*pos[0]]=0,ans[3*pos[1]-2]=x,ans[3*pos[1]-1]=y;
			int p=x?3*pos[1]-2:3*pos[1]-1;
			ans[3*pos[0]-2]=query(3*pos[0]-2,3*pos[0],p),
			ans[3*pos[1]]=query(3*pos[1],3*pos[0],p),
			ans[3*pos[0]-1]=ans[3*pos[0]-2]^1;
		}
		qu[0]=ans[3*pos[0]-2]==0?3*pos[0]-2:3*pos[0]-1,
		qu[1]=ans[3*pos[1]-2]==1?3*pos[1]-2:3*pos[1]-1;
		
		for(int i=1;i<=n/3;i++)if(i!=pos[0]&&i!=pos[1])work(i,qu[group[i]^1],group[i]);
		int k=0;for(int i=1;i<=n;i++)if(!ans[i])k++;
		printf("! %d ",k);for(int i=1;i<=n;i++)if(!ans[i])printf("%d ",i);puts("");fflush(stdout);
	}
}