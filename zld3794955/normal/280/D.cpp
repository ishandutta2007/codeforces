#include<bits/stdc++.h>
using namespace std;
const int N=100010,K=23;
struct node
{
	int ps[2][2],pos[2][2],pl[2],pr[2],ds[2],sum,rev,l,r;
}t[N<<2]={};
bool cmp1(const int& a,const int& b) { return a<b; }
bool cmp2(const int& a,const int& b) { return a>b; }
bool (*cmp[2])(const int&,const int&) = { cmp1,cmp2 };
int n,m,a[N]={},tot=0;
void init_node(int k,int v)
{
	int side=v>=0;
	t[k].sum=v;
	t[k].ps[side][0] = t[k].ps[side][1] = v;
	t[k].pos[side][0] = t[k].pos[side][1]= t[k].l;
	t[k].ds[side] = v , t[k].pl[side] = t[k].l , t[k].pr[side] = t[k].r;
	
	t[k].ps[!side][0] = t[k].ps[!side][1] = 0;
	t[k].pos[!side][0] = t[k].l-1 , t[k].pos[!side][1] = t[k].r+1;
	t[k].ds[!side] = 0 , t[k].pl[!side] = t[k].pr[!side] = 0;
}
void update(int k,int s1,int s2)
{
	int s[2]={s1,s2};
	t[k].sum=t[s[0]].sum+t[s[1]].sum;
	for(int i=0;i<=1;++i)
	{
		for(int j=0;j<=1;++j)
		{
			int v1=t[s[j]].ps[i][j] , v2=t[s[j]].sum + t[s[!j]].ps[i][j];
			if(cmp[i](v1,v2))
				t[k].ps[i][j]=v1 , t[k].pos[i][j]=t[s[j]].pos[i][j];
			else
				t[k].ps[i][j]=v2 , t[k].pos[i][j]=t[s[!j]].pos[i][j];
		}
		t[k].ds[i]=0;
		for(int j=0;j<=1;++j)
			if(cmp[i] ( t[s[j]].ds[i] , t[k].ds[i] ) )
				t[k].ds[i]=t[s[j]].ds[i] , t[k].pl[i]=t[s[j]].pl[i] , t[k].pr[i]=t[s[j]].pr[i]; 
		int v=t[s[0]].ps[i][1] + t[s[1]].ps[i][0];
		if(cmp[i](v,t[k].ds[i]))
			t[k].ds[i]=v , t[k].pl[i]=t[s[0]].pos[i][1],t[k].pr[i]=t[s[1]].pos[i][0];
	}
}
void update(int k) { return update(k,k<<1,(k<<1)|1); }
void rev(int k)
{
	t[k].rev=!t[k].rev;
	for(int j=0;j<=1;++j)
	{
		swap(t[k].ps[0][j],t[k].ps[1][j]);
		swap(t[k].pos[0][j],t[k].pos[1][j]);
		t[k].ps[0][j]=-t[k].ps[0][j];
		t[k].ps[1][j]=-t[k].ps[1][j];
	}
	swap(t[k].ds[0],t[k].ds[1]);
	swap(t[k].pl[0],t[k].pl[1]);
	swap(t[k].pr[0],t[k].pr[1]);
	t[k].sum=-t[k].sum;
	t[k].ds[0]=-t[k].ds[0] , t[k].ds[1]=-t[k].ds[1];
}
void push(int k)
{
	if(t[k].rev)
	{
		rev(k<<1),rev((k<<1)|1);
		t[k].rev=0;
	}
}
void make_tree(int l,int r,int k)
{
	if(l!=r)
	{
		int mid=(l+r)>>1;
		make_tree(l,mid,k<<1);
		make_tree(mid+1,r,(k<<1)|1);
	}
	t[k].l=l;
	t[k].r=r;
}
void change(int pos,int v,int k)
{
	if(t[k].l==t[k].r)
		return init_node(k,v);
	push(k);
	if(t[k<<1].r>=pos)
		change(pos,v,k<<1);
	else
		change(pos,v,(k<<1)|1);
	update(k);
}
void rev(int l,int r,int k)
{
	if(t[k].l>=l && t[k].r<=r)
		return rev(k);
	push(k);
	if(t[k<<1].r>=l)
		rev(l,r,k<<1);
	if(t[(k<<1)|1].l<=r)
		rev(l,r,(k<<1)|1);
	update(k);
}
void init()
{
	scanf("%d",&n);
	make_tree(1,n,1);
	for(int i=1,v;i<=n;++i)
	{
		scanf("%d",&v);
		change(i,v,1);
	}
}
int merge(int l,int r,int k)
{
	if(t[k].l>=l && t[k].r<=r)
		return k;
	push(k);
	if(t[k<<1].r<l)
		return merge(l,r,(k<<1)|1);
	if(t[(k<<1)|1].l>r)
		return merge(l,r,k<<1);
	int tmp=--tot;
	update(tmp,merge(l,r,k<<1),merge(l,r,(k<<1)|1));
	return tmp;
}
void get_seg(int x,int y,int &l,int &r,int &s)
{
	tot=(N<<2)-1;
	int k=merge(x,y,1);
	if(t[k].ds[1]==0)
		l=0,r=0;
	else
		s+=t[k].ds[1],l=t[k].pl[1],r=t[k].pr[1];
}
void work()
{
	scanf("%d",&m);
	int type,x,y,k,l[K]={},r[K]={};
	for(int i=1;i<=m;++i)
	{
		scanf("%d",&type);
		if(type==0)
		{
			scanf("%d%d",&x,&y);
			change(x,y,1);
		}
		if(type==1)
		{
			scanf("%d%d%d",&x,&y,&k);
			int ans=0,j=1;
			for(; j<=k; ++j)
			{
				get_seg(x,y,l[j],r[j],ans);
				if(!l[j] && !r[j])
					break;
				else
					rev(l[j],r[j],1);
			}
			for(int z=j-1;z>=1;--z)
				rev(l[z],r[z],1);
			printf("%d\n",ans);
		}
	}
}
int main()
{
	init();
	work();
	return 0;
}