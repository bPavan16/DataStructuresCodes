#include <stdio.h>
#include <string.h>

struct student
{
    char name[20];
    int rno;
    double CGPA;
};

void SelectionSort(void *, int, int, int (*cmp)(void *, void *));
void displayStudentDetails(struct student *, int);
void readStudentDetails(struct student *, int);
void Swap(void *, void *, int);
void readArray(int[], int);
void displayArray(int[], int);
void Swap(void *, void *, int);
int cmpint(void *, void *);
int cmpCGPA(void *, void *);

int main()
{

    int a[100];
    int n;
    printf("Enter the number of Array elements to be read :  ");
    scanf("%d", &n);
    printf("Enter the array Elements :");
    readArray(a, n);
    printf("\n");
    printf("\n");
    printf("The array before Sorting\n\n");
    displayArray(a, n);
    SelectionSort(a, n, sizeof(int), cmpint);
    printf("The array after Sorting is\n\n");
    displayArray(a, n);

    struct student s[3] = {{"ABC", 10, 8.7}, {"XYZ", 25, 9.24}, {"PQR", 27, 7.9}};

    printf("The Structure before Sorting\n\n");

    displayStudentDetails(s, 3);
    SelectionSort(s, 3, sizeof(struct student), cmpCGPA);

    printf("The Structure after Sorting\n\n");
    displayStudentDetails(s, 3);

    return 0;
}

void readArray(int a[], int n)
{

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void displayArray(int a[], int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("%d \t", a[i]);
    }
    printf("\n\n");
}

void readStudentDetails(struct student *s, int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("Enter Student Name :  ");
        scanf("%s", s[i].name);
        printf("Enter Student Rno :  ");
        scanf("%d", &s[i].rno);
        printf("Enter Student CGPA :  ");
        scanf("%lf", &s[i].CGPA);
    }
}
void displayStudentDetails(struct student *s, int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("The Student Name is  %s\n", s[i].name);
        printf("The Student Roll_Num is  %d\n", s[i].rno);
        printf("The Student CGPA is  %.3lf\n", s[i].CGPA);
        printf("\n\n");
    }
}

void SelectionSort(void *a, int n, int datasize, int (*cmp)(void *, void *))
{
    char *x, *y, *z;
    int i, j, max;

    for (i = 0; i < n - 1; i++)
    {
        max = i;
        x = (char *)(a + i * datasize);
        y = (char *)(a + max * datasize);

        for (j = i + 1; j < n; j++)
        {
            z = (char *)(a + j * datasize);

            if ((*cmp)(y, z))
            {
                max = j;
                y = (char *)(a + max * datasize);
            }
        }

        Swap(x, y, datasize);
    }
}

void Swap(void *a, void *b, int s)
{
    char temp;
    char *p = (char *)a;
    char *q = (char *)b;

    for (int i = 0; i < s; i++)
    {
        temp = *p;
        *p = *q;
        *q = temp;
        p++;
        q++;
    }
}

int cmpint(void *a, void *b)
{
    int *p = (int *)a;
    int *q = (int *)b;
    if (*q > *p)
        return 1;
    else
        return 0;
}

int cmpCGPA(void *a, void *b)
{
    struct student *p = (struct student *)a;
    struct student *q = (struct student *)b;
    if (q->CGPA > p->CGPA)
        return 1;
    else
        return 0;
}