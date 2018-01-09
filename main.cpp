//Linearly Seperable Data by Anish Sanyal


#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>

float mean(float *a, int n);
void deviation(float *a, float mean, int n, float *d, float *S);

int main() 
{
 float a[20], b[20], dx[20], dy[20];
 float sy = 0, sx = 0, mean_x = 0, mean_y = 0, sum_xy = 0;
 float corr_coff = 0, reg_coff_xy = 0, reg_coff_yx = 0;
 char type_coff[7];
 int n = 0, i = 0;

printf("Enter the value of n: ");
 scanf("%d", &n);
 printf("Enter the values of x and y:n");
 for (i = 0; i < n; i++)
  scanf("%f%f", &a[i], &b[i]);
 mean_x = mean(a, n);
 mean_y = mean(b, n);
 deviation(a, mean_x, n, dx, &sx);
 deviation(b, mean_y, n, dy, &sy);

 for (i = 0; i < n; i++)
  sum_xy = sum_xy + dx[i] * dy[i];
 corr_coff = sum_xy / (n * sx * sy);
 printf("Enter the type of regression coefficient as 'x on y' or 'y on x': ");
 fflush(stdin);
 gets(type_coff);

 if (strcmp(type_coff, "x on y") == 1) {
  reg_coff_xy = corr_coff * (sx / sy);
  printf("nThe value of linear regression coefficient is %f",
    reg_coff_xy);
 } else if (strcmp(type_coff, "y on x") == 1) {
  reg_coff_yx = corr_coff * (sy / sx);
  printf("nThe value of linear regression coefficient is %f",
    reg_coff_yx);
 } else
  printf("nEnter the correct type of regression coefficient.");
 getch();
 return 0;
}

float mean(float *a, int n) {
 float sum = 0;
 int i = 0;
 for (i = 0; i < n; i++)
  sum = sum + a[i];
 sum = sum / n;
 return (sum);
}

void deviation(float *a, float mean, int n, float *d, float *s) {
 float sum = 0, t = 0;
 int i = 0;
 for (i = 0; i < n; i++) {
  d[i] = a[i] - mean;
  t = d[i] * d[i];
  sum = sum + t;
 }
 sum = sum / n;
 *s = sqrt(sum);
}

