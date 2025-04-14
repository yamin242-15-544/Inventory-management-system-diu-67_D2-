// Update item
void updateItem() {
    system("cls");
    char name[50], categoryName[50];
    int quantity,arridx_count;
    float price;
    case_struct(20,45,12);
    gotoxy(34,17);
    printf("Enter \"0\" to return ");
    showcategories();
    gotoxy(22,6);
    printf("Select the category:");
    gotoxy(43,6);
    scanf("%d",&arridx_count);
    if(arridx_count==0){
        menu();
    }
    int arr_idx=arr_element;
    int arr_idx1=arr_element;
    int arrsize=++arr_idx;
    if(arridx_count<=arrsize||arridx_count>=1){
        int reverse_idx =arr_idx1 - arridx_count;
        strcpy(categoryName,cat_arr[reverse_idx]);
    }
    else{
        system("cls");
        gotoxy(45,10);
        slines(30);
        gotoxy(45,11);
        printf("%-9c\e[1;31mInvalid Input.\e[0m%9c",186,186);
        gotoxy(45,12);
        printf("%-10c\e[1;31mTRY AGAIN\e[0m%13c",186,186);
        gotoxy(45,13);
        elines(30);
        sleep(2);
        return;
    }
    gotoxy(22,8);
    printf("Enter item name to update:");
    gotoxy(48,8);
    scanf(" %[^\n]", name);
    Category *cat = findCategory(categoryName);
    Item *temp = cat->items;
    while (temp) {
        if (strcasecmp(temp->name, name) == 0) {
            gotoxy(22,10);
            printf("Enter new quantity: ");
            gotoxy(42,10);
            scanf("%d", &temp->quantity);
            gotoxy(22,12);
            printf("Enter new price: ");
            gotoxy(39,12);
            scanf("%f", &temp->price);
            getCurrentTime(temp->entryTime);
            system("cls");
            gotoxy(45,10);
            slines(30);
            gotoxy(45,11);
            printf("%-3c\e[1;32mItem updated successfully.\e[0m%3c",186,186);
            gotoxy(45,12);
            elines(30);
            sleep(2);
            return;
        }
        temp = temp->next;
    }
        system("cls");
        gotoxy(45,10);
        slines(30);
        gotoxy(45,11);
        printf("%-9c\e[1;31mItem not found.\e[0m%8c",186,186);
        gotoxy(45,12);
        elines(30);
        sleep(2);
}
// Generate inventory report
void generateWeeklyReport() {
    system("cls");
    FILE *fp = fopen("inventory_weekly_report.txt", "w");
    char week[100];
    getCurrentWeek(week);
    float totalValue = 0, maxPrice = 0, minPrice = 1e9;
    char maxName[50], minName[50];
    Category *cat = categories;

//    printf("\n\e[1mInventory Report Week(%s)\e[0m\n\n",week);
    fprintf(fp, "\nInventory Report Week(%s)\n\n",week);

//        printf("\n\e[1m# Financial Summery\e[0m\n\n");
    fprintf(fp, "\n# Financial Summery\n\n");
    while (cat) {
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
            item = item->next;
        }
        cat = cat->next;
    }
//    printf("\nTotal Inventory Value: %.2f\n", totalValue);
//    printf("Most Expensive Item: %s (%.2f)\n", maxName, maxPrice);
//    printf("Cheapest Item: %s (%.2f)\n", minName, minPrice);

    fprintf(fp, "\nTotal Inventory Value: ৳%.2f\n", totalValue);
    fprintf(fp, "Most Expensive Item: %s (৳%.2f)\n", maxName, maxPrice);
    fprintf(fp, "Cheapest Item: %s (৳%.2f)\n", minName, minPrice);

//            printf("\n\e[1m# Stock Status\e[0m\n\n");
    fprintf(fp, "\n# Stock Status\n\n");
        Category *cat1 = categories;
     int low_stock=0,out_of_stock=0,In_stock=0;
    while (cat1) {
        Item *item = cat1->items;
        while (item) {
                In_stock++;
                if(item->quantity<10){
                    low_stock++;
                }
                if(item->quantity==0){
                    out_of_stock++;
                }
            item = item->next;
        }
        cat1= cat1->next;
    }
