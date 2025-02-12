/**
 * @file main.c
 * @author Samuel Sánchez
 * @date 10 Feb 2025
 * @brief File with the main function of the program.
 *
 * This file contains the implementation of the `hexcat` program, which allows
 * the user to view the contents of a file in hexadecimal format with various
 * options for specifying the range, start byte, number of bytes to display,
 * byte offsets, and more.
 */

#include <getopt.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/hexcat.h"

/** Software details. */
#define NAME "hexcat"
#define VERSION "1.0.0"

/** Messages for invalid combinations. */
typedef enum INVALID_COMBINATION {
    START_MGS,
    END_MGS,
    RANGE_MGS,
    NUM_BYTES_MGS,
    BYTE_OFFSET_MGS
} Invalid_Combination;

/**
 * @brief Print the help message for the program.
 *
 * This function displays the usage instructions and options for the program.
 */
void print_help();

/**
 * @brief Print the version of the program.
 *
 * This function prints the current version of the program.
 */
void print_version();

/**
 * @brief Print the invalid combination message.
 *
 * This function prints one of the invalid combination messages.
 */
void print_invalid_message(Invalid_Combination type);

int main(int argc, char* argv[]) {
    /* File to read. */
    char* file = NULL;
    /* Flags values. */
    int start = -1;
    int end = -1;
    int offset = -1;
    int num_bytes = -1;
    /* Flag trackers */
    int has_start = 0;
    int has_end = 0;
    int has_range = 0;
    int has_num_bytes = 0;

    char* range_start = NULL;
    char* range_end = NULL;
    int opt;

    struct option long_options[] = {
        {"start", required_argument, NULL, 's'},
        {"end", required_argument, NULL, 'e'},
        {"range", required_argument, NULL, 'r'},
        {"num-bytes", required_argument, NULL, 'n'},
        {"byte-offset", required_argument, NULL, 'b'},
        {"version", no_argument, NULL, 'v'},
        {"help", no_argument, NULL, 'h'},
        {NULL, 0, NULL, 0}};

    while ((opt = getopt_long(argc, argv, "s:e:r:n:b:vh", long_options,
                              NULL)) != -1) {
        switch (opt) {
            case 's': /* Start byte */
                has_start = 1;
                if (has_range) {
                    print_invalid_message(START_MGS);
                    return 1;
                }
                start = strtol(optarg, NULL, 0);
                break;

            case 'e': /* End byte */
                has_end = 1;
                if (has_range || has_num_bytes) {
                    print_invalid_message(END_MGS);
                    return 1;
                }
                end = strtol(optarg, NULL, 0);
                break;

            case 'n': /* Number of bytes */
                has_num_bytes = 1;
                if (has_end || has_range) {
                    print_invalid_message(NUM_BYTES_MGS);
                    return 1;
                }
                num_bytes = strtol(optarg, NULL, 0);
                break;

            case 'b': /* Byte offset */
                offset = strtol(optarg, NULL, 0);
                break;

            case 'r': /* Range */
                has_range = 1;
                if (has_start || has_end || has_num_bytes) {
                    print_invalid_message(RANGE_MGS);
                    return 1;
                }
                range_start = strtok(optarg, ":");
                range_end = strtok(NULL, ":");
                if (!range_start || !range_end) {
                    fprintf(stderr, "Invalid range format. ");
                    fprintf(stderr, "Use --range <start>:<end>.\n");
                    return 1;
                }
                start = strtol(range_start, NULL, 0);
                end = strtol(range_end, NULL, 0);
                break;

            case 'v': /* Version */
                print_version();
                return 0;

            case 'h': /* Help */
                print_help();
                return 0;

            default:
                print_help();
                return 1;
        }
    }

    /* File check. */
    if (optind < argc) {
        file = argv[optind];
    } else {
        fprintf(stderr, "Error: No file specified.\n");
        print_help();
        return 1;
    }

    if ((has_start && has_end) || has_range) {
        /* It is verified that start is less than end. */
        if (start >= end) {
            fprintf(stderr, "Error: You cannot start after the end.\n");
            return 1;
        }
    }

    if (has_num_bytes) {
        /* The byte count starts at 0, 1 is subtracted to correctly represent
         * the range. For example, displaying 60 bytes means ending at byte 59.
         */
        if (!has_start) {
            end = num_bytes - 1;
        } else {
            end = start + num_bytes - 1;
        }
    }

    return hexcat(file, start, end, offset);
}

void print_help() {
    printf("Usage: %s [OPTIONS] <file>\n\n", NAME);
    printf("View the contents of a file in hexadecimal format.\n\n");
    printf("Options:\n");
    printf("  -s, --start <byte>        Start viewing the file from the specified byte (hexadecimal or decimal).\n");
    printf("  -e, --end <byte>          End viewing the file at the specified byte (hexadecimal or decimal).\n");
    printf("  -r, --range <start>:<end> View a range of bytes from <start> to <end> (hexadecimal or decimal).\n");
    printf("  -n, --num-bytes <count>   Display <count> bytes starting from the <start> byte.\n");
    printf("  -b, --byte-offset <byte>  Start viewing from a specific byte offset (relative position).\n");
    printf("  -v, --version             Show the version of the command.\n");
    printf("  -h, --help                Show this help message and exit.\n");
}

void print_version() {
    printf("%s version %s\n", NAME, VERSION);
}

void print_invalid_message(Invalid_Combination type) {
    fprintf(stderr, "Invalid combination:\n");
    switch (type) {
        case START_MGS:
            fprintf(stderr, "--start cannot be used with --range.\n");
            break;
        case END_MGS:
            fprintf(stderr, "--end cannot be used with ");
            fprintf(stderr, "--range or --num-bytes.\n");
            break;
        case RANGE_MGS:
            fprintf(stderr, "--range cannot be used with ");
            fprintf(stderr, "--start, --end or --num-bytes.\n");
            break;
        case NUM_BYTES_MGS:
            fprintf(stderr, "--num-bytes cannot be used with ");
            fprintf(stderr, "--end or --range.\n");
            break;
        default:
            fprintf(stderr, "You cannot be here.\n");
    }
}
