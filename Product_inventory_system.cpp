#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h> // For sleep()
#include <windows.h>

//Regular text
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

//Regular bold text
#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"

//Regular underline text
#define UBLK "\e[4;30m"
#define URED "\e[4;31m"
#define UGRN "\e[4;32m"
#define UYEL "\e[4;33m"
#define UBLU "\e[4;34m"
#define UMAG "\e[4;35m"
#define UCYN "\e[4;36m"
#define UWHT "\e[4;37m"

//Regular background
#define BLKB "\e[40m"
#define REDB "\e[41m"
#define GRNB "\e[42m"
#define YELB "\e[43m"
#define BLUB "\e[44m"
#define MAGB "\e[45m"
#define CYNB "\e[46m"
#define WHTB "\e[47m"

//High intensty background
#define BLKHB "\e[0;100m"
#define REDHB "\e[0;101m"
#define GRNHB "\e[0;102m"
#define YELHB "\e[0;103m"
#define BLUHB "\e[0;104m"
#define MAGHB "\e[0;105m"
#define CYNHB "\e[0;106m"
#define WHTHB "\e[0;107m"

//High intensty text
#define HBLK "\e[0;90m"
#define HRED "\e[0;91m"
#define HGRN "\e[0;92m"
#define HYEL "\e[0;93m"
#define HBLU "\e[0;94m"
#define HMAG "\e[0;95m"
#define HCYN "\e[0;96m"
#define HWHT "\e[0;97m"

//Bold high intensity text
#define BHBLK "\e[1;90m"
#define BHRED "\e[1;91m"
#define BHGRN "\e[1;92m"
#define BHYEL "\e[1;93m"
#define BHBLU "\e[1;94m"
#define BHMAG "\e[1;95m"
#define BHCYN "\e[1;96m"
#define BHWHT "\e[1;97m"

//Reset
#define reset "\e[0m"
#define CRESET "\e[0m"
#define COLOR_RESET "\e[0m"


char cat_arr[100][50];
int arr_element=0;

