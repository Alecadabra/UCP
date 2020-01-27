#ifndef ORDER_H
    #define ORDER_H

    #ifndef TEST_HARNESS
        typedef void (*OrderMethod)( int*, int*, int* );

        static OrderMethod order( char );
    #endif

    static void ascending2( int*, int* );

    static void ascending3( int*, int*, int* );

    static void descending2( int*, int* );

    static void descending3( int*, int*, int* );
#endif
