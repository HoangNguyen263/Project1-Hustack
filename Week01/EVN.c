#include <stdio.h>

double tinhTien6Bac(int kwh) {
    double tien = 0;

    // Bậc 1: 0-50 kWh
    if (kwh > 50) {
        tien += 50 * 1728;
        kwh -= 50;
    } else {
        tien += kwh * 1728;
        return tien;
    }

    // Bậc 2: 51-100 kWh
    if (kwh > 50) {
        tien += 50 * 1786;
        kwh -= 50;
    } else {
        tien += kwh * 1786;
        return tien;
    }

    // Bậc 3: 101-200 kWh
    if (kwh > 100) {
        tien += 100 * 2074;
        kwh -= 100;
    } else {
        tien += kwh * 2074;
        return tien;
    }

    // Bậc 4: 201-300 kWh
    if (kwh > 100) {
        tien += 100 * 2612;
        kwh -= 100;
    } else {
        tien += kwh * 2612;
        return tien;
    }

    // Bậc 5: 301-400 kWh
    if (kwh > 100) {
        tien += 100 * 2919;
        kwh -= 100;
    } else {
        tien += kwh * 2919;
        return tien;
    }

    // Bậc 6: 401 kWh trở lên
    tien += kwh * 3015;

    return tien;
}


double tinhTien5Bac(int kwh) {
    double tien = 0;

    // Bậc 1: 0-100 kWh
    if (kwh > 100) {
        tien += 100 * 1728;
        kwh -= 100;
    } else {
        tien += kwh * 1728;
        return tien;
    }

    // Bậc 2: 101-200 kWh
    if (kwh > 100) {
        tien += 100 * 2074;
        kwh -= 100;
    } else {
        tien += kwh * 2074;
        return tien;
    }

    // Bậc 3: 201-400 kWh
    if (kwh > 200) {
        tien += 200 * 2612;
        kwh -= 200;
    } else {
        tien += kwh * 2612;
        return tien;
    }

    // Bậc 4: 401-700 kWh
    if (kwh > 300) {
        tien += 300 * 3111;
        kwh -= 300;
    } else {
        tien += kwh * 3111;
        return tien;
    }

    // Bậc 5: 701 kWh trở lên
    tien += kwh * 3457;

    return tien;
}

int main() {
    int kwh;
    scanf("%d", &kwh);
    double tien6Bac = tinhTien6Bac(kwh);
    double tien5Bac = tinhTien5Bac(kwh);
    double chenhlech = 1.1*(tien5Bac - tien6Bac);
    printf("%.2lf", chenhlech);

    return 0;
}
