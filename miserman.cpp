#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	int n,m;
	scanf("%d %d",&n,&m);
	int arr[n+1][m+1];
	int ans[n+1][m+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	memset(ans,1061109567,sizeof(ans));
	for(int i=1;i<=m;i++){
		ans[1][i]=arr[1][i];
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			ans[i][j]=arr[i][j]+min(ans[i-1][j],min(ans[i-1][j-1],ans[i-1][j+1]));
		}
	}
	int r=ans[n][1];
	for(int i=2;i<=m;i++){
		r=min(r,ans[n][i]);
	}
	printf("%d\n",r);	
	return 0;
}
