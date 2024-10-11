#include<stdio.h>

int main(){
    int n;
    int a[100000];
    scanf("%d",&n);
    int count_odd = 0, count_even = 0;
    for (int i = 0; i < n; i++){
        scanf("%d",&a[i]);
        if (a[i] % 2 == 0) count_even++;
        else count_odd++;
    } 
    printf("%d %d",count_odd,count_even);
}