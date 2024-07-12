#include <stdio.h>
#include "clex.h"

int main() {
    const char *input = "int main() { return 0; }";

    // Initialize the lexer
    clex_t lexer;
    clex_init(&lexer, input);

    // // Tokenize the input
    // ctok_t token = clex_next_token(&lexer);
    // while (token.type != CTOK_TYPE_EOF) {
    //     // Print token details
    //     printf("Token: type=%d, value='%s'\n", token.type, token.token.string);

    //     // Get next token
    //     token = clex_next_token(&lexer);
    // }

    clex_display_tokens(&lexer);

    return 0;
}
