// Muhammad Munaf Ul Hassan     20i-0891     Sec D
// Part 2   Recursive Algo with Memoization

#include <iostream>
using namespace std;

const int Size = 22;

// these are in k, e.g. 15 -> 15k
int Data[Size] = {
    15, 75, 120, 135, 150, 185, 200, 220, 250, 270, 300, 310, 330, 375, 400, 450, 480, 500, 520, 550, 560, 600
};

int temp[Size+1] = {0}; // table used for memoization 1D array instead of 2D

int getMax(int x, int y)
{
    return (x>y)? x: y;
}

// main function for calculation
int findMaxProfit(int n = Size, int i = 0)
{    
    if(n+1 <= 0)
        return 0;

    for(int j =0; j<n+1; j++)
        if(i>j)
            temp[j] = temp[j];
        else
            temp[j] = getMax( temp[j], findMaxProfit(i-j, ++i) + Data[i-1]);
        
    return temp[n];
}

int main() {

    int n1 = 20, n2 = 25;
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

    int profit = findMaxProfit(n);

    cout << "\nMaximum Profit of an area of " << n1 << "x" << n2 << " is $" << profit << ",000\n\n";
    
	return 1;
}