//to change cursor position.....
void gotoxy(int x, int y) {
  COORD c;
  c.X = x;
  c.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

//simple spaces....
void spaces(int a){
for (int b=0;b<=a;b++){
    printf(" ");
}
}

//starting lines......
 void slines(int a){
     printf("%c",201);
       for (int i = 0; i < a; i++) {
    printf("%c", 205);
 }
 printf("%c",187);
 }

 //end lines...
  void elines(int a){
     printf("%c",200);
       for (int i = 0; i < a; i++) {
    printf("%c", 205);
 }
 printf("%c",188);
 }

//middle line...
   void mlines(int a){
     printf("%c",204);
       for (int i = 0; i < a; i++) {
    printf("%c", 205);
 }
 printf("%c",185);
 }

//horizontal line...
  void dashes_vline(int c) {
     printf("%c",186);
    for (int b = 0; b <= c; b++) {
        printf("-");
    }
    printf("%c",186);
}

//box for loading screen....
void box() {
    gotoxy(4, 1);
    printf("%c", 201);
    for (int i = 0; i < 111; i++) {
        printf("%c", 205);
    }
    printf("%c", 187);
    for (int i = 2; i <= 27; i++) {
        gotoxy(4, i);
        printf("%c", 186);
        gotoxy(116, i);
        printf("%c", 186);
    }
    gotoxy(4, 28);
    printf("%c", 200);
    for (int i = 0; i < 111; i++) {
        printf("%c", 205);
    }
    printf("%c", 188);
}

 //to build every box......
void case_struct(int p,int wid,int hi){
    int x=p, y=4,wid1;
    gotoxy(x,y);
    slines(wid);
    wid1=wid;
    wid1++;
    for(int i=0;i<=hi;i++){
    gotoxy(x,++y);
    printf("%c",186);
    gotoxy(x+wid1,y);
    printf("%c",186);
}
gotoxy(x,++y);
elines(wid);
}

// Function to display the logo or text inside the box (centered "ProStock")
void displayLogo() {
    gotoxy(30,3);
    printf(BHCYN"  _____ _____  ________   _____ ________ ______   _____  _  __        "reset);
    gotoxy(30, 4);
    printf(BHCYN" |  __ \\  __ \\/ ______ \\ / ____|__   __/ _____ \\/ _____|| |/ /    "reset);
    gotoxy(30, 5);
    printf(BHCYN" | |__) ||__)   |    | || (__     | |  | |   | || |     | ' /         "reset);
    gotoxy(30, 6);
    printf(BHCYN" |  ___/|  _  / |    | | \\___ \\   | |  | |   | || |     |  <        "reset);
    gotoxy(30, 7);
    printf(BHCYN" | |    | | \\ \\ |____| | _____)|  | |  | |___| || |____ | .  \\     "reset);
    gotoxy(30, 8);
    printf(BHCYN" |_|    |_|  \\_\\______/ |_____/   |_|  \\_______/ \\_____||_| \\_\\ "reset);
}

// Function to display the loading screen
void loadingScreen() {
    system("cls");
    box();
    displayLogo(); // Display ASCII logo
 int x=219;
    int barWidth = 30;
    gotoxy(50, 14);
    printf("Loading,Please Wait...");
    gotoxy(44,16);
    printf(BHCYN"["reset);
    for (int i = 0; i < barWidth; i++) {
        printf(BHCYN"%c",x);
        Sleep(25);
    }
    printf(BHCYN"]"reset);
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

Category *categories = NULL;//the head node...

//Required functions......
void getCurrentTime();
void getCurrentWeek();
void getCurrentDate();
Item* createItem(char *name, int quantity, float price ,char *chatagories) ;
Category* createCategory(char *name);
Category* findCategory(char *name);
void showcategories();
void showcategories1();
void addItem();
void addCategory() ;
void showItems();
void showlowItem();
void searchItem();
void searchcategory();
void updateItem();
void removeCategory();
void deleteItem();
void menu();
void generateWeeklyReport();
void generatedailyReport();
void add_page();
void show_page();
void deletion();
void loadFromFile();
void saveToFile();

//main menu....
int main(){
    char user_name[8];
    char password[11];
    char user_name1[7]="admin";
    char password1[]="admin";
    int count1=0;
    while(1){
    system("cls");
    box();
    displayLogo();
    gotoxy(45,15);
    printf("Enter username: ");
    gotoxy(61,15);
    scanf(" %[^\n]", user_name);
    gotoxy(45,16);
    printf("Enter password: ");
    gotoxy(61,16);
    scanf("%11s",&password);
        if(strcasecmp(user_name1,user_name)==0 && strcasecmp(password1,password)==0){
                loadingScreen();
                system("cls");
            gotoxy(48,12);
            slines(22);
            gotoxy(48,13);
            printf("%-5c\e[1;32mACCESS GRANTED\e[0m%5c",186,186);
            gotoxy(48,14);
            elines(22);
            sleep(1);
            loadFromFile();
            menu();
            break;
        }
        else{
                system("cls");
                gotoxy(40,10);
                slines(40);
                gotoxy(40,11);
                printf("%-5c\e[1;31m!!Invalid Username or Password!!\e[0m%5c",186,186);
                gotoxy(40,12);
                printf("%-12c\e[1;31mPlease Try again\e[0m%14c",186,186);
                gotoxy(40,13);
                elines(40);
                count1++;
                sleep(2);
        }
                if(count1==5)break;

    }
                system("cls");
                gotoxy(33,10);
                slines(57);
                gotoxy(33,11);
                printf("%-12c\e[1;31m!!Maximum login attempts exceeded!!\e[0m%12c",186,186);
                gotoxy(33,12);
                printf("%-2c\e[1;31m!!The application will now close for security reasons!!\e[0m%2c",186,186);
                gotoxy(33,13);
                elines(57);
                sleep(1);
                printf("\n\n\n\n\n\n\n");
    return 0;
}


//to Get current time as string
void getCurrentTime(char *buffer) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, 100, "%d-%m-%Y %H:%M:%S", t);
}

//to Get current week as string
void getCurrentWeek(char *buffer) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, 100, "Week %U, %Y", t);
}

//to Get current date
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
    strcpy(cat_arr[arr_element],name);
    arr_element++;
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

//to show all saved category....
void showcategories(){
        Category *cat = categories;
    if (!cat) {
        gotoxy(68,4);
        slines(31);
        gotoxy(68,5);
        printf("%-6c\e[1;31mNo categories found\e[0m%8c",186,186);
        gotoxy(68,6);
        printf("%-6c\e[1;31mAdd a category first\e[0m%7c",186,186);
        gotoxy(68,7);
        elines(31);
        return;
    }
    int point=1,y=4;
        gotoxy(68,y);
        slines(31);
    while (cat) {
        gotoxy(68,++y);
        printf("%-9c%-2d.%-20s%c",186,point++,cat->name,186);
        cat = cat->next;
    }
        gotoxy(68,++y);
        elines(31);
}

