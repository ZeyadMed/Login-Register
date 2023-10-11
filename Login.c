#include <stdio.h>
#include <string.h>
#include <math.h>

    struct login {

    char fname[100];
    char lname[20];
    char UserName[20];
    char Password[20];

    };

 Register () {
    FILE *log;
    log = fopen ("login5.txt" , "w");
    struct login l;

    printf("Enter first name : ");
    scanf("%s",l.fname);

    printf("Enter Last name : ");
    scanf("%s",l.lname);

    printf("Enter UserName : ");
    scanf("%s",l.UserName);

    printf("Enter Password : ");
    scanf("%s",l.Password);

    fwrite(&l,sizeof(l),1,log);

    fclose(log);

    printf("\n\nyour UserName is UserID\n");
    printf("Now Login with UserID and Password");
    printf("\nPress any button to continue ...");
    getch();
    system("CLS");
    login();

}

login(){

    char UserName[200], Password[20];
    FILE *log;
    log=fopen("login5.txt" , "r");
    struct login l;
    printf("UserID: ");
    scanf("%s" , UserName);
    printf("Password: ");
    scanf("%s" , Password);

    while(fread(&l, sizeof(l), 1, log)){
        if (strcmp (UserName , l.UserName)== 0 && strcmp(Password, l.Password)==0)
        {
            printf("Successfullay Login \n");
        }
        else
        {
            printf("Please Enter correct UserID and Password \n");
        }
    }

   fclose(log);
}

int main(){

    int x;

    printf("Press '1' for Regester \nPress '2' for Login \n");
    scanf("%d" , &x);
    if (x == 1){
        system("CLS");
        Register();
    }
    else if (x==2){
        system("CLS");
        login();
    }

}

