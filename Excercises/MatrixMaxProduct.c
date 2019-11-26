#include <stdio.h>

int size, n;

void get_sub_matrix(int source_matrix[][size], int start_row, int start_column,  int sub_matrix[][n]){
    int r = 0, c = 0;
    for(int i = start_row; i < (start_row + n); i++){
        for(int j = start_column; j < (start_column + n); j++){
            //printf("DEBUG: i = %d, j = %d\n", i, j);
            sub_matrix[r][c++] = source_matrix[i][j];
            //printf("DEBUG: [%d][%d] = %d\n", r, c - 1, sub_matrix[r][c - 1]);
        }
        c = 0;
        r++;
    }

}

int maxProduct(int matrix[][size]){
    // Iterate through all (n x n) sub-matrices

    scanf("%d", &n);

    int sub_matrix[n][n];

    int max_product = 0;

    int start_x = 0, start_y = 0;

    for(int i = 0; i < (size - n + 1); i++){
        for(int j = 0; j < (size - n + 1); j++){
            get_sub_matrix(matrix, i, j, sub_matrix);

            /*printf("*******************DEBUG: START******************\n");
            for(int x = 0; x < n; x++){
                for(int y = 0; y < n; y++){
                    printf("[%d][%d] = %d ", x, y, sub_matrix[x][y]);
                }
                printf("\n");
            }
            printf("*******************DEBUG: END******************\n");*/


            // Find out the maximum product
            int temp_max_product = 0;

            int max_product_linear = 0;

            int max_product_row = 1;
            int max_product_column = 1;

            for(int x = 0; x < n; x++){
                int product_row = 1, product_column = 1;
                int location_array_row[n][2], location_array_column[n][2];
                for(int y = 0; y < n; y++){
                    product_row *= sub_matrix[x][y];

                    product_column *= sub_matrix[y][x];
                }

                if(product_row > max_product_row){
                    max_product_row = product_row;
                }

                if(product_column > max_product_column){
                    max_product_column = product_column;
                }
            }

            if(max_product_row > max_product_column){
                max_product_linear = max_product_row;
            }else{
                max_product_linear = max_product_column;
            }

            int max_product_diagonal = 0;
            int product_diagonal = 1; int product_anti_diagonal = 1;

            for(int x = 0; x < n; x++){
                product_diagonal *= sub_matrix[x][x];

                product_anti_diagonal *= sub_matrix[n-1-x][n-1-x];
            }

            if(product_diagonal > product_anti_diagonal){
                max_product_diagonal = product_diagonal;
            }else{
                max_product_diagonal = product_anti_diagonal;
            }

            if(max_product_linear > max_product_diagonal){
                temp_max_product = max_product_linear;
            }else{
                temp_max_product = max_product_diagonal;
            }

            if(temp_max_product > max_product){
                max_product = temp_max_product;

                // Record the start_X and start_y position of the sub-matrix where max_product is located
                start_x = i;
                start_y = j;
            }
        }
    }

    // Retrieve the sub-matrix where max_product is located
    int targeted_matrix[n][n];
    int glorious_pairs[n][2];

    get_sub_matrix(matrix, start_x, start_y, targeted_matrix);

    // Find whether max_product is located diagonally or anti-diagonally.
    // If so, record the co-ordinates of those elements

    int prod_d = 1, prod_ad = 1;

    for(int z = 0; z < n; z++){
        prod_d *= targeted_matrix[z][z];
        prod_ad *= targeted_matrix[n-1-z][n-1-z];
    }

    if(prod_d == max_product){
        for(int x = 0; x < n; x++){
            glorious_pairs[x][0] = x;
            glorious_pairs[x][1] = x;
        }
    }else if(prod_ad == max_product){
        for(int x = 0; x < n; x++){
            glorious_pairs[n-1-x][0] = n-1-x;
            glorious_pairs[n-1-x][1] = n-1-x;
        }
    }else{
        // If max_product is not located diagonally or anti-diagonally,
        // look for the row or column where it is located and record the co-ordinates.

        for(int i = 0; i < n; i++){
            int prod_x = 1, prod_y = 1;
            for(int j = 0; j < n; j++){
                prod_x *= targeted_matrix[i][j];
                prod_y *= targeted_matrix[j][i];
            }

            if(prod_x == max_product){
                for(int x = 0; x < n; x++){
                    glorious_pairs[x][0] = i;
                    glorious_pairs[x][1] = x;
                }
                break;
            }else if(prod_y == max_product){
                for(int x = 0; x < n; x++){
                    glorious_pairs[x][0] = x;
                    glorious_pairs[x][1] = i;
                }
                break;
            }
        }
    }

    // Print an (n x 2) matrix containing the co-ordinates of the elements that make the max_product

    printf("[");
    for(int i = 0; i < n; i++){
        printf("%d %d", glorious_pairs[i][0]+ start_x, glorious_pairs[i][1]+ start_y);

        if(i != n-1){
            printf("; ");
        } else{
            printf("]\n");
        }

    }

    // Return value is just for testing purposes.
    return max_product;
}

int MatrixMaxProduct_main(){
    // Create a (size x size) matrix where size is the user input
    scanf("%d", &size);

    int matrix[size][size];

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
            printf("\n");
        }
    }

    maxProduct(matrix);

    return 0;

}
