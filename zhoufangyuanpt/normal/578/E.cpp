#include<cstdio>
#include<cstring>
using namespace std;
char S[110000];
struct node
{
	int p,last,next;
}L[110000],R[110000];int Len,Ren;
int Order[110000],Ordered[110000];
struct trnode
{
	int l,r,lc,rc,c;
}tr[210000];int trlen;
void bt(int l,int r)
{
	int now=++trlen;
	tr[now].l=l;tr[now].r=r;tr[now].lc=tr[now].rc=-1;tr[now].c=-1;
	if(l<r)
	{
		int mid=(l+r)/2;
		tr[now].lc=trlen+1;bt(l,mid);
		tr[now].rc=trlen+1;bt(mid+1,r);
	}
}
void change(int now,int l,int r,int c)
{
	if(tr[now].l==l&&tr[now].r==r){tr[now].c=c;return ;}
	int lc=tr[now].lc,rc=tr[now].rc;
	int mid=(tr[now].l+tr[now].r)/2;
	if(tr[now].c!=-1)
	{
		tr[lc].c=tr[now].c;
		tr[rc].c=tr[now].c;
	}
	if(r<=mid)change(lc,l,r,c);
	else if(l>=mid+1)change(rc,l,r,c);
	else change(lc,l,mid,c),change(rc,mid+1,r,c);
	tr[now].c=tr[lc].c==tr[rc].c?tr[lc].c:-1;
}
int findc(int now,int x)
{
	if(tr[now].c!=-1)return tr[now].c;
	int lc=tr[now].lc,rc=tr[now].rc;
	int mid=(tr[now].l+tr[now].r)/2;
	if(tr[now].c!=-1)
	{
		tr[lc].c=tr[now].c;
		tr[rc].c=tr[now].c;
	}
	if(x<=mid)return findc(lc,x);
	else return findc(rc,x);
}
int G[110000],Gen;
int main()
{
	scanf("%s",S+1);
	int n=strlen(S+1);
	int LeftPrint=0,RightPrint=0;
	for(int i=1;i<=n;i++)S[i]=='L'?LeftPrint++:RightPrint++;
	trlen=0;bt(1,n);
	int BackStep=n;
	if(n<=LeftPrint*2)
	{
		Len=Ren=1;
		L[1].last=L[1].next=1;L[1].p=0;
		R[1].last=R[1].next=1;R[1].p=0;
		for(int i=1;i<=n;i++)
		{
			if(S[i]=='L')
			{
				int last=Len++,next=L[last].next;
				L[Len].last=last;L[Len].next=next;
				L[last].next=Len;L[next].last=Len;
				L[Len].p=i;
				if(L[last].p+1<i)change(1,L[last].p+1,i-1,Len);
			}
			else
			{
				int last=Ren++,next=R[last].next;
				R[Ren].last=last;R[Ren].next=next;
				R[last].next=Ren;R[next].last=Ren;
				R[Ren].p=i;
				if(R[last].p+1<i)change(1,R[last].p+1,i-1,Ren);
			}
		}
		if(L[Len].p<n)change(1,L[Len].p+1,n,1);
		if(R[Ren].p<n)change(1,R[Ren].p+1,n,1);
		int Step=1,Print=L[1].next,Back=0;node *F=L;
		while(Print!=1)
		{
			Order[Step]=F[Print].p;
			if(F[F[Print].last].p+1<F[Print].p)change(1,F[F[Print].last].p+1,F[Print].p-1,F[Print].next);
			F[F[Print].last].next=F[Print].next;
			F[F[Print].next].last=F[Print].last;
			Print=findc(1,F[Print].p);
			F=F==L?R:L;
			if(Print==1)Back++,Print=F[Print].next;
			else if(findc(1,F[Print].p)==1&&F[F[1].next].p<(F==L?R:L)[(F==L?R:L)[1].next].p)Back++,Print=F[1].next;
			Step++;
		}
		Back--;
		if(Back<BackStep)
		{
			BackStep=Back;
			for(int i=1;i<=n;i++)Ordered[i]=Order[i];
		}
	}
	if(n<=RightPrint*2)
	{
		Len=Ren=1;
		L[1].last=L[1].next=1;L[1].p=0;
		R[1].last=R[1].next=1;R[1].p=0;
		for(int i=1;i<=n;i++)
		{
			if(S[i]=='L')
			{
				int last=Len++,next=L[last].next;
				L[Len].last=last;L[Len].next=next;
				L[last].next=Len;L[next].last=Len;
				L[Len].p=i;
				if(L[last].p+1<i)change(1,L[last].p+1,i-1,Len);
			}
			else
			{
				int last=Ren++,next=R[last].next;
				R[Ren].last=last;R[Ren].next=next;
				R[last].next=Ren;R[next].last=Ren;
				R[Ren].p=i;
				if(R[last].p+1<i)change(1,R[last].p+1,i-1,Ren);
			}
		}
		if(L[Len].p<n)change(1,L[Len].p+1,n,1);
		if(R[Ren].p<n)change(1,R[Ren].p+1,n,1);
		int Step=1,Print=R[1].next,Back=0;node *F=R;
		while(Print!=1)
		{
			Order[Step]=F[Print].p;
			if(F[F[Print].last].p+1<F[Print].p)change(1,F[F[Print].last].p+1,F[Print].p-1,F[Print].next);
			F[F[Print].last].next=F[Print].next;
			F[F[Print].next].last=F[Print].last;
			Print=findc(1,F[Print].p);
			F=F==L?R:L;
			if(Print==1)Back++,Print=F[Print].next;
			else if(findc(1,F[Print].p)==1&&F[F[1].next].p<(F==L?R:L)[(F==L?R:L)[1].next].p)Back++,Print=F[1].next;
			Step++;
		}
		Back--;
		if(Back<BackStep)
		{
			BackStep=Back;
			for(int i=1;i<=n;i++)Ordered[i]=Order[i];
		}
	}
	printf("%d\n",BackStep);
	for(int i=1;i<n;i++)printf("%d ",Ordered[i]);
	printf("%d\n",Ordered[n]);
	return 0;
}