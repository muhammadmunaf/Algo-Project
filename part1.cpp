// Muhammad Munaf Ul Hassan     20i-0891     Sec D
// Part 1   Recursive Algo without Memoization

#include <iostream>
using namespace std;

const int Size = 22;

// these are in k, e.g. 15 -> 15k
int Data[Size] = {
    15, 75, 120, 135, 150, 185, 200, 220, 250, 270, 300, 310, 330, 375, 400, 450, 480, 500, 520, 550, 560, 600
};

int getMax(int x, int y)
{
    return (x>y)? x: y;
}

// recursive function for main working
int FindMaxProfit(int cost[], int n = Size)
{
    if(n == 0)
        return 0;
  
    int temp = 0;

    for(int i = 1; i<=n; i++)
        temp = getMax(FindMaxProfit(cost, n-i) + cost[i-1], temp);
    
    return temp;
}

// to get the data ready before computation
void setCosts(int* costs, int n)
{
    for(int i = 0; i<Size; i++)
        costs[i] = Data[i];
}

int main() {

    int n1 = 1, n2 = 1;
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

    int profit = FindMaxProfit(cost, n);

    cout << "\nMaximum Profit of an area of " << n1 << "x" << n2 << " is $" << profit << ",000\n\n";

	return 0;
}