#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int minDistanceArray(string& word1, string& word2) {
    int lengthOfWord1 = word1.length();
    int lengthOfWord2 = word2.length();
    if (lengthOfWord1 == 0 || lengthOfWord2 == 0) {
        //��������һ������Ϊ0������Ҫ�ı༭�����������ݵ��ַ����ĳ���
        return max(lengthOfWord1, lengthOfWord2);
    }
    int arraySize = (lengthOfWord2 + 1) * 2;
    int* dp = (int*)malloc(sizeof(int) * arraySize);
    memset(dp, 0, arraySize * sizeof(int));
    int currentOffset = lengthOfWord2 + 1;
    int formerOffset = 0;
    for (int i = 1; i <= lengthOfWord2; i++) {
        //��ʼ״̬�£�s1����ͳһΪ 0����s1Ҫ�䵽��Ӧ���ȵ�s2���ַ���Ҫ�Ĳ��������� ��Ӧ��s2�ĳ���
        dp[currentOffset + i] = i;
    }
    //s1�ĳ��Ȳ�����������formerOffsetλ�ü�¼��s1�ĳ���Ϊ��ǰ���ȼ�1��ʱ�򣬶�Ӧ��s2��Ҫ�Ĳ���
    //��s1�ĳ���Ϊ1��ʼ�𲽵��ơ���
    for (int s1Length = 1; s1Length <= lengthOfWord1; s1Length++) {
        //s1ÿ��һ�оͽ���ǰ����ǰһ����offset��תһ�¡�
        swap(formerOffset, currentOffset);
        dp[currentOffset] = s1Length;
        for (int s2Length = 1; s2Length <= lengthOfWord2; s2Length++) {
            //��
            //S1 ����һ��
            int up = dp[formerOffset + s2Length] + 1;
            //S2 ����һ��
            int left = dp[currentOffset + s2Length - 1] + 1;
            //S1 S2������һ������Ҫ�Ĳ��������S1 S2 ��ǰλ�õ��ַ�����ȣ���Ҫ��֮ǰ�Ļ����ϼ���һ��
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


