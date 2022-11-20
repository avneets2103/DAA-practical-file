#include<iostream>
using namespace std;

int linearSearch(int* arr, int n, int req){
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==req){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    int* arr = new int[n];
    cout<<"Enter size of array: "<<endl;
    cin>>n;
    cout<<"Enter the array in order: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int req;
    cout<<"Enter what number to find in array: "<<endl;
    cin>>req;
    if (linearSearch(arr,n,req) >= 0)
    {
        cout<<"The number is present first at index: "<<linearSearch(arr,n,req);
    }
    else{
        cout<<"The number is absent"<<endl;
    }
    
    return 0;
}
