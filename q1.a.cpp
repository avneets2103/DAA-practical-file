#include<iostream>
using namespace std;

//1. merge sort
void merge(int* A, int s, int m, int e)
{
    // og positions of variables
    // for later use
    int a = s, b = m + 1;

    // making a new array 
    int arr[e - s + 1]; 
    int c = 0;

    for (int i = s; i <= e; i++)
    {
        if (a > m){
            arr[c++] = A[b++];
        }
        else if (b > e){
            arr[c++] = A[a++];
        }
        else if (A[a] < A[b]){
            arr[c++] = A[a++];
        }
        else{
            arr[c++] = A[b++];
        }
    }

    for (int i = 0; i < c; i++)
    {
        A[s++] = arr[i];
    }
}

void merge_sort(int* A, int s, int e)
{
    if (s < e) //check for validity 
    {
        // dividing in 2 parts
        int m = (s + e) / 2; 
        //applying merge_sort to different parts of code
        merge_sort(A, s, m);   
        merge_sort(A, m + 1, e); 

        // merging the sorted sub arrays
        merge(A, s, m, e);
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
    merge_sort(BP,0,n);
    cout<<"Max BP recorded: "<<BP[n-1]<<endl;
    cout<<"Min BP recorded: "<<BP[0]<<endl;
    return 0;
}