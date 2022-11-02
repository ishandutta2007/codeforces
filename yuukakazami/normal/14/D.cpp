#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(i,n) for(int i=0;i<n;i++)
#define OK cout<<"-----------------"<<endl;
using namespace std;
const int MaxVet=300000+100;
typedef long long LL;

struct TGraph
{
    static const int MaxEdge=MaxVet*2;
    int head[MaxVet],Vet;
    int next[MaxEdge],dest[MaxEdge],Mnt;

    void Clear(int _Vet)
    {
        Vet=_Vet;memset(head,-1,sizeof(int)*Vet);
        Mnt=0;
    }

    void AddEdge(int s,int t)
    {
        next[Mnt]=head[s];dest[Mnt]=t;
        head[s]=Mnt++;
    }

    void InsEdge(int s,int t)
    {
        AddEdge(s,t);
        AddEdge(t,s);
    }
};
#define tr(e,G,u) for(int e=G.head[u];e!=-1;e=G.next[e])

TGraph Tree;

inline void Scan_Int(int&t)
{
    char c;while(c=getchar(),c<'0'||c>'9');t=c-'0';
    while(c=getchar(),c>='0'&&c<='9')t=t*10+c-'0';
}

void Input_Data()
{
    int Vet,s,t;
    Scan_Int(Vet);Tree.Clear(Vet);

    rep(i,Vet-1)
    {
        Scan_Int(s);Scan_Int(t);
        --s;--t;
        Tree.InsEdge(s,t);
    }
}

int Ord[MaxVet],Father[MaxVet];
int Vis[MaxVet]={},Flag=0;

int BFS(int*Q,int vs,int cut=-1)//return the last point
{
    ++Flag;

    int h=0,t=0;
    Q[t++]=vs;Vis[vs]=Flag;Father[vs]=-1;
    if(cut>=0)
        Vis[cut]=Flag;

    for(;h<t;h++)
    {
        int u=Q[h];
        tr(e,Tree,u)
        {
            int v=Tree.dest[e];
            if(Vis[v]==Flag)continue;
            Vis[v]=Flag;
            Q[t++]=v;
            Father[v]=u;
        }
    }

    return Q[t-1];
}

struct DistSet
{
    static const int MaxSaved=3;
    int A[MaxSaved+1];

    void Clear()
    {
        rep(i,MaxSaved)
            A[i]=0;
    }

    void Add_Item(int x)
    {
        A[MaxSaved]=x;
        for(int i=MaxSaved;i>=1;i--)
        {
            if(A[i]>A[i-1])
                swap(A[i],A[i-1]);
            else
                break;
        }
    }

    int Get_Result_Two(int dist=-1)
    {
        bool find=false;
        int got=0;
        int ret=0;

        for(int i=0;i<MaxSaved&&got<2;i++)
        {
            if(!find&&A[i]==dist)
                find=true;
            else
                got++,ret+=A[i];
        }

        return ret;
    }

    int Get_Result_One(int dist)
    {
        if(A[0]==dist)return A[1];
        return A[0];
    }

    int Get_Max()
    {
        return A[0];
    }
};

DistSet Sets[MaxVet];

int LongestPathDown[MaxVet];
int LongestPathUp[MaxVet];
int MaxDistUp[MaxVet];

void Calc_DistSet()
{
    for(int it=Tree.Vet-1;it>=0;it--)
    {
        int u=Ord[it];
        DistSet&Set=Sets[u];
        Set.Clear();

        tr(e,Tree,u)
        {
            int v=Tree.dest[e];
            if(v==Father[u])continue;
            Set.Add_Item(Sets[v].Get_Max()+1);
        }
    }
}

inline void UpdateMax(int&x,int c)
{
    if(x<c)x=c;
}

int FindPoint(int u,int fa)
{
    static int Path[MaxVet],Cnt;

    int v=BFS(Ord,u,fa);
    int w=BFS(Ord,v,fa);
    Cnt=0;
    do
    {
        Path[Cnt++]=w;
        w=Father[w];
    }while(w!=-1);

    //cout<<"Max Len is:"<<Cnt-1<<endl;

    return Path[Cnt/2];
}

DistSet RetSets[MaxVet];
void Dp()
{
    //Calc the Down
    for(int it=Tree.Vet-1;it>=0;it--)
    {
        int u=Ord[it];
        LongestPathDown[u]=Sets[u].Get_Result_Two();

        RetSets[u].Clear();
        tr(e,Tree,u)
        {
            int v=Tree.dest[e];
            if(v==Father[u])continue;

            RetSets[u].Add_Item(LongestPathDown[v]);
            UpdateMax(LongestPathDown[u],LongestPathDown[v]);
        }
    }

    //Calc The Up
    for(int it=0;it<Tree.Vet;it++)
    {
        int u=Ord[it];
        int fa=Father[u];

        if(fa!=-1)
        {
            LongestPathUp[u]=LongestPathUp[fa];

            MaxDistUp[u]=MaxDistUp[fa]+1;
            UpdateMax(MaxDistUp[u],Sets[fa].Get_Result_One(Sets[u].Get_Max()+1)+1);

            UpdateMax(LongestPathUp[u],MaxDistUp[fa]+Sets[fa].Get_Result_One(Sets[u].Get_Max()+1));
            UpdateMax(LongestPathUp[u],Sets[fa].Get_Result_Two(Sets[u].Get_Max()+1));
            UpdateMax(LongestPathUp[u],RetSets[fa].Get_Result_One(LongestPathDown[u]));
        }
        else
        {
            LongestPathUp[u]=0;
            MaxDistUp[u]=0;
        }
    }

    //Calc Ans
    LL Ans=0;
    rep(u,Tree.Vet)
    {
        //cout<<u+1<<":"<<LongestPathUp[u]<<endl;
        int fa=Father[u];
        if(fa==-1)continue;

        int UpMax=LongestPathUp[u];
        int DownMax=LongestPathDown[u];

        LL ret=UpMax*DownMax;
        if(ret>Ans)
            Ans=ret;
    }

    cout<<Ans<<endl;
}

void Work()
{
    BFS(Ord,0);
    Calc_DistSet();
    Dp();
}

void Solve()
{
    Input_Data();
    Work();
}

int main()
{
    //freopen("in","r",stdin);
    Solve();
}