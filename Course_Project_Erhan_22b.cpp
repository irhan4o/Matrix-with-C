#include <stdio.h>
#include <limits.h>

int main() 
{
    // --- Декларации и заглавна част ---
    char taskDescription[] = 
    "=========================================================================\n"
    "УСЛОВИЕ НА ЗАДАЧАТА:\n"
    "Да се състави програма за обработка на два масива A[N,N] и B[N,N],\n"
    "със стойности цели числа в интервала [-1000; 1000].\n"
    "Действия:\n"
    "1. Отпечатване на условието и автора;\n"
    "2. Въвеждане и отпечатване на входните данни;\n"
    "3. а) Нулиране на елементите в A, по-големи от MAX на съответната колона в B;\n"
    "4. б) Преброяване на променените елементи в масива A;\n"
    "5. Отпечатване на получените резултати след обработка а) и б).\n"
    "=========================================================================";
    char author[] = "Author: Erhan Nebi";
    
    printf("%s\n", taskDescription);
    printf("%s\n\n", author);

    // --- Въвеждане на размер на матриците ---
    int n;
    printf("Enter size N: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size!\n");
        return 1;
    }

    int matrixA[n][n];
    int matrixB[n][n];

     // --- Въвеждане на матрицата A с do-while валидация ---
    printf("\n--- Input Matrix A (Values: -1000 to 1000) ---\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            do {
                printf("A[%d][%d] = ", i, j);
                scanf("%d", &matrixA[i][j]);
                if (matrixA[i][j] < -1000 || matrixA[i][j] > 1000) {
                    printf("Error! Range is [-1000; 1000]. Try again: ");
                }
            } while (matrixA[i][j] < -1000 || matrixA[i][j] > 1000);
        }
    }

    // --- Въвеждане на матрицата B с do-while валидация ---
    printf("\n--- Input Matrix B (Values: -1000 to 1000) ---\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            do {
                printf("B[%d][%d] = ", i, j);
                scanf("%d", &matrixB[i][j]);
                if (matrixB[i][j] < -1000 || matrixB[i][j] > 1000) {
                    printf("Error! Range is [-1000; 1000]. Try again: ");
                }
            } while (matrixB[i][j] < -1000 || matrixB[i][j] > 1000);
        }
    }
    // --- Принтиране на първоначалната матрица A ---
    printf("\n--- Matrix A ---\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d ", matrixA[i][j]);
        }
        printf("\n");
    }
     
    // --- Принтиране на първоначалната матрица B ---
    printf("\n--- Matrix B ---\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d ", matrixB[i][j]);
        }
        printf("\n");
    }

    // --- Логика: Намиране на максимален елемент за всяка колона на B ---
    int a[n];
    for(int j = 0; j < n; j++) 
    {
         int max = INT_MIN; 
         for(int i = 0; i < n; i++)
         {
           if(max < matrixB[i][j])
           {
            max = matrixB[i][j];
           }        
         }
         a[j] = max;
    }
    
    // --- Логика: Сравняване на елементите на A с намерените максимуми ---
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
             if(matrixA[i][j] > a[j])
             {
                  matrixA[i][j] = 0;
                  count++;          
             }   
        }                
    }

    // --- Извеждане на крайните резултати ---
    printf("\nThe matrix A is: \n");    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
             printf("%4d ", matrixA[i][j]); 
        }
        printf("\n");
    }  
    printf("The count of changes are %d\n", count);     
    
    return 0;
}
