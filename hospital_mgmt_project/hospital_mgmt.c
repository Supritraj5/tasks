#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// Define PATIENT_REGISTRATION structure
typedef struct {
    int rno, age, d, m, y;
    char pname[25], add[25], dis[10], bg[5];
} PATIENT_REGISTRATION;

// Function to accept patient details
void accept_patient(PATIENT_REGISTRATION *p) {
    //clrscr();
    printf("\t\tWELCOME TO NEW PATIENT REGISTRATION\n");
    printf("NOTICE!!!  PLEASE ENTER THE APPROPRIATE VALUE\n");
    printf("ENTER REGISTRATION NUMBER\n");
    scanf("%d", &p->rno);
    printf("ENTER THE DATE\n");
    printf("D:- "); scanf("%d", &p->d);
    printf("M:- "); scanf("%d", &p->m);
    printf("Y:- "); scanf("%d", &p->y);
    printf("\nENTER AGE\n");
    scanf("%d", &p->age);
    printf("\nENTER PATIENT NAME\n");
    if(p->age > 18) {
        printf("Mr./Mrs.");
    }
    getchar(); 
    fgets(p->pname, 25, stdin);
    printf("\nENTER BLOOD GROUP\n");
    fgets(p->bg, 5, stdin);
    printf("\nENTER ADDRESS\n");
    fgets(p->add, 25, stdin);
    printf("\nENTER DISEASE\n");
    fgets(p->dis, 10, stdin);
    printf("\nPATIENT REGISTRATION WAS DONE SUCCESSFULLY\n");
}

// Function to display patient details
void display_patient(PATIENT_REGISTRATION p) {
    
    printf("\nHERE WHAT YOU WANT\n");
    printf("REGISTRATION NUMBER:-\t%d\n", p.rno);
    printf("DATE:-\t%d-%d-%d\n", p.d, p.m, p.y);
    printf("AGE:-\t%d\n", p.age);
    printf("NAME:-\t%s\n", p.pname);
    printf("BLOOD GROUP:-\t%s\n", p.bg);
    printf("DISEASE:-\t%s\n", p.dis);
    printf("ADDRESS:-\t%s\n", p.add);
    printf("____________________________________________________\n");
}

// Define STAFF_REGISTRATION structure
typedef struct {
    int rno, age;
    char sname[25], add[25], post[25], qu[10];
} STAFF_REGISTRATION;

// Function to accept staff details
void accept_staff(STAFF_REGISTRATION *s) {
    
    printf("\t\tWELCOME TO STAFF REGISTRATION\n");
    printf("NOTICE!!! PLEASE ENTER APPROPRIATE VALUE\n");
    printf("ENTER THE POST:-\n");
    fgets(s->post, 25, stdin);
    printf("\nENTER THE REGISTRATION NUMBER:-\n");
    scanf("%d", &s->rno);
    printf("\nENTER THE NAME:-\n");
    if(strcmp(s->post, "doctor") == 0) {
        printf("Dr.");
    }
    getchar(); 
    fgets(s->sname, 25 , stdin);
    printf("\nENTER QUALIFICATION:-\n");
    fgets(s->qu, 10, stdin);
    printf("\nENTER ADDRESS:-\n");
    fgets(s->add, 25 , stdin);
    printf("\nENTER AGE:-\n");
    scanf("%d", &s->age);
    printf("\nREGISTRATION WAS DONE SUCCESSFULLY\n");
}

// Function to display staff details
void display_staff(STAFF_REGISTRATION s) {
    
    printf("HERE WHAT YOU WANT\n");
    printf("REGISTRATION NUMBER:-\t%d\n", s.rno);
    printf("POST:-\t%s\n", s.post);
    printf("NAME:-\t%s\n", s.sname);
    printf("AGE:-\t%d\n", s.age);
    printf("QUALIFICATION:-\t%s\n", s.qu);
    printf("____________________________________________________\n");
}

// Function to display front page
void front_page() {
    char gf[5];
    
    printf("\n\t\t\t\t\t||\n\t\t\t\t\t||\n\t\t\t\t\t||\n\t\t\t\t\t||\n");
    printf("\t\t\t\t||||||||||||||||||\n");
    printf("\t\t\t\t\t||\n\t\t\t\t\t||\n\t\t\t\t\t||\n\t\t\t\t\t||\n");
    printf("\t\t\t______________________\n");
    printf("\t\t\t| HOSPITAL MANAGEMENT |\n");
    printf("\t\t\t______________________\n");
    printf("PRESS 'Y' TO CONTINUE\n");
    fgets(gf, 5, stdin);
}

// Function to display ambulance details
void camb() {
    
    char g;
    FILE *fin = fopen("amb.txt", "r");
    if (fin == NULL) {
        printf("Error opening file amb.txt\n");
        return;
    }
    while ((g = fgetc(fin)) != EOF) {
        putchar(g);
    }
    fclose(fin);
}

// Function to display disease details
void cdis() {
    
    char f;
    FILE *finn = fopen("dis.txt", "r");
    if (finn == NULL) {
        printf("Error opening file dis.txt\n");
        return;
    }
    while ((f = fgetc(finn)) != EOF) {
        putchar(f);
    }
    fclose(finn);
}

