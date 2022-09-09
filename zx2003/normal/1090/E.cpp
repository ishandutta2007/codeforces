#include<cstdio>
#include<cstring>

int ans[100001][4],an,n,lax[10][10],lay[10][10],qx[100001],l,r,qy[100001],x,y,X,Y,dx[8],dy[8];
bool bo[10][10],boo[10][10],B[10][10],BB[10][10];
char s[10];

void pri()
{
	printf("%d\n",an);
	for (int i=1; i<=an; i++) 
		putchar(ans[i][0]-1+'a'),putchar(ans[i][1]+'0'),putchar('-'),putchar(ans[i][2]-1+'a'),putchar(ans[i][3]+'0'),putchar('\n');
}

void ins(int x,int y,int X,int Y) {ans[++an][0]=x,ans[an][1]=y,ans[an][2]=X,ans[an][3]=Y;}

void add(int x,int y,int X,int Y)
{
	bo[x][y]=0;
	while (x!=X||y!=Y) 
	{
		int t=lay[x][y];
		if (B[lax[x][y]][t]) 
		{
			add(lax[x][y],t,X,Y);
			ins(x,y,lax[x][y],t);
			return;
		}
		ins(x,y,lax[x][y],t),x=lax[x][y],y=t;
	}
}

int main()
{
	dx[0]=-2; dy[0]=-1;
	dx[1]=-2; dy[1]=1;
	dx[2]=-1; dy[2]=-2;
	dx[3]=-1; dy[3]=2;
	dx[4]=1; dy[4]=-2;
	dx[5]=1; dy[5]=2;
	dx[6]=2; dy[6]=-1;
	dx[7]=2; dy[7]=1;
	scanf("%d",&n); an=0;
	memset(bo,0,sizeof(bo));
	memset(B,0,sizeof(B));
	memset(BB,0,sizeof(BB));
	for (int i=1; i<=n; i++)
	{
		scanf("%s",s);
		bo[s[0]-'a'+1][s[1]-'0']=1;
	}
	for (int i=1; i<=8; i++)
		for (int j=1; j<=8; j++)
		{
			if ((i-1)*8+(j-1)>=n) break;
			BB[j][i]=1;
		}
	for (int s=2; s<=16; s++)
		for (int i=1; i<=8; i++)
		{
			int j=s-i;
			if (j<1||j>8||!BB[j][i]) continue;
			l=r=1; qx[1]=j; qy[1]=i;
			memset(lax,0,sizeof(lax));
			memset(lay,0,sizeof(lay));
			memset(boo,0,sizeof(boo));
			boo[j][i]=1;
			while (l<=r)
			{
				if (bo[qx[l]][qy[l]]) {add(qx[l],qy[l],j,i); break;}
				x=qx[l]; y=qy[l];
				for (int k=0; k<8; k++)
				{
					X=x+dx[k]; Y=y+dy[k];
					if (X<1||X>8||Y<1||Y>8||boo[X][Y]) continue;
					qx[++r]=X; qy[r]=Y; boo[X][Y]=1;
					lax[X][Y]=x; lay[X][Y]=y;
				}
				l++;
			}
			B[j][i]=1;
		}
	pri();
	return 0;
}