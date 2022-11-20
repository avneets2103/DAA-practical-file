#include<iostream>
using namespace std;

void countSort(int array[], int size) {
  int out[10];
  int cnt[10];
  int max = array[0];

  // LARGEST IN THE ARRAY 
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }

  // Initialize as all zeroes
  for (int i = 0; i <= max; ++i) {
    cnt[i] = 0;
  }

  // Store the count
  for (int i = 0; i < size; i++) {
    cnt[array[i]]++;
  }

  // Store the cummulative count
  for (int i = 1; i <= max; i++) {
    cnt[i] += cnt[i - 1];
  }

  // place the elements in out array
  for (int i = size - 1; i >= 0; i--) {
    out[cnt[array[i]] - 1] = array[i];
    cnt[array[i]]--;
  }

  // Copy the sorted elements into original array
  for (int i = 0; i < size; i++) {
    array[i] = out[i];
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
    countSort(BP,n);
    cout<<"Max BP recorded: "<<BP[n-1]<<endl;
    cout<<"Min BP recorded: "<<BP[0]<<endl;
    return 0;
}
