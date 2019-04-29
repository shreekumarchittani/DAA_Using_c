#include<stdio.h>
int a[10][10],visited[50],n;
void dfs(int i)
{
  int j;
  printf("\n%d",i);
  visited[i]=1;
  for(j=0;j<n;j++)
  {
    if(!visited[j]&&a[i][j]==1)
     dfs(j);
  }
}
void main()
{
  int i,j;
  printf("Enter number of nodes\n");
  scanf("%d",&n);
  printf("Enter adjecancy matrix\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      scanf("%d",&a[i][j]);
    }
  }
  dfs(0);
}
