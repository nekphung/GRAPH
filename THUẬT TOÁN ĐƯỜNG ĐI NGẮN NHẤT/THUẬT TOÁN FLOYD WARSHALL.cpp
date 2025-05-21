// Thuat toan nay ap dung quy hoach dong vao de xu ly
#include <iostream>
using namespace std;

int Mat[1005][1005];
//Mat[i][j] : Khoảng cách đường đi ngắn nhất từ i tới j
int n; //V
void Floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				Mat[i][j] = min(Mat[i][j], Mat[i][k] + Mat[k][j]);
			}
		}
	}
}
