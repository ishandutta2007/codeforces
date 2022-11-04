#include <stdio.h>
#include <stdlib.h>

int n,i,m,l,r,mid,ans2,c[500005],s[500005],size[500005],d[500005],tag[500005],pd[500005];
int e[500005],succ[500005],last[500005],sum;
int hash_tag,hash[500005];
long long ans;

void sort(int l,int r,int a[],int b[]);
void sort(int l,int r,int a[],int b[],int c[]);
void sort2(int l,int r,int a[],int b[],int c[]);
int dfs(int i);

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d %d",&c[i],&s[i]),tag[i]=i;
	scanf("%d",&m);
	for(i=1;i<=m;i++)
		scanf("%d %d",&d[i],&size[i]);
	sort(1,n,s,c,tag);
	for(i=1;i<=m;i++)
	{
		l=1,r=n;
		while (l<r)
		{
			mid=(l+r+1)>>1;
			if (s[mid]<=size[i]) l=mid;
			else r=mid-1;
		}
		if ((size[i]==s[l] || size[i]==s[l]-1) && d[i]>=c[l])
			e[++sum]=n+i,succ[sum]=last[tag[l]],last[tag[l]]=sum;
		l++;
		if (l<=n && (size[i]==s[l] || size[i]==s[l]-1) && d[i]>=c[l])
			e[++sum]=n+i,succ[sum]=last[tag[l]],last[tag[l]]=sum;
		l++;
		if (l<=n && (size[i]==s[l] || size[i]==s[l]-1) && d[i]>=c[l])
			e[++sum]=n+i,succ[sum]=last[tag[l]],last[tag[l]]=sum;
	}
	sort2(1,n,c,s,tag);
	for(i=1;i<=n;i++)
	{
		hash_tag++;
		if (dfs(tag[i])==1) ans+=c[i],ans2++;
	}
	printf("%I64d\n",ans);
	printf("%d\n",ans2);
	for(i=1;i<=m;i++)
		if (pd[n+i]!=0) printf("%d %d\n",i,pd[n+i]);
	return 0;
}

void sort(int l,int r,int a[],int b[])
{
	int i=l,j=r,k,mid;
	mid=a[l+rand()%(r-l+1)];
	while (i<=j)
	{
		while (i<=j && a[i]<mid) i++;
		while (i<=j && a[j]>mid) j--;
		if (i<=j)
		{
			k=a[i],a[i]=a[j],a[j]=k;
			k=b[i],b[i]=b[j],b[j]=k;
			i++,j--;
		}
	}
	if (l<j) sort(l,j,a,b);
	if (i<r) sort(i,r,a,b);
	return;
}

void sort(int l,int r,int a[],int b[],int c[])
{
	int i=l,j=r,k,mid;
	mid=a[l+rand()%(r-l+1)];
	while (i<=j)
	{
		while (i<=j && a[i]<mid) i++;
		while (i<=j && a[j]>mid) j--;
		if (i<=j)
		{
			k=a[i],a[i]=a[j],a[j]=k;
			k=b[i],b[i]=b[j],b[j]=k;
			k=c[i],c[i]=c[j],c[j]=k;
			i++,j--;
		}
	}
	if (l<j) sort(l,j,a,b,c);
	if (i<r) sort(i,r,a,b,c);
	return;
}

void sort2(int l,int r,int a[],int b[],int c[])
{
	int i=l,j=r,k,mid;
	mid=a[l+rand()%(r-l+1)];
	while (i<=j)
	{
		while (i<=j && a[i]>mid) i++;
		while (i<=j && a[j]<mid) j--;
		if (i<=j)
		{
			k=a[i],a[i]=a[j],a[j]=k;
			k=b[i],b[i]=b[j],b[j]=k;
			k=c[i],c[i]=c[j],c[j]=k;
			i++,j--;
		}
	}
	if (l<j) sort2(l,j,a,b,c);
	if (i<r) sort2(i,r,a,b,c);
	return;
}

int dfs(int i)
{
	int x,y;
	for(x=last[i];x!=0;x=succ[x])
	{
		if (pd[e[x]]==0) 
		{
			pd[e[x]]=i;
			return 1;
		}
	}
	for(x=last[i];x!=0;x=succ[x])
	{
		if (hash[e[x]]==hash_tag) continue;
		hash[e[x]]=hash_tag;
		y=pd[e[x]],pd[e[x]]=i;
		if (y==0 || dfs(y)==1) return 1;
		pd[e[x]]=y;
	}
	return 0;
}