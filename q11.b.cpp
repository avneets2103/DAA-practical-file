#include <iostream>
using namespace std;

int knapSack(int W, int* w, int* v, int n) {
   //dynamic table and iterators
   int i, j; 
   int DP[n + 1][W + 1];

   //filling values in the table
   for (i = 0; i <= n; i++) {
      for (j = 0; j <= W; j++) {
         //filling zeroes at the sides 
         if (i == 0 || j == 0){
            DP[i][j] = 0;
         }
         else if (w[i - 1] <= j)
            DP[i][j] = max(v[i - 1] + DP[i - 1][j - w[i - 1]], DP[i - 1][j]);
         else
         DP[i][j] = DP[i - 1][j];
      }
   }
   //returning the last block of the table matrix
   return DP[n][W];
}

int main() {
   cout << "Number of items in a Knapsack: ";
   int n, W;
   cin >> n;
   int* v=  new int[n];
   int* w = new int[n];
   cout << "Enter value and weight in order: "<<endl;
   for (int i = 0; i < n; i++) {
      cin >> v[i];
      cin >> w[i];
   }
   cout << "Enter the capacity of knapsack";
   cin >> W;
   cout << knapSack(W, w, v, n);
   return 0;
}