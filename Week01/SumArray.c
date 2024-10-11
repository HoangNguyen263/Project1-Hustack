#include<stdio.h>
int main(){
    int a[1000000];
    int n;
    scanf("%d",&n);
    int Q = 0;
    for (int i = 0; i < n; i++) scanf("%d",&a[i]);
    for (int i = 0; i < n; i++) Q += a[i];
    printf("%d",Q);
}