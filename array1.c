#include<stdio.h>
int main()
{
    int n=11;
    int arr[n];
    printf("Enter the elements of the array:");
    for(int i=0;i<11;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<11;i++)
    {
        printf("\n%d",arr[i]);
    }
    int num;
    printf("Enter the number you want to insert");
    scanf("%d",&num);

    int pos;
    printf("Enter the position at which you want the number to be inserted:");
    scanf("%d",&pos);
    for(int i=n;i>=pos;i--)
    {
        arr[i]=arr[i-1];
    }
arr[pos]=num;

for(int i=0;i<n;i++)
printf("%d",arr[i]);
}