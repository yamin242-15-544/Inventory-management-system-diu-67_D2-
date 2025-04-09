//This is not complete code and it is missing some keyfunctions and will be added shortly!!
//Don't get misleaded if you find any function that isn't in action right now they will be implimented soon!!




#include <conio.h> // getch()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h> // For sleep()
#include <windows.h>

void gotoxy(int x, int y) {
  COORD c;
  c.X = x;
  c.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
 void slines(int a){
     printf("%c",201);
       for (int i = 0; i < a; i++) {
    printf("%c", 205);
 }
 printf("%c",187);
 }
  void elines(int a){
     printf("%c",200);
       for (int i = 0; i < a; i++) {
    printf("%c", 205);
 }
 printf("%c",188);
 }
 
   void mlines(int a){
     printf("%c",204);
       for (int i = 0; i < a; i++) {
    printf("%c", 205);
 }
 printf("%c",185);
 }
 
  void dashes_vline(int c) {
     printf("%c",186);
    for (int b = 0; b <= c; b++) {
        printf("-");
    }
    printf("%c",186);
}


// Structure for each item
typedef struct Item {
    char name[50];
    int quantity;
    float price;
    char entryTime[100];
    char chatagories[50];
    struct Item *next;
} Item;

// Structure for category
typedef struct Category {
    char name[50];
    Item *items;
    struct Category *next;
} Category;

Category *categories = NULL;

// Utility: Get current time as string
void getCurrentTime(char *buffer) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, 100, "%d-%m-%Y %H:%M:%S", t);
}

// Utility: Get current week as string
void getCurrentWeek(char *buffer) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, 100, "Week %U, %Y", t);
}

// Utility: Get current date
void getCurrentDate(char *buffer) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, 100, "%d-%m-%Y", t);
}

// Create a new item node
Item* createItem(char *name, int quantity, float price ,char *chatagories) {
    Item *newItem = (Item*)malloc(sizeof(Item));
    strcpy(newItem->name, name);
    newItem->quantity = quantity;
    newItem->price = price;
    getCurrentTime(newItem->entryTime);
    strcpy(newItem->chatagories, chatagories);
    newItem->next = NULL;
    return newItem;
}

// Create a new category
Category* createCategory(char *name) {
    Category *newCategory = (Category*)malloc(sizeof(Category));
    strcpy(newCategory->name, name);
    newCategory->items = NULL;
    newCategory->next = categories;
    categories = newCategory;
    return newCategory;
}

// Find a category
Category* findCategory(char *name) {
    Category *temp = categories;
    while (temp) {
        if (strcasecmp(temp->name, name) == 0) return temp;
        temp = temp->next;
    }
    return NULL;
}

void showcategories(){
        Category *cat = categories;
    if (!cat) {
        printf("NO category found. Add a category first\n");
        return;
    }
    int point=1;
    while (cat) {
        printf("%d.%s\n", point++,cat->name);
        cat = cat->next;
    }
}

void showcategories1(){
        Category *cat = categories;
    if (!cat) {
        printf("Add a category please\n");
        return;
    }
    int point=1;
    while (cat) {
        printf("%d.%s\n", point++,cat->name);
        cat = cat->next;
    }
}
// Add new item to a category
void addItem() {
    char name[50], categoryName[50];
    int quantity;
    float price;
    printf("Enter item name: ");
    scanf(" %[^\n]", name);
    showcategories();
    printf("Enter category name: ");
    scanf(" %[^\n]", categoryName);

    Category *cat1 = findCategory(categoryName);
    if (!cat1) {
        printf("Category not found. Add it first.\n");
        return;
    }

    printf("Enter quantity: ");
    scanf("%d", &quantity);
    printf("Enter price: ");
    scanf("%f", &price);
    char cat_name[50];
    strcpy(cat_name,cat1->name);

    Item *newItem = createItem(name, quantity, price,cat_name);
    newItem->next = cat1->items;
    cat1->items = newItem;
    printf("Item added successfully!\n");
}

// Add a new category
void addCategory() {
    showcategories1();
    char name[50];
    printf("Enter new category name: ");
    scanf(" %[^\n]", name);
    if (findCategory(name)) {
        printf("Category already exists.\n");
        return;
    }
    createCategory(name);
    printf("Category added successfully.\n");
}

