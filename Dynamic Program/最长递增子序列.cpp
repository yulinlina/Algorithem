#include<iostream>
#include<cstring>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
int nums[100000];
int n;
int lengthOfLIS(int nums[]) {
    int *top = (int*)malloc(sizeof(int)*n);
    // 牌堆数初始化为 0
    int piles = 0;
    for (int i = 0; i < n; i++) {
        // 要处理的扑克牌
        int poker = nums[i];

        /***** 搜索左侧边界的二分查找 *****/
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

        // 没找到合适的牌堆，新建一堆
        if (left == piles) piles++;
        // 把这张牌放到牌堆顶
        top[left] = poker;
    }
    // 牌堆数就是 LIS 长度
    return piles;
}

int main() {
    cin >> n;
	_for(i, 0, n) { cin >> nums[i]; }
    cout << lengthOfLIS(nums) << endl;
    return 0;
}