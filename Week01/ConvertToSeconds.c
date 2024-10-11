#include<stdio.h>

int main(){
    char str[9];
    fgets(str,9,stdin);

    if (str[2] != ':' || str[5] != ':') printf("INCORRECT");
    else if (str[0] > '2' || (str[0] == '2' && str[1] > '3')) printf("INCORRECT");
    else if (str[3] > '5') printf("INCORRECT");
    else if (str[6] > '5') printf("INCORRECT");
    else if (str[7] == '\0') printf("INCORRECT");
    else if (str[1] == ':' || str[4] == ':' || str[3] == ':') printf("INCORRECT");
    else {
        int s1 = (str[0] - 48) * 10 + (str[1] - 48);
        int s2 = (str[3] - 48) * 10 + (str[4] - 48);
        int s3 = (str[6] - 48) * 10 + (str[7] - 48);
        printf("%d",s1*60*60+s2*60+s3);
    }
}