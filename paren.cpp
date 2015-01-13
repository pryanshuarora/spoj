#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
	int t;
	scanf("%d",&t);
	while (t--) {
		int v, n;
		scanf("%d %d",&v,&n);
		v /= 10;
		int vol[60][4], prod[60][4], child[60];
		memset(vol, 0, sizeof(vol));
		memset(prod, 0, sizeof(prod));
		memset(child, 0, sizeof(child));
	
		for (int i = 1; i <= n; i++) {
		int v, c, u;
		scanf("%d %d %d",&v,&c,&u);
		v /= 10;
		if (!u) {
			vol[i][0] = v;
			prod[i][0] = v * c;
		}
		 else {
			child[u]++;
			vol[u][child[u]] = v;
			prod[u][child[u]] = v * c;
			}
		}
	
		for (int i = 0; i <= n; i++) {
			vol[i][3] = vol[i][0] + vol[i][1] + vol[i][2];
			prod[i][3] = prod[i][0] + prod[i][1] + prod[i][2];
			vol[i][1] = vol[i][0] + vol[i][1];
			prod[i][1] = prod[i][0] + prod[i][1];
			vol[i][2] = vol[i][0] + vol[i][2];
			prod[i][2] = prod[i][0] + prod[i][2];
		}
		int dp[3201][61];

		for (int j = 0; j <= v; j++) {
			dp[j][0] = 0;
		}
		for (int i = 0; i <= n; i++) {
			dp[0][i] = 0;
		}
		for (int j = 1; j <= v; j++) {
			for (int i = 1; i <= n; i++) {
				int ele = max(dp[j-1][i], dp[j][i-1]);
				if (prod[i][0] > 0) {
					for (int k = 0; k < 4; k++) {
						int v = j - vol[i][k];
						if (v >= 0) {
							ele = max(ele, dp[v][i-1] + prod[i][k]);
						}
					}
				}
				dp[j][i] = ele;
			}
		}
		printf("%d\n",dp[v][n]*10);
		}
	return 0;
}
