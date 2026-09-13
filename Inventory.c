#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Product
{
    int id;
    char name[50];
    int quantity;
    float price;
};

struct Product products[MAX];
int count = 0;

/* Load Data */
void loadData()
{
    FILE *fp = fopen("inventory.txt", "r");

    if(fp == NULL)
        return;

    count = 0;

    while(fscanf(fp,
                 "%d,%49[^,],%d,%f",
                 &products[count].id,
                 products[count].name,
                 &products[count].quantity,
                 &products[count].price) == 4)
    {
        count++;

        if(count >= MAX)
            break;
    }

    fclose(fp);
}

/* Save Data */
void saveData()
{
    FILE *fp = fopen("inventory.txt", "w");

    int i;

    if(fp == NULL)
    {
        printf("\nError Saving File!\n");
        return;
    }

    for(i = 0; i < count; i++)
    {
        fprintf(fp, "Product ID   : %d\n", products[i].id);
        fprintf(fp, "Product Name : %s\n", products[i].name);
        fprintf(fp, "Quantity     : %d\n", products[i].quantity);
        fprintf(fp, "Price        : %.2f\n", products[i].price);
        fprintf(fp, "----------------------------------\n");
    }

    fclose(fp);

}

/* Add Product */
void addProduct()
{
    int i;
    int newID;

    if(count >= MAX)
    {
        printf("\nInventory Full!\n");
        return;
    }

    printf("\nEnter Product ID: ");
    scanf("%d", &newID);

    for(i = 0; i < count; i++)
    {
        if(products[i].id == newID)
        {
            printf("\nProduct ID Already Exists!\n");
            return;
        }
    }

    products[count].id = newID;

    printf("Enter Product Name: ");
    scanf(" %[^\n]", products[count].name);

    printf("Enter Quantity: ");
    scanf("%d", &products[count].quantity);

    printf("Enter Price: ");
    scanf("%f", &products[count].price);

    count++;

    printf("\nProduct Added Successfully!\n");
}

/* Display Products */
void displayProducts()
{
    int i;

    if(count == 0)
    {
        printf("\nNo Products Available!\n");
        return;
    }

    printf("\n=========== PRODUCT LIST ===========\n");

    for(i = 0; i < count; i++)
    {
        printf("\nID       : %d", products[i].id);
        printf("\nName     : %s", products[i].name);
        printf("\nQuantity : %d", products[i].quantity);
        printf("\nPrice    : %.2f\n", products[i].price);

        printf("----------------------------------\n");
    }
}

/* Search Product */
void searchProduct()
{
    int id, i;

    printf("\nEnter Product ID: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++)
    {
        if(products[i].id == id)
        {
            printf("\nProduct Found!\n");

            printf("ID       : %d\n", products[i].id);
            printf("Name     : %s\n", products[i].name);
            printf("Quantity : %d\n", products[i].quantity);
            printf("Price    : %.2f\n", products[i].price);

            return;
        }
    }

    printf("\nProduct Not Found!\n");
}

/* Update Product */
void updateProduct()
{
    int id, i;

    printf("\nEnter Product ID to Update: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++)
    {
        if(products[i].id == id)
        {
            printf("Enter New Name: ");
            scanf(" %[^\n]", products[i].name);

            printf("Enter New Quantity: ");
            scanf("%d", &products[i].quantity);

            printf("Enter New Price: ");
            scanf("%f", &products[i].price);

            printf("\nProduct Updated Successfully!\n");
            return;
        }
    }

    printf("\nProduct Not Found!\n");
}

/* Delete Product */
void deleteProduct()
{
    int id, i, j;

    printf("\nEnter Product ID to Delete: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++)
    {
        if(products[i].id == id)
        {
            for(j = i; j < count - 1; j++)
            {
                products[j] = products[j + 1];
            }

            count--;

            printf("\nProduct Deleted Successfully!\n");
            return;
        }
    }

    printf("\nProduct Not Found!\n");
}

/* Sell Product */
void sellProduct()
{
    int id, qty, i;

    printf("\nEnter Product ID: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++)
    {
        if(products[i].id == id)
        {
            printf("Enter Quantity Sold: ");
            scanf("%d", &qty);

            if(qty > products[i].quantity)
            {
                printf("\nInsufficient Stock!\n");
                return;
            }

            products[i].quantity -= qty;

            printf("\nSale Successful!\n");

            printf("Bill Amount = %.2f\n",
                   qty * products[i].price);

            printf("Remaining Stock = %d\n",
                   products[i].quantity);

            return;
        }
    }

    printf("\nProduct Not Found!\n");
}

/* Restock Product */
void restockProduct()
{
    int id, qty, i;

    printf("\nEnter Product ID: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++)
    {
        if(products[i].id == id)
        {
            printf("Enter Quantity to Add: ");
            scanf("%d", &qty);

            products[i].quantity += qty;

            printf("\nStock Updated Successfully!\n");
            printf("Current Stock = %d\n",
                   products[i].quantity);

            return;
        }
    }

    printf("\nProduct Not Found!\n");
}

/* Low Stock Alert */
void lowStockAlert()
{
    int i;
    int found = 0;

    printf("\n====== LOW STOCK PRODUCTS ======\n");

    for(i = 0; i < count; i++)
    {
        if(products[i].quantity < 5)
        {
            printf("\nID       : %d", products[i].id);
            printf("\nName     : %s", products[i].name);
            printf("\nQuantity : %d\n",
                   products[i].quantity);

            found = 1;
        }
    }

    if(found == 0)
    {
        printf("\nNo Low Stock Products Found!\n");
    }
}

/* Inventory Value Report */
void inventoryValue()
{
    int i;
    float total = 0;

    for(i = 0; i < count; i++)
    {
        total += products[i].quantity *
                 products[i].price;
    }

    printf("\nTotal Inventory Value = %.2f\n",
           total);
}

/* Dashboard */
void dashboard()
{
    int i;
    int totalStock = 0;
    float totalValue = 0;

    for(i = 0; i < count; i++)
    {
        totalStock += products[i].quantity;

        totalValue += products[i].quantity *
                      products[i].price;
    }

    printf("\n========== DASHBOARD ==========\n");

    printf("Total Products : %d\n", count);
    printf("Total Stock    : %d\n", totalStock);
    printf("Inventory Value: %.2f\n", totalValue);
}

/* Main Function */
int main()
{
    int choice;

    loadData();

    do
    {
        printf("\n\n========== INVENTORY MANAGEMENT ==========\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Search Product\n");
        printf("4. Update Product\n");
        printf("5. Delete Product\n");
        printf("6. Sell Product\n");
        printf("7. Restock Product\n");
        printf("8. Low Stock Alert\n");
        printf("9. Inventory Value Report\n");
        printf("10. Dashboard Statistics\n");
        printf("11. Save Data\n");
        printf("12. Exit\n");

        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: addProduct(); break;
            case 2: displayProducts(); break;
            case 3: searchProduct(); break;
            case 4: updateProduct(); break;
            case 5: deleteProduct(); break;
            case 6: sellProduct(); break;
            case 7: restockProduct(); break;
            case 8: lowStockAlert(); break;
            case 9: inventoryValue(); break;
            case 10: dashboard(); break;

            case 11:
                saveData();
                printf("\nData Saved Successfully!\n");
                break;

            case 12:
                saveData();
                printf("\nData Saved Successfully!\n");
                printf("Thank You!\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while(choice != 12);

    return 0;
}