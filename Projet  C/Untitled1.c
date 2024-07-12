#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char buffer[80];
    printf( "Enter your login (only alpha-numeric characters) : " );
    scanf( "%s", buffer );

    bool isCorrect = true;
    size_t length = strlen( buffer );
    for( int i=0; i<length; i++ ) {
        if ( isalnum( buffer[i] ) == false ) {
            isCorrect = false;
        }
    }

    if ( isCorrect ) {
        printf( "Your login is correct\n" );
    } else {
        printf( "Your login is not correct\n" );
    }

    return EXIT_SUCCESS;
}
