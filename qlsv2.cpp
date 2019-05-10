#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
 
using namespace std;
struct Student
{
	char hoten[30],mssv[20],monhoc[20];
	float diem;
	int low;
	int high;
};
typedef Student student;
void input(Student &stu);
void inputstu(Student a[], int n);
void output(Student &stu);
void outputstu(Student a[], int n);
void Bubblesort(Student a[], int n);
/*void InterchanceSort(Student *a, int n);*/
/*void QuickSort(Student a[], int n);*/
void InsertionSort (Student a[], int n);
int main(){
    int key;
    char fileName[] = "DSSVV.txt";
    int n;
    bool Nhap = false;
    do{
        printf("\nNhap so luong SV: "); scanf("%d", &n);
    }while(n <= 0);
    Student a[n];
    while(true){
        system("cls");
        printf("******************************************\n");
        printf("**    CHUONG TRINH QUAN LY SINH VIEN    **\n");
        printf("**      1. Nhap du lieu                 **\n");
        printf("**      2. In danh sach sinh vien       **\n");
        printf("**      3. Sap xep sinh vien theo diem   **\n");
        printf("**      4. Sap xep theo thuat toan Interchance sort  **\n");
        printf("**      0. Thoat                        **\n");
        printf("******************************************\n");
        printf("**       Nhap lua chon cua ban          **\n");
        scanf("%d",&key);
        switch(key){
            case 1:
                printf("\nBan da chon nhap danh sach SV!");
                inputstu(a, n);
                printf("\nBan da nhap thanh cong!");
                Nhap = true;
                printf("\nChon phim bat ky de tiep tuc!");
                getch();
                break;
            case 2:
                if(Nhap){
                    printf("\nBan da chon xuat danh sach SV!");
                    outputstu(a, n);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                printf("\nChon phim bat ky de tiep tuc!");
                getch();
                break;
            case 3:
                if(Nhap){
                    printf("\nBan da chon sap xep SV theo diem!");
                    Bubblesort(a, n);
                    InsertionSort(a, n);
                    outputstu(a, n);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                printf("\nChon phim bat ky de tiep tuc!");
                getch();
                break;
            case 4:
                if(Nhap){
                    printf("\nBan da chon sap xep danh sach SV theo thuat toan Interchance sort!");
                    Bubblesort(a, n);
                    /*InterchanceSort(a,n);*/
                    InsertionSort(a, n);
                    outputstu(a, n);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                printf("\nChon phim bat ky de tiep tuc!");
                getch();
                break;    
            case 0:
                printf("\nBan da chon thoat chuong trinh!");
                getch();
                return 0;
            default:
                printf("\nError: phim chuc nang khong kha dung!");
                printf("\nChon phim bat ky de tiep tuc!");
                getch();
                break;
        }
    }
    Student stu;
	input(stu);
	output(stu);
	getch();
}
void input(Student &stu){
    printf("\nNhap Ho Va Ten: "); fflush(stdin); gets(stu.hoten);
    printf("\nNhap MSSV: "); fflush(stdin); gets(stu.mssv);
    printf("\nNhap Ten Mon Hoc: "); fflush(stdin); gets(stu.monhoc);
    fflush(stdin);
     do{
		printf("\nNhap Vao Diem: ");
		scanf("%f", &stu.diem);

		if(stu.diem < 0 || stu.diem > 10)
		{
			printf("\nError: Nhap Diem Sai! ");
		}
	}while(stu.diem < 0 || stu.diem > 10);
}
void inputstu(Student a[], int n){
    printf("\n____________________________________\n");
    for(int i = 0; i< n; ++i){
        printf("\nNhap SV thu %d:", i+1);
        input(a[i]);
    }
    printf("\n____________________________________\n");
}
void output(Student &stu){
    printf("\nHo Va Ten Sinh Vien: %s", stu.hoten);
    printf("\nMa So Sinh Vien SV: %s", stu.mssv);
	printf("\nTen Mon Hoc: %s", stu.monhoc);
	printf("\nDiem Mon Hoc: %f", stu.diem);	
}
void outputstu(Student a[], int n){
    printf("\n____________________________________\n");
    for(int i = 0;i < n;++i){
        printf("\nThong tin SV thu %d:", i+1);
        output(a[i]);
    }
    printf("\n____________________________________\n");
}
void Bubblesort(struct Student a[], int n)
{
int i, j;
for (i = 0; i < n; i++)
for (j = n - 1; j > i; j--)
if (a[j].diem < a[j - 1].diem )
{
student temp = a[j];
a[j] = a[j - 1];
a[j - 1] = temp;
}
}
void InsertionSort(struct Student a[], int n)
{
   int i, j;
   int max;
   for (i = 1; i < n; i++)
   {
       max = a[i].diem;
       j = i-1;
       while (j >= 0 && a[j].diem > max)
       {
           a[j+1] = a[j];
           j = j-1;
       }
       a[j+1].diem = max;
   }
}



/*void InterchangeSort(int *a, int n)
{
   for (int i = 0; i < n-1; i++)
      for (int j = i+1; j < n; j++)
         if (a[i] > a[j])
         {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
         }
}*/

