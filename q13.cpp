#include <iostream>
using namespace std;

#define MAX 10
int DP[MAX][MAX];

int mcm(int arr[], int i, int j)
{
    if (j <= i + 1) {
        return 0;
    } 
    int min = INT32_MAX; 
    if (DP[i][j] == 0)
    {
       for (int k = i + 1; k <= j - 1; k++)
        {
            int cost = mcm(arr, i, k); 
            cost += mcm(arr, k, j); 
            cost += arr[i] * arr[k] * arr[j]; 
            if (cost < min) {
                min = cost;
            }
        } 
        //putting in look up table
        DP[i][j] = min;
    } 
    //corner element
    return DP[i][j];
}

int main()
{
    int n;
    cout<<"Enter n:"<<endl;
    cin>>n;
    int* arr= new int[n];
    cout<<"Enter the elements of array: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout << "The minimum cost is " << mcm(arr, 0, n-1);
    return 0;
}