#include<stdio.h>
#include<math.h>
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int d = b*b - 4*a*c;
    if (d < 0) printf("NO SOLUTION");
    else if (d == 0) printf("%.2lf",-1.0 * b / (2*a));
    else {
        printf("%.2lf %.2lf", 1.0*(-b - sqrt(d)) / (2*a), 1.0*(-b + sqrt(d)) / (2*a));
    }
}