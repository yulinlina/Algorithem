//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<string>
//#include<cstdio>
//using namespace std;
//#define MAX 1000  
////char std1[MAX];
////char std2[MAX];
//string std1, std2;
//int main() {	
//	while (cin >> std1 >> std2) {
//		int length1 = std1.length();
//		int length2 = std2.length();
//		int a[MAX] = { 0 };
//		int b[MAX] = { 0 };
//		int result[2 * MAX] = { 0 };
//		int i = 0, j = 0;
//		//���ַ���ת�Ƶ������У��Է������ ��ע���ǵ���洢
//		//���ַ���123��Ϊ321��Ϊ���ǽ���λ����ǰ�淽����� 
//		for (i = length1 - 1, j = 0; i >= 0; i--, j++)
//		{
//			a[j] = std1[i] - '0';
//		}
//		for (i = length2 - 1, j = 0; i >= 0; i--, j++)
//		{
//			b[j] = std2[i] - '0';
//		}
//		//����������� resullt�У�result[i + j] = a[i] * b[j]�ǹؼ��㷨 
//		for (i = 0; i < length1; i++)
//		{
//			for (j = 0; j < length2; j++)
//			{
//				result[i + j] += a[i] * b[j];
//			}
//		}
//
//		//�ӵ�λ����λ���н�λ
//		for (i = 0; i < (length1 + length2); i++) {
//			if (result[i] > 9)
//			{
//				result[i + 1] += result[i] / 10;
//				result[i] %= 10;
//			}
//		}
//		//��ǰ��0ȫ���޵����������ǽ����236����result��
//		//�������洢��63200����������Ҫ��λ����һ����Ϊ�����������λ��Ҳ����i ��������ˣ�λ�����������λ��֮��
//
//		for (i = length1 + length2; i >= 0; i--)
//		{
//			if (result[i] == 0) continue;
//			else break;
//		}
//		//����i����������������ǵĽ�� 
//		for (; i >= 0; i--)
//			printf("%d", result[i]);
//		printf("\n");
//	}
//	printf("I love Python.");
//	return 0;
//}
