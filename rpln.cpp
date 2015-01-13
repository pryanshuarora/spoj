#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
long long arr[100008];
long long tree[400008];
long long query(long long nod,long long st,long long end,long long i,long long j);
void initialise(long long nod,long long st,long long end);
int main(int argc, char const *argv[])
{
	int t;
	long long n,q,a,j;
	scanf("%d",&t);
	int h=1;
	while(t--){
		printf("Scenario #%d:\n",h);
		scanf("%lld %lld",&n,&q);
		for(int i=1;i<=n;i++){
			scanf("%lld",&arr[i]);
		}
		initialise(1,1,n);
		for(int k=1;k<=q;k++){
			scanf("%lld %lld",&a,&j);
			printf("%lld\n",query(1,1,n,a,j));
		}
		h++;
	}
	return 0;
}
void initialise(long long nod,long long st,long long end){
	if(st==end){
		tree[nod]=arr[st];
		return;
	}
	long long l=2*nod;
	long long r=l+1;
	long long mid=(st+end)>>1;
	initialise(l,st,mid);
	initialise(r,mid+1,end);
	tree[nod]=min(tree[l],tree[r]);
}
long long query(long long nod,long long st,long long end,long long i,long long j){
	if(st>j||end<i){
		return 1000000007;
	}
	if(st>=i&&end<=j){
		return tree[nod];
	}
	long long l=2*nod;
	long long r=l+1;
	long long mid=(st+end)>>1;
	return min(query(l,st,mid,i,j),query(r,mid+1,end,i,j));
}
