//
// Created by wang haolin on 2022/4/26.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
int D(){
    long group = 0,count = 0,num=0;
    std::cin>>group;
    std::vector<long> arr,wait_time;
    long temp_sum =0;

    for(int i =0;i<group;i++){
        std::cin>>count;
        for(int j = 0;j<count;j++){
            std::cin>>num;
            arr.push_back(num);
        }
        std::sort(arr.begin(),arr.end());
        wait_time.push_back(0); // the first job don't need to wait
        for(int a = 0;a < arr.size()-1;a++){
            temp_sum += arr[a];
            wait_time.push_back(temp_sum);   // the next job wait
        }
//        for(auto t:wait_time){
//            std::cout<<t<<std::endl;
//        }
        std::cout<<std::accumulate(wait_time.begin(),wait_time.end(),0)<<std::endl;
        arr.clear();
        wait_time.clear();
        temp_sum = 0;

    }


    return 0;
}
int main(){
    int a[10]={4,3,2,1};
    std::cout<<std::accumulate(a,a+4,0)<<std::endl;
    return 0;
}