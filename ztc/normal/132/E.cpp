#include<stdio.h>
int Last[5000004],Next[5000002],End[5000002],Len[5000002],Val[5000002],tot=1,dis[5000004],pre[5000004],mk[5000004],a[500004],p[500004],tp,n,m,T;
void add(int s,int t,int l,int v){
	End[++tot]=t;Next[tot]=Last[s];Last[s]=tot;Len[tot]=l;Val[tot]=v;
	End[++tot]=s;Next[tot]=Last[t];Last[t]=tot;Len[tot]=0;Val[tot]=-v;
}
bool spfa(){
	for(int i=1;i<=T;i++)dis[i]=-0xdeafdeaf,pre[i]=mk[i]=0;dis[1]=0;static int q[500002];int f=0,b=0;q[b++]=1;
	while(f!=b){int p=q[f++];mk[p]=0;for(int i=Last[p],v;i;i=Next[i])if(Len[i]&&dis[End[i]]>(v=dis[p]+Val[i]))dis[End[i]]=v,pre[End[i]]=i^1,!mk[End[i]]&&(mk[q[b++]=End[i]]=1);}
	return dis[T]!=-0xdeafdeaf;
}
int main(){
	scanf("%d%d",&n,&m);add(1,2,m,0);T=n+n+3;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		add(1,i+2,1,0);add(2,i+n+2,1,__builtin_popcount(a[i]));add(i+n+2,T,1,0);
		for(int j=1;j<i;j++)add(j+2,i+n+2,1,a[i]==a[j]?0:__builtin_popcount(a[i]));
	}int ans=0,cnt=0;
	while(spfa()){
		ans+=dis[T];
		for(int i=pre[T];i;i=pre[End[i]])Len[i]++,Len[i^1]--;
	}for(int i=2;i<=tot;i+=2){if(Len[i^1]&&End[i^1]!=1&&End[i]!=T&&(End[i^1]==2||a[End[i]-n-2]!=a[End[i^1]-2]))cnt++;if(End[i]==2)tp=Len[i^1];}
	printf("%d %d\n",cnt+n,ans);
	for(int i=2;i<=tot;i+=2)if(Len[i^1]&&End[i^1]!=1&&End[i]!=T){
		if(End[i^1]==2)p[End[i]-n-2]=--tp;
		else p[End[i]-n-2]=p[End[i^1]-2];
		if(End[i^1]==2||a[End[i]-n-2]!=a[End[i^1]-2])printf("%c=%d\n",p[End[i]-n-2]+'a',a[End[i]-n-2]);
		printf("print(%c)\n",p[End[i]-n-2]+'a');
	}
}