#include<stdio.h>

int main()
{
int a[5];
int ele = sizeof(a)/sizeof(a[0]);

for(int i=0;i<ele;i++){
scanf("%d",&a[i]);
}

int key;
printf("Enter element to search : ");
scanf("%d",&key);

for(int i=0;i<ele;i++){
if(a[i]==key){
printf("Element is present\n");
return 0;
}
}

printf("Element not present\n");

return 0;
}
