#ifndef CTOK_H
#define CTOK_H

#include <stddef.h>
#include <stdint.h>

/**
 * @brief Macro to create a null token of type EOF.
 *
 * This macro calls the clex_make_token function with CTOK_TYPE_EOF, NULL, and 0
 * to create a null token representing the end of the file (EOF).
 *
 * @return Null token of type EOF.
 */
#define CTOK_MAKE_NULL_TOKEN() ctok_make_token(CTOK_TYPE_EOF, NULL, 0);

/**
 * @brief Enumeration of token types used in tokenization.
 */
typedef enum _e_ctok_type {
    CTOK_TYPE_STRING,       /**< String token type */
    CTOK_TYPE_INTEGER,      /**< Integer token type */
    CTOK_TYPE_FLOAT,        /**< Float token type */
    CTOK_TYPE_IDENTIFIER,   /**< Identifier token type */
    CTOK_TYPE_KEYWORD,      /**< Keyword token type */
    CTOK_TYPE_OPERATOR,     /**< Operator token type */
    CTOK_TYPE_PUNCTUATION,  /**< Punctuation token type */
    CTOK_TYPE_COMMENT,      /**< Comment token type */
    CTOK_TYPE_WHITESPACE,   /**< Whitespace token type */
    CTOK_TYPE_NEWLINE,      /**< Newline token type */
    CTOK_TYPE_EOF           /**< End of file token type */
} ctok_type_t;

/**
 * @brief Structure representing a basic token.
 */
typedef struct _s_basic_ctok {
    char   *string;  /**< Pointer to the string value of the token */
    size_t  length;  /**< Length of the token's string */
} basic_ctok_t;

/**
 * @brief Structure representing a token with type information.
 */
typedef struct _s_ctok {
    ctok_type_t         type;   /**< Type of the token */
    basic_ctok_t        token;  /**< Basic information about the token */
} ctok_t;

/**
 * @brief Creates a token with the specified type, string start, and length.
 *
 * @param type Type of the token.
 * @param start Pointer to the start of the token string.
 * @param length Length of the token string.
 * @return Created token.
 */
ctok_t ctok_make_token(ctok_type_t type, const char *start, size_t length);

/**
 * @brief Displays the type of a token.
 *
 * @param type Type of the token.
 */
void ctok_display_token_type(ctok_type_t type);

#endif // CTOK_H
