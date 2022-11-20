#include <iostream>
using namespace std;

int binarySearch(int *arr, int start, int end, int req)
{
    if(start>end){
        return -1;
    }
    int mid = start + ((end - start) / 2);
    if (arr[mid] == req)
    {
        return mid;
    }
    else if (arr[mid] > req)
    {
        return binarySearch(arr, start, mid - 1, req);
    }
    else
    {
        return binarySearch(arr, mid + 1, end, req);
    }
}
int main()
{
    int n;
    int *arr = new int[n];
    cout << "Enter size of array: " << endl;
    cin >> n;
    cout << "Enter the array in order: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int req;
    cout << "Enter what number to find in array: " << endl;
    cin >> req;
    if (binarySearch(arr, 0, n - 1, req) >= 0)
    {
        cout << "The number is present first at index: " << binarySearch(arr, 0, n - 1, req);
    }
    else
    {
        cout << "The number is absent" << endl;
    }

    return 0;
}
