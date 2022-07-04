
//
// Created by wang haolin on 2022/4/19.
//
#include <iostream>
#include <algorithm>
#include <vector>
#define N 1010
using namespace  std;
int n,v;
int magic[N];
int summons[N];
int cnt[N];
struct spirt{
    int magic;
    int summon;
};
int Mulbag(){
    int t;
    cin>>t;
    while(t){
        cin>>n>>v;
        vector<spirt> spirts;
        int f[100010]={0};
        for(int i =0 ;i <n;i++) cin>>magic[i];
        for(int i =0 ;i <n;i++) cin>>summons[i];
        for(int i =0 ;i <n;i++) cin>>cnt[i];
        for(int i =0 ;i <n;i++){
            for(int k =1;k<cnt[i];k*=2){
                    spirts.push_back({magic[i]*k,summons[i]*k});
                    cnt[i]-=k;
            }
            if (cnt[i]>0) spirts.push_back({magic[i]*cnt[i],summons[i]*cnt[i]});
        }
        for(auto spirt:spirts){
            for (int j=v;j>=spirt.summon;j--){
                f[j]=max(f[j],f[j-spirt.summon]+spirt.magic);
            }
        }
        cout<<f[v]<<endl;
        t--;
    }
    return 0;
}