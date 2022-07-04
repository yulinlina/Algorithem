#include<iostream>
#include<cstring>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
int nums[100000];
int n;
int lengthOfLIS(int nums[]) {
    int *top = (int*)malloc(sizeof(int)*n);
    // �ƶ�����ʼ��Ϊ 0
    int piles = 0;
    for (int i = 0; i < n; i++) {
        // Ҫ������˿���
        int poker = nums[i];

        /***** �������߽�Ķ��ֲ��� *****/
        int left = 0, right = piles;
        while (left < right) {
            int mid = (left + right) / 2;
            if (top[mid] > poker) {
                right = mid;
            }
            else if (top[mid] < poker) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        /*********************************/

        // û�ҵ����ʵ��ƶѣ��½�һ��
        if (left == piles) piles++;
        // �������Ʒŵ��ƶѶ�
        top[left] = poker;
    }
    // �ƶ������� LIS ����
    return piles;
}

int main() {
    cin >> n;
	_for(i, 0, n) { cin >> nums[i]; }
    cout << lengthOfLIS(nums) << endl;
    return 0;
}