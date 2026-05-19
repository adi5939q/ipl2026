#include <stdio.h>

typedef struct{
    int SRN;
    char name[50];
    float marks;
}Student;

void records(Student s[], int n);
int createseekpositions(int pos[], int maxrecords);
void displayrecords(int position);

int main() {
    int n, choice;
    int positions[100];

    printf("Enter number of records:");
    scanf("%d", &n);

    Student s[n];

    for(int i=0; i<n; i++){
        printf("Enter details of the student: %d\n", i+1);

        printf("Enter SRN:");
        scanf("%d", &s[i].SRN);

        printf("Enter Name:");
        scanf("%s", s[i].name);

        printf("Enter marks:");
        scanf("%f", &s[i].marks);
    }

    records(s, n);
    int total = createseekpositions(positions, 100);

    printf("\nSeek positions:\n");

    for(int i=0; i<n; i++){
        printf("Record %d starts at position %d\n", i+1, positions[i]);
    }

    printf("\nEnter record number to display: ");
    scanf("%d", &choice);

    if(choice >= 1 && choice <= total){
        displayrecords(positions[choice - 1]);
    }else{
        printf("\nInvalid record number");
    }
    return 0;
}

void records(Student s[], int n){
    FILE *fp;
    fp = fopen("records.txt", "w");

    if(fp == NULL){
        printf("Error opening file\n");
        return;
    }

    for(int i=0; i<n; i++){
        fprintf(fp, "%d %s %.2f\n", s[i].SRN, s[i].name, s[i].marks);
    }

    fclose(fp);
    printf("Records stored successfully");
}

int createseekpositions(int pos[], int maxrecords){
    FILE *fp;
    int count = 0;
    Student temp;

    fp = fopen("records.txt", "r");

    if(fp == NULL){
        printf("Error opening file\n");
        return 0;
    }

    while(!feof(fp) && count < maxrecords){
        pos[count] = ftell(fp);
        if(fscanf(fp, "%d %S %f", &temp.SRN, temp.name, &temp.marks) == 3){
            count++;
        }

    }
    fclose(fp);
    return count;
}

void displayrecords(int position){
    FILE *fp;
    Student s;
    fp = fopen("records.txt", "r");
    
    if(fp == NULL){
        printf("Error opening file\n");
        return;
    }

    fseek(fp, position, SEEK_SET);

    if(fscanf(fp, "%d %s %f", &s.SRN, s.name, &s.marks) == 3){
        printf("SRN: %d\n", s.SRN);
        printf("Name: %s\n", s.name);
        printf("Marks: %.2f\n", s.marks);
    }else{
        printf("Record not found\n");
    }
    
    fclose(fp);
}