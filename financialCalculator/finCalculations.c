#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include "finCalculations.h"


void calculations ( int years, float **result, Row *rows )
{
    int i;
    for ( i = 0; i < 23; i++ )
    {
        *result = ( float* ) calloc ( sizeof ( float ), years );
    }
    liquidity ( years, result, rows );
    liquidity ( years, result, rows );
    liquidity ( years, result, rows );
}

void liquidity ( int years, float **result, Row *rows )
{
    int i;
    for ( i = 0; i < years; i++ )
    {
        if ( ( rows + 49 )->average[i] > 0 && ( rows + 98 )->average[i] > 0 )
        {
            * ( * ( result + 0 ) + i ) = ( rows + 49 )->average[i] / ( rows + 98 )->average[i] ;
        }
    }
    for ( i = 0; i < years; i++ )
    {
        if ( ( rows + 49 )->average[i] > 0 && ( rows + 98 )->average[i] > 0 && ( rows + 23 )->average[i] > 0 )
        {
            * ( * ( result + 1 ) + i ) = ( ( rows + 49 )->average[i] - ( rows + 23 )->average[i] ) / ( rows + 98 )->average[i] ;
        }
    }
    for ( i = 0; i < years; i++ )
    {
        if ( ( rows + 39 )->average[i] > 0 && ( rows + 98 )->average[i] > 0 )
        {
            * ( * ( result + 2 ) + i ) = ( rows + 39 )->average[i] / ( rows + 98 )->average[i] ;
        }
    }
}

void finStability ( int years, float **result, Row *rows )
{
    int i;
    for ( i = 0; i < years; i++ )
    {
        if ( ( rows + 63 )->average[i] > 0 && ( rows + 51 )->average[i] > 0 )
        {
            * ( * ( result + 3 ) + i ) = ( rows + 63 )->average[i] / ( rows + 51 )->average[i] ;
        }
    }
    for ( i = 0; i < years; i++ )
    {
        if ( ( rows + 98 )->average[i] > 0 && ( rows + 101 )->average[i] > 0 )
        {
            * ( * ( result + 4 ) + i ) = ( rows + 98 )->average[i] / ( rows + 101 )->average[i] ;
        }
    }
    for ( i = 0; i < years; i++ )
    {
        if ( ( rows + 98 )->average[i] > 0 && ( rows + 63 )->average[i] > 0 )
        {
            * ( * ( result + 5 ) + i ) = ( rows + 98 )->average[i] / ( rows + 63 )->average[i] ;
        }
    }
    for ( i = 0; i < years; i++ )
    {
        if ( ( rows + 63 )->average[i] > 0 && ( rows + 22 )->average[i] > 0 )
        {
            * ( * ( result + 6 ) + i ) = ( ( rows + 63 )->average[i] - ( rows + 22 )->average[i] ) / ( rows + 63 )->average[i] ;
        }
    }
    for ( i = 0; i < years; i++ )
    {
        if ( ( rows + 63 )->average[i] > 0 && ( rows + 22 )->average[i] > 0 && ( rows + 49 )->average[i] > 0 )
        {
            * ( * ( result + 7 ) + i ) = ( ( rows + 63 )->average[i] - ( rows + 22 )->average[i] ) / ( rows + 49 )->average[i] ;
        }
    }
    for ( i = 0; i < years; i++ )
    {
        if ( ( rows + 63 )->average[i] > 0 && ( rows + 22 )->average[i] > 0 && ( rows + 23 )->average[i] > 0 )
        {
            * ( * ( result + 8 ) + i ) = ( ( rows + 63 )->average[i] - ( rows + 22 )->average[i] ) / ( rows + 23 )->average[i] ;
        }
    }
}

