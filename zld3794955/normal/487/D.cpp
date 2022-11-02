#include<iostream>
#include<cstdio>
using namespace std;
const int N=100010,M=12,L=0,R=1;
struct node
{
	int l,r,s[2],x[M],y[M];
}t[N*2]={};
int n,m,q,tot=0,root=0;
char ch[N][M]={};
inline void update(int k)
{
	for(int j=1, l=t[k].s[L], r=t[k].s[R];j<=m;++j)
		if(1<=t[r].y[j] && t[r].y[j]<=m)
			t[k].x[j]=t[l].x[t[r].y[j]] , t[k].y[j]=t[l].y[t[r].y[j]];
		else
			t[k].x[j]=t[r].x[j] , t[k].y[j]=t[r].y[j];
}
inline void recalc(int i,int pos)
{
	int last=0;
	t[i].x[0]=pos , t[i].y[0]=0;
	t[i].x[m+1]=pos , t[i].y[m+1]=m+1;
	for(int j=1;j<=m;++j)
		if(ch[pos][j]!='>')
		{
			if(ch[pos][j]=='<')
			{
				for(int k=last+1;k<j;++k) //1. last+1==j  2. last+1<j
					t[i].x[k]=t[i].y[k]=-1;
				t[i].x[j]=t[i].x[j-1] , t[i].y[j]=t[i].y[j-1];
			}
			else
				for(int k=last+1;k<=j;++k)
					t[i].x[k]=pos,t[i].y[k]=j;
			last=j;
		}
	for(int j=last+1;j<=m;++j)
		t[i].x[j]=pos,t[i].y[j]=m+1;
}
int make_tree(int l,int r)
{
	int k=++tot;
	if(l!=r)
	{
		int mid=(l+r)>>1;
		t[k].s[L]=make_tree(l,mid);
		t[k].s[R]=make_tree(mid+1,r);
		update(k);
	}
	else
		recalc(k,l);
	t[k].l=l,t[k].r=r;
	return k;
}
void init()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i)
		scanf("%s\n",ch[i]+1);
	root=make_tree(1,n);
}
void change(int now,int pos)
{
	if(t[now].l==t[now].r)
		return recalc(now,pos);
	change(t[now].s[ t[t[now].s[R]].l<=pos ] , pos);
	update(now);
}
void get_ans(int k,int r,int &ax,int &ay)
{
	if(t[k].l==t[k].r)
		ax=t[k].x[ay] , ay=t[k].y[ay];
	else if(t[t[k].s[R]].l<=r)
	{
		get_ans(t[k].s[R],r,ax,ay);
		if(ay<=0 || ay>m)
			return;
		int l=t[k].s[L];
		ax=t[l].x[ay] , ay=t[l].y[ay];
	}
	else
		get_ans(t[k].s[L],r,ax,ay);
}
void work()
{
	char type,c;
	int x,y;
	for(int i=1;i<=q;++i)
	{
		scanf("%c",&type);
		if(type=='A')
		{
			scanf("%d%d\n",&x,&y);
			get_ans(root,x,x,y);
			printf("%d %d\n",x-(1<=y && y<=m),y);
		}
		else
		{
			scanf("%d%d\n%c\n",&x,&y,&c);
			if(ch[x][y]!=c)
			{
				ch[x][y]=c;
				change(root,x);
			}
		}
	}
}
int main()
{	
	init();
	work();
	return 0;
}