#include <cstdio>
#include <cstdlib>
#include <vector>
#define INF 2000000000

using namespace std;

class mimax
{
public:
    int mi,ma;
    mimax(int i,int a)
    {
        mi=i;
        ma=a;
    }
};
vector <mimax*> vec;

int main()
{
    int n,min=INF,max=0;
    
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        int l,r;
        scanf("%d %d",&l,&r);
        
        mimax* m=new mimax(l,r);
        vec.push_back(m);
        
        if(max<r) max=r;
        if(min>l) min=l;
    }
    
    int i;
    for(i=0;i<vec.size();i++)
    {
        mimax* m=vec[i];
        if(m->mi==min&&m->ma==max)
        {
            printf("%d\n",i+1);
            break;
        }
    }
    if(i==vec.size()) printf("%d\n",-1);
    return 0;
}