//to show all saved category in different format...
void showcategories1(){
        Category *cat = categories;
    if (!cat) {
        gotoxy(68,4);
        slines(31);
        gotoxy(68,5);
        printf("%-6c\e[1;31mAdd a category please\e[0m%6c",186,186);
        gotoxy(68,6);
        elines(31);
        return;
    }
    int point=1,y=4;
    system("cls");
        gotoxy(68,y);
        slines(31);
    while (cat) {
        gotoxy(68,++y);
        printf("%-9c%-2d.%-20s%c",186,point++,cat->name,186);
        cat = cat->next;
    }
        gotoxy(68,++y);
        elines(31);
}
// Add new item to a category
void addItem() {
    system("cls");
    char name[50], categoryName[50];
    int quantity,arridx_count;
    float price;
    case_struct(20,45,12);
    showcategories();
    gotoxy(33,17);
    printf("Enter \"0\" to return");
    gotoxy(22,6);
    printf("Select the category:");
    gotoxy(43,6);
    scanf("%d",&arridx_count);
    if(arridx_count==0){
        return;
    }
    int arr_idx=arr_element;
    int arr_idx1=arr_element;
    int arrsize=++arr_idx;
    if(arridx_count<=arrsize&&arridx_count>=1){
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
        return ;
    }
    Category *cat1 = findCategory(categoryName);
    if (!cat1) {
        system("cls");
        gotoxy(45,10);
        slines(30);
        gotoxy(45,11);
        printf("%-7c\e[1;31mCategory not found.\e[0m%6c",186,186);
        gotoxy(45,12);
        printf("%-8c\e[1;31mAdd it first.\e[0m%11c",186,186);
        gotoxy(45,13);
        elines(30);
        sleep(2);
        return;
    }
    gotoxy(22,8);
    printf("Enter for %s",categoryName);
    gotoxy(22,10);
    printf("Enter item name: ");
    gotoxy(40,10);
    scanf(" %[^\n]", name);
    gotoxy(22,12);
    printf("Enter quantity: ");
    gotoxy(38,12);
    scanf("%d", &quantity);
    gotoxy(22,14);
    printf("Enter price: ");
    gotoxy(35,14);
    scanf("%f", &price);
    char cat_name[50];
    strcpy(cat_name,cat1->name);
    Item *newItem = createItem(name, quantity, price,cat_name);
    newItem->next = cat1->items;
    cat1->items = newItem;
    system("cls");
    gotoxy(45,10);
    slines(30);
    gotoxy(45,11);
    printf("%-4c\e[1;32mItem added successfully!\e[0m%4c",186,186);
    gotoxy(45,12);
    elines(30);
    sleep(2);

}

// Add a new category
void addCategory() {
    system("cls");
    showcategories1();
    char name[50];
    case_struct(20,45,9);
    gotoxy(33,14);
    printf("Enter \"0\" to return ");
    gotoxy(22,9);
    printf("Enter new category name: ");
    gotoxy(48,9);
    scanf(" %[^\n]", name);
    if(name[0]=='0'){
        return;
    }
    if (findCategory(name)) {
        gotoxy(45,10);
        slines(30);
        gotoxy(45,11);
        printf("%-4c\e[1;32mCategory already exists.\e[0m%4c",186,186);
        gotoxy(45,12);
        elines(30);
        sleep(2);
        return;
    }
    system("cls");
    createCategory(name);
    gotoxy(45,10);
    slines(30);
    gotoxy(45,11);
    printf("%-2c\e[1;32mCategory added successfully.\e[0m%2c",186,186);
    gotoxy(45,12);
    elines(30);
    sleep(2);
}

// Show all items grouped by category
void showItems() {
    system("cls");
    Category *cat = categories;
    if (!cat) {
        gotoxy(45,10);
        slines(30);
        gotoxy(45,11);
        printf("%-6c\e[1;31mNo categories found.\e[0m%6c",186,186);
        gotoxy(45,12);
        elines(30);
        return;
    }
        int y=3,ext;
        spaces(7);
        slines(98);
        printf("\n");
    while (cat) {
        spaces(7);
        printf("%c                                        category: %-48s%c",186,cat->name,186);
        printf("\n");
        spaces(7);
        mlines(98);
        printf("\n");
        Item *temp = cat->items;
        if (!temp) {
                        spaces(7);
            printf("%-38c\e[1;31mNo items in this category.\e[0m%36c",186,186);
                printf("\n");
            if(cat->next != NULL){
        spaces(7);
            mlines(98);
                    printf("\n");
            }
        }
        while (temp) {
                if(temp->quantity<10){
        spaces(7);
            printf("%c\e[5;41m Name: %-14s | Quantity: %-8d | Price: %-11.2f | Added on: %-22s\e[0m%C",186,
                   temp->name, temp->quantity, temp->price, temp->entryTime,186);
                           printf("\n");
                }
                else{
        spaces(7);
                printf("%c Name: %-14s | Quantity: %-8d | Price: %-11.2f | Added on: %-22s%C",186,
                   temp->name, temp->quantity, temp->price, temp->entryTime,186);
                           printf("\n");
                }

                if (temp->next != NULL){
        spaces(7);
                    dashes_vline(97);
                            printf("\n");
                }
                else{
                        if(cat->next != NULL){
        spaces(7);
                    mlines(98);
                            printf("\n");
                    }
                }
                 temp = temp->next;
        }
        cat = cat->next;
    }
        spaces(7);
    elines(98);
            printf("\n");
        spaces(7);
    printf("Enter \"0\" to return ");
    scanf("%d",&ext);
    if(ext==0){
        return;
    }
    else return;
}

// Show all items by low stock
void showlowItem() {
    system("cls");
    Category *cat = categories;
    if (!cat) {
        gotoxy(45,10);
        slines(30);
        gotoxy(45,11);
        printf("%-6c\e[1;31mNo categories found.\e[0m%6c",186,186);
        gotoxy(45,12);
        elines(30);
        return;
    }
        int y=3,ext;
        spaces(7);
        slines(98);
        printf("\n");
    while (cat) {
        spaces(7);
        printf("%c                                        category: %-48s%c",186,cat->name,186);
        printf("\n");
        spaces(7);
        mlines(98);
        printf("\n");
        Item *temp = cat->items;
        if (!temp) {
            spaces(7);
            printf("%-38c\e[2;31mNo items in this category.\e[0m%36c",186,186);
            printf("\n");
            if(cat->next != NULL){
            spaces(7);
            mlines(98);
            printf("\n");
            }
        }
        while (temp) {
                if(temp->quantity<10){
            spaces(7);
            printf("%c Name: %-14s | Quantity: %-8d | Price: %-11.2f | Added on: %-22s%C",186,
                   temp->name, temp->quantity, temp->price, temp->entryTime,186);
                        printf("\n");
                    if (temp->next != NULL){
                        spaces(7);
                        dashes_vline(97);
                        printf("\n");
                    }
                    else{
                            if(cat->next != NULL){
                        spaces(7);
                        mlines(98);
                        printf("\n");
                        }
                    }
                }
//                if (temp->next != NULL){
//                    spaces(7);
//                    dashes_vline(97);
//                    printf("\n");
//                }
//                else{
//                        if(cat->next != NULL){
//                    spaces(7);
//                    mlines(98);
//                    printf("\n");
//                    }
//                }
                 temp = temp->next;
        }
        cat = cat->next;
    }
    spaces(7);
    elines(98);
    printf("\n");
    spaces(7);
    printf("Enter \"0\" to return ");
    scanf("%d",&ext);
    if(ext==0){
        return;
    }
    else return;
}




// Search item by name and category
void searchItem() {
    system("cls");
    char name[50], categoryName[50];
    int arridx_count,ext;
    case_struct(20,45,6);
    gotoxy(34,11);
    printf("Enter \"0\" to return ");
    showcategories();
    gotoxy(22,7);
    printf("Select the category:");
    gotoxy(43,7);
    scanf("%d",&arridx_count);
    if(arridx_count==0){
        menu();
    }
    int arr_idx=arr_element;
    int arr_idx1=arr_element;
    int arrsize=++arr_idx;
    if(arridx_count<=arrsize&&arridx_count>=1){
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
    gotoxy(22,9);
    printf("Enter item name to search:");
    gotoxy(49,9);
    scanf(" %[^\n]", name);

    Category *cat = findCategory(categoryName);
    if (!cat) {
        system("cls");
        gotoxy(45,10);
        slines(30);
        gotoxy(45,11);
        printf("%-6c\e[1;31mNo categories found.\e[0m%6c",186,186);
        gotoxy(45,12);
        elines(30);
        sleep(2);
        return;
    }
    Item *temp = cat->items;
    while (temp) {
        if (strcasecmp(temp->name, name) == 0) {
            system("cls");
            case_struct(40,45,13);
            gotoxy(42,6);
            printf("Category: %s",temp->chatagories);
            gotoxy(42,8);
            printf("Item name: %s",temp->name);
            gotoxy(42,10);
            printf("Quantity: %d",temp->quantity);
            gotoxy(42,12);
            printf("Per unit price: %.2f",temp->price);
            gotoxy(42,14);
            printf("Product In time: %s",temp->entryTime);
            if(temp->quantity<10){
            gotoxy(58,16);
            printf("\e[5;41m LOW STOCK \e[0m");
            }
            gotoxy(41,20);
            printf("Enter \"0\" to return ");
            scanf("%d",&ext);
            if(ext==0){
                return;
            }
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

//search by category.....
void searchcategory() {
    system("cls");
    int ext;
    char name[50], categoryName[50];
    int arridx_count,y=3;
    case_struct(20,45,6);
    gotoxy(34,11);
    printf("Enter \"0\" to return ");
    showcategories();
    gotoxy(22,7);
    printf("Select the category:");
    gotoxy(43,7);
    scanf("%d",&arridx_count);
    if(arridx_count==0){
        return;
    }
    int arr_idx=arr_element;
    int arr_idx1=arr_element;
    int arrsize=++arr_idx;
    if(arridx_count<=arrsize&&arridx_count>=1){
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
    }

    Category *cat = findCategory(categoryName);
    if (!cat) {
        system("cls");
        gotoxy(45,10);
        slines(30);
        gotoxy(45,11);
        printf("%-6c\e[1;31mNo categories found.\e[0m%6c",186,186);
        gotoxy(45,12);
        elines(30);
        return;
    }
        system("cls");
        spaces(7);
        slines(98);
        printf("\n");
        spaces(7);
        printf("%c                                        category: %-48s%c",186,cat->name,186);
        printf("\n");
        spaces(7);
        mlines(98);
        printf("\n");
        Item *temp = cat->items;
        if (!temp) {
            spaces(7);
            printf("%-38c\e[1;31mNo items in this category.\e[0m%36c",186,186);
            printf("\n");
            if(cat->next != NULL){
            spaces(7);
            mlines(98);
            printf("\n");
            }
        }
        while (temp) {
                spaces(7);
                printf("%c Name: %-14s | Quantity: %-8d | Price: %-11.2f | Added on: %-22s%C",186,
                   temp->name, temp->quantity, temp->price, temp->entryTime,186);
                printf("\n");
                if (temp->next != NULL){
                    spaces(7);
                    dashes_vline(97);
                    printf("\n");
                }
                else{
                        if(cat->next != NULL){
                    spaces(7);
                    mlines(98);
                    printf("\n");
                    }
                }
                 temp = temp->next;
        }
        spaces(7);
        elines(98);
        printf("\n");
        spaces(7);
    printf("Enter \"0\" to return ");
    scanf("%d",&ext);
    if(ext==0){
        return;
    }
    else return;
}

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
    if(arridx_count<=arrsize&&arridx_count>=1){
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

// Remove a category
void removeCategory() {
        system("cls");
    showcategories1();
    char categoryName[50];
    case_struct(20,45,9);
    gotoxy(33,14);
    printf("Enter \"0\" to return ");
    gotoxy(22,9);
    printf("Enter category name to remove:");
    gotoxy(53,9);
    scanf(" %[^\n]", categoryName);
    if(categoryName[0]=='0'){
        return;
    }
    int arr_idx_copy=arr_element;
    int arr_size=arr_idx_copy;
    int idx;
    for (int i = 0; i < arr_size; i++) {
        if (strcasecmp(cat_arr[i], categoryName) == 0) {
            idx= i;
            break;
        }
    }
    for (int i = idx; i < arr_size ; i++) {
            strcpy(cat_arr[i],cat_arr[i + 1]);
    }
    arr_element--;

    Category *prev = NULL, *temp = categories;
    while (temp) {
        if (strcasecmp(temp->name, categoryName) == 0) {
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
            system("cls");
            gotoxy(45,10);
            slines(33);
            gotoxy(45,11);
            printf("%-2c\e[1;32mCategory and its items removed.\e[0m%2c",186,186);
            gotoxy(45,12);
            elines(33);
            sleep(2);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
        system("cls");
        gotoxy(45,10);
        slines(30);
        gotoxy(45,11);
        printf("%-7c\e[1;31mCategory not found.\e[0m%6c",186,186);
        gotoxy(45,12);
        elines(30);
        sleep(2);
}

// Delete item
void deleteItem() {
    system("cls");
    char name[50], categoryName[50];
    int quantity,arridx_count;
    float price;
    case_struct(20,45,6);
    gotoxy(34,11);
    printf("Enter \"0\" to return ");
    showcategories();
    gotoxy(22,7);
    printf("Select the category:");
    gotoxy(43,7);
    scanf("%d",&arridx_count);
    if(arridx_count==0){
        return;
    }
    int arr_idx=arr_element;
    int arr_idx1=arr_element;
    int arrsize=++arr_idx;
    if(arridx_count<=arrsize&&arridx_count>=1){
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
    }
    gotoxy(22,9);
    printf("Enter item name to delete:");
    gotoxy(49,9);
    scanf(" %[^\n]", name);

    Category *cat = findCategory(categoryName);
    if (!cat) {
        system("cls");
        gotoxy(45,10);
        slines(30);
        gotoxy(45,11);
        printf("%-7c\e[1;31mCategory not found.\e[0m%6c",186,186);
        gotoxy(45,12);
        elines(30);
        sleep(2);
        return;
    }

    Item *temp = cat->items, *prev = NULL;
    while (temp) {
        if (strcasecmp(temp->name, name) == 0) {
            if (prev) prev->next = temp->next;
            else cat->items = temp->next;
            free(temp);
            system("cls");
            gotoxy(45,10);
            slines(30);
            gotoxy(45,11);
            printf("%-9c\e[1;32mItem deleted.\e[0m%10c",186,186);
            gotoxy(45,12);
            elines(30);
            sleep(2);
            return;
        }
        prev = temp;
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


// Save data to file
void saveToFile() {
    Category *cat = categories;
    FILE *file = fopen("category.dat", "wb");
        if (!file)
        {
            gotoxy(45,4);
            slines(36);
            gotoxy(45,5);
            printf("%-2c\e[1;31mError opening file for saving data\e[0m%2c",186,186);
            gotoxy(45,6);
            elines(36);
            sleep(2);
            return;
        }
    while (cat) {

        // Save category name....
        fwrite(cat->name, sizeof(cat->name), 1, file);
        cat = cat->next;
        }
        fclose(file);

    // to save the items......
    Category *cat2 = categories;
    FILE *file1= fopen("item.dat", "wb");
    while (cat2)
    {
        // Save items separetly...
        Item *item = cat2->items;
        while (item)
        {
            fwrite(item, sizeof(Item), 1, file);
            item = item->next;
        }
        cat2 = cat2->next;
    }
    fclose(file1);
}

//load all the data....
void loadFromFile() {
    FILE *file = fopen("category.dat", "rb");
    if (!file)
    {
        return;
    }
    char catName[50];
    while (fread(catName, sizeof(catName), 1, file)) {
        // Create new category
        createCategory(catName);
    }
        fclose(file);

    //load item file.....
    FILE *file1= fopen("item.dat", "rb");
        Item tempItem;
        while (fread(&tempItem, sizeof(Item) , 1, file)) {
            if (strlen(tempItem.name) == 0) break;
            // Create new item and add to category
        Category *cat1 = findCategory(tempItem.chatagories);
        if (!cat1)
        {
            system("cls");
            gotoxy(45,10);
            slines(30);
            gotoxy(45,11);
            printf("%-7c\e[1;31mCategory not found.\e[0m%6c",186,186);
            gotoxy(45,12);
            printf("%-8c\e[1;31mAdd it first.\e[0m%11c",186,186);
            gotoxy(45,13);
            elines(30);
            sleep(2);
            return;
        }
            Item *newItem = createItem(tempItem.name, tempItem.quantity, tempItem.price,tempItem.chatagories);
            strcpy(newItem->entryTime, tempItem.entryTime);
            newItem->next = cat1->items;
            cat1->items = newItem;
        }
    fclose(file1);
}


// function to add all data....
void add_page(){
    sleep(1);
     int choice;
        do {
                        system("cls");
            case_struct(40,40,18);
            gotoxy(42,7);
            Sleep(100);
            printf("1. Add Category");
            gotoxy(42,9);
            Sleep(100);
            printf("2. Add Product");
            Sleep(100);
            gotoxy(45,23);
            printf("Enter \"0\" to return to the menu" );
            gotoxy(42,20);
            Sleep(100);
            printf("\e[1;32mEnter your choice:\e[0m");
            gotoxy(61,20);
            scanf("%d", &choice);

        switch (choice) {
            case 1: addCategory(); break;
            case 2: addItem(); break;
            case 0: menu(); break;
            default:
                 gotoxy(68,4);
                slines(30);
                gotoxy(68,5);
                printf("%-9c\e[1;31mInvalid choice.\e[0m%8c",186,186);
                gotoxy(68,6);
                elines(30);
        }
    } while (choice != 10);
}


//function to show all data...
void show_page(){
        sleep(1);
     int choice;
        do {
                    system("cls");
            case_struct(40,40,18);
            gotoxy(42,7);
            Sleep(100);
            printf("1. Show all Records");
            gotoxy(42,9);
            Sleep(100);
            printf("2. Show Low Stock");
            gotoxy(42,11);
            Sleep(100);
            printf("3. Show by Category");
            Sleep(100);
            gotoxy(45,23);
            printf("Enter \"0\" to return to the menu" );
            gotoxy(42,20);
            Sleep(100);
            printf("\e[1;32mEnter your choice:\e[0m");
            gotoxy(61,20);
            scanf("%d", &choice);


        switch (choice) {
            case 1: showItems(); break;
            case 2: showlowItem(); break;
            case 3: searchcategory(); break;
            case 0: menu(); break;
            default:
                 gotoxy(68,4);
                slines(30);
                gotoxy(68,5);
                printf("%-9c\e[1;31mInvalid choice.\e[0m%8c",186,186);
                gotoxy(68,6);
                elines(30);
        }
    } while (choice != 10);
}

//deletion ....
void deletion(){
        sleep(1);
     int choice;
        do {
                        system("cls");
            case_struct(40,40,18);
            gotoxy(42,7);
            Sleep(100);
            printf("1. Remove Category");
            gotoxy(42,9);
            Sleep(100);
            printf("2. Remove Product");
            Sleep(100);
            gotoxy(45,23);
            printf("Enter \"0\" to return to the menu" );
            gotoxy(42,20);
            Sleep(100);
            printf("\e[1;32mEnter your choice:\e[0m");
            gotoxy(61,20);
            scanf("%d", &choice);


        switch (choice) {
            case 1: removeCategory(); break;
            case 2: deleteItem(); break;
            case 0: menu(); break;
            default:
                 gotoxy(68,4);
                slines(30);
                gotoxy(68,5);
                printf("%-9c\e[1;31mInvalid choice.\e[0m%8c",186,186);
                gotoxy(68,6);
                elines(30);
        }
    } while (choice != 10);
}




// Main menu
void menu() {
        system("cls");
        sleep(1);
    int choice;
        case_struct(40,40,18);
        gotoxy(42,7);
        Sleep(100);
        printf("1. Add Category And Products");
        gotoxy(42,9);
        Sleep(100);
        printf("2. Display Products");
        gotoxy(42,11);
        Sleep(100);
        printf("3. Search for Specific Product");
        gotoxy(42,13);
        Sleep(100);
        printf("4. Update Product data");
        gotoxy(42,15);
        Sleep(100);
        printf("5. Deletion of Category or Products");
        gotoxy(42,17);
        Sleep(100);
        printf("6. Generate Weekly Report");
        gotoxy(42,19);
        Sleep(100);
        printf("7. Save and Exit the Program");
        gotoxy(42,22);
        Sleep(100);
        printf("\e[1;32mEnter your choice:\e[0m");
        gotoxy(61,22);
        scanf("%d",&choice);

        while(1){
        switch (choice) {
            case 1: add_page(); break;
            case 2: show_page(); break;
            case 3: searchItem(); break;
            case 4: updateItem(); break;
            case 5: deletion(); break;
            case 6: generateWeeklyReport(); break;
            case 7: saveToFile(); generatedailyReport();printf("\n\n\n\n\n\n\n");
exit(0); break;
                 gotoxy(68,4);
                slines(30);
                gotoxy(68,5);
                printf("%-9c\e[1;31mInvalid choice.\e[0m%8c",186,186);
                gotoxy(68,6);
                elines(30);
            }
    }
}

