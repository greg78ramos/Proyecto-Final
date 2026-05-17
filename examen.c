//Proyecto Final Morales Ramos Gregorio Ixu//

#include <stdio.h>

// encabezados//

int lectura(int votosdeparticipantes[100][3],char *tituloscanciones[10]);
void votaciones(int votosdeparticipantes[100][3], int totaldeparticipantes, char *tituloscanciones[10], int *id1, int *id2);
void premiacion(int votosdeparticipantes[100][3], int totaldeparticipantes, int id1, int id2);

int main() 
{
    //declaración de variables y matrices//
    char *tituloscanciones[10] = {"Hielo","La Célula Que Explota","Trátame Suavemente","En La Ciudad De La Furia","Azul","Viento","Lamento Boliviano","La Mentira","Persiana Americana","EoO"};
    int votosdeparticipantes[100][3];
    int totaldeparticipantes = 0;
    int id1 = -1, id2 = -1;
    
    // llamar función 1 //
    totaldeparticipantes = lectura(votosdeparticipantes, tituloscanciones);
    
    // llamar función 2 //
    votaciones(votosdeparticipantes, totaldeparticipantes, tituloscanciones, &id1, &id2);
    
    // llamar función 3 //
    premiacion(votosdeparticipantes, totaldeparticipantes, id1, id2);
    
    return 0;
}

// función 1 desarrollo //
int lectura(int votosdeparticipantes[100][3], char *tituloscanciones[10]) 
{
    int v1, v2, v3, i;
    int total = 0;
    
    printf("CONCURSO\n");
    printf("CANCIONES DISPONIBLES:\n");
    for(i = 0; i < 10; i++) 
    {
        printf("Numero %d: %s\n", i + 1, tituloscanciones[i]);
    }

    while(total < 100) 
    {
        printf("Dame la posición de tus 3 canciones, o un -1 si ya no hay más participantes:\n");
        
        do
        {
            printf("  1er lugar (3 pts): ");
            scanf("%d", &v1);
            if (( v1<1 || v1>10 ) && v1 != -1)
            {
                printf("Necio, eso no es válido\n");
            }
        }
        while(( v1<1 || v1>10 ) && v1 != -1);
        
        if(v1 == -1) 
        {
            printf("Total de participantes: %d\n", total);
            break;
        }
                
        do
        {
            printf("  2do lugar (2 pts): ");
            scanf("%d", &v2);
            if ( v2<1 || v2>10 )
            {
                printf("Dato no válido\n");
            }
        }
        while( v2<1 || v2>10 );
        
        do
        {
            printf("  3er lugar (1 pt) : ");
            scanf("%d", &v3);
            if ( v3<1 || v3>10 )
            {
                printf("Dato no válido\n");
            }
        }
        while( v3<1 || v3>10 );

        votosdeparticipantes[total][0] = v1;
        votosdeparticipantes[total][1] = v2;
        votosdeparticipantes[total][2] = v3;

        total++;
    }
    return total;
}

// función 2 desarrollo //

void votaciones(int votosdeparticipantes[100][3], int totaldeparticipantes, char *tituloscanciones[10], int *id1, int *id2)
{
    if(totaldeparticipantes > 0) 
    {
        int i;
        int numvot[10]={0,0,0,0,0,0,0,0,0,0};
            
        for( i=0 ; i<totaldeparticipantes ; i++ )
        {
            int au=votosdeparticipantes[i][0] - 1, ad=votosdeparticipantes[i][1] - 1, at=votosdeparticipantes[i][2] - 1 ;
            numvot[au]+= 3;
            numvot[ad]+= 2;
            numvot[at]+= 1;
        }
        printf("Votos totales:\n");
            
        for( i=0 ; i<10 ; i++ )
        {
            printf("%s = %d votos totales\n", tituloscanciones[i], numvot[i]);
        }
        
        int max1 = -1 , max2 = -1 ;
        
        for(i=0;i<10;i++)
        {
            if(numvot[i]>max1)
            {
                max2=max1;
                *id2=*id1;
                
                max1=numvot[i];
                *id1=i;
            }
            else if(numvot[i]>max2)
            {
                max2=numvot[i];
                *id2=i;
            }
        }
        printf("La canción más votada es %s con %d votos\n", tituloscanciones[*id1], max1);
        printf("La segunda canción más votada es: %s con %d votos\n\n", tituloscanciones[*id2], max2);
    }
}

// función 3 desarrollo //

void premiacion(int votosdeparticipantes[100][3], int totaldeparticipantes, int id1, int id2)
{
    if(totaldeparticipantes > 0)
    {
        int i;
        int conteo[100] = {0};
        int maxpun = -1, champiñon = -1;
        
        printf("PUNTAJES   PUNTAJES  PUNTAJES  PUNTAJES  PUNTAJES  PUNTAJES  PUNTAJES  PUNTAJES\n");
        
        for(i = 0; i < totaldeparticipantes; i++)
        {
            int aprim = 0, asegun = 0, j;
            
            for(j = 0; j < 3; j++) 
            {
                if(votosdeparticipantes[i][j] == id1 + 1) aprim = 1;
                if(votosdeparticipantes[i][j] == id2 + 1) asegun = 1;
            }
            
            if(aprim)           conteo[i] += 30;
            if(asegun)          conteo[i] += 20;
            if(aprim && asegun) conteo[i] += 10;
            
            printf("Participante %d: %d puntos\n", i, conteo[i]);
            
            if(conteo[i] > maxpun) 
            {
                maxpun = conteo[i];
                champiñon = i;
            }
        }
        
        printf("\nEL GANADOR DEL PREMIO ES: Participante %d con %d puntos\n", champiñon, maxpun);
    }
}
