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
	int t,n,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		if(n>m){
			if(m%2==0){
				printf("U\n");
				continue;
			}
			printf("D\n");
			continue;
		}
		if(n<=m){
			if(n%2==0){
				printf("L\n");
				continue;
			}
			printf("R\n");
			continue;
		}
	}
	return 0;
}
