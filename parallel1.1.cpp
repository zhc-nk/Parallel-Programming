#include<iostream>
#include <windows.h> 
using namespace std;
int a[1001][1101];
int b[1101];
int sum[1001];
int main()
{
	LARGE_INTEGER head, tail, freq; // timers
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&head);
	int n = 400;
	for (int k = 1; k <= 5; k++) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				a[i][j] = i + j;
		for (int i = 1; i <= n; i++)
			b[i] = i;
		for (int i = 1; i <= n; i++)
			sum[i] = 0;
		for (int j = 1; j <= n; j++)
			sum[i] += a[j][i] * b[j];
	}
	QueryPerformanceCounter(&tail);
	int second_time = (double)(tail.QuadPart - head.QuadPart) / (double)(freq.QuadPart);
	int micro_time = (double)(tail.QuadPart - head.QuadPart) / (double)(freq.QuadPart) * 1e6;
	cout << "The total time of the project is（naive）:" << second_time << " s and " << micro_time << " ms" << endl;
	system("pause");
	return 0;
}
#include<iostream>
#include <windows.h> 
using namespace std;
int main()
{
    LARGE_INTEGER head, tail, freq; // timers
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&head);
    int n;
    n = 101;
    int a[1001][1101]; int b[1101];
    int sum[1001];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = i + j;
    for (int i = 1; i <= n; i++)
        b[i] = i;
    for (int i = 1; i <= n; i++)
        sum[i] = 0;
    for (int j = 1; j <= n; j++)
        for (int i = 1; i <= n; i++)
            sum[i] += a[j][i] * b[j];

    QueryPerformanceCounter(&tail);
    int second_time = (double)(tail.QuadPart - head.QuadPart) / (double)(freq.QuadPart);
    int micro_time = (double)(tail.QuadPart - head.QuadPart) / (double)(freq.QuadPart) * 1e6;
    cout << "The total time of the project is :" << second_time << " s and " << micro_time << " ms" << endl;
    return 0;
}