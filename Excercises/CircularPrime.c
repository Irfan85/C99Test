#include <stdio.h>

int is_prime(int num) {
    int div_count = 0;
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            div_count++;
        }
    }

    if (div_count == 0) {
        return 0;
    }
    return 1;
}

// The pow() function of C returns double value which causes inaccuracy while dealing with int.
// So, I made my own power function
int to_the_power(int b, int p){
    int res = 1;
    for(int i = 0; i < p; i++){
        res *= b;
    }
    return res;
}

int is_circular_prime(int input) {
    int input_cpy = input;

    // Determine how many digits are in input
    int digit_number = 0;

    if (input_cpy >= 10) {
        digit_number++;
    }

    while ((input_cpy / 10) >= 10) {
        digit_number++;
        input_cpy = input_cpy / 10;
    }

    digit_number++;

   /* TESTING
    printf("%d\n", digit_number);*/

    // DONE: Determine how many digits are in input

    // Turn the input to an array of digits that it contains
    input_cpy = input;
    int input_digit_array[digit_number];

    int remainder;
    for (int i = digit_number - 1; i >= 0; i--) {
        remainder = input_cpy % 10;
        //printf("DEBUG: rem : %d\n", remainder);
        input_digit_array[i] = remainder;
        input_cpy = input_cpy / 10;
    }

    /* TESTING
    printf("DEBUGGING:");
    for(int i = 0; i < digit_number; i++){
        printf("%d", input_digit_array[i]);
    }
    printf("\n");*/

    //DONE: Turn the input to an array of digits that it contains

    // Make cyclic permutations
    int cyclic_permutation_array[digit_number][digit_number];

    int start_pos = 0, ignore_pos = 0;
    for (int i = 0; i < digit_number; i++) {
        for (int j = 0; j < digit_number; j++) {
            if (start_pos + j < digit_number) {
                cyclic_permutation_array[i][j] = input_digit_array[start_pos + j];
            } else {
                cyclic_permutation_array[i][j] = input_digit_array[(start_pos + j) - digit_number];
            }

        }
        start_pos++;
    }

    /* TESTING
    printf("DEBUGGING:");
    for(int i = 0; i < digit_number; i++){
        for(int j = 0; j < digit_number; j++){
            printf("%d", cyclic_permutation_array[i][j]);
        }
        printf("\n");
    }*/

    // DONE: Make cyclic permutations

    // Convert the arrays to numbers
    int generated_numbers[digit_number];

    for (int i = 0; i < digit_number; i++) {
        int num = 0, power = 0;
        for (int j = digit_number - 1; j >= 0; j--) {
            num += (cyclic_permutation_array[i][j] * to_the_power(10, power++));
        }
        generated_numbers[i] = num;
    }

    /* TESTING
    printf("For %d,\n", input);
    for(int i = 0; i < digit_number; i++){
        printf("Number: %d\n", generated_numbers[i]);
    }*/

    // DONE: Convert the arrays to numbers

    // Check whether each of the numbers are prime numbers or not
    int is_all_prime = 0;
    for (int i = 0; i < digit_number; i++) {
        if (is_prime(generated_numbers[i]) == 1) {
            is_all_prime = 1;
            break;
        }
    }
    // DONE: Check whether each of the numbers are prime numbers or not

    if (is_all_prime == 0) {
        return 0;
    }

    return 1;
}

int CircularPrime_main() {
    int n;
    scanf("%d", &n);

    for (int i = 2; i < n; i++) {
        if (is_prime(i) == 0) {
            if (is_circular_prime(i) == 0) {
                printf("%d\n", i);
            }
        }
    }

    return 0;
}
