#include<stdio.h>
#include<string.h>
#define MAX 400
int shift[MAX];
int horspool(char str[],char comp[])
{
	int i,j,k,m,n;
	m = strlen(comp);
	n = strlen(str);
	i = m-1;
	while(i<n)
	{
		k = 0;
		while((k<m)&&(comp[m-1-k]==str[i-k]))
		 {
		   k++;
  		 }
		if(k==m)
		 return (i-m+1);
		else
		 i+=shift[str[i]];
	}
	return -1;
}
void shiftTable(char comp[])
{
	int i,j,m;
	m = strlen(comp);
	for(i=0;i<MAX;i++)
	 shift[i] = m;
	for(j=0;j<m-1;j++)
	 shift[comp[j]] = m-1-j;
}
void main()
{
	char str[80],comp[80];
	int position;
	printf("Enter the main string\n");
	gets(str);
	printf("Enter string you want to search\n");
	gets(comp);
	shiftTable(comp);
	position = horspool(str,comp);
	if(position>0)
	 printf("String %s start from position %d in %s string",comp,position,str);
	else
	 printf("String is not there\n");
}
