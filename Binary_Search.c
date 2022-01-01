#include <stdio.h>
int main()
{
  int a[50],find, low, high, mid, n, i ; // here we declare a 50 size of array and 6 variables

  printf("Enter size of array:"); // this print will show in console for user
  scanf("%d", &n); // this scanf we used for getting input from users and this will store to variable called "n"

  printf("Enter integers:");

  for (i = 0; i < n; i++) //this for loop is for getting integer values sequentially
    scanf("%d", &a[i]);

  printf("Enter the value you want to find:");
  scanf("%d", &find);

  low = 0;
  high = n - 1;
  mid = (low+high)/2; // here we get the mid value

  while (low <= high) {
    if (a[mid] < find)
      low= mid + 1;
    else if (a[mid] == find) {
      printf("%d found at location %d.\n", find, mid+1);
      break;
    }
    else
      high = mid - 1;

    mid = (low + high)/2;
  }
  if (low > high)
    printf("Not found! %d isn't present in the list.\n", find);

  return 0;
}
