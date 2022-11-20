#include<iostream>
using namespace std;

void insertionSort(int* arr, int n)
{
    int i;
    int key;
    int  j;

    //inserting elements    
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1; 
        // shifting
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    insertionSort(BP,n);
    cout<<"Max BP recorded: "<<BP[n-1]<<endl;
    cout<<"Min BP recorded: "<<BP[0]<<endl;
    return 0;
}
