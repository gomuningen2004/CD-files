#include<stdio.h>
int main()
{
    
  int r, c, i, j;
  printf ("Enter required number of rows & columns ");
  scanf ("%d %d", &r, &c);
  int a[r][c];
  printf ("Enter emelmets of matrix ");
  for (i = 0; i < r; i++)
  {
      for (j = 0; j < c; j++)
      {
          scanf ("%d", &a[i][j]);
      }
  }
  printf ("Transpose of the matrix is\n");
  for (i = 0; i < c; i++)
  {
      for (j = 0; j < r; j++)
      {
          printf ("%d ", a[j][i]);
      }
      printf ("\n");
  }
  return 0;
}