#include<stdio.h>
int n,m;
int Last[100002],Next[200002],End[200002],tot=0;
bool mk[100002];int ans;
void dfs(int p){mk[p]=0;
    for(int i=Last[p];i;i=Next[i])if(mk[End[i]])dfs(End[i]);
}
int main(){
    scanf("%d%d",&n,&m);ans=m;
    for(int i=1;i<=m;i++){
        int p,q;scanf("%d%d",&p,&q);mk[p]=mk[q]=1;
        End[++tot]=q;Next[tot]=Last[p];Last[p]=tot;
        End[++tot]=p;Next[tot]=Last[q];Last[q]=tot;
    }for(int i=1;i<=n;i++)ans-=mk[i];
    for(int i=1;i<=n;i++)if(mk[i]){
        ans++;dfs(i);
    }printf("%d",ans);
}