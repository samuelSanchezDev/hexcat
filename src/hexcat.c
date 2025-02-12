/**
 * @file hexcat.c
 * @author Samuel Sánchez
 * @date 10 Feb 2025
 * @brief Implementation of the `hexcat` function.
 *
 * This file implements the `hexcat` function, which reads a specified segment
 * of a file and prints its contents in hexadecimal format.
 */

#include "../include/hexcat.h"
#include <stdio.h>
#include <stdlib.h>

#define ROW_LEN 16 /** Length of the string (bytes) read from the file. */
#define PADDING 8  /** Length of the index field. */

#define PRINTABLE_CHAR(c) (((c) >= 33) && ((c) <= 126))
/** Macro to check if a character is printable (ASCII range 33-126). */

/**
 * @brief Prints the header row for the hex dump.
 *
 * This function prints the column headers, which represent the byte offsets
 * in a row. The output follows a structured format for better readability.
 */
void print_head();

/**
 * @brief Prints a row of bytes in hexadecimal and ASCII format.
 *
 * This function prints a row of bytes in both hexadecimal and ASCII format.
 * Non-printable characters are replaced with spaces.
 *
 * @param row Pointer to the array of bytes to print.
 * @param length Number of bytes in the row.
 * @param location Starting position of the row in the file.
 */
void print_row(const unsigned char* row, int length, int location);

int hexcat(const char* filename, int start, int end, int offset) {
    FILE* file = NULL;
    int byte_counter = 0;
    unsigned char* row = NULL;
    int row_len = 0;
    int end_loop = 0;
    int end_flag = 0;

    /* Open file. */
    file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    /* If there is an offset, it is set. */
    if (offset > 0) {
        if (fseek(file, offset, SEEK_CUR) != 0) {
            perror("Failed to set offset");
            fclose(file);
            return 1;
        }
    }

    /* If there is a start position, it is set. */
    if (start > 0) {
        byte_counter = start;
        if (fseek(file, start, SEEK_CUR) != 0) {
            perror("Failed to set start position");
            fclose(file);
            return 1;
        }
    }

    if (end > 0) {
        end_flag = 1;
    }

    row = (unsigned char*)calloc(ROW_LEN, sizeof(char));
    if (!row) {
        fprintf(stderr, "Memory allocation error.");
        fclose(file);
        return 1;
    }

    /* Print the column headers. */
    print_head();

    /* Read and process the file in chunks of ROW_LEN bytes. */
    while (!end_loop) {
        row_len = fread(row, sizeof(unsigned char), ROW_LEN, file);

        if (row_len != ROW_LEN) { /* Check if end of file is reached. */
            if (row_len == 0) {   /* Final reached without content to print. */
                break;
            }
            end_loop = 1;

        } else if (end_flag) { /* Check if the end position has been reached. */
            if (byte_counter + row_len >= end) {
                end_loop = 1;
                /* The addition of the 1 is to convert the position of the last
                 * byte to the size. Example: Position 46 corresponds to 47
                 * bytes. */
                row_len = (end + 1) - byte_counter;
            }
        }

        print_row(row, row_len, byte_counter);
        byte_counter += row_len;
    }

    if (ferror(file)) {
        fprintf(stderr, "Error reading the file.\n");
    }

    free(row);
    fclose(file);
    return 0;
}

void print_head() {
    printf("%*s 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n", PADDING,
           "");
}

void print_row(const unsigned char* row, int length, int location) {
    int i;

    /* Print the starting index of the row in hexadecimal format. */
    printf("%0*X ", PADDING, location);

    /* Print each byte as a two-digit hexadecimal number. */
    for (i = 0; i < length; i++) {
        printf("%02X ", row[i]);
    }

    /* Pad the output with spaces if the row is shorter than ROW_LEN. */
    for (i = length; i < ROW_LEN; i++) {
        printf("   ");
    }

    /* Print ASCII representation, replacing non-printable characters with
     * spaces. */
    for (i = 0; i < length; i++) {
        printf("%c", PRINTABLE_CHAR(row[i]) ? row[i] : ' ');
    }

    printf("\n");
}
