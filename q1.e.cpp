#include<iostream>
using namespace std;

void selectionSort(int* arr, int size) {
  for (int i = 0; i < size - 1; i++) {
    int min_idx = i; //index of the minimum value in the array
    for (int j = i+1; j < size; j++) {

      // Finding the min. element.
      if (arr[j] < arr[min_idx])
        min_idx = j;//found the new min index
    }

    // swap the positions
    swap(arr[min_idx], arr[i]);
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
    selectionSort(BP,n);
    cout<<"Max BP recorded: "<<BP[n-1]<<endl;
    cout<<"Min BP recorded: "<<BP[0]<<endl;
    return 0;
}
