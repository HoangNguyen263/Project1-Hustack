#include<stdio.h>
#include<string.h>
int checkChar(char x){
    if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z')){
            return 1;
    }
    else return 0;
}
int main(){
    char str[1000000];
    fgets(str,1000000,stdin);
    int p,q;
    p=q=0;
    int i = 0;
    int count = 0;
    while (str[i] != '\0'){
        p = i;
        q = i+ 1;
        if (checkChar(str[p]) == 1 && checkChar(str[q]) == 0 ){
            count++;
        }
        i++;
    }
    printf("%d",count);
}
