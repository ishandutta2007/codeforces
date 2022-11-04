//by hyy
//on 2011.12.4

#include <stdio.h>
#include <stdlib.h>
#define ll long long

int ans,max[500005];
int n,m,i,fa,fb,a[300005],b[300005],c[300005],Tag[300005],f[100005],ok[300005];
int e[200005],succ[200005],last[200005],val[200005],sum;
int size[100005],zl[200005],father[200005],h,t,x;
int next[100005],key[300005],k2[300005],ceng[300005],head[300005],tag[300005],tot;
int left[500005],right[500005],min_tag[500005],min[500005],Last_ans[100005];
int s,Ans,now;

void sort(int l,int r);
void dfs(int i,int s,int f);
void make(int l,int r,int i);
void ask(int l,int r,int i);
void qmax(int aa,int bb);
void cover(int aa,int bb,int cc);
void Cover(int l,int r,int i,int c);
void down(int i);
void ask_min(int l,int r,int i);
int find(int i);

int main()
{
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
       scanf("%d %d %d",&a[i],&b[i],&c[i]),Tag[i]=i;
    sort(1,m);
    for(i=1;i<=n;i++) f[i]=i,size[i]=1;
    for(i=1;i<=m;i++)
    {
       fa=find(a[i]);
       fb=find(b[i]);
       if (fa==fb) continue;
       ok[i]=1;
       f[fa]=fb;
       e[++sum]=b[i],succ[sum]=last[a[i]],last[a[i]]=sum,val[sum]=c[i];
       e[++sum]=a[i],succ[sum]=last[b[i]],last[b[i]]=sum,val[sum]=c[i];
       if (sum==((n-1)<<1)) continue;
    }
    zl[1]=1,father[1]=0;
    for(h=t=1;h<=t;h++)
    {
       now=zl[h];
       for(x=last[now];x!=0;x=succ[x])
       {
          if (father[now]==e[x]) continue;
          father[e[x]]=now,key[e[x]]=val[x],zl[++t]=e[x];
       }
    }
    for(i=t;i>=2;i--)
    {
       fa=father[zl[i]];
       size[fa]+=size[zl[i]];
       if (next[fa]==0 || size[zl[i]]>size[next[fa]])
          next[fa]=zl[i];
    }
    dfs(1,0,0);
    make(1,n,1);
    Ans=-1;
    for(i=1;i<=m;i++)
    {
       if (ok[i]==1) continue;
       qmax(a[i],b[i]);
       cover(a[i],b[i],c[i]);
       if (ans==c[i]) Last_ans[Tag[i]]=1;
       else Last_ans[Tag[i]]=2;
    }
    for(i=1;i<=m;i++)
    {
       if (ok[i]==0) continue;
       ans=1616161616;
       if (father[a[i]]==b[i]) ask_min(tag[a[i]],tag[a[i]],1);
       else ask_min(tag[b[i]],tag[b[i]],1);
       if (ans==c[i]) Last_ans[Tag[i]]=1;
       else Last_ans[Tag[i]]=3;
    }
    for(i=1;i<=m;i++)
    {
       if (Last_ans[i]==1) printf("at least one\n");
       else if (Last_ans[i]==2) printf("none\n");
       else printf("any\n");
    }
    return 0;
}

void sort(int l,int r)
{
     int i=l,j=r,k,mid;
     mid=c[l+rand()%(r-l+1)];
     while (i<=j)
     {
           while (i<=j && c[i]<mid) i++;
           while (i<=j && c[j]>mid) j--;
           if (i<=j)
           {
              k=a[i],a[i]=a[j],a[j]=k;
              k=b[i],b[i]=b[j],b[j]=k;
              k=c[i],c[i]=c[j],c[j]=k;
              k=Tag[i],Tag[i]=Tag[j],Tag[j]=k;
              i++,j--;
           }
     }
     if (l<j) sort(l,j);
     if (i<r) sort(i,r);
     return;
}

