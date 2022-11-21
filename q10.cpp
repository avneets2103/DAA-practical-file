#include <iostream>
using namespace std;

// m is the maximum capacity of knapsack, and n is the number of items or size of array
void knapsack(int m, int n, float* p, float* w, float* x)
{
    // sorting using selection sort but in descending order
    for (int i = 1; i < n; i++)
    {
        int max = i;
        for (int j = i + 1; j <= n; j++)
        {
            if (p[j] / w[j] > p[max] / w[max])
            {
                max = j;
            }
        }
        swap(p[max], p[i]);
        swap(w[max], w[i]);
    }

    //making a dummy variable to store value of max capacity and then changing it
    int u = m;
    int i;
    //filling the knapsack
    for (i = 1; i <= n; i++)
    {
        // checking if can fit the full item or not 
        if (w[i] > u){
            break;
        }
        x[i] = 1;
        // u is the left out capacity
        u = u - w[i];
    }
    //in case of still left (fraction case)
    if (i <= n)
    {
        x[i] = u / w[i];
    }
}

int profit_calculation(int n,float* x, float* p)
{
    float total = 0;
    // profit of item = fraction of item * unitary profit 
    for (int i = 1; i <= n; i++){
        total += x[i]*p[i];
    }
    return total;
}

int main()
{
    int n; // n is the number of items
    cout <<"Enter the no. of items:";
    cin >> n;

    // initialising array 
    float* p = new float[n];
    float* w =  new float[n];
    float* x = new float[n];

    // setting every element of x to be zero
    for (int i = 0; i < n; i++)
    {
        x[i]=0;
    }

    cout<<"Enter profit and weight in order together: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i] >> w[i]; // Enter Profit space Weight respectively
    }

    int m; //max capacity of knapsack
    cout<<"Enter max capacity if knapsack"<<endl;
    cin>>m;

    //calling the knapsack
    knapsack(m, n,p,w,x);

    cout << "your total profit is: "<<20;
    return 0;
}