//    printf("Low Stock Item:%d\n",low_stock);
//    printf("Out of Stock Item:%d\n",out_of_stock);
//    printf("In Stock Item:%d\n",In_stock);
    fprintf(fp, "Low Stock Item:%d\n",low_stock);
    fprintf(fp, "Out of Stock Item:%d\n",out_of_stock);
    fprintf(fp, "In Stock Item:%d\n",In_stock);

    Category *cat2 = categories;
//    printf("\n\e[1m# Cateory Breakdown\e[0m\n\n");
    fprintf(fp, "\n# Cateory Breakdow\n\n");
    while (cat2){
            int item_num=0;
            float item_price=0;
        Item *item = cat2->items;
        while (item){
                item_num++;
                item_price+=item->price;
            item = item->next;
        }
//        printf("Category:%s",cat2->name);
//        printf("%d(%.2f)\n",item_num,item_price);
        fprintf(fp, "Category:%s",cat2->name);
        fprintf(fp, "=%d(৳%.2f)\n",item_num,item_price);
        cat2= cat2->next;
    }

//    printf("\n\e[1m# Recommendation\e[0m\n\n");
    fprintf(fp, "\n# Recommendation\n\n");
    Category *cat3 = categories;
    while (cat3) {
        Item *item = cat3->items;
        while (item) {
                In_stock++;
                if(item->quantity<10){
//                    printf("Restock %s(current:%d)",item->name,item->quantity);
                    fprintf(fp, "Restock %s(current:%d)",item->name,item->quantity);
                }
            item = item->next;
        }
        cat3= cat3->next;
    }
    fclose(fp);
    system("start inventory_weekly_report.txt");
    menu();
}

// Daily report
void generatedailyReport() {
    FILE *fp = fopen("inventory_Daily_report.txt", "w");
    char today[100];
    getCurrentDate(today);
    float totalValue = 0, maxPrice = 0, minPrice = 1e9;
    char maxName[50] = "", minName[50] = "";
    Category *cat = categories;

    fprintf(fp, "Inventory Report (%s)\n\n",today);

    fprintf(fp, "\n# Financial Summery\n\n");
    while (cat) {
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
            item = item->next;
        }
        cat = cat->next;
    }

    fprintf(fp, "\nTotal Inventory Value: ৳%.2f\n", totalValue);
    fprintf(fp, "Most Expensive Item: %s (৳%.2f)\n", maxName, maxPrice);
    fprintf(fp, "Cheapest Item: %s (৳%.2f)\n", minName, minPrice);

    fprintf(fp, "\n# Stock Status\n\n");
        Category *cat1 = categories;
     int low_stock=0,out_of_stock=0,In_stock=0;
    while (cat1) {
        Item *item = cat1->items;
        while (item) {
                In_stock++;
                if(item->quantity<10){
                    low_stock++;
                }
                if(item->quantity==0){
                    out_of_stock++;
                }
            item = item->next;
        }
        cat1= cat1->next;
    }
    fprintf(fp, "Low Stock Item:%d\n",low_stock);
    fprintf(fp, "Out of Stock Item:%d\n",out_of_stock);
    fprintf(fp, "In Stock Item:%d\n",In_stock);

    Category *cat2 = categories;
    fprintf(fp, "\n# Cateory Breakdow\n\n");
    while (cat2){
            int item_num=0;
            float item_price=0;
        Item *item = cat2->items;
        while (item){
                item_num++;
                item_price+=item->price;
            item = item->next;
        }
        fprintf(fp, "Category:%s",cat2->name);
        fprintf(fp, "=%d(৳%.2f)\n",item_num,item_price);
        cat2= cat2->next;
    }
    fprintf(fp, "\n# Recommendation\n\n");
    Category *cat3 = categories;
    while (cat3) {
        Item *item = cat3->items;
        while (item) {
                In_stock++;
                if(item->quantity<10){
                    fprintf(fp, "Restock %s(current:%d)",item->name,item->quantity);
                }
            item = item->next;
        }
        cat3= cat3->next;
    }
    fclose(fp);
    system("start inventory_Daily_report.txt");
}


