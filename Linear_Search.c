#include <stdio.h>
int main()
{
  int a[50], search, i, n;

  printf("Enter size of array:");
  scanf("%d", &n);

  printf("Enter integers:");

  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  printf("Enter the value you want to search:");
  scanf("%d", &search);

  for (i = 0; i < n; i++)
  {
    if (search == a[i])    /* If required element is found */
    {
      printf("The value %d is found at location %d", search, i+1);
      break;
    }
  }
  if (search != a[i])
    printf("The value %d is not found", search);

  return 0;
}