// Show all items grouped by category
void showItems() {
    Category *cat = categories;
    if (!cat) {
        printf("No categories found.\n");
        return;
    }
    while (cat) {
        printf("\nCategory: %s\n", cat->name);
        Item *temp = cat->items;
        if (!temp) {
            printf("  No items in this category.\n");
        }
        while (temp) {
                if(temp->quantity<10){
            printf("  Name: %s | Quantity: %d | Price: %.2f | Added on: %s\n",
                   temp->name, temp->quantity, temp->price, temp->entryTime);
                }
                else{
                printf("  Name: %s | Quantity: %d | Price: %.2f | Added on: %s\n",
                   temp->name, temp->quantity, temp->price, temp->entryTime);
                }
                temp = temp->next;
        }
        cat = cat->next;
    }
}



// Search item by name and category
void searchItem() {
    char name[50], categoryName[50];
    printf("Enter item name to search: ");
    scanf(" %[^\n]", name);
    printf("Enter category: ");
    scanf(" %[^\n]", categoryName);

    Category *cat = findCategory(categoryName);
    if (!cat) {
        printf("Category not found.\n");
        return;
    }
    Item *temp = cat->items;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            printf("Found - Name: %s | Quantity: %d | Price: %.2f | Added on: %s\n",
                   temp->name, temp->quantity, temp->price, temp->entryTime);
            return;
        }
        temp = temp->next;
    }
    printf("Item not found.\n");
}

// Update item
void updateItem() {
    char name[50], categoryName[50];
    printf("Enter category name: ");
    scanf(" %[^\n]", categoryName);
    printf("Enter item name to update: ");
    scanf(" %[^\n]", name);

    Category *cat = findCategory(categoryName);
    if (!cat) {
        printf("Category not found.\n");
        return;
    }

    Item *temp = cat->items;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &temp->quantity);
            printf("Enter new price: ");
            scanf("%f", &temp->price);
            getCurrentTime(temp->entryTime);
            printf("Item updated successfully.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Item not found.\n");
}