int main() {
    
    int c, s, p, sr, fp = 0, fl = 0;
    char u[5], log[10], pass[7];
    PATIENT_REGISTRATION P1;
    STAFF_REGISTRATION S1;
    FILE *f;
    FILE *fk;
    FILE *g;
    FILE *gk;

    front_page();
    //clrscr();
    printf("\n\n\n\t\t\tWELCOME USER");
    printf("\n\n\n\t\t_______\n\t\t|LOGIN :-\t ");
    fgets(log, 10, stdin);
    printf("\n\t\t_________\n\t\t|PASSWORD :-\t");
    fgets(pass, 7, stdin);
    pass[strcspn(pass, "\n")] = '\0';

    if(strcmp(pass, "*****") == 0) {
        do {
            //clrscr();
            printf("\n\n\n\nSelect any of our services? ::\n");
            printf("\t ________________________________________________\n");
            printf("\t| REGISTRATIONS:\t| DETAILS:\t\t|\n");
            printf("\t|_______________________|_______________________|");
            printf("\n\t| 1.STAFF REGISTRATION\t| 2.AMBULANCE\t\t|\n");
            printf("\t| 3.PATIENT REGISTRATION| 4.DISEASE\t\t|\n");
            printf("\t|\t\t\t| 5.ALL PATIENT\t\t|\n\t|\t\t\t| 6.ALL STAFF \t\t|\n");
            printf("\t|\t\t\t| 7.SPECIFIC PATIENT\t|\n\t|\t\t\t| 8.SPECIFIC STAFF     |");
            printf("\n\t|_______________________|_______________________|\n");
            printf("\nENTER HERE:-\t");
            scanf("%d", &c);
            //clrscr();

            if(c == 1) {
                printf("HOW MANY REGISTRATIONS:- ");
                scanf("%d", &s);
                for(int i = 0; i < s; i++) {
                    g = fopen("recordstaff.dat", "ab");
                    accept_staff(&S1);
                    fwrite(&S1, sizeof(STAFF_REGISTRATION), 1, g);
                    fclose(g);
                }
            } else if(c == 2) {
                camb();
            } else if(c == 3) {
                printf("HOW MANY REGISTRATIONS:- ");
                scanf("%d", &p);
                for(int i = 0; i < p; i++) {
                    f = fopen("recordpatient.dat", "ab");
                    accept_patient(&P1);
                    fwrite(&P1, sizeof(PATIENT_REGISTRATION), 1, f);
                    fclose(f);
                }
            } else if(c == 4) {
                cdis();
            } else if(c == 5) {
                fk = fopen("recordpatient.dat", "rb");
                int al = 0;
                char z[5];
                while(fread(&P1, sizeof(PATIENT_REGISTRATION), 1, fk)) {
                    display_patient(P1);
                    al++;
                    if(al == 3) {
                        printf("TYPE NEXT FOR NEXT PAGE DETAILS");
                        fgets(z,5,stdin);
                        //clrscr();
                        al = 0;
                    }
                }
                fclose(fk);
            } else if(c == 6) {
                gk = fopen("recordstaff.dat", "rb");
                int aj = 0;
                char x[5];
                while(fread(&S1, sizeof(STAFF_REGISTRATION), 1, gk)) {
                    display_staff(S1);
                    aj++;
                    if(aj == 3) {
                        printf("TYPE NEXT FOR NEXT PAGE DETAILS");
                        gets(x);
                        //clrscr();
                        aj = 0;
                    }
                }
                fclose(gk);
            } else if(c == 7) {
                printf("ENTER THE REGISTRATION NUMBER OF THE SEARCHING ONE\n");
                scanf("%d", &sr);
                fk = fopen("recordpatient.dat", "rb");
                while(fread(&P1, sizeof(PATIENT_REGISTRATION), 1, fk)) {
                    if(P1.rno == sr) {
                        display_patient(P1);
                        fp = 1;
                    }
                }
                if(fp == 0) {
                    printf("not found ");
                }
                fclose(fk);
            } else if(c == 8) {
                printf("ENTER THE REGISTRATION NUMBER OF THE SEARCHING ONE\n");
                scanf("%d", &sr);
                gk = fopen("recordstaff.dat", "rb");
                while(fread(&S1, sizeof(STAFF_REGISTRATION), 1, gk)) {
                    if(S1.rno == sr) {
                        display_staff(S1);
                        fl = 1;
                    }
                }
                if(fl == 0) {
                    printf("not found ");
                }
                fclose(gk);
            } else {
                printf("\n!!!!OOOOPS SOMETHING WENT WRONG\n");
            }

            // clrscr(); - clear screen is not required here in C version
            printf("WANT TO RUN PROGRAM ONE MORE TIME (yes) \n");
            getchar(); // Consume newline
            gets(u);
        } while(strcmp(u, "yes") == 0);
        //clrscr();
    } else {
        //clrscr();
        printf("\nWRONG PASSWORD\nACCESS CAN'T BE GRANTED\n");
    }

    getch();
    return 0;
}
