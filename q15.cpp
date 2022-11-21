#include<iostream>
#include <string>
using namespace std;

int LCS(string text, string seq, int m, int n){
    int DP[m+1][n+1];

    //mkaing the sides zero
    for (int i = 0; i < m; i++)
    {
        DP[i][0]=0;
    }
    for (int j = 1; j < n; j++)
    {
        DP[0][j]=0;
    }

    //filling the other boxes
    for (int i = 1; i <= n; i++)
    {
        for (int j =1; j <= m; j++)
        {
            if(text[i]==seq[j]){
                DP[i][j]=1+DP[i-1][j-1];
            }
            else{
                DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
            }
        }
    }
    return DP[m][n];
}

int main(){
    string text;
    string seq;
    int i = 0;
    char input = 'a';
    while (input != '0')
    {
        cin>>text[i];
        input=text[i];
    }
    int j = 0;
    input = 'a';
    while (input != '0')
    {
        cin>>seq[j];
        input=seq[j];
    }
    int m =text.length();
    int n = seq.length();
    cout<<"The longest common subsequence's length is: "<<endl;
    cout<<LCS(text,seq,m,n)<<endl;
    return 0;
}
