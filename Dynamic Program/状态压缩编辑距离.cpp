#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int minDistanceArray(string& word1, string& word2) {
    int lengthOfWord1 = word1.length();
    int lengthOfWord2 = word2.length();
    if (lengthOfWord1 == 0 || lengthOfWord2 == 0) {
        //两个中有一个长度为0，则需要的编辑距离是由内容的字符串的长度
        return max(lengthOfWord1, lengthOfWord2);
    }
    int arraySize = (lengthOfWord2 + 1) * 2;
    int* dp = (int*)malloc(sizeof(int) * arraySize);
    memset(dp, 0, arraySize * sizeof(int));
    int currentOffset = lengthOfWord2 + 1;
    int formerOffset = 0;
    for (int i = 1; i <= lengthOfWord2; i++) {
        //初始状态下，s1长度统一为 0。。s1要变到对应长度的s2的字符需要的步骤数等于 对应的s2的长度
        dp[currentOffset + i] = i;
    }
    //s1的长度不断增长。。formerOffset位置记录下s1的长度为当前长度减1的时候，对应的s2需要的步骤
    //从s1的长度为1开始逐步递推。。
    for (int s1Length = 1; s1Length <= lengthOfWord1; s1Length++) {
        //s1每过一行就将当前行与前一样的offset翻转一下。
        swap(formerOffset, currentOffset);
        dp[currentOffset] = s1Length;
        for (int s2Length = 1; s2Length <= lengthOfWord2; s2Length++) {
            //求
            //S1 回退一格
            int up = dp[formerOffset + s2Length] + 1;
            //S2 回退一格
            int left = dp[currentOffset + s2Length - 1] + 1;
            //S1 S2都回退一格所需要的步数，如果S1 S2 当前位置的字符不相等，需要在之前的基础上加上一步
            int left_up = dp[formerOffset + s2Length - 1] + ((word2[s2Length - 1] == word1[s1Length - 1]) ? 0 : 1);
            dp[currentOffset + s2Length] = min(min(left, up), left_up);
        }
    }
    int result = dp[currentOffset + lengthOfWord2];
    free(dp);
    return result;
}
int main() {
    int t;
    cin >> t;
    string str_a, str_b;
    while (t) {
        cin >> str_a >> str_b;
        cout << minDistanceArray(str_a, str_b) << endl;
        t--;
    }
    return 0;
}


