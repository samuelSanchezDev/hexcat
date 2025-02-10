/**
 * @file hexcat.h
 * @author Samuel Sánchez
 * @date 10 Feb 2025
 * @brief Header file for the `hexcat` function.
 *
 * This file declares the `hexcat` function, which reads a specified segment
 * of a file and prints its contents in hexadecimal format.
 */
#ifndef _HEXCAT_H
#define _HEXCAT_H

/**
 * @brief Prints a hexadecimal view of a file segment.
 *
 * Reads and displays a portion of a file in hexadecimal format, based on the
 * specified byte range and offset. If any of the integer parameters (`start`,
 * `end`, or `offset`) are negative, they are ignored.
 *
 * @param filename Path to the file to be read.
 * @param start Byte position (from the start) where reading begins (ignored if
 * negative).
 * @param end Byte position (from the end) where reading stops (ignored if
 * negative).
 * @param offset Additional offset applied to the start position (ignored if
 * negative).
 * @return 0 on success, a nonzero value on error.
 */
int hexcat(const char* filename, int start, int end, int offset);

#endif