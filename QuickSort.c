#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a[10000];
void quickSort(int a[],int low,int high)
{
  if(low<=high)
  {
    int pos;
    pos = partition(a,low,high);
    quickSort(a,low,pos-1);
    quickSort(a,pos+1,high);
  }
}
int partition(int a[],int low,int high)
{
  int key,i,j,temp;
  key = a[low];
  i = low+1;
  j = high;
  while(i<=j)
  {
    while(a[i]<=key)
     i++;
    while(a[j]>key)
      j--;
      if(i<j)
      {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
  }
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
  return j;
}
void main()
{
  int i,n;
  double t;
  printf("Enter size of array\n");
  scanf("%d",&n);
  for(i=0;i<n;i++)
   a[i] = rand();
   printf("Before sorting\n");
   for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    clock_t start = clock();
  quickSort(a,0,n-1);
  t =((double)(clock()-start)/CLOCKS_PER_SEC);
  printf("After sorting\n");
  for(i=0;i<n;i++)
   printf("%d\t",a[i]);
  printf("Time:%fs\n",t);
}
