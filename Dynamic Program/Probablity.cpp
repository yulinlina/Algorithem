//
// Created by wang haolin on 2022/4/17.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace  std;
int probablity(){
     vector<int> track;
     int n,k;
     float p[201];
     float track_sum =0;
     float dp[201][101]={0};
     cin>>n>>k;
     for (int i=0;i<n;i++) cin>>p[i];
     dp[1][0]=1-p[0];
     dp[0][0]=1;
     for (int i =1;i<n+1;i++){
         dp[i][0] = dp[i-1][0]*(1-p[i-1]);
     }
     for (int i =1;i<n+1;i++){
         for(int j =1;j<k+1;j++){
             dp[i][j] = dp[i-1][j]*(1-p[i-1])+dp[i-1][j-1]*p[i-1];
         }
     }
     printf("%.4f",dp[n][k]);
    return 0;
 }