#include <stdio.h>
#define inf 1000;
void main()
{
    int size, n_coin, i, j;

    printf("Enter bag size: ");
    scanf("%d", &size);

    printf("Enter number of coins: ");
    scanf("%d", &n_coin);

    int v_coin[n_coin+1];
    printf("Enter %d coin values: ", n_coin);
    for(i=1; i<=n_coin; i++)
    {
        scanf("%d", &v_coin[i]);
    }

    int table[n_coin+1][size+1];
    for(i=0; i<=size; i++)
        table[0][i] = inf;

    for(j=0; j<=n_coin; j++)
        table[j][0] = 0;

    for(i=1; i<=n_coin; i++)
    {
        for(j=1; j<=size; j++)
        {
            if(j<v_coin[i])
                table[i][j] = table[i-1][j];
            else
            {
                if(table[i-1][j] <= 1 + table[i][j-v_coin[i]])
                    table[i][j] = table[i-1][j];
                else
                    table[i][j] = 1 + table[i][j-v_coin[i]];
            }
        }
    }
    //print
    for(i=0; i<=n_coin; i++)
    {
        for(j=0; j<=size; j++)
        {
            printf("%4d  ", table[i][j]);
        }
        printf("\n");
    }
    i = n_coin;
    j = size;
    while(i!=0 && j!=0)
    {
        if(table[i][j] == table[i-1][j])
            i--;
        else
        {
            printf("\ncoin %d picked.", i);
            j = j - v_coin[i];
        }
    }
}// C program to find minimum
// number of denominations
#include <stdio.h>
#define COINS 9
#define MAX 20

// All denominations of Indian Currency
int coins[COINS] = { 1, 2, 5, 10, 20,
					50, 100, 200, 2000 };

void findMin(int cost)
{
	int coinList[MAX] = { 0 };
	int i, k = 0;

	for (i = COINS - 1; i >= 0; i--) {
		while (cost >= coins[i]) {
			cost -= coins[i];
			// Add coin in the list
			coinList[k++] = coins[i];
		}
	}

	for (i = 0; i < k; i++) {
		// Print
		printf("%d ", coinList[i]);
	}
	return;
}

int main(void)
{
	// input value
	int n = 93;

	printf("Following is minimal number"
		"of change for %d: ",
		n);
	findMin(n);
	return 0;
}
// Code by Munish Bhardwaj

