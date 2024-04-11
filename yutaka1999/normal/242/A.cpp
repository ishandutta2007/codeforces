#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

class card
{
public:
    int vas,pet;
    card(int v,int p)
    {
        vas=v;
        pet=p;
    }
};

vector <card*> vec;

int main()
{
    int x,y,a,b;
    scanf("%d %d %d %d",&x,&y,&a,&b);
    
    for(int i=a;i<=x;i++)
    {
        for(int j=b;j<=y;j++)
        {
            if(i>j)
            {
                card* c=new card(i,j);
                vec.push_back(c);
            }
        }
    }
    printf("%d\n",vec.size());
    
    for(int i=0;i<vec.size();i++)
    {
        card* c=vec[i];
        printf("%d %d\n",c->vas,c->pet);
    }
    return 0;
}