void profitability ( int years, float **result, Row *rows )
{
    int i, supportValue, supportValue2;
    for ( i = 0; i < years; i++ )
    {
        if ( ( rows + 139 )->average[i] > 0 && ( rows + 51 )->average[i] > 0 )
        {
            * ( * ( result + 9 ) + i ) = ( rows + 139 )->average[i] / ( rows + 51 )->average[i] ;
        }
    }
    for ( i = 0; i < years; i++ )
    {
        if ( ( rows + 139 )->average[i] > 0 && ( rows + 63 )->average[i] > 0 )
        {
            * ( * ( result + 10 ) + i ) = ( rows + 139 )->average[i] / ( rows + 63 )->average[i] ;
        }
    }
    for ( i = 0; i < years; i++ )
    {
        if ( ( rows + 139 )->average[i] > 0 && ( rows + 102 )->average[i] > 0 )
        {
            * ( * ( result + 11 ) + i ) = ( rows + 139 )->average[i] / ( rows + 102 )->average[i] ;
        }
    }
    for ( i = 0; i < years; i++ )
    {
        if ( ( rows + 139 )->average[i] > 0 && ( rows + 139 )->average[i] > 0 && ( rows + 139 )->average[i] > 0 && ( rows + 139 )->average[i] > 0 )
        {
            supportValue = ( rows + 139 )->average[i] + ( rows + 139 )->average[i] + ( rows + 139 )->average[i] + ( rows + 139 )->average[i];
            if ( ( rows + 125 )->average[i] > 0 )
            {
                * ( * ( result + 12 ) + i ) = ( rows + 125 )->average[i] / supportValue ;
            }
        }
    }
    for ( i = 0; i < years; i++ )
    {
        if ( ( rows + 139 )->average[i] > 0 && ( rows + 139 )->average[i] > 0 && ( rows + 139 )->average[i] > 0 && ( rows + 139 )->average[i] > 0 )
        {
            supportValue = ( rows + 139 )->average[i] + ( rows + 139 )->average[i] + ( rows + 139 )->average[i] + ( rows + 139 )->average[i];
            if ( ( rows + 131 )->average[i] > 0 && ( rows + 132 )->average[i] > 0 && ( rows + 133 )->average[i] > 0 )
            {
                supportValue2 = supportValue + ( rows + 131 )->average[i] + ( rows + 132 )->average[i] + ( rows + 133 )->average[i];
                if ( ( rows + 125 )->average[i] > 0 )
                {
                    * ( * ( result + 13 ) + i ) = ( rows + 125 )->average[i] / supportValue2 ;
                }
            }
        }
    }
    for ( i = 0; i < years; i++ )
    {
        if ( ( rows + 139 )->average[i] > 0 && ( rows + 139 )->average[i] > 0 && ( rows + 139 )->average[i] > 0 && ( rows + 139 )->average[i] > 0 )
        {
            supportValue = ( rows + 139 )->average[i] + ( rows + 139 )->average[i] + ( rows + 139 )->average[i] + ( rows + 139 )->average[i];
            if ( ( rows + 131 )->average[i] > 0 && ( rows + 132 )->average[i] > 0 && ( rows + 133 )->average[i] > 0 )
            {
                supportValue2 = supportValue + ( rows + 131 )->average[i] + ( rows + 132 )->average[i] + ( rows + 133 )->average[i];
                if ( ( rows + 139 )->average[i] > 0 )
                {
                    * ( * ( result + 14 ) + i ) = ( rows + 139 )->average[i] / supportValue2 ;
                }
            }
        }
    }
}

void businessActivity ( int years, float **result, Row *rows )
{
    int i, supportValue;
    for ( i = 0; i < years; i++ )
    {
        if ( ( rows + 102 )->average[i] > 0 && ( rows + 51 )->average[i] > 0 )
        {
            * ( * ( result + 15 ) + i ) = ( rows + 102 )->average[i] / ( rows + 51 )->average[i] ;
        }
    }
    for ( i = 0; i < years; i++ )
    {
        if ( ( rows + 102 )->average[i] > 0 && ( rows + 98 )->average[i] > 0 )
        {
            * ( * ( result + 16 ) + i ) = ( rows + 102 )->average[i] / ( rows + 98 )->average[i] ;
            * ( * ( result + 19 ) + i ) = 360 / * ( * ( result + 16 ) + i );
        }
    }
    for ( i = 0; i < years; i++ )
    {
        if ( ( rows + 32 )->average[i] > 0 && ( rows + 33 )->average[i] > 0 && ( rows + 35 )->average[i] > 0 && ( rows + 36 )->average[i] > 0 && ( rows + 37 )->average[i] )
        {
            supportValue = ( rows + 32 )->average[i] + ( rows + 33 )->average[i] + ( rows + 35 )->average[i] + ( rows + 36 )->average[i] + ( rows + 37 )->average[i];
            if ( ( rows + 102 )->average[i] > 0 && ( rows + 51 )->average[i] > 0 )
            {
                * ( * ( result + 17 ) + i ) = ( rows + 102 )->average[i] / supportValue ;
                * ( * ( result + 18 ) + i ) = 360 / * ( * ( result + 17 ) + i );
            }
        }
    }
    for ( i = 0; i < years; i++ )
    {
        if ( ( rows + 102 )->average[i] > 0 && ( rows + 4 )->average[i] > 0 )
        {
            * ( * ( result + 20 ) + i ) = ( rows + 102 )->average[i] / ( rows + 4 )->average[i] ;
        }
    }
    for ( i = 0; i < years; i++ )
    {
        if ( ( rows + 102 )->average[i] > 0 && ( rows + 63 )->average[i] > 0 )
        {
            * ( * ( result + 21 ) + i ) = ( rows + 102 )->average[i] / ( rows + 63 )->average[i] ;
        }
    }
}
