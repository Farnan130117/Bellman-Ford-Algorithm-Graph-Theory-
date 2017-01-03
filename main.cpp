#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define MAXE 10000
#define MAXN 100
int main()
{

    int node,edge;
    int d[MAXN],edge_u[MAXE],edge_v[MAXE],edge_cost[MAXE];
    cin>>node>>edge;

    for(int i=1;i<=node;i++)
        d[i]=1000000000;

    d[1]=0; //distance to source is 0

    for(int i=1;i<=edge;i++)
    {
       cin>>edge_u[i]>>edge_v[i]>>edge_cost[i];
    }

    int neg_cycle=false;

    for(int step=1;step<=node;step++)
    {
      int updated=false;
      for(int i=1;i<=edge;i++)
      {
        int u=edge_u[i],v=edge_v[i];
            if(d[u]+edge_cost[i]<d[v])
            {
              updated=true;
              if(step==node)
                neg_cycle=true; //If we can update in n'th step, there is a negative cycle

              d[v]=d[u]+edge_cost[i];
            }
       }
     if(updated==false)
        break; //If we can't update in a any step, no need to try anymore
    }
     if(neg_cycle==false)
     {
      for(int i=1;i<=node;i++)
        cout<<d[i]<<endl;
     }
    else puts("Negative cycle detected");
return 0;
}
