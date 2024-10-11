#include<stdio.h>
#include<string.h>

int main(){
    char str[11];
    fgets(str,11,stdin);
    
    if (str[4] != '-' || str[7] != '-') printf("INCORRECT");
    else if (str[5] > '1' || (str[5] == '1' && str[6] > '2')) printf("INCORRECT");
    else if (str[8] > '3' || (str[8] == '3' && str[9] > '1')) printf("INCORRECT");
    else if (str[9] == '\0') printf("INCORRECT");
    else if (str[6] == '-') printf("INCORRECT");
    else {
        for (int i = 0; i <= 3; i++) printf("%c",str[i]);
        printf(" ");
        if (str[5] == '1') printf("%c%c",str[5],str[6]);
        else if (str[5] == '0') printf("%c",str[6]);
        printf(" ");
        if (str[8] == '0') printf("%c",str[9]);
        else printf("%c%c",str[8],str[9]);
    }

}