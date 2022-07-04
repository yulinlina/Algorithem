#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace  std;
typedef pair<char,int> PAIR;

bool cmp_by_value(const PAIR& lhs, const PAIR& rhs) {
    return lhs.second >rhs.second;
}

int weight() {
    string s;
    cin>>s;
    map<char,int> mymap;
    for(int i ='a';i<='z';i++){
        mymap[i] = 0;
    }
    for(auto &item : s){
        mymap[item]++;
    }
    vector<PAIR> map_2_vec (mymap.begin(),mymap.end());
    sort(map_2_vec.begin(),map_2_vec.end(), cmp_by_value);
    int sum =0;
    for(int i =0;i<26;i++) {
        sum += map_2_vec[i].second * (26 - i);
    }
    cout << sum <<endl;
    return 0;
}
