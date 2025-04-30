#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void pythagoras(){
    int a,b;
    double c;
    printf("enter first number : ");
    scanf("%d", &a);
    printf("enter second number : ");
    scanf("%d", &b);

    c = sqrt(pow(a, 2) + pow(b, 2));

    printf("c = %.2lf\n",c);
}

void factorial(){

}

void fibbonaci(){

}

void circle_area(){

}

void exponential(){
    int base,power,x;

    printf("enter a base number : ");
    scanf("%d",&base);
    printf("enter a power number : ");
    scanf("%d",&power);

    x = pow(base,power);

    printf("x = %d",x);
}

void logarithms(){
    double x,logarithm,ln;

    printf("enter a number : ");
    scanf("%lf",&x);

    logarithm = log10(x);

    ln = log(x);

    printf("log10 = %lf\n",logarithm);
    printf("ln = %lf\n",ln);
}

void trig(){

}

void dist_2d_plane(){
    int x1,x2,y1,y2;
    double a;

    printf("enter x1 number = ");
    scanf("%d", &x1);
    printf("enter x2 number = ");
    scanf("%d", &x2);
    printf("enter y1 number = ");
    scanf("%d",&y1);
    printf("enter y2 number = ");
    scanf("%d",&y2);

    a = sqrt(pow(x2 - x1,2) + pow(y2 - y1,2));
    
    printf("a = %2.lf",a);
}

void dist_3d_plane(){
    int x1,x2,y1,y2,z1,z2;
    double b;

    printf("enter x1 number = ");
    scanf("%d", &x1);
    printf("enter x2 number = ");
    scanf("%d", &x2);
    printf("enter y1 number = ");
    scanf("%d",&y1);
    printf("enter y2 number = ");
    scanf("%d",&y2);
    printf("enter z1 number = ");
    scanf("%d",&z1);
    printf("enter z2 number = ");
    scanf("%d",&z2);

    b = sqrt(pow(x2 - x1,2) + pow(y2 - y1,2) + pow(z2 - z1,2));
    
    printf("b = %lf",b);
}

void derivative(){

}

void num_integration(){

}

void printmatrix(int mat[2][2]){
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 2;j++){
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
}

void addmatrix(int result[2][2], int mat1[2][2], int mat2[2][2]){
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 2;j++){
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
        printf("\n");
    }
}

void matrix_2x2(){
    int mat1[2][2], mat2[2][2], result[2][2];
    printf("enter first matrix elemen : \n");
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 2;j++){
            scanf("%d",&mat1[i][j]);
        }
    }

    printf("enter second matrix elemen : \n");
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 2;j++){
            scanf("%d",&mat2[i][j]);
        }
    }

    printf("first matrix : \n");
    printmatrix(mat1);

    printf("second matrix : \n");
    printmatrix(mat2);

    addmatrix(result,mat1,mat2);
    printf("result of 2x2 matrix sum : \n");
    printmatrix(result);
}

void printmatrix_3x3(int mat[3][3]){
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
}

void addmatrix_3x3(int result[3][3], int mat1[3][3], int mat2[3][3]){
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
        printf("\n");
    }
}

void matrix_3x3(){
    int result[3][3], mat1[3][3], mat2[3][3];
    printf("enter first matrix elemen : \n");
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            scanf("%d",&mat1[i][j]);
        }
    }

    printf("enter second matrix elemen : \n");
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            scanf("%d",&mat2[i][j]);
        }
    }

    printf("first matrix : \n\n");
    printmatrix_3x3(mat1);

    printf("second matrix : \n\n");
    printmatrix_3x3(mat2);

    addmatrix_3x3(result,mat1,mat2);
    printf("result of 3x3 matrix sum : \n");
    printmatrix_3x3(result);
}

void print_matrix(int mat[2][2]){
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 2;j++){
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
}

void sub_matrix(int result[2][2], int mat1[2][2], int mat2[2][2]){
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 2;j++){
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
        printf("\n");
    }
}

void matrix2x2(){
    int result[2][2], mat1[2][2], mat2[2][2];
    printf("enter first matrix elemen : \n");
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 2;j++){
            scanf("%d",&mat1[i][j]);
        }
    }

    printf("enter second matrix elemen : \n");
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 2;j++){
            scanf("%d",&mat2[i][j]);
        }
    }

    printf("first matrix : \n");
    print_matrix(mat1);

    printf("second matrix : \n");
    print_matrix(mat2);

    sub_matrix(result, mat1, mat2);
    printf("result of 2x2 matrix subtraction : \n");
    print_matrix(result);
}

