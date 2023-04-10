#include<stdio.h>
#include<string.h>
//C Final Project
struct bms{
    int acc_no;
    char names[100];
    char adress[100];
    int phone;
}ad, upd, rem, sr, st[100], temp;

void new_acc(){
    system("cls");
    FILE *fp;
    fp = fopen("record.dat", "a+");
    printf("\n\n\t\xB2\xB2\xB2\xB2\xB2\xB2\ ADD RECORD  \xB2\xB2\xB2\xB2\xB2\xB2");

    printf("\n\tEnter acc_no:.. ");
    scanf("%d", &ad.acc_no);
    printf("\n\tEnter Names:.. ");
    scanf("%s", ad.names);
    printf("\n\tEnter adress:.. ");
    scanf("%s", ad.adress);
    printf("\n\tEnter Phone:.. ");
    scanf("%d", &ad.phone);

    fprintf(fp, "%d\t%s\t%s\t%d\n", ad.acc_no, ad.names, ad.adress, ad.phone);

    fclose(fp);
    printf("\n\tAccount created successfully!\n\n\t");
    system("pause");
}

void view_list(){
    system("cls");
    int test=0;
    FILE *view;
    view= fopen("record.dat", "r");
    printf("\n\n\t\xB2\xB2\xB2\xB2\xB2\xB2\ ALL RECORDS  \xB2\xB2\xB2\xB2\xB2\xB2\n");

    printf("\n\tACC_NO\tNAME\tADRESS\tPHONE\t\xB2\n");
    while(fscanf(view, "%d %s %s %d", &ad.acc_no, ad.names, ad.adress, &ad.phone) !=EOF){
        printf("\t%d\t%s\t%s\t%d\n", ad.acc_no, ad.names, ad.adress, ad.phone);
        test++;
    }
    fclose(view);
    if (test==0){
        system("cls");
        printf("\n\tNO RECORDS!!\n\t");
    }
    printf("\n\t");
    system("pause");
}

