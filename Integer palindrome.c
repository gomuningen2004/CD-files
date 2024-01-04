#include <stdio.h>
#include <math.h>

int main()
{
   int n, x, up;
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
       count--;
       up = x * pow(10, count);
       sum = sum + up;
       temp = temp / 10;
   }
   if(sum == n)
   {
       printf("Number is a palindrome number");
   }
   else
   {
       printf("Number is not a palindrome number");
   }

   return 0;
}


