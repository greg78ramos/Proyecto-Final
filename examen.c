//Proyecto Final Morales Ramos Gregorio Ixu//

#include <stdio.h>

int main()
{
    char songs[10][50], song ;
    int i;
    
    for( i = 0 ; i < 10 ; i++ )
    {
    printf("Proporcioname la canción número %d: ", i+1);
    scanf(" %c", &song );
    songs[i] = song;
    }
    
    for( i = 0 ; i < 10 ; i++ )
    {
    printf("Canción %d: %c ", i+1, songs[i]);
    }
    
    return 0;
}