// Remove a category
void removeCategory() {
    showcategories1();
    char categoryName[50];
    printf("Enter category name to remove: ");
    scanf(" %[^\n]", categoryName);

    Category *prev = NULL, *temp = categories;
    while (temp) {
        if (strcmp(temp->name, categoryName) == 0) {
            // Free all items in the category
            Item *item = temp->items;
            while (item) {
                Item *tempItem = item;
                item = item->next;
                free(tempItem);
            }

            // Remove the category from the linked list
            if (prev) {
                prev->next = temp->next;
            } else {
                categories = temp->next;
            }

            free(temp);
            printf("Category and its items removed.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Category not found.\n");
}

// Delete item
void deleteItem() {
    char name[50], categoryName[50];
    printf("Enter category name: ");
    scanf(" %[^\n]", categoryName);
    printf("Enter item name to delete: ");
    scanf(" %[^\n]", name);

    Category *cat = findCategory(categoryName);
    if (!cat) {
        printf("Category not found.\n");
        return;
    }

    Item *temp = cat->items, *prev = NULL;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            if (prev) prev->next = temp->next;
            else cat->items = temp->next;
            free(temp);
            printf("Item deleted.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Item not found.\n");
}

// Generate inventory report
void generateReport() {
    FILE *fp = fopen("inventory_report.txt", "w");
    float totalValue = 0, maxPrice = 0, minPrice = 1e9;
    char maxName[50] = "", minName[50] = "";
    Category *cat = categories;

    printf("\nInventory Report\n\n");
    fprintf(fp, "Inventory Report\n\n");
    while (cat) {
        int count = 0;
        Item *item = cat->items;
        while (item) {
            float value = item->price * item->quantity;
            totalValue += value;
            if (item->price > maxPrice) {
                maxPrice = item->price;
                strcpy(maxName, item->name);
            }
            if (item->price < minPrice) {
                minPrice = item->price;
                strcpy(minName, item->name);
            }
            count++;
            item = item->next;
        }
        printf("Category: %s | Items: %d\n", cat->name, count);
        fprintf(fp, "Category: %s | Items: %d\n", cat->name, count);
        cat = cat->next;
    }
    printf("\nTotal Inventory Value: %.2f\n", totalValue);
    printf("Most Expensive Item: %s (%.2f)\n", maxName, maxPrice);
    printf("Cheapest Item: %s (%.2f)\n", minName, minPrice);

    fprintf(fp, "\nTotal Inventory Value: %.2f\n", totalValue);
    fprintf(fp, "Most Expensive Item: %s (%.2f)\n", maxName, maxPrice);
    fprintf(fp, "Cheapest Item: %s (%.2f)\n", minName, minPrice);
    fclose(fp);
    printf("Report saved to inventory_report.txt\n");
}

// Weekly report
void generateWeeklyReport() {
    FILE *fp = fopen("weekly_report.txt", "w");
    char week[100];
    getCurrentWeek(week);
    fprintf(fp, "Weekly Inventory Report - %s\n\n", week);
    printf("Weekly Inventory Report - %s\n\n", week);

    Category *cat = categories;
    while (cat) {
        fprintf(fp, "Category: %s\n", cat->name);
        printf("Category: %s\n", cat->name);
        Item *item = cat->items;
        while (item) {
            fprintf(fp, "  Item: %s | Quantity: %d | Price: %.2f | Added: %s\n",
                    item->name, item->quantity, item->price, item->entryTime);
            printf("  Item: %s | Quantity: %d | Price: %.2f | Added: %s\n",
                    item->name, item->quantity, item->price, item->entryTime);
            item = item->next;
        }
        cat = cat->next;
    }
    fclose(fp);
    printf("Weekly report saved to weekly_report.txt\n");
}

// Daily report
void generateDailyReport() {
    FILE *fp = fopen("daily_report.txt", "w");
    char today[100];
    getCurrentDate(today);
    fprintf(fp, "Daily Inventory Report - %s\n\n", today);
    printf("Daily Inventory Report - %s\n\n", today);

    Category *cat = categories;
    while (cat) {
        fprintf(fp, "Category: %s\n", cat->name);
        printf("Category: %s\n", cat->name);
        Item *item = cat->items;
        while (item) {
            if (strstr(item->entryTime, today)) {
                fprintf(fp, "  Item: %s | Quantity: %d | Price: %.2f | Added: %s\n",
                        item->name, item->quantity, item->price, item->entryTime);
                printf("  Item: %s | Quantity: %d | Price: %.2f | Added: %s\n",
                        item->name, item->quantity, item->price, item->entryTime);
            }
            item = item->next;
        }
        cat = cat->next;
    }
    fclose(fp);
    printf("Daily report saved to daily_report.txt\n");
}

// Save data to file
//void saveToFile() {
//    FILE *file = fopen("inventory.dat", "wb");
//    if (!file) {
//        printf("Error opening file for saving data.\n");
//        return;
//    }
//
//    Category *cat = categories;
//    while (cat) {
//        // Save category name
//        fwrite(cat->name, sizeof(cat->name), 1, file);
//
//        // Save items in the category
//        Item *item = cat->items;
//        while (item) {
//            fwrite(item, sizeof(Item) - sizeof(item->next), 1, file); // Exclude 'next' pointer
//            item = item->next;
//        }
//
//        cat = cat->next;
//    }
//    fclose(file);
//}
//
//// Load data from file (basic, simplified)
//void loadFromFile() {
//    FILE *file = fopen("inventory.dat", "rb");
//    if (!file) {
//        printf("Error opening file for loading data.\n");
//        return;
//    }
//
//    Category *lastCat = NULL;
//    char catName[50];
//    while (fread(catName, sizeof(catName), 1, file)) {
//        // Create new category
//        Category *newCat = createCategory(catName);
//
//        // Load items for the current category
//        Item tempItem;
//        while (fread(&tempItem, sizeof(Item) - sizeof(tempItem.next), 1, file)) {
//            if (strlen(tempItem.name) == 0) break;
//
//            // Create new item and add to category
//            Item *newItem = createItem(tempItem.name, tempItem.quantity, tempItem.price);
//            strcpy(newItem->entryTime, tempItem.entryTime);
//            newItem->next = newCat->items;
//            newCat->items = newItem;
//        }
//
//        // Link the category into the global list
//        if (lastCat) {
//            lastCat->next = newCat;
//        } else {
//            categories = newCat;  // First category
//        }
//        lastCat = newCat;
//    }
//
//    fclose(file);
//}


// Main menu
void menu() {
    int choice;
//    loadFromFile();
    do {
        printf("\n-- Inventory Management --\n");
        printf("1. Add Category\n2. Add Item\n3. Show All Items\n4. Search Item\n5. Update Item\n6. Delete Item\n7. Generate Report\n8. Weekly Report\n9. Daily Report\n ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addCategory(); break;
            case 2: addItem(); break;
            case 3: showItems(); break;
            case 4: searchItem(); break;
            case 5: updateItem(); break;
            case 6: deleteItem(); break;
            case 7: generateReport(); break;
            case 8: generateWeeklyReport(); break;
            case 9: generateDailyReport(); break;
//            case 10: saveToFile(); printf("Data saved. Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 10);
}

int main() {
    menu();
    return 0;
}

