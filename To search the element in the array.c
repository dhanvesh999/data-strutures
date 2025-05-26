#include <stdio.h>
int main() {
    int a[100]={1,2,3,4,5,6,7,8,9,10,25,34},i,n;
    printf("Enter the number to be searched in the array\n");
    scanf("%d",&n);
    for(i=0;i<100;i++)
    {
        if(a[i]==n)
        {printf("Yes the element is present in the array\n");
        return 0;}
    }
    printf("The element is not present");
    return 0;
}
  
