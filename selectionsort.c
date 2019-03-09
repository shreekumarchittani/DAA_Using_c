#include<stdio.h>
#include<stdlib.h>
#include<time.h>//to polot the graph
int a[10000];//we want to plot graph
double selectionSort(int a[],int n)//returning time required
{
  int i,j,min,temp;
  clock_t start = clock();
  for(i=0;i<n-1;i++)
  {
    min = i;
    for(j=i+1;j<n;j++)
    {
      if(a[j]<a[min])
        min = j;
    }
    /*now we found the location of the small element
    for the location i.Now swap that and place it
    in ith position. */
    temp = a[i];
    a[i] = a[min];
    a[min] = temp;
  }
  return((double)(clock()-start)/CLOCKS_PER_SEC);
  //time = (present clock-starting clock)/clocks per second
}
void main()
{
  int i,n;
  double t;
  printf("Enter size of array\n");
  scanf("%d",&n);
  for(i=0;i<n;i++)
   a[i] = rand()%100;//random fuction may give larger numbers
   printf("Before sorting\n");
   for(i=0;i<n;i++)
    printf("%d\t",a[i]);
  t = selectionSort(a,n);
  printf("After sorting\n");
  for(i=0;i<n;i++)
   printf("%d\t",a[i]);
  printf("Time:%fs\n",t);
}
