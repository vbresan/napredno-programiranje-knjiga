#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BLOCK_SIZE 1000
#define BLOCK_DIGITS 3
#define MAX_SIZE 10000 
#define MAX_PRODUCT_SIZE (2 * MAX_SIZE)

// Function to convert a string representation of a large number into an array of blocks
void read_large_number(const char *s, int *arr, int *num_blocks) {
    int len = strlen(s);
    int block_val = 0;
    int block_pos = 0;
    int block_power_of_10 = 1;
    
    // Initialize the array to zeros
    for (int i = 0; i < MAX_SIZE; i++) {
        arr[i] = 0;
    }

    // Process the string from right to left, creating blocks
    for (int i = len - 1; i >= 0; i--) {
        block_val += (s[i] - '0') * block_power_of_10;
        block_power_of_10 *= 10;
        
        // If we've reached a full block or the beginning of the string
        if (block_power_of_10 == BLOCK_SIZE || i == 0) {
            arr[block_pos] = block_val;
            block_pos++;
            block_val = 0;
            block_power_of_10 = 1;
        }
    }
    *num_blocks = block_pos;
}

// Function to print the large number from its array representation
void print_large_number(const int *arr, int num_blocks) {
    if (num_blocks == 0) {
        printf("0");
        return;
    }

    // Find the most significant block
    int first_digit_index = num_blocks - 1;
    while (first_digit_index >= 0 && arr[first_digit_index] == 0) {
        first_digit_index--;
    }

    if (first_digit_index < 0) {
        printf("0");
        return;
    }
    
    // Print the most significant block (without leading zeros)
    printf("%d", arr[first_digit_index]);

    // Print the rest of the blocks with leading zeros
    for (int i = first_digit_index - 1; i >= 0; i--) {
        printf("%0*d", BLOCK_DIGITS, arr[i]);
    }
}

int main() {
    char s1[MAX_SIZE + 1];
    char s2[MAX_SIZE + 1];

    printf("Enter the first large number: ");
    scanf("%s", s1);

    printf("Enter the second large number: ");
    scanf("%s", s2);

    int num1[MAX_SIZE];
    int num2[MAX_SIZE];
    int product[MAX_PRODUCT_SIZE] = {0};

    int num1_blocks, num2_blocks, product_blocks;
    
    read_large_number(s1, num1, &num1_blocks);
    read_large_number(s2, num2, &num2_blocks);

    // --- The Multiplication Algorithm ---

    // 1. Core Multiplication
    for (int i = 0; i < num1_blocks; i++) {
        for (int j = 0; j < num2_blocks; j++) {
            product[i + j] += num1[i] * num2[j];
        }
    }

    // 2. Carry-over
    product_blocks = num1_blocks + num2_blocks;
    for (int i = 0; i < product_blocks; i++) {
        int carry = product[i] / BLOCK_SIZE;
        product[i] %= BLOCK_SIZE;
        product[i + 1] += carry;
    }

    // --- End of Algorithm ---
    
    // Find the actual number of blocks in the product
    product_blocks = num1_blocks + num2_blocks;
    while (product_blocks > 0 && product[product_blocks - 1] == 0) {
        product_blocks--;
    }

    printf("\nProduct: ");
    print_large_number(product, product_blocks);
    printf("\n");

    return 0;
}
