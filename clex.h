#ifndef CLEX_H
#define CLEX_H

#include "ctok.h"

#define CLEX_MAKE_NULL_TOKEN() clex_make_token(CTOK_TYPE_EOF, NULL, 0);

typedef struct _s_clex_input {
    const char     *string;
    size_t          length;
} clex_input_t;

typedef struct _s_clex {
    clex_input_t    input;
    size_t          position;
    size_t          read_position;
    char            current_char;
    char            prev_char;
    ctok_t          current_token;
    ctok_t          prev_token;
} clex_t;

void clex_init(clex_t *lexer, const char *input);
void clex_read_char(clex_t *lexer);
void clex_skip_whitespace(clex_t *lexer);
ctok_t clex_make_token(ctok_type_t type, const char *start, size_t length);
ctok_t clex_read_identifier(clex_t *lexer);
ctok_t clex_read_number(clex_t *lexer);
ctok_t clex_read_string(clex_t *lexer);
ctok_t clex_next_token(clex_t *lexer);
ctok_t clex_current_token(clex_t *lexer);
ctok_t clex_prev_token(clex_t *lexer);
void clex_display_token_type(ctok_type_t type);
void clex_display_tokens(clex_t *lexer);

#endif // CLEX_H
