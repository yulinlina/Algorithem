#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

struct Complex
{
    double re_number, im_number;//real imag
    Complex() {}
    Complex(double _r, double _i) { re_number = _r;im_number = _i; }
    friend Complex operator + (const Complex& x, const Complex& y) { return Complex(x.re_number + y.re_number, x.im_number + y.im_number); }
    friend Complex operator - (const Complex& x, const Complex& y) { return Complex(x.re_number - y.re_number, x.im_number - y.im_number); }
    friend Complex operator * (const Complex& x, const Complex& y) { return Complex(x.re_number * y.re_number - x.im_number * y.im_number, x.re_number * y.im_number + x.im_number * y.re_number); }
};
const double PI = acos(-1.0);
const int MAX_SIZE = 1100010;

int R[MAX_SIZE], sum[MAX_SIZE];
char s1[MAX_SIZE], s2[MAX_SIZE];
Complex a[MAX_SIZE], b[MAX_SIZE];

void FFT(Complex* y, int len, int on)
{
    for (int i = 0;i < len;i++)if (i < R[i]) { Complex tt;tt = y[i];y[i] = y[R[i]];y[R[i]] = tt; }
    for (int i = 1;i < len;i <<= 1)

    {
        Complex wn(cos(PI / i), sin(on * PI / i));

        for (int j = 0;j < len;j += (i << 1))

        {
            Complex w(1, 0);

            for (int k = 0;k < i;k++, w = w * wn)

            {
                Complex u = y[j + k];

                Complex v = w * y[j + k + i];

                y[j + k] = u + v;
                y[j + k + i] = u - v;
            }
        }
    }
    if (on == -1)for (int i = 0;i < len;i++)y[i].re_number /= len;
}
int main()
{
    while (scanf("%s %s", s1, s2) != EOF) {

        int len1 = strlen(s1), len2 = strlen(s2);
        int len = 1, lenx = len1 + len2;int L = 0;
        for (len = 1;len < lenx;len <<= 1)L++;
        for (int i = 0;i < len;i++)R[i] = ((R[i >> 1]) >> 1) | ((i & 1) << (L - 1));
        for (int i = 0;i < len1;i++)a[i] = Complex(s1[len1 - i - 1] - '0', 0);
        for (int i = len1;i < len;i++)a[i] = Complex(0, 0);
        for (int i = 0;i < len2;i++)b[i] = Complex(s2[len2 - i - 1] - '0', 0);
        for (int i = len2;i < len;i++)b[i] = Complex(0, 0);
        FFT(a, len, 1);
        FFT(b, len, 1);
        for (int i = 0;i < len;i++)a[i] = a[i] * b[i];
        FFT(a, len, -1);
        for (int i = 0;i < len;i++)sum[i] = int(a[i].re_number + 0.5);
        for (int i = 0;i < len;i++)
        {
            sum[i + 1] += sum[i] / 10;
            sum[i] %= 10;
        }
        len = len1 + len2 - 1;
        while (sum[len] <= 0 && len > 0)len--;
        for (int i = len;i >= 0;i--)printf("%c", sum[i] + '0');
        printf("\n");
    }
    printf("I love Python.\n");
    return 0;
}