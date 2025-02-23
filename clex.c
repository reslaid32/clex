#include "clex.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void clex_init(clex_t *lexer, const char *input) {
    lexer->input.string = input;
    lexer->input.length = strlen(input);
    lexer->position = 0;
    lexer->read_position = 0;
    lexer->current_char = input[0];
    lexer->current_token = CTOK_MAKE_NULL_TOKEN();
    lexer->prev_token = CTOK_MAKE_NULL_TOKEN();
}

void clex_read_char(clex_t *lexer) {
    if (lexer->read_position >= lexer->input.length) {
        lexer->current_char = 0; // Null character to indicate end of input
    } else {
        lexer->current_char = lexer->input.string[lexer->read_position];
    }
    lexer->prev_char = lexer->input.string[lexer->position];
    lexer->position = lexer->read_position;
    lexer->read_position++;
}

void clex_skip_whitespace(clex_t *lexer) {
    while (isspace(lexer->current_char)) {
        clex_read_char(lexer);
    }
}

ctok_t clex_read_identifier(clex_t *lexer) {
    size_t start_pos = lexer->position;
    while (isalpha(lexer->current_char) || lexer->current_char == '_') {
        clex_read_char(lexer);
    }
    size_t length = lexer->position - start_pos;
    return ctok_make_token(CTOK_TYPE_IDENTIFIER, lexer->input.string + start_pos, length);
}

ctok_t clex_read_number(clex_t *lexer) {
    size_t start_pos = lexer->position;
    while (isdigit(lexer->current_char)) {
        clex_read_char(lexer);
    }
    size_t length = lexer->position - start_pos;
    return ctok_make_token(CTOK_TYPE_INTEGER, lexer->input.string + start_pos, length);
}

ctok_t clex_read_string(clex_t *lexer) {
    size_t start_pos = lexer->position + 1; // Skip the starting quote
    clex_read_char(lexer);
    while (lexer->current_char != '"' && lexer->current_char != 0) {
        clex_read_char(lexer);
    }
    size_t length = lexer->position - start_pos;
    clex_read_char(lexer); // Skip the ending quote
    return ctok_make_token(CTOK_TYPE_STRING, lexer->input.string + start_pos, length);
}

ctok_t clex_next_token(clex_t *lexer) {
    clex_skip_whitespace(lexer);

    ctok_t token;
    switch (lexer->current_char) {
        case '"':
            token = clex_read_string(lexer);
            break;
        case 0:
            token = ctok_make_token(CTOK_TYPE_EOF, "", 0);
            break;
        default:
            if (isalpha(lexer->current_char) || lexer->current_char == '_') {
                return clex_read_identifier(lexer);
            } else if (isdigit(lexer->current_char)) {
                return clex_read_number(lexer);
            } else {
                token = ctok_make_token(CTOK_TYPE_PUNCTUATION, &lexer->current_char, 1);
                clex_read_char(lexer);
            }
            break;
    }
    lexer->prev_token = lexer->current_token;
    lexer->current_token = token;
    return token;
}

ctok_t clex_current_token(clex_t *lexer) {
    return lexer->current_token;
}

ctok_t clex_prev_token(clex_t *lexer) {
    return lexer->prev_token;
}

void clex_display_tokens(clex_t *lexer) {
    ctok_t token;
    size_t index = 0;

    printf("Token List:\n");
    do {
        index++;
        token = clex_next_token(lexer);

        printf("  Token { Index: %zu, Type: [ Index: %d, Name: ", index, (int)token.type);
        
        ctok_display_token_type(token.type);

        printf(" ] }\n");
    } while (token.type != CTOK_TYPE_EOF);
}