void print_matrix_3x3(int mat[3][3]){
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
}

void submatrix_3x3(int result[3][3], int mat1[3][3], int mat2[3][3]){
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
        printf("\n");
    }
}

void matrix3x3(){
    int result[3][3], mat1[3][3], mat2[3][3];
    printf("enter first matrix elemen : \n");
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            scanf("%d",&mat1[i][j]);
        }
    }

    printf("enter second matrix elemen : \n");
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            scanf("%d",&mat2[i][j]);
        }
    }

    printf("first matrix : \n");
    print_matrix_3x3(mat1);

    printf("second matrix : \n");
    print_matrix_3x3(mat2);

    submatrix_3x3(result, mat1, mat2);
    printf("result of 3x3 matrix subtraction : \n");
    print_matrix_3x3(result);
}

void prints_matrix(int matrix[2][2]){
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 2;j++){
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }
}

void multiplication_matrix(int result[2][2], int matrix1[2][2], int matrix2[2][2]){
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 2;j++){
            result[i][j] = 0;
            for(int k = 0;k < 2;k++){
                result[i][j] += matrix1[i][j] * matrix2[i][j];
            }
        }
    }
}

void multiplication_matrix_2x2(){
    int result[2][2], matrix1[2][2], matrix2[2][2];
    printf("enter first matrix elemen : \n");
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 2;j++){
            scanf("%d",&matrix1[i][j]);
        }
    }

    printf("enter second matrix elemen : \n");
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 2;j++){
            scanf("%d",&matrix2[i][j]);
        }
    }

    printf("first matrix : \n");
    prints_matrix(matrix1);

    printf("second matrix : \n");
    prints_matrix(matrix2);

    multiplication_matrix(result, matrix1, matrix2);
    printf("result of 2x2 matrix multiplication : \n");
    prints_matrix(result);
}

void multiplications_matrix_3x3(result[3][3], int matriks1[3][3], int matriks2[3][3]){
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            result[i][j] = 0;
            for(int k = 0;k < 3;k++){
                result[i][j] += matriks1[i][j] * matriks2[i][j];
            }
        }
    }
}

void print_3x3_matrix_multiplication(matriks[3][3]){
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            printf("%d",matriks[i][j]);
        }
        printf("\n");
    }
}

void multiplication_matrix_3x3(){
    int result[3][3], matrix1[3][3], matrix2[3][3];

    printf("enter 3x3 matrix first elemen : \n");
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            scanf("%d",&matrix1[i][j]);
        }
    }

    printf("enter 3x3 matrix second elemen : \n");
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            scanf("%d",&matrix2[i][j]);
        }
    }

    printf("first matrix : \n");
    print_3x3_matrix_multiplication(matrix1);

    printf("second matrix : \n");
    print_3x3_matrix_multiplication(matrix2);

    multiplications_matrix_3x3(result, matrix1, matrix2);
    printf("result of 3x3 matrix multiplication : \n");
    print_3x3_matrix_multiplication(result);
}

int main(){
    int choose,choose1;
    do{
        printf("+-------------------------------------------+\n");
        printf("|                Mathematics                |\n");
        printf("+-------------------------------------------+\n");
        printf("|1. Pythagoras                              |\n");
        printf("|2. Factorial                               |\n");
        printf("|3. Fibbonaci                               |\n");
        printf("|4. Circle Area                             |\n");
        printf("|5. Exponential                             |\n");
        printf("|6. Logarithms                              |\n");
        printf("|7. Trigonometry                            |\n");
        printf("|8. Distance 2D plane                       |\n");
        printf("|9. Distance 3D plane                       |\n");
        printf("|10. Calculus                               |\n");
        printf("|11. Linear Algebra                         |\n");
        printf("|12. Exit                                   |\n");
        printf("+-------------------------------------------+\n");
        printf("Choose a number(1-12) : ");
        scanf("%d",&choose);
        switch(choose){
            case 1:
                pythagoras();
            break;

            case2:
            break;

            case 3:
            break;

            case 4:
            break;

            case 5:
                exponential();
            break;

            case 6:
                logarithms();
            break;

            case 7:
            break;

            case 8:
            dist_2d_plane();
            break;

            case 9:
                dist_3d_plane();
            break;

            case 10:
            break;

            case 11:
                printf("+-------------------------------------------+\n");
                printf("|              Linear Algebra               |\n");
                printf("+-------------------------------------------+\n");
                printf("|1. Matrix addition 2x2                     |\n");
                printf("|2. Matrix addition 3x3                     |\n");
                printf("|3. Matrix subtraction 2x2                  |\n");
                printf("|4. Matrix subtraction 3x3                  |\n");
                printf("|5. Matrix multiplication 2x2               |\n");
                printf("|6. Matrix multiplication 3x3               |\n");
                printf("|7. Exit                                    |\n");
                printf("+-------------------------------------------+\n");
                printf("Choose a number(1-6) : ");
                scanf("%d",&choose1);
                switch(choose1){
                    case 1: 
                        matrix_2x2();
                    break;

                    case 2:
                        matrix_3x3();
                    break;

                    case 3:
                        matrix2x2();
                    break;

                    case 4:
                        matrix3x3();
                    break;

                    case 5:
                        multiplication_matrix_2x2();
                    break;

                    case 6:
                        multiplication_matrix_3x3();
                    break;

                    case 7: 
                        printf("thank you for using this program");
                        return 0;
                    break;

                    default: 
                        printf("Wrong number. . .");
                        printf("Please choose a correct number. . .");
                    break;
                }
            break;

            case 12:
                matrix_2x2();
            break;

            case 13:
                matrix_3x3();
            break;

            case 14:
                matrix2x2();
            break;

            case 15:
                matrix3x3();
            break;

            case 16:
                multiplication_matrix_2x2();
            break;

            case 17:
            break;

            case 18:
                printf("Thank you for using this program");
                return 0;
            break;

            default:
                printf("Wrong number. Please choose a correct number");
            break;
        }
    }while(1);
    return 0;
}

