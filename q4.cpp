#include<iostream>
using namespace std;

// A is source .. B is helper .. C is destination
void TOH(int n, char A, char B, char C){
    if(n>=1){
    // shifting the top n-1 plates from A to B using C
    TOH(n-1,A,C,B);
    // shifting the last one plate in A to C
    cout<<"Move a plate from "<<A<<" to "<<C<<endl;
    // shifting the n-1 plates from B to C using A
    TOH(n-1,B,A,C);}
}

int main(){
    int n;
    cout<<"How many plates in this Tower of Hanoi"<<endl;
    cin>>n;
    TOH(n,'A','B','C');
    return 0;
}
