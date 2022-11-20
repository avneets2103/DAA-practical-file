#include<iostream>
#include <algorithm>
using namespace std;

// A struct for jobs
struct Job {
   int jobId; 
   int deadline;  
   int profit; 
};

class Solution {
   public:
    // mapping the profits and returns
    bool static comparison(Job a, Job b){
        return (a.profit > b.profit);
    }

   //Function to find the maximum profit and the number of jobs done
   pair <int,int> JobScheduling(Job arr[], int n) {
      sort(arr, arr + n, comparison);
      int maximum_deadline = arr[0].deadline;
      for (int i = 1; i < n; i++) {
         maximum_deadline = max(maximum_deadline, arr[i].deadline);
      }
      int slot[maximum_deadline + 1];
      for (int i = 0; i <= maximum_deadline; i++)
         slot[i] = -1;
      int countJobs = 0, jobProfit = 0;
      for (int i = 0; i < n; i++) {
         for (int j = arr[i].deadline; j > 0; j--) {
            if (slot[j] == -1) {
               slot[j] = i;
               countJobs++;
               jobProfit += arr[i].profit;
               break;
            }
         }
      }
      return make_pair(countJobs, jobProfit);
   }
}; 

int main() {
   int n = 4;
   Job arr[n] = {{1,4,34},{2,2,65},{3,1,14},{4,5,55}};
   Solution an;
   pair <int,int> ans = an.JobScheduling(arr, n);
   cout << ans.first << " " << ans.second << endl;

   return 0;

} 