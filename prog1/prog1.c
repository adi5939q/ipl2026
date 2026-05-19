#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int id;
    char name[20];
    float marks;
};

/* Function Prototypes */
void storeRecords(int n);
void displayAll();
void getMthRecord(int m);
void deleteRecord(int deleteId);

int main()
{
    int n, m, deleteId;

    printf("Enter number of records: ");
    scanf("%d", &n);

    storeRecords(n);

    printf("\nStored Records:\n");
    displayAll();

    printf("\nEnter record number to display: ");
    scanf("%d", &m);

    getMthRecord(m);

    printf("\nEnter ID to delete: ");
    scanf("%d", &deleteId);

    deleteRecord(deleteId);

    printf("\nRecords after deletion:\n");
    displayAll();

    return 0;
}


void storeRecords(int n)
{
    FILE *fp;
    struct Student s;

    fp = fopen("student.dat", "wb");

    if (fp == NULL)
    {
        printf("File cannot be opened.\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter details of student %d\n", i + 1);

        printf("Enter ID: ");
        scanf("%d", &s.id);

        printf("Enter Name: ");
        scanf("%s", s.name);

        printf("Enter Marks: ");
        scanf("%f", &s.marks);

        fwrite(&s, sizeof(struct Student), 1, fp);
    }

    fclose(fp);
}


void displayAll()
{
    FILE *fp;
    struct Student s;

    fp = fopen("student.dat", "rb");

    if (fp == NULL)
    {
        printf("File cannot be opened.\n");
        return;
    }

    printf("\nID\tName\tMarks\n");
    while (fread(&s, sizeof(struct Student), 1, fp))
    {
        printf("%d\t%s\t%.2f\n", s.id, s.name, s.marks);
    }
    fclose(fp);
}


void getMthRecord(int m)
{
    FILE *fp;
    struct Student s;

    fp = fopen("student.dat", "rb");

    if (fp == NULL)
    {
        printf("File cannot be opened.\n");
        return;
    }

    /* Move file pointer to mth record */
    fseek(fp, (m - 1) * sizeof(struct Student), SEEK_SET);

    if (fread(&s, sizeof(struct Student), 1, fp))
    {
        printf("\nMth Record:\n");

        printf("ID  = %d\n", s.id);
        printf("Name= %s\n", s.name);
        printf("Marks= %.2f\n", s.marks);
    }
    else
    {
        printf("Record not found.\n");
    }

    fclose(fp);
}


void deleteRecord(int deleteId)
{
    FILE *fp, *temp;
    struct Student s;

    fp = fopen("student.dat", "rb");
    temp = fopen("temp.dat", "wb");

    if (fp == NULL || temp == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    while (fread(&s, sizeof(struct Student), 1, fp))
    {
        /* Copy only records not matching deleteId */
        if (s.id != deleteId)
        {
            fwrite(&s, sizeof(struct Student), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);
    remove("student.dat");
    rename("temp.dat", "student.dat");
    printf("Record deleted successfully.\n");
}