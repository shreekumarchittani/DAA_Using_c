/* Heap sort is a technique in which given array is imagined as a complete
binary tree.
If index is i then
the left child = 2i
the right child = 2i+1
Here the given code illustrates Max heaping technique in which the root node
will have largest element after heapifying the array.*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void adjust(int a[],int i,int n)
{
  int j,item,temp;
  j = 2*i;
  item = a[i];
  while(j<=n)
  {
    if(j<n && a[j]<a[j+1])//Finding greatest element in child node
     j = j + 1;
    if(item>a[j])//if parent node is already has greater no. than child nodes
      break;
    temp = a[j/2];//if child node has greater element then swap child and parent
    a[j/2] = a[j];
    a[j] = temp;
    j = 2*j;
  }
  a[j/2] = item;
}
void Heapify(int a[],int n)
{
  for(int i=n/2;i>=1;i--)
   adjust(a,i,n);
}
void heapSort(int a[],int n)
{
  int i,temp;
  Heapify(a,n);
  for(i=n;i>=2;i--)
  {
    temp = a[1];//placing greatest elements in right place in array
    a[1] = a[i];
    a[i] = temp;
    adjust(a,1,i-1);/*heapifying elements 1 to i-1:i.e, except the greater
     element that is kept in correct place*/
  }
}
void main()
{
  int i,n;
  double time;
  printf("Enter the size array\n");
  scanf("%d",&n);
  int a[n];
  for(i=1;i<=n;i++)
   a[i] = rand()%100;
  printf("Before sorting\n");
  for(i=1;i<=n;i++)
    printf("%d\t",a[i]);
  clock_t start = clock();
  heapSort(a,n);
  time = (clock()-start)/CLOCKS_PER_SEC;
  printf("After sorting\n");
  for(i=1;i<=n;i++)
    printf("%d\t",a[i]);
  printf("Time:%fs\n",time);
}
