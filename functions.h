/*
Shopping retail cart
21mcme27 Shashikant Yadav
Date created:- 5th jan 2024
Last Modified:- 12th jan 2024
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct item {
    char name[30];
    int quantity;
    float price;
} item;

void addItem();
void updateItem();
void updateStock();
void generateReport();
int isItemExists(const char *itemName);
void adminMenu();
void buyerMenu();

#endif // FUNCTIONS_H