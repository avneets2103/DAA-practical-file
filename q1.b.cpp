#include<iostream>
using namespace std;

int partition (int* a, int start, int end)  
{  
    int pivot = a[end];
    int var = (start - 1);  
  
    for (int i = start; i < end ; i++)  
    {  
        // if current val < pivot
        if (a[i] < pivot)  
        {  
            var++;
            // swap values
            int val = a[var];  
            a[var] = a[i];  
            a[i] = val;  
        }  
    }  
    var++;
    // swap values
    int t = a[var];  
    a[var] = a[end];  
    a[end] = t;  
    return (var);  
}  
  
void quick_sort(int a[], int start, int end)
{  
    if (start < end)  
    {  
        // finding partition index
        int i = partition(a, start, end); 
        // quick sort on ind. parts
        quick_sort(a, start, i-1);  
        quick_sort(a, i+1, end);  
    }  
}  


int main(){
    int n;
    cout<<"Enter the number of counts for taking BP details: "<<endl;
    cin>>n;
    int * BP = new int[n];
    cout<<"Enter BP data: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>BP[i];
    }
    quick_sort(BP,0,n-1);
    cout<<"Max BP recorded: "<<BP[n-1]<<endl;
    cout<<"Min BP recorded: "<<BP[0]<<endl;
    return 0;
}
