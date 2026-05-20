/*
* String slices utility
*/


/*
 * --- CORE PRIMITIVES (The Bare Minimum) ---
 * jj_slice_make(const char* ptr, size_t len): Creates a slice from a raw pointer and an explicit length.
 * jj_slice_from_cstr(const char* str): Creates a slice from a null-terminated string, calculating length under the hood.
 * jj_slice_subslice(jj_slice s, size_t start, size_t len): Returns a new slice representing a sub-region of 's', clamping to safe bounds.
 *
 * --- ESSENTIAL OPERATIONS & INTEROP ---
 * jj_slice_eq(jj_slice a, jj_slice b): Returns true (1) if both slices have the exact same length and identical contents.
 * jj_slice_to_cstr(jj_slice s, char* buffer, size_t buf_size): Safely copies the slice to a user-provided buffer and guarantees null-termination.
 * jj_slice_slccpy(jj_slice dest, jj_slice src): Safely copies 'src' contents into 'dest', truncating gracefully if 'dest' is smaller.
 * jj_slice_cmp(jj_slice a, jj_slice b): Lexicographically compares two slices (returns <0, 0, or >0, similar to memcmp).
 *
 * --- BASIC SEARCHING ---
 * jj_slice_find_char(jj_slice s, char c): Returns the index of the first occurrence of 'c', or -1 (or size_t max) if not found.
 * jj_slice_starts_with(jj_slice s, jj_slice prefix): Returns true if 's' begins with the contents of 'prefix'.
 * jj_slice_ends_with(jj_slice s, jj_slice suffix): Returns true if 's' ends with the contents of 'suffix'.
 *
 * --- ADVANCED / EXOTIC (Parsing & Complex Search) ---
 * jj_slice_find_slice(jj_slice haystack, jj_slice needle): Returns the index of the first occurrence of 'needle' inside 'haystack'.
 * jj_slice_trim(jj_slice s): Returns a new slice with all leading and trailing whitespace adjusted away (ptr moves forward, len shrinks).
 * jj_slice_split(jj_slice* s, char delim): Returns the slice before 'delim' and mutates 's' to point to the remainder (perfect for loop iteration).
 */

#define DEBUG


#ifndef JJ_SLICES_H
#define JJ_SLICES_H

// --- includes --
// system includes
#include <stddef.h>
#include <stdint.h>

//--- user defined includes ---

#ifndef JJ_SLICES_MALLOC
    #include <stdlib.h>
    #define JJ_SLICES_MALLOC malloc
    #define JJ_SLICES_FREE free
    #define JJ_SLICES_REALLOC realloc
#endif // !JJ_SLICES_MALLOC


#ifndef JJ_SLICES_MEMCPY
    #include <string.h>
    #define JJ_SLICES_MEMCPY memcpy
    #define JJ_SLICES_MEMMOVE memmove
    #define JJ_SLICES_MEMCMP memcmp
#endif // !JJ_SLICES_MALLOC


typedef struct {
    char* buffer;
    size_t size;
} jj_str_slice;


typedef struct {
    const void* buffer;
    size_t size;
} jj_bin_slice;

#endif // !JJ_SLICES_H

#ifdef DEBUG
    #define JJ_SLICES_IMPLEMENTATION
#endif


#ifdef JJ_SLICES_IMPLEMENTATION

#endif // JJ_SLICES_IMPLEMENTATION












