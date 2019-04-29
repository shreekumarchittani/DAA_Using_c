#include<stdio.h>
void main()
{
  int n,c[20][20],i,a,b,u,v,j,min_cost=0,ne=1,min;
  printf("Enter number of nodes\n");
  scanf("%d",&n);
  printf("Enter cost matrix\n");
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      scanf("%d",&c[i][j]);
      if(c[i][j]==0)
       c[i][j]=999;//make all the elements infinity which have cost 0
    }
  }
  int parent[n];
  for(i=1;i<=n;i++)
   parent[i]=0;//this array is to check cyclicity
   while(ne<n)
   {
     min=999;
    for(i=1;i<=n;i++)
    {
      for(j=1;j<=n;j++)
      {
        if(c[i][j]<min)//find the edge with minimum cost
        {
          min = c[i][j];
          a=u=i;
          b=v=j;
        }
      }
    }
  while(parent[u])
   u=parent[u];
  while(parent[v])
    v=parent[v];
  if(u!=v)//if it becomes cyclic parent value will be same for 2 nodes
  {
    min_cost+=min;
    printf("\n%d -> %d = %d",a,b,min);
    parent[v]=u;
    ne++;
  }
  c[a][b]=c[b][a]=999;//already added to mst so remove it for next iteration
 }
 printf("\nMinimum cost = %d\n",min_cost);
}
