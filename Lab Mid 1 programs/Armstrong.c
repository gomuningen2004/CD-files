#include <stdio.h>
#include <math.h>

int main()
{
   int n, x;
   int count = 0;
   int sum = 0;
   printf("Enter a number : ");
   scanf("%d", &n);
   int temp = n;
   while(temp != 0)
   {
       temp = temp/10;
       count++;
   }
   temp = n;
   while(temp != 0)
   {
       x = temp % 10;
       sum = sum + pow(x, count);
       temp = temp / 10;
   }
   if(sum == n)
   {
       printf("%d is an armstrong number", n);
   }
   else
   {
       printf("%d isn't an armstrong number", n);
   }

   return 0;
}

