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
    printf(BHCYN" |  __ \\  __ \\/ ______ \\ / ___|_   __/ _____ \\/ _____|| |/ /    "reset);
    gotoxy(30, 5);
    printf(BHCYN" | |) ||)   |    | || (__     | |  | |   | || |     | ' /         "reset);
    gotoxy(30, 6);
    printf(BHCYN" |  __/|  _  / |    | | \\__ \\   | |  | |   | || |     |  <        "reset);
    gotoxy(30, 7);
    printf(BHCYN" | |    | | \\ \\ || | ____)|  | |  | || || |____ | .  \\     "reset);
    gotoxy(30, 8);
    printf(BHCYN" ||    ||  \\\\/ |/   ||  \\/ \\||| \\_\\ "reset);
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
