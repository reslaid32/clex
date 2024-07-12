#ifndef CTOK_H
#define CTOK_H

#include <stddef.h>
#include <stdint.h>

typedef enum _e_ctok_type {
    CTOK_TYPE_STRING,
    CTOK_TYPE_INTEGER,
    CTOK_TYPE_FLOAT,
    CTOK_TYPE_IDENTIFIER,
    CTOK_TYPE_KEYWORD,
    CTOK_TYPE_OPERATOR,
    CTOK_TYPE_PUNCTUATION,
    CTOK_TYPE_COMMENT,
    CTOK_TYPE_WHITESPACE,
    CTOK_TYPE_NEWLINE,
    CTOK_TYPE_EOF // End of file
} ctok_type_t;

typedef struct _s_basic_ctok {
    char   *string;
    size_t  length;
} basic_ctok_t;

typedef struct _s_ctok {
    ctok_type_t         type;
    basic_ctok_t        token;
} ctok_t;

#endif // CTOK_H