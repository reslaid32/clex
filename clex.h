
#ifndef CLEX_H
#define CLEX_H

#include "ctok.h"

/**
 * @brief Struct representing input string and its length for the lexer.
 */
typedef struct _s_clex_input {
    const char     *string; /**< Input string */
    size_t          length; /**< Length of the input string */
} clex_input_t;

/**
 * @brief Struct representing the lexer state.
 */
typedef struct _s_clex {
    clex_input_t    input;           /**< Input string and its length */
    size_t          position;        /**< Current position in the input */
    size_t          read_position;   /**< Current read position in the input */
    char            current_char;    /**< Current character being processed */
    char            prev_char;       /**< Previous character processed */
    ctok_t          current_token;   /**< Current token being processed */
    ctok_t          prev_token;      /**< Previous token processed */
} clex_t;

/**
 * @brief Initializes the lexer with the provided input string.
 *
 * @param lexer Pointer to the lexer struct.
 * @param input Input string to tokenize.
 */
void clex_init(clex_t *lexer, const char *input);

/**
 * @brief Reads the next character from the input string and updates lexer state.
 *
 * @param lexer Pointer to the lexer struct.
 */
void clex_read_char(clex_t *lexer);

/**
 * @brief Skips whitespace characters in the input until a non-whitespace character is encountered.
 *
 * @param lexer Pointer to the lexer struct.
 */
void clex_skip_whitespace(clex_t *lexer);

/**
 * @brief Reads an identifier token from the lexer input.
 *
 * @param lexer Pointer to the lexer struct.
 * @return Identifier token.
 */
ctok_t clex_read_identifier(clex_t *lexer);

/**
 * @brief Reads a number token (integer or float) from the lexer input.
 *
 * @param lexer Pointer to the lexer struct.
 * @return Number token.
 */
ctok_t clex_read_number(clex_t *lexer);

/**
 * @brief Reads a string token enclosed in double quotes from the lexer input.
 *
 * @param lexer Pointer to the lexer struct.
 * @return String token.
 */
ctok_t clex_read_string(clex_t *lexer);

/**
 * @brief Retrieves the next token from the lexer input.
 *
 * @param lexer Pointer to the lexer struct.
 * @return Next token.
 */
ctok_t clex_next_token(clex_t *lexer);

/**
 * @brief Retrieves the current token from the lexer.
 *
 * @param lexer Pointer to the lexer struct.
 * @return Current token.
 */
ctok_t clex_current_token(clex_t *lexer);

/**
 * @brief Retrieves the previous token processed by the lexer.
 *
 * @param lexer Pointer to the lexer struct.
 * @return Previous token.
 */
ctok_t clex_prev_token(clex_t *lexer);

/**
 * @brief Displays all tokens parsed by the lexer.
 *
 * @param lexer Pointer to the lexer struct.
 */
void clex_display_tokens(clex_t *lexer);

#endif // CLEX_H
