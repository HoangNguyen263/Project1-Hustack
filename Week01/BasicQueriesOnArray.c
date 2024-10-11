#include<stdio.h>
#include<string.h>
int res[10000];
int a[10000];

int findMax(int n){
    int max = a[0];
    for (int i = 0; i < n; i++){
        if (a[i] > max) max = a[i];
    }
    return max;
}

int findMin(int n){
    int min = a[0];
    for (int i = 0; i < n; i++){
        if (a[i] < min) min = a[i];
    }
    return min;
}

int sum(int n){
    int s = 0;
    for (int i = 0; i < n; i++){
        s += a[i];
    }
    return s;
}

int maxSegment(int x, int y){
    int max = a[x];
    for (int i = x; i <= y; i++){
        if (a[i] > max) max = a[i];
    }
    return max;
}

int main(){
    int n;
    char x;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) scanf("%d",&a[i]);
    scanf("%c",&x);
    getchar();

    char query[21];
    int j = 0;
    while (1){
        scanf("%s",query);
        if (strcmp(query, "find-max") == 0){
            res[j] = findMax(n);
            j++;
        } else if (strcmp(query,"find-min") == 0){
            res[j] = findMin(n);
            j++;
        } else if (strcmp(query,"sum") == 0){
            res[j] = sum(n);
            j++;
        } else if (strcmp(query,"find-max-segment") == 0){
            int m,k;
            scanf("%d %d",&m,&k);
            res[j] = maxSegment(m-1,k-1);
            j++;
        } else if (strcmp(query,"***") == 0) break;
    }
    for (int i = 0; i < j; i++) printf("%d\n",res[i]);

}