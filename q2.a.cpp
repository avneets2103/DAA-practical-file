#include<iostream>
using namespace std;

int getMax(int* arr, int n) {
  int max = arr[0];
  for (int i = 1; i < n; i++)
    if (arr[i] > max)
      max = arr[i];
  return max;
}

void countingSort(int* arr, int size, int place) {
  int max = 10;
  int output[size]; //making a new array of size same as og array
  int count[max]; //another array of size 10 i.e. (buckets)

  //initiating the whole array with 0
  for (int i = 0; i < max; i++){
    count[i] = 0;
  }

  // Calculate count of elements
  for (int i = 0; i < size; i++){
        int a = (arr[i] / place) % 10;
        count[a]++;
  }

  // cumulative count
  for (int i = 1; i < max; i++)
    count[i] = count[i] + count[i - 1];

  //place wise sorting
  for (int i = size; i > 0; i--) {
    output[count[(arr[i-1] / place) % 10] - 1] = arr[i-1];
    count[(arr[i-1] / place) % 10]--;
  }
  for (int i = 0; i < size; i++){
    arr[i] = output[i];
  }
}

void radixsort(int* arr, int size) {
  // to get the max element
  int max = getMax(arr, size);

  // Place based sorting using countSort
  for (int place = 1 ; max/place > 0; place = place*10){
    countingSort(arr,size,place);
    //first it calls on basis of first place
    //then calls on basis of seconds place 
    // and the place value increaments evertime
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
    radixsort(BP,n);
    cout<<"Max BP recorded: "<<BP[n-1]<<endl;
    cout<<"Min BP recorded: "<<BP[0]<<endl;
    return 0;
}