void rem_rec(){
    system("cls");
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("\n\n\t\xB2\xB2\xB2\xB2\xB2\xB2\ REMOVE RECORD  \xB2\xB2\xB2\xB2\xB2\xB2");

    printf("\n\tEnter the account no to delete:.. ");
    scanf("%d",&rem.acc_no);
    while (fscanf(old, "%d %s %s %d", &ad.acc_no, ad.names, ad.adress, &ad.phone)!=EOF){
        if(ad.acc_no!=rem.acc_no)
            fprintf(newrec, "%d\t%s\t%s\t%d\n", ad.acc_no, ad.names, ad.adress, ad.phone);
        else{
            test++;
            printf("\n\tRecord deleted successfully!\n\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat", "record.dat");
}

void update(){
    system("cls");
    int choice, test=0;
    FILE *od, *nr;
    od = fopen("record.dat","r");
    nr = fopen("new.dat","w");
    printf("\n\n\t\xB2\xB2\xB2\xB2\xB2\xB2\ UPDATE RECORD  \xB2\xB2\xB2\xB2\xB2\xB2");

    printf("\n\tEnter the account no to change:.. ");
    scanf("%d", &upd.acc_no);
    while(fscanf(od, "%d %s %s %d", &ad.acc_no, ad.names, ad.adress, &ad.phone)!=EOF)
    {
        if (ad.acc_no==upd.acc_no){
            test=1;
            printf("\n\tWhich One do you want to change?\n"
                   "\t1.Address\n\t2.Phone\n\t3.Name\n\n\tEnter your choice(1 for address, 2 for phone and 3 for name):.. ");
            scanf("%d",&choice);

            if(choice==1){
                printf("\n\tEnter the new address:.. ");
                scanf("%s", upd.adress);
                fprintf(nr, "%d\t%s\t%s\t%d\n", ad.acc_no, ad.names, upd.adress, ad.phone);
                printf("\n\tChanges saved!\n\n\t");
                system("pause");
                }
            else if(choice==2){
                printf("\n\tEnter the new phone:");
                scanf("%d",&upd.phone);
                fprintf(nr, "%d\t%s\t%s\t%d\n", ad.acc_no, ad.names, ad.adress, upd.phone);
                printf("\n\tChanges saved!\n\n\t");
                system("pause");
                }
            else if(choice==3){
                printf("\n\tEnter the new name:");
                scanf("%s", upd.names);
                fprintf(nr, "%d\t%s\t%s\t%d\n", ad.acc_no, upd.names, ad.adress, ad.phone);
                printf("\n\tChanges saved!\n\n\t");
                system("pause");
                }
        }
        else
            fprintf(nr, "%d\t%s\t%s\t%d\n", ad.acc_no, ad.names, ad.adress, ad.phone);
    }
    fclose(od);
    fclose(nr);
    remove("record.dat");
    rename("new.dat", "record.dat");
}

void search(){
    system("cls");
    FILE *old;
    int test=0;
    old=fopen("record.dat","r");
    printf("\n\tSEARCH BY ACCNo"
           "\n\t***************\n");
    printf("\n\tSearch by Account:.. ");
    scanf("%d",&sr.acc_no);
    printf("\n\tACC_NO\tNAME\tADRESS\tPHONE\t\xB2\n");
    while (fscanf(old, "%d %s %s %d", &ad.acc_no, ad.names, ad.adress, &ad.phone)!=EOF){
        if(ad.acc_no==sr.acc_no){
            printf("\n\t%d\t%s\t%s\t%d\n", ad.acc_no, ad.names, ad.adress, ad.phone);
            test+=1;
        }
    }
    if(test==0){
        printf("\n\tRecord Not Found!\n\n\t");
    }
    printf("\n\t");
    fclose(old);
    system("pause");
}

void sort(){
    system("cls");
    FILE *srt;
    int i=0, j, k, key, c;
    srt = fopen("record.dat", "r");
    printf("\n\tTHIS IS YOUR LIST SORTED"
           "\n\t************************\n");
    while(fscanf(srt, "%d %s %s %d", &st[i].acc_no, st[i].names, st[i].adress, &st[i].phone)!=EOF){
        i++;
    }
    for(j=0; j<i; j++){
        for(k=j+1; k<i; k++){
            if(st[k].acc_no<st[j].acc_no){
                temp = st[j];
                st[j]=st[k];
                st[k]=temp;
            }
        }
    }
    printf("\n\tACC_NO\tNAME\tADRESS\tPHONE\t\xB2\n");
    for(j=0; j<i; j++){
        printf("\t%d\t%s\t%s\t%d\n", st[j].acc_no, st[j].names, st[j].adress, st[j].phone);
    }
    if(i==0){
        printf("\n\tNO RECORDS!\n\n\t");
    }
    fclose(srt);
    printf("\n\t");
    system("pause");
}

void main(){
    int choice;
    system("color 5e");

    printf("\n\n\t\t\t..==============================================..\n"
           "\t\t\t||``````````````````````````````````````````````||\n"
           "\t\t\t||                                              ||\n"
           "\t\t\t||       BANK ACCOUNTS MANAGEMENT SYSTEM        ||\n"
           "\t\t\t||                                              ||\n"
           "\t\t\t||..............................................||\n"
           "\t\t\t''==============================================''\n");
    printf("\n\t\t\t\xB2\xB2\ MADE by: N.E.J.A.H \xB2\xB2\n\n");

    printf("\t\t\t..``````````````````````````````````````````````..\n"
           "\t\t\t||        GROUP MEMBERS                         ||\n"
           "\t\t\t||,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,||\n"
           "\t\t\t||                                              ||\n"
           "\t\t\t||        24159 NIYONZIMA Yoramu                ||\n"
           "\t\t\t||        24070 NDIKUBWIMANA Emmanuel           ||\n"
           "\t\t\t||        24114 JABO Yvan                       ||\n"
           "\t\t\t||        24069 KANYANA Anitha                  ||\n"
           "\t\t\t||        24496 MUHIMPUNDU Husna                ||\n"
           "\t\t\t||                                              ||\n"
           "\t\t\t'',,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,''\n\n\t\t\t");

    system("pause");
    while(1){
        system("cls");
        int choice;
        printf("\n\n\n\n\n\tPRESS 1 TO RECORD\n\n"
               "\tPRESS 2 TO DISPLAY\n\n"
               "\tPRESS 3 TO ERASE\n\n"
               "\tPRESS 4 TO UPDATE\n\n"
               "\tPRESS 5 TO SEARCH\n\n"
               "\tPRESS 6 TO SORT\n\n"
               "\tPRESS 0 TO EXIT\n\n\t");
        scanf("%d", &choice);

        switch(choice){
        case 1:
            new_acc();
            break;
        case 2:
            view_list();
            break;
        case 3:
            rem_rec();
            break;
        case 4:
            update();
            break;
        case 5:
            search();
            break;
        case 6:
            sort();
            break;
        case 0:
            printf("\n\tThank you!\n");
            exit(0);
            break;
        default:
            printf("\n\tNO VALID CHOICE MADE!\n\t");
            printf("\n\tRun again and use valid keys!\n\n\t");
            system("pause");
            exit(0);
        }
    }
}
