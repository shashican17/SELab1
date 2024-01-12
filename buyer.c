/*
Shopping retail cart
21mcme27 Shashikant Yadav
Date created:- 5th jan 2024
Last Modified:- 12th jan 2024
*/

#include<stdio.h>
#include<string.h>
#include "functions.h"


void buyerMenu() {
    char userName[30];
    printf("Welcome Buyer\n");
    printf("Enter your name\n");
    scanf("%s", userName);

    while (1) {
        int userOperation;
        printf("Enter 1 to see the menu of items, 2 to go to your cart, 3 to exit\n");
        scanf("%d", &userOperation);

        if (userOperation == 1) {
            // itemsMenu();
        } else if (userOperation == 2) {
            // userCart();
        } else if (userOperation == 3) {
            printf("Thanks for shopping\n");
            break;
        } else {
            printf("Invalid operation, enter again.\n");
        }
    }
}