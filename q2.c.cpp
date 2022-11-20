#include <iostream>
using namespace std;

//maximum element of the array 
int Max(int list[], int length)
{
    int maximum = list[0];
    for (int i = 1; i < length; i++)
        if (list[i] > maximum){
            maximum = list[i];
        }
    return maximum;
}

void bucketSort(int list[], int length)
{
    // setting bucket arrays
    int bucket[10];
    // getting the max in the array
    int maximum = Max(list, length);
    //setting each as 0
    for (int i = 0; i <= maximum; i++)
    {
        bucket[i] = 0;
    }
    // filling buckets with the element counts
    for (int i = 0; i < length; i++)
    {
        bucket[list[i]]++;
    }
    // taking out from the buckets
    for (int i = 0; i <= maximum; i++)
    {
        static int j = 0;
        while (bucket[i] > 0)
        {
            list[j++] = i;
            bucket[i]--;
        }
    }
}

int main()
{
    int n;
    cout<<"Enter the number of counts for taking BP details: "<<endl;
    cin>>n;
    int * BP = new int[n];
    cout<<"Enter BP data: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>BP[i];
    }
    bucketSort(BP,n);
    cout<<"Max BP recorded: "<<BP[n-1]<<endl;
    cout<<"Min BP recorded: "<<BP[0]<<endl;
    return 0;
}
