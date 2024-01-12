/*
Shopping retail cart
21mcme27 Shashikant Yadav
Date created:- 5th jan 2024
Last Modified:- 12th jan 2024
*/

#include<stdio.h>
#include<string.h>
#include "functions.h"


#define gst 0.18;


void addItem()
{
    printf( "Enter the item name\n" );
    char name[20];
     if (scanf(" %19[^\n]", name) != 1)
    {
        // Handle input error
        printf("Error reading item name.\n");
        return;
    }

    printf( "Enter the quantity\n" );
    int quantity;
    scanf("%d", &quantity);

    printf( "Enter the price\n" );
    float price;
    scanf("%f", &price);

    struct item newItem;
    strncpy(newItem.name, name, sizeof(name));
    newItem.quantity = quantity;
    newItem.price = price;

    FILE *fptr;
    fptr = fopen( "items.txt", "wb" );
    if (fptr != NULL) 
    {
        fwrite(&newItem, sizeof(struct item), 1, fptr);
        printf("Item Added Succesfully\n");
        fclose(fptr);
    }
    else 
    {
        printf( "Error opening file for writing.\n" );
    }
}


int isItemExists(const char *itemName)
{
    FILE *fptr = fopen( "items.txt", "r" );
    if (fptr == NULL)
    {
        printf("Error opening file for reading.\n");
        return 0; // Returns false if file cannot be opened
    }

    item currentItem;
    while (fread(&currentItem, sizeof(item), 1, fptr) == 1)
    {
        if (strcmp(currentItem.name, itemName) == 0)
        {
            fclose(fptr);
            return 1; // Returns true if item found
        }
    }

    fclose(fptr);
    return 0; // Returns false if item not found
}


void updateItem()
{
    printf( "Enter the item name\n" );
    char name[20];
    if (scanf(" %19[^\n]", name) != 1)
    {
        // Handle input error
        printf( "Error reading item name.\n" );
        return;
    }

    if (isItemExists(name))
    {
        // Item exists, proceed with the update
        printf( "Enter the new name\n" );
        if (scanf(" %19[^\n]", name) != 1)
        {
            // Handle input error
            printf( "Error reading item name.\n" );
            return;
        }

        printf( "Enter the quantity\n" );
        int quantity;
        scanf("%d", &quantity);

        printf( "Enter the price\n" );
        float price;
        scanf("%f", &price);

        // Update the item in the file
        FILE *fptr = fopen( "items.txt", "r+" );
        if (fptr == NULL)
        {
            printf( "Error opening file for updating.\n" );
            return;
        }

        item currentItem;
        while (fread(&currentItem, sizeof(item), 1, fptr) == 1)
        {
            if (strcmp(currentItem.name, name) == 0)
            {
                fseek(fptr, -sizeof(item), SEEK_CUR);
                strncpy(currentItem.name, name, sizeof(currentItem.name));
                currentItem.quantity = quantity;
                currentItem.price = price;
                fwrite(&currentItem, sizeof(item), 1, fptr);
                fclose(fptr);

                printf( "Item updated successfully.\n" );
                return;
            }
        }

        fclose(fptr);
    }
    else
    {
        printf( "No product with such name found. Try again\n" );
    }
}


void updateStock()
{
    printf ( "Enter the item name to update stock\n" );
    char name[20];
    if (scanf(" %19[^\n]", name) != 1)
    {
        // Handle input error
        printf( "Error reading item name.\n" );
        return;
    }

    if (isItemExists(name))
    {
        // Item exists, proceed with the update
        printf("Enter the new quantity\n");
        int quantity;
        scanf("%d", &quantity);

        item newItem;
        strncpy(newItem.name, name, sizeof(newItem.name));
        newItem.quantity = quantity;

        return;
    }
    else
    {
        printf( "No product with such name found\n" );
        return;
    }
}


void adminMenu() {
    while (1)
    {
        int adminOperation;
        printf( "Welcome Admin\n" );
        printf( "Please enter the number of the operation you want to perform\n");
        printf( "1. Add Item\n" );
        printf( "2. Update Item\n" );
        printf(" 3. Update stock\n" );
        printf( "4. Generate Reports\n" );
        printf( "5. Main menu\n" );

        scanf( "%d", &adminOperation );
        switch (adminOperation) {
            case 1:
                addItem();
                break;

            case 2:
                updateItem();
                break;

            case 3:
                updateStock();
                break;

            case 4:
                generateReport();
                break;

            default:
                printf( "Going to main menu...\n" );
                return;
        }
    }
}