int main(){
    int choose,choose1;
    do{
        printf("+-------------------------------------------+\n");
        printf("|                Mathematics                |\n");
        printf("+-------------------------------------------+\n");
        printf("|1. Pythagoras                              |\n");
        printf("|2. Factorial                               |\n");
        printf("|3. Fibbonaci                               |\n");
        printf("|4. Circle Area                             |\n");
        printf("|5. Exponential                             |\n");
        printf("|6. Logarithms                              |\n");
        printf("|7. Trigonometry                            |\n");
        printf("|8. Distance 2D plane                       |\n");
        printf("|9. Distance 3D plane                       |\n");
        printf("|10. Calculus                               |\n");
        printf("|11. Linear Algebra                         |\n");
        printf("|12. Exit                                   |\n");
        printf("+-------------------------------------------+\n");
        printf("Choose a number(1-12) : ");
        scanf("%d",&choose);
        switch(choose){
            case 1:
                pythagoras();
            break;

            case2:
            break;

            case 3:
            break;

            case 4:
            break;

            case 5:
                exponential();
            break;

            case 6:
                logarithms();
            break;

            case 7:
            break;

            case 8:
            dist_2d_plane();
            break;

            case 9:
                dist_3d_plane();
            break;

            case 10:
            break;

            case 11:
                printf("+-------------------------------------------+\n");
                printf("|              Linear Algebra               |\n");
                printf("+-------------------------------------------+\n");
                printf("|1. Matrix addition 2x2                     |\n");
                printf("|2. Matrix addition 3x3                     |\n");
                printf("|3. Matrix subtraction 2x2                  |\n");
                printf("|4. Matrix subtraction 3x3                  |\n");
                printf("|5. Matrix multiplication 2x2               |\n");
                printf("|6. Matrix multiplication 3x3               |\n");
                printf("|7. Exit                                    |\n");
                printf("+-------------------------------------------+\n");
                printf("Choose a number(1-6) : ");
                scanf("%d",&choose1);
                switch(choose1){
                    case 1: 
                        matrix_2x2();
                    break;

                    case 2:
                        matrix_3x3();
                    break;

                    case 3:
                        matrix2x2();
                    break;

                    case 4:
                        matrix3x3();
                    break;

                    case 5:
                        multiplication_matrix_2x2();
                    break;

                    case 6:
                        multiplication_matrix_3x3();
                    break;

                    case 7: 
                        printf("thank you for using this program");
                        return 0;
                    break;

                    default: 
                        printf("Wrong number. . .");
                        printf("Please choose a correct number. . .");
                    break;
                }
            break;

            case 12:
                matrix_2x2();
            break;

            case 13:
                matrix_3x3();
            break;

            case 14:
                matrix2x2();
            break;

            case 15:
                matrix3x3();
            break;

            case 16:
                multiplication_matrix_2x2();
            break;

            case 17:
            break;

            case 18:
                printf("Thank you for using this program");
                return 0;
            break;

            default:
                printf("Wrong number. Please choose a correct number");
            break;
        }
    }while(1);
    return 0;
}