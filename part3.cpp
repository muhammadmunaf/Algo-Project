// Muhammad Munaf Ul Hassan     20i-0891     Sec D
// Part 3   Iterative Algo with Memoization

#include <iostream>
using namespace std;

const int Size = 22;

// these are in k, e.g. 15 -> 15k
int Data[Size] = {
    15, 75, 120, 135, 150, 185, 200, 220, 250, 270, 300, 310, 330, 375, 400, 450, 480, 500, 520, 550, 560, 600
};

int table[Size+1][Size+1] = {0}; // table used for memoization

int getMax(int x, int y)
{
    return (x>y)? x: y;
}

// main function for calculation
int findMaxProfit(int cost[], int n = Size)
{    
    for(int i = 1; i < n+1; i++)
        for(int j = 1; j < n+1; j++)
            if(i > j)
                table[i][j] = table[i-1][j];
            else
                table[i][j] = getMax( table[i-1][j], table[i][j-i] + cost[i-1]);
        
    return table[n][n];
}

// to get the data ready before computation
void setCosts(int* costs, int n)
{
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            table[i][j] = 0;

    for(int i = 0; i<Size; i++)
        costs[i] = Data[i];
}

int main() {

    int n1, n2;
    while(n1%5 != 0 || n2%5 != 0)
    {
        cout << "Enter Dimension 1: ";
        cin >> n1;
        cout << "Enter Dimension 2: ";
        cin >> n2;

        if(n1%5 != 0 || n2%5 != 0)
            cout << "\n*Error! Dimensions can only be a multiple of 5*\n\n";
    }
    
    int n = n1*n2;
    n = n/100;

    int* cost;
    cost = new int[n]{0};

    setCosts(cost, n);

    int profit = findMaxProfit(cost, n);

    cout << "\nMaximum Profit of an area of " << n1 << "x" << n2 << " is $" << profit << ",000\n\n";
    
	return 1;
}