void dfs(int i,int s,int f)
{
     int x;
     x=i;
     ceng[i]=s;
     if (next[f]!=i)
     {
        while (x!=0)
        {
             head[x]=i;
             tag[x]=++tot;
             k2[tot]=key[x];
             x=next[x];
        }
     }
     for(x=last[i];x!=0;x=succ[x])
     {
        if (e[x]==f) continue;
        if (e[x]==next[i])
           dfs(e[x],s,i);
        else dfs(e[x],s+1,i);
     }
     return;
}

void make(int l,int r,int i)
{
     int mid=((l+r)>>1),lc,rc;
     left[i]=l,right[i]=r;
     min[i]=1616161616;
     min_tag[i]=1616161616;
     if (l==r)
     {
        max[i]=k2[l];
        return;
     }
     lc=(i<<1),rc=(lc|1);
     make(l,mid,lc),make(mid+1,r,rc);
     max[i]=max[lc];
     if (max[rc]>max[lc]) max[i]=max[rc];
     return;
}

void ask(int l,int r,int i)
{
     if (l>r) return;
     if (l>right[i] || r<left[i]) return;
     if (l<=left[i] && r>=right[i])
     {
        if (max[i]>ans) ans=max[i];
        return;
     }
     ask(l,r,(i<<1));
     ask(l,r,((i<<1)|1));
     return;
}

void qmax(int aa,int bb)
{
     int a=aa,b=bb;
     ans=-1;
     while (ceng[a]>ceng[b])
     {
           ask(tag[head[a]],tag[a],1);
           a=father[head[a]];
     }
     while (ceng[b]>ceng[a])
     {
           ask(tag[head[b]],tag[b],1);
           b=father[head[b]];
     }
     while (head[a]!=head[b])
     {
           ask(tag[head[a]],tag[a],1);
           a=father[head[a]];
           ask(tag[head[b]],tag[b],1);
           b=father[head[b]];
     }
     if (tag[a]>tag[b]) ask(tag[b]+1,tag[a],1);
     else ask(tag[a]+1,tag[b],1);
     return;
}

void cover(int aa,int bb,int cc)
{
     int a=aa,b=bb;
     while (ceng[a]>ceng[b])
     {
           Cover(tag[head[a]],tag[a],1,cc);
           a=father[head[a]];
     }
     while (ceng[b]>ceng[a])
     {
           Cover(tag[head[b]],tag[b],1,cc);
           b=father[head[b]];
     }
     while (head[a]!=head[b])
     {
           Cover(tag[head[a]],tag[a],1,cc);
           a=father[head[a]];
           Cover(tag[head[b]],tag[b],1,cc);
           b=father[head[b]];
     }
     if (tag[a]>tag[b]) Cover(tag[b]+1,tag[a],1,cc);
     else Cover(tag[a]+1,tag[b],1,cc);
     return;
}

void down(int i)
{
     int lc,rc;
     lc=(i<<1);
     rc=(lc|1);
     if (min_tag[i]<min[lc])
     {
        min[lc]=min_tag[i];
        min_tag[lc]=min_tag[i];
     }
     if (min_tag[i]<min[rc])
     {
        min[rc]=min[i];
        min_tag[rc]=min_tag[i];
     }
     min_tag[i]=1616161616;
     return;
}

void Cover(int l,int r,int i,int c)
{
     if (l>r) return;
     if (l>right[i] || r<left[i]) return;
     if (l<=left[i] && r>=right[i])
     {
        if (c<min[i]) min[i]=c,min_tag[i]=c;
        return;
     }
     down(i);
     Cover(l,r,(i<<1),c);
     Cover(l,r,((i<<1)|1),c);
     return;
}

void ask_min(int l,int r,int i)
{
     if (l>r) return;
     if (l>right[i] || r<left[i]) return;
     if (l<=left[i] && r>=right[i])
     {
        ans=min[i];
        return;
     }
     down(i);
     ask_min(l,r,(i<<1));
     ask_min(l,r,((i<<1)|1));
     return;
}

int find(int i)
{
    if (f[i]==i) return i;
    f[i]=find(f[i]);
    return f[i];
}