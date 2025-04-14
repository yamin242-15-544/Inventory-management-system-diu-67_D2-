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
