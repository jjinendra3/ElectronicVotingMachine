/*ELECTRONIC VOTING MACHINE
    PROJECT BY
    JINENDRA JAIN
    LAKSHYA KANDPAL
    NILESH VERMA
    PARTH KHARE*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>
#define MAX_FILE_NAME 100
char ArreyOfPartyName[46][20];
int countRES;
int totalregistrations;
float totalvotes;
int NumberOfParty;
int totalvotesbtech;
int totalvotesbba;
int analysismode80085;
int Credit()
{
    char f;
    system("cls");
    system("cls");
    printf(" \033[0;36m \n");
    printf("********************************************************************************\n");
    printf("*                                CREDITS                                       *\n");
    printf("********************************************************************************\n");
    printf("*                                   *                                          *\n");
    printf("*       NAME                        *         ENROLLEENT   NUMBER              *\n");
    printf("*                                   *                                          *\n");
    printf("********************************************************************************\n");
    printf("*                                   *                                          *\n");
    printf("*       JINENDRA JAIN               *            NJG224365                     *\n");
    printf("*       LAKSHYA KANDPAL             *            NJG221243                     *\n");
    printf("*       NILESH VERMA                *            JEG223027                     *\n");
    printf("*       PARTH KAHRE                 *            NJG226162                     *\n");
    printf("*                                   *                                          *\n");
    printf("********************************************************************************\n");
    printf("\33[0m");
    printf("Enter any key to continue\n");
    getch();
    return 0;
}
// loading
int loading()
{
    int i, j, k, a;

    printf("\n\nPlease wait loading program\n");
    printf("Loading ");

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 4 * 100000000; j++)
        {
            k = 100000 * j;
            if (k == j)
                printf(".");
        }
    }
    system("cls");
    return 0;
}
// loading 2
int Loading2()
{
    int i, j, k, a;

    printf("\n\nLoading");

    for (i = 0; i < 15; i++)
    {
        for (j = 0; j < 100000000; j++)
        {
            k = 100000 * j;
            if (k == j)
                printf(".");
        }
    }
    printf("\n");
    // system("cls");
    return 0;
}
// logo  nw
int logo()
{
    char f;

    printf("\033[1;32m");
    printf(" ________   ____   ____   ____    ____        \n");
    printf("|_   __  | |_  _| |_  _| |_   \\  /   _|      \n");
    printf("  | |_ \\_|   \\ \\   / /     |   \\/   |        \n");
    printf("  |  _| _     \\ \\ / /      | |\\  /| |        \n");
    printf(" _| |__/ |     \\ ' /      _| |_\\/_| |_       \n");
    printf("|________|      \\_/      |_____||_____|      \n");

    for (int i = 0; i < 5; i++)
    {
        printf("\n");
    }

    printf("\033[0m");
    printf("Enter any key to continue\n");
    getch();
    system("cls");

    return 0;
}
int endlogo()
{
    char f;

    printf("\033[1;32m");
    printf("___________ .__                         __        _____.___.                     \n");
    printf("\\__    ___/ |  |__   _____      ____   |  | __    \\__  |   |   ____    __ __      \n");
    printf("  |    |    |  |  \\  \\__  \\    /    \\  |  |/ /     /   |   |  /  _ \\  |  |  \\      \n");
    printf("  |    |    |   Y  \\  / __ \\_ |   |  \\ |    <      \\____   | (  <_> ) |  |  /         \n");
    printf("  |____|    |___|  / (____  / |___|  / |__|_ \\     / ______|  \\____/  |____/ \n");
    printf("                 \\/       \\/       \\/       \\/     \\/                        \n");

    for (int i = 0; i < 5; i++)
    {
        printf("\n");
    }

    printf("\033[0m");
    printf("Enter any key to continue\n");
    getch();
    system("cls");

    return 0;
}
// return true if the file specified by the filename exists
bool file_exists(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    bool is_exist = false;
    if (fp == NULL)
    {
        is_exist = true;
        fclose(fp);
        // close the file
    }
    return is_exist;
}
int makeEnroller()
{
    FILE *ptr = fopen("EnrollmentVerificationFile.txt", "a+");
    fputs("\n", ptr);
    fclose(ptr);
    return 0;
}
int no_party()
{
    FILE *fPtr;
    int count = 0;
    char enrollmentVerificationFile[MAX_FILE_NAME];
    char c;

    fPtr = fopen("allpartyname.txt", "r");

    for (c = getc(fPtr); c != EOF; c = getc(fPtr))
    {
        if (c == '\n')
            count++;
    }
    fclose(fPtr);
    NumberOfParty = count;
    return count;
}
int Unique_party(char p_name[20])
{

    FILE *fPtr;
    fPtr = fopen("allpartyname.txt", "r+");
    char temp[20];
    int count = 0;
    while (fgets(temp, 21, fPtr))
    {
        // printf("%s %d",temp,strlen(temp));
        if (strcmp(temp, p_name) == 0)
        {
            fclose(fPtr);
            return 1;
        }
    }
    fclose(fPtr);
    return 0;
}
int file_arrey()
{

    FILE *fPtr;
    fPtr = fopen("allpartyname.txt", "r");

    char temp[20];
    int count = 0;
    int j = 0;
    while (fgets(temp, 20, fPtr))
    {
        strcpy(ArreyOfPartyName[j++], temp);
    }
    for (int i = 0; i < NumberOfParty; i++)
    {
        strcpy(ArreyOfPartyName[i], ArreyOfPartyName[i * 2]);
    }

    return 0;
}
int UniquenessCheckForEnrollmentNumber(char stringinput[15])
{

    FILE *pointerforuniquecheck;
    pointerforuniquecheck = fopen("EnrollmentVerificationFile.txt", "r+");
    char linereadvariable[9];
    int count = 0;
    while (fgets(linereadvariable, 10, pointerforuniquecheck))
    {

        if (strcmp(linereadvariable, stringinput) == 0)
        {
            fclose(pointerforuniquecheck);
            return 1;
        }
    }
    fclose(pointerforuniquecheck);
    return 0;
}
int total_registrartions()
{
    FILE *ptr = fopen("totalreg.txt", "r");
    char ch;
    totalregistrations = 0;
    ch = fgetc(ptr);
    while (ch != EOF)
    {
        ch = fgetc(ptr);
        totalregistrations++;
    }
    return totalregistrations;
}
int total_votes()
{
    FILE *ptr = fopen("ALLVOTES.txt", "r");
    char ch;
    totalvotes = 0;
    ch = fgetc(ptr);
    while (ch != EOF)
    {
        ch = fgetc(ptr);
        totalvotes++;
    }
    fclose(ptr);
    return totalvotes;
}
int total_btechvotes()
{
    FILE *ptr = fopen("totalbtechvotes.txt", "r");
    char ch;
    totalvotesbtech = 0;
    ch = fgetc(ptr);
    while (ch != EOF)
    {
        ch = fgetc(ptr);
        totalvotesbtech++;
    }
    fclose(ptr);
    return totalvotesbtech;
}
int total_bbavotes()
{
    FILE *ptr = fopen("VoteInEVMBBAVOTESIDK.txt", "r");
    char ch;
    totalvotesbba = 0;
    ch = fgetc(ptr);
    while (ch != EOF)
    {
        ch = fgetc(ptr);
        totalvotesbba++;
    }
    return totalvotesbba;
}
int UniquenessCheckForEnrollmentNumberBTECH(char stringinput[15])
{

    FILE *pointerforuniquecheck;
    pointerforuniquecheck = fopen("EnrollmentVerificationFileBTECH.txt", "r+");
    char linereadvariable[9];
    int count = 0;
    while (fgets(linereadvariable, 10, pointerforuniquecheck))
    {

        if (strcmp(linereadvariable, stringinput) == 0)
        {
            fclose(pointerforuniquecheck);
            return 1;
        }
    }
    fclose(pointerforuniquecheck);
    return 0;
}
int UniquenessCheckForEnrollmentNumberBBA(char stringinput[15])
{

    FILE *pointerforuniquecheck;
    pointerforuniquecheck = fopen("EnrollmentVerificationFileBBA.txt", "r+");
    char linereadvariable[9];
    int count = 0;
    while (fgets(linereadvariable, 10, pointerforuniquecheck))
    {

        if (strcmp(linereadvariable, stringinput) == 0)
        {
            fclose(pointerforuniquecheck);
            return 1;
        }
    }
    fclose(pointerforuniquecheck);
    return 0;
}
int UniquenessCheckforreverificationBTECH(char stringinput[15])
{

    FILE *pointerforuniquecheck;
    pointerforuniquecheck = fopen("ReverificationEnrollmentVerificationFileBTECH.txt", "r+");
    char linereadvariable[9];
    int count = 0;
    while (fgets(linereadvariable, 10, pointerforuniquecheck))
    {

        if (strcmp(linereadvariable, stringinput) == 0)
        {
            fclose(pointerforuniquecheck);
            return 1;
        }
    }
    fclose(pointerforuniquecheck);
    return 0;
}
int UniquenessCheckforreverificationBBA(char stringinput[15])
{

    FILE *pointerforuniquecheck;
    pointerforuniquecheck = fopen("ReverificationEnrollmentVerificationFileBBA.txt", "r+");
    char linereadvariable[9];
    int count = 0;
    while (fgets(linereadvariable, 10, pointerforuniquecheck))
    {

        if (strcmp(linereadvariable, stringinput) == 0)
        {
            fclose(pointerforuniquecheck);
            return 1;
        }
    }
    fclose(pointerforuniquecheck);
    return 0;
}

int UniquenessCheckforreverification(char stringinput[15])
{

    FILE *pointerforuniquecheck;
    pointerforuniquecheck = fopen("ReverificationEnrollmentVerificationFile.txt", "r+");
    char linereadvariable[9];
    int count = 0;
    while (fgets(linereadvariable, 10, pointerforuniquecheck))
    {

        if (strcmp(linereadvariable, stringinput) == 0)
        {
            fclose(pointerforuniquecheck);
            return 1;
        }
    }
    fclose(pointerforuniquecheck);
    return 0;
}
int MainMenuText(void)
{
    printf("\033[1;32m");
    printf("********************************************************************************\n");
    printf("*                                                                              *\n");
    printf("*                              MAIN MENU                                       *\n");
    printf("*                                                                              *\n");
    printf("********************************************************************************\n");
    printf("*                                                                              *\n");
    printf("*                           1. Voters Registraion                              *\n");
    printf("*                           2. Party Registraion                               *\n");
    printf("*                           3. Vote                                            *\n");
    printf("*                           4. Result                                          *\n");
    printf("*                           5. Credits                                         *\n");
    printf("*                           6. Exit                                            *\n");
    printf("*                                                                              *\n");
    printf("********************************************************************************\n");
    printf("\033[0m");
    printf("Enter a choice :");
    int value;
    scanf("%d", &value);

    return value;
}

int main()
{
    system("cls");
    logo();
    loading();

    if (file_exists("EnrollmentVerificationFile.txt"))
        makeEnroller();
    total_registrartions();
    total_votes();
    no_party();
    file_arrey();
MainMenuTextLabel:
    printf("");
    int mainMenuOption;
    mainMenuOption = MainMenuText();
    // scanf("%d", &mainMenuOption);
    if (mainMenuOption == 5)
    {
        Credit();
        printf("\n");
        Loading2();
        system("cls");
        goto MainMenuTextLabel;
    }

    else if (mainMenuOption == 6)
    {
        Loading2();
        goto end;
    }
    else if (mainMenuOption == 1)
    {
        system("cls");
        Loading2();
        system("cls");
        char aa[1];
        gets(aa);
        int flag = 1;
        int serial = 101;
        int count = 0;
        char studreg[6][45];
        char enroll[10];
        int x;
        FILE *ptr = NULL;
        ptr = fopen("student_details.txt", "a+");
        while (flag == 1)
        {
            printf("\033[1;32m");
            printf("\nPlease enter your enrollment ID: ");
            printf("\033[0m");
            gets(enroll);
            if (!(strcmp("#", enroll)))
            {
                system("cls");
                goto MainMenuTextLabel;
            }
            strcpy(studreg[0], enroll);
            if (!(strcmp(enroll, "Q")))
            {
                flag = 0;
                system("cls");
                goto MainMenuTextLabel;
            }
            FILE *pointerforuniquecheck;
            pointerforuniquecheck = fopen("EnrollmentVerificationFile.txt", "r");
            char linereadvariable[9];
            char stringinput[15];
            strcpy(stringinput, enroll);
            int count = 0;
            while (fgets(linereadvariable, 10, pointerforuniquecheck))
            {

                if (strcmp(linereadvariable, stringinput) == 0)
                {
                    fclose(pointerforuniquecheck);
                    x = 1;
                }
                else
                {
                    x = 0;
                }
            }
            fclose(pointerforuniquecheck);

            if (x == 0)
            {
                FILE *pointerfordataentryintextfile;
                pointerfordataentryintextfile = fopen("EnrollmentVerificationFile.txt", "a+");
                fprintf(pointerfordataentryintextfile, "%s\n", studreg);
                fclose(pointerfordataentryintextfile);
            }

            else
            {
                printf("\033[1;31m");
                printf("The Enrollment Number has been registered already!\n");
                printf("\033[0m");
                continue;
            }
            printf("\033[1;32m");
            printf("Enter your name: ");
            printf("\033[0m");
            gets( studreg[1]);
            // printf("\n");
            printf("\033[1;32m");
            printf("Enter your gender: ");
            printf("\033[0m");
            gets(studreg[2]);
            // printf("\n");
            printf("\033[1;32m");
            printf("Enter your year: ");
            printf("\033[0m");
            gets(studreg[3]);
            // printf("\n");
            printf("\033[1;32m");
            printf("BTECH or BBA?:");
            printf("\033[0m");
            gets(studreg[4]);
            // printf("\n");
            if (!(strcmp(studreg[4], "BTECH")))
            {
                printf("\033[1;32m");
                printf("Enter your Branch:");
                printf("\033[0m");
                gets(studreg[5]);
                // printf("\n");
                printf("\033[1;31m");
                printf("THANK YOU! Enrollment no. %s has been registered succesfully.\n\n", studreg[0]);
                printf("\033[0m");
                countRES++;
                for (int i = 0; i < 6; i++)
                {

                    fprintf(ptr, "%s\t", studreg[i]);
                }
                fprintf(ptr, "\n");
                FILE *pointerforuniquecheck;
                pointerforuniquecheck = fopen("EnrollmentVerificationFileBTECH.txt", "a+");
                FILE *BTECHptr = fopen("VoteInEVMBTECH", "a+");

                fprintf(BTECHptr, "%s\n", studreg[0]);
                fprintf(pointerforuniquecheck, "%s\n", studreg[0]);
                fclose(BTECHptr);
                fclose(pointerforuniquecheck);
            }
            else if (!(strcmp(studreg[4], "BBA")))
            {
                printf("\033[1;31m");
                printf("THANK YOU!\n Enrollment no. %s has been registered succesfully.\n\n", studreg[0]);
                printf("\033[0m");
                countRES++;
                for (int i = 0; i < 5; i++)
                {
                    fprintf(ptr, "%s\t", studreg[i]);
                }
                fprintf(ptr, "\n");
                FILE *BBAptr = fopen("VoteInEVMBBA", "a+");
                fprintf(BBAptr, "%s\n", studreg[0]);

                fclose(BBAptr);
                FILE *pointerforuniquecheck;
                pointerforuniquecheck = fopen("EnrollmentVerificationFileBBA.txt", "a+");
                fprintf(pointerforuniquecheck, "%s\n", studreg[0]);
                fclose(pointerforuniquecheck);
            }
            FILE *toto = fopen("totalreg.txt", "a+");
            fprintf(ptr, "\n");
            fprintf(toto, "#");
        }
        printf("xxxQUITxxx");
        fclose(ptr);
    }
    else if (mainMenuOption == 2)
    {
        system("cls");
        Loading2();
        system("cls");
        int quit = 0;
        char p_name[50], c1_name[50], c2_name[50], temp[1];
        gets(temp);
        while (quit != 1)
        {
            printf("\033[1;32m");
            printf("Enter the name of your party\n");
            printf("\033[0m");
            gets(p_name);
            if (!(strcmp("#", p_name)))
            {
                system("cls");
                goto MainMenuTextLabel;
            }
            // scanf("%s",&p_name);
            if (!(strcmp(p_name, "Q")))
            {
                printf("\033[1;32m");
                printf("all registation successfull\n");
                printf("\033[0m");
                NumberOfParty = no_party();
                file_arrey();
                goto MainMenuTextLabel;
            }
            int p_l = strlen(p_name);
            for (int i = 1; i <= (20 - p_l); i++)
                strcat(p_name, " ");
            int qwe = Unique_party(p_name);

            // printf("%d",qwe);
            if (qwe != 0)
            {
                printf("\033[1;31m");
                printf("\nParty name already used\n");
                printf("\033[0m");
            }
            else
            {
                printf("\033[1;32m");
                printf("Enter the name of candidate for B.Tech president\n");
                printf("\033[0m");
                // scanf("%s",&c1_name);

                gets(c1_name);
                printf("\033[1;32m");
                printf("Enter the name of candidate for B.B.A president\n");
                printf("\033[0m");
                // scanf("%s",&c2_name);
                gets(c2_name);
                FILE *fPtr = NULL;

                int c1_l = strlen(c1_name);
                int c2_l = strlen(c2_name);

                for (int i = 1; i <= (20 - c1_l); i++)
                    strcat(c1_name, " ");
                for (int i = 1; i <= (20 - c2_l); i++)
                    strcat(c2_name, " ");

                fPtr = fopen("allpartydetails.txt", "a+");
                fputs("\n", fPtr);
                fputs(p_name, fPtr);
                fputs("\t", fPtr);
                fputs(c1_name, fPtr);
                fputs("\t", fPtr);
                fputs(c2_name, fPtr);
                fclose(fPtr);
                fPtr = fopen("allpartyname.txt", "a++");
                fputs(p_name, fPtr);
                fputs("\n", fPtr);
                fclose(fPtr);
                fPtr = fopen("allbtech.txt", "a+");
                fputs(c1_name, fPtr);
                fputs("\n", fPtr);
                fclose(fPtr);
                fPtr = fopen("allbba.txt", "a+");
                fputs(c2_name, fPtr);
                fputs("\n", fPtr);

                fclose(fPtr);
            }
        }
    }
    else if (mainMenuOption == 3)
    {
        system("cls");
        Loading2();
        system("cls");
        while (1)
        {
            char InputStringEnrollmentNumber[15];
            printf("\033[1;32m");
            printf("Enter your enrollment number :");
            printf("\033[0m");
            scanf("%s", &InputStringEnrollmentNumber);
            if (!(strcmp("#", InputStringEnrollmentNumber)))
            {
                system("cls");
                goto MainMenuTextLabel;
            }

            int x = UniquenessCheckForEnrollmentNumber(InputStringEnrollmentNumber);
            if (x != 0)
            {

                int BTECH = UniquenessCheckForEnrollmentNumberBTECH(InputStringEnrollmentNumber);
                if (BTECH != 0)
                {

                    int y = UniquenessCheckforreverificationBTECH(InputStringEnrollmentNumber);

                    if (y == 0)
                    {
                        FILE *pointerfordataentryintextfilereverificationBTECH;

                        pointerfordataentryintextfilereverificationBTECH = fopen("ReverificationEnrollmentVerificationFileBTECH.txt", "a");

                        fprintf(pointerfordataentryintextfilereverificationBTECH, "%s\n", InputStringEnrollmentNumber);

                        fclose(pointerfordataentryintextfilereverificationBTECH);

                        FILE *pointerfordataentryintextfileBTECH;

                        pointerfordataentryintextfileBTECH = fopen("VoteInEVMBTECH.txt", "r");

                        fprintf(pointerfordataentryintextfileBTECH, "%s = ", InputStringEnrollmentNumber);

                        fclose(pointerfordataentryintextfileBTECH);
                        no_party();
                        file_arrey();
                        // printf("%d",NumberOfParty);

                        for (int i = 0; i < NumberOfParty; i++)
                        {

                            printf("Enter %c: for %s \n", 65 + i, ArreyOfPartyName[i]);
                        }

                        printf("\033[1;32m");
                        printf("Enter choice your choice \n");
                        printf("\033[0m");
                        char VoteEntry[1];

                        scanf("%s", &VoteEntry);

                        FILE *pointerfordataentryintextfilechoiceBTECH;
                        FILE *pointerfordataentryintextfilechoice = fopen("ALLVOTES.txt", "a+");
                        pointerfordataentryintextfilechoiceBTECH = fopen("VoteInEVMBTECHvotes.txt", "a+");

                        fprintf(pointerfordataentryintextfilechoiceBTECH, "%s", VoteEntry);
                        fprintf(pointerfordataentryintextfilechoice, "%s", VoteEntry);
                        FILE *btechvoters = fopen("totalbtechvotes.txt", "a+");
                        fprintf(btechvoters, "#");
                        fclose(btechvoters);
                        fclose(pointerfordataentryintextfilechoiceBTECH);
                        fclose(pointerfordataentryintextfilechoice);
                        printf("\033[1;32m");
                        printf("Vote casted successfully.\n");
                        printf("\033[0m");
                    }

                    else if (y == 1)
                    {
                        int BBA = UniquenessCheckForEnrollmentNumberBBA(InputStringEnrollmentNumber);
                        if (BBA != 0)
                        {

                            int z = UniquenessCheckforreverificationBBA(InputStringEnrollmentNumber);

                            if (z == 0)
                            {
                                FILE *pointerfordataentryintextfilereverificationBBA;

                                pointerfordataentryintextfilereverificationBBA = fopen("ReverificationEnrollmentVerificationFileBBA.txt", "a");

                                fprintf(pointerfordataentryintextfilereverificationBBA, "%s\n", InputStringEnrollmentNumber);

                                fclose(pointerfordataentryintextfilereverificationBBA);

                                FILE *pointerfordataentryintextfileBBA;

                                pointerfordataentryintextfileBBA = fopen("VoteInEVMBBA.txt", "r");

                                fprintf(pointerfordataentryintextfileBBA, "%s = ", InputStringEnrollmentNumber);

                                fclose(pointerfordataentryintextfileBBA);
                                no_party();
                                file_arrey();
                                // printf("%d",NumberOfParty);
                                for (int i = 0; i < NumberOfParty; i++)
                                {
                                    printf("Enter %c: for %s \n", 65 + i, ArreyOfPartyName[i]);
                                }
                                printf("Enter choice your choice \n");

                                char VoteEntry[1];

                                scanf("%s", &VoteEntry);

                                FILE *pointerfordataentryintextfilechoiceBBA;

                                pointerfordataentryintextfilechoiceBBA = fopen("VoteInEVMBBAvotes.txt", "a+");
                                fprintf(pointerfordataentryintextfilechoiceBBA, "%s", VoteEntry);

                                fclose(pointerfordataentryintextfilechoiceBBA);
                                printf("\033[1;32m");
                                printf("Vote casted successfully.\n");
                                printf("\033[0m");
                            }

                            else if (z == 1)
                            {
                                printf("\033[1;31m");
                                printf("You already voted.\n");
                                printf("\033[0m");
                            }
                        }
                        else
                        {
                            printf("\033[1;31m");
                            printf("You already voted\n");
                            printf("\033[0m");
                        }
                    }
                }
                else
                {
                    int BBA = UniquenessCheckForEnrollmentNumberBBA(InputStringEnrollmentNumber);
                    if (BBA != 0)
                    {

                        int z = UniquenessCheckforreverificationBBA(InputStringEnrollmentNumber);

                        if (z == 0)
                        {
                            FILE *pointerfordataentryintextfilereverificationBBA;

                            pointerfordataentryintextfilereverificationBBA = fopen("ReverificationEnrollmentVerificationFileBBA.txt", "a");

                            fprintf(pointerfordataentryintextfilereverificationBBA, "%s\n", InputStringEnrollmentNumber);

                            fclose(pointerfordataentryintextfilereverificationBBA);

                            FILE *pointerfordataentryintextfileBBA;

                            pointerfordataentryintextfileBBA = fopen("VoteInEVMBBA.txt", "r");

                            fprintf(pointerfordataentryintextfileBBA, "%s = ", InputStringEnrollmentNumber);

                            fclose(pointerfordataentryintextfileBBA);
                            no_party();
                            file_arrey();
                            // printf("%d",NumberOfParty);
                            for (int i = 0; i < NumberOfParty; i++)
                            {
                                printf("Enter %c: for %s \n", 65 + i, ArreyOfPartyName[i]);
                            }
                            printf("\033[1;32m");
                            printf("Enter choice your choice \n");
                            printf("\033[0m");
                            char VoteEntry[1];

                            scanf("%s", &VoteEntry);

                            FILE *pointerfordataentryintextfilechoiceBBA;
                            FILE *pointerfordataentryintextfilechoiceoldie = fopen("ALLVOTES.txt", "a+");
                            fprintf(pointerfordataentryintextfilechoiceoldie, "%s", VoteEntry);

                            pointerfordataentryintextfilechoiceBBA = fopen("VoteInEVMBBAVOTESIDK.txt", "a");

                            fprintf(pointerfordataentryintextfilechoiceBBA, "%s", VoteEntry);

                            fclose(pointerfordataentryintextfilechoiceBBA);

                            fclose(pointerfordataentryintextfilechoiceoldie);
                            FILE *bbavoters = fopen("totalbbavotes.txt", "a+");
                            fprintf(bbavoters, "#");
                            fclose(bbavoters);
                            printf("\033[1;32m");
                            printf("Vote casted successfully.\n");
                            printf("\033[0m");
                        }

                        else if (z == 1)
                        {
                            printf("\033[1;31m");
                            printf("You already voted.\n");
                            printf("\033[0m");
                        }
                    }
                    else
                    {
                        printf("\033[1;31m");
                        printf("You already voted\n");
                        printf("\033[0m");
                    }
                }
            }
            else
            {
                printf("\033[1;31m");
                printf("The enrollment number is not registered\n");
                printf("\033[0m");
            }
        }
    }
    else if (mainMenuOption == 4)
    {
        system("cls");
        char a[40];
        char b[40];
        char c[40];
        char d[40];
        int check = 0;

        char names[4][10] = {"Jinendra", "Lakshya", "Parth", "Nilesh"};
        int count = 0;
        int k = 0;
        char user[4][20] = {"jjinendra3", "h", "parth000", "Nilesh"};
        char pass[4][20] = {"jjinendra3", "h", "parth000", "2004"};
        char input[10];
        int counter = 0;
        printf("Please Enter your username:");
        scanf("%s", &input);
        int i = 0;
        for (i = 0; i < 4; i++)
        {
            if (!(strcmp(user[i], input)))
            {
                counter = 1;
                break;
            }
        }
        char passs[10];
        printf("Please enter your password:");
        scanf("%s", &passs);
        if (!(strcmp(pass[i], passs)))
        {
            count = 4;
        }
        else
        {
            return 0;
        }
        system("cls");
        if (count == 4)
        {
            system("cls");
            Loading2();
            system("cls");
            printf("\n\nWelcome %s, Here are the results: \n \n", names[i]);
            int totalregistrations = total_registrartions();
            total_votes();
            int bbavotes = total_bbavotes();
            int btechvotes = total_btechvotes();
            int flag = 1;
            while (flag == 1)
            {
                printf("\n");
                int arrforres[26];
                int arrforbtech[26];
                int arrforbba[26];
                char ch;
                int i = 0;
                printf("\033[1;34m");
                printf("\nBTECH\n\n");
                printf("\033[0m");
                for (int i = 0; i < NumberOfParty; i++)
                {
                    int counttotal = 0;
                    int countbba = 0;
                    int countbtech = 0;
                    char chs = i + 65;
                    FILE *ptrresult = fopen("ALLVOTES.txt", "r");
                    FILE *ptrbtech = fopen("VoteInEVMBTECHvotes.txt", "r");
                    FILE *ptrbba = fopen("VoteInEVMBBAVOTESIDK.txt", "r");
                    do
                    {
                        ch = fgetc(ptrresult);
                        if (chs == ch)
                        {
                            counttotal++;
                        }
                    } while (ch != EOF);
                    fclose(ptrresult);
                    do
                    {
                        ch = fgetc(ptrbtech);
                        if (chs == ch)
                        {
                            countbtech++;
                        }
                    } while (ch != EOF);
                    fclose(ptrbtech);
                    do
                    {
                        ch = fgetc(ptrbba);
                        if (chs == ch)
                        {
                            countbba++;
                        }
                    } while (ch != EOF);
                    fclose(ptrbba);
                    arrforres[i] = counttotal;
                    arrforbtech[i] = countbtech;
                    arrforbba[i] = countbba;
                }
                // FOR BTECH START
                for (int i = 0; i < NumberOfParty; i++)
                {
                    if (arrforbtech[i] == 0)
                    {
                        continue;
                    }
                    printf("\033[1;32m");
                    printf("%s:%d\n", ArreyOfPartyName[i], arrforbtech[i]);

                    printf("VOTE PERCENT:%0.2f", (float)arrforbtech[i] * 100 / btechvotes);
                    printf("%c\n\n", 37);
                    printf("\033[0m");
                }
                int max = arrforbtech[0];
                int partyy = 0;
                for (int i = 0; i < NumberOfParty; i++)
                {
                    if (max < arrforbtech[i])
                    {
                        max = arrforbtech[i];
                        partyy = i;
                    }
                }
                printf("\033[1;32m");
                printf("MAX IS %s:%d\n", ArreyOfPartyName[partyy], max);
                printf("PERCENTAGE OF BTECH VOTERS ARE:%f%c\n\n", ((float)totalvotesbtech * 100) / btechvotes, 37);
                printf("\033[0m");
                // FOR BTECH END
                printf("\033[1;34m");
                printf("\n\nBBA\n\n");
                printf("\033[0m");
                // FOR BBA START
                for (int i = 0; i < NumberOfParty; i++)
                {
                    if (arrforbba[i] == 0)
                    {
                        continue;
                    }
                    printf("\033[1;32m");
                    printf("%s:%d\n", ArreyOfPartyName[i], arrforbba[i]);
                }
                int maxbba = arrforbba[0];
                int partyybba = 0;
                for (int i = 0; i < NumberOfParty; i++)
                {
                    if (maxbba < arrforbba[i])
                    {
                        maxbba = arrforbba[i];
                        partyybba = i;
                    }
                }

                printf("MAX IS %s:%d\n", ArreyOfPartyName[partyybba], maxbba);

                printf("\033[0m");
                // FOR BBA END

                // TOTAL TURN OUT AND PARTY WON
                printf("\033[1;34m");
                printf("\n\nTOTAL VOTES IN COLLEGE\n");
                printf("\033[0m");
                printf("\n\n");
                for (int i = 0; i < NumberOfParty; i++)
                {
                    if (arrforres[i] == 0)
                    {
                        continue;
                    }
                    printf("\033[1;32m");
                    printf("%s:%d\n", ArreyOfPartyName[i], arrforres[i]);

                    printf("\033[0m");
                }
                int maxt = arrforres[0];
                int partyyt = 0;
                for (int i = 0; i < NumberOfParty; i++)
                {
                    if (maxt < arrforres[i])
                    {
                        maxt = arrforres[i];
                        partyyt = i;
                    }
                }

                printf("MAX IS %s:%d\n", ArreyOfPartyName[partyyt], maxt);
                printf("\033[0m");
                printf("\n\n\n");

                printf("\n\n Enter any key to continue:\n");
                getch();
                system("cls");
                goto MainMenuTextLabel;
            }
        }
    }
    else
    {
        printf("ENTER A VALID INPUT!\n");
        goto MainMenuTextLabel;
    }

end:
   //system("cls");
    endlogo();
    // printf("xxxxx T H A N K  Y O U xxxxx");
    return 0;
}