/*
Shopping retail cart
21mcme27 Shashikant Yadav
Date created:- 5th jan 2024
Last Modified:- 12th jan 2024
*/

#include<stdio.h>
#include<string.h>
#include "functions.h"

struct order
{
    char *customerName;
    struct item *items;
    float priceOfItems;
    float totalPrice;
};





int main() {
    while (1) {
        int userType;
        printf("Please tell your user type. Enter 1 for admin, 2 for buyer and 3 to exit the program\n");
        scanf("%d", &userType);

        if (userType == 1) {
            adminMenu();
        } else if (userType == 2) {
            buyerMenu();
        } else if (userType == 3) {
            printf("Exiting Now. Thank you...\n");
            break;
        } else {
            printf("Invalid Input, Please Try Again\n");
        }
    }

    return 0;
}