#include<stdio.h>

int main(){
    int a[100000];
    int n,k;
    scanf("%d%d",&n,&k);
    for (int i = 0; i < n; i++) scanf("%d",&a[i]);

    int sum[10000] = {0};
    int count = 0;
    for (int j = 0; j <= k - 1; j++) sum[0] += a[j]; 
    for (int i = 1; i < n-k+2; i++){
        sum[i] = sum[i-1] - a[i-1] + a[k-1];
        if (sum[i] % 2 == 0) count++;
    }
    printf("%d",count);
    return 0;
}