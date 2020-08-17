#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char maxChar=20;
const int dim=30;

/**                             PROTOTIPADO                          **/
/** Ejercicio 1  **/
void inicializarArray(int a[], int dim);
void cargaArray(int a[], int dim);
int sumaArray(int a[], int dim);
int cantArray(int a[], int dim);
int subProgArray(int a[], int dim);
/** Ejercicio 2  **/
void menuDos();
int cargaArrayChar(char C[][maxChar],int dim);
void mostrarArray(int validos, char C[validos]);
void invertirArray(int dim,char C[]);

int searchMax(int a[], int validos);                                                                     ///EJERCICIO 4
int capicuaArray(int C[], int validos);                                                                 ///EJERCICIO 6
void intercambioVar(int *x, int *y);                                                                    ///EJERCICIO 7
int OrdenaSeleccion(int a[], int validos);                                                              ///EJERCICIO 8
int orderedSelection(int a[], int validos, int ultimaPos);                                        ///EJERCICIO 8
int intercalateArrays(int a[], int B[], int I[], int validos, int valuesB, int dimI);     ///EJERCICIO 8
int cargaArreglosParalelos(char apellido[][maxChar], int edad[], int dim);           ///EJERCICIO 9
int buscaMayorEdad(char apellido[][maxChar], int edad[], int validos);                 ///EJERCICIO 9

int main()
{
    int *arrDinamico=NULL;
    int dim=-1, opc, validos=0, opc2, cap=-1,a,b;
    float prom=0;
    char arrCaracteres[dim][maxChar], control='s';

    do
    {
        printf("EJERCICIO 1\n");
        printf("EJERCICIO 2\n");
        printf("EJERCICIO 3\n");
        printf("EJERCICIO 4\n");
        printf("EJERCICIO 5\n");
        printf("EJERCICIO 6\n");
        printf("EJERCICIO 7\n");
        printf("EJERCICIO 8\n");
        printf("EJERCICIO 9\n");
        printf("EJERCICIO 10\n");
        printf("SALIR  0\n");
        printf("Ingrese una opci%cn: ", 162);
        scanf("%d", &opc);
        switch(opc)
        {
        case 0:
            return 0;
            break;
        case 1:
            printf("Ingrese cuantos datos desea que tenga el arreglo: ");
            scanf("%d", &dim);
            arrDinamico = (int *) malloc (dim * sizeof(int));                     //Guardo el espacio de memoria para el array
            if (arrDinamico != NULL)                                                      // Se comprueba que la asignación de memoria dinámica fue exitosa
            {
                inicializarArray(arrDinamico, dim);
                cargaArray(arrDinamico, dim);
                prom = subProgArray(arrDinamico, dim);
                printf("El promedio de los datos cargados en el array es de: %.2f", prom);
                free(arrDinamico);
            }
            else                                                                                    // En este caso malloc retornó 'NULL', es decir no pudo reservar memoria
            {
                printf("No se pudo reservar memoria\n");
            }
            break;
        case 2:
            menuDos();
            scanf("%d", &opc2);
            if(opc2==1)
            {
                validos = cargaArrayChar(arrCaracteres, dim);
            }
            else if(opc2 == 2)
            {
                invertirArray(validos, arrCaracteres);
            }
            else
            {
                mostrarArray(validos,arrCaracteres);
            }
            break;
        case 3:
            break;
        case 4:
            printf("Buscar el MAX.");
            printf("El maximo es %d", searchMax(arrDinamico, validos));
            break;
        case 5:
            break;
        case 6:
            cap = capicuaArray(arrCaracteres, validos);
            if(cap == 1)
            {
                printf("LA CADENA NO ES CAPICUA.\n");
            }
            else
            {
                printf("La cadena es capicua!!\n");
            }
            break;
        case 7:
            printf("Intercambio de variables!\n");
            printf("Escriba un valor para a: ");
            scanf("%d", &a);
            printf("\nAhora uno para b: ");
            scanf("%d", &b);
            intercambioVar(&a, &b);
            printf("Muy bien, ahora intercambiaron\n");
            printf("Valor de 'a' : %d", &a);
            printf("Valor de 'b' : %d", &b);
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        }
    }
    while(toupper(control)=='S');

    return 0;
}


/**                                 EJERCICIO 1                        **/
/*1. Se tienen un arreglo de números enteros positivos. Se desea obtener el promedio de sus valores.
 Para ello se debe:
 a. Hacer una función que inicialice las celdas del arreglo en –1.*/
void inicializarArray(int a[], int dim)
{
    int valor = -1;
    for(int i=0; i<dim; i++)
    {
        valor = a[i];
    }
}
/*b. Hacer una función que permita al usuario ingresar los valores. No se conoce la cantidad de antemano.*/
void cargaArray(int a[], int dim)
{
    for(int i=0; i<dim; i++)
    {
        printf("Ingrese un valor: ");
        scanf("%d", a[i]);
    }
}
/*c. Hacer una función que sume el contenido del arreglo y lo retorne.*/
int sumaArray(int a[], int dim)
{
    int suma=0;
    for(int i=0; i<dim; i++)
    {
        suma += a[i];
    }
    return suma;
}
/*d. Hacer una función que cuente la cantidad de valores ingresados.*/
int cantArray(int a[], int dim)
{
    int i=0;
    while(i<dim)
    {
        i++;
    }
    return i;
}
/*e. Hacer una función que reciba como parámetro el arreglo ya cargado, calcule y retorne el valor promedio  usando las funciones anteriores (c y d). */
int subProgArray(int a[], int dim)
{
    float promedio=0;
    int suma = sumaArray(a,dim);
    int cant = cantArray(a,dim);
    if(cant>0)
    {
        promedio = (float)suma/(float)cant;
    }
    return promedio;
}
/**                                 EJERCICIO 2                        **/
/*2. Invertir el contenido de un arreglo de caracteres. Para ello se debe modularizar de la siguiente forma:
/*a. Hacer una función para la carga del arreglo.*/
int cargaArrayChar(char C[dim][maxChar],int dim)
{
    int i=0;
    char control='s';
    while(i<dim && toupper(control)=='S')
    {
        printf("Ingrese una palabra <max. %d>\n", maxChar);
        fflush(stdin);
        gets(C[i]);
        i++;
        printf("Desea agregar otra? s/n\n");
        fflush(stdin);
        scanf("%c", &control);
    }
    return i;
}
/* b. Hacer una función para invertir el arreglo.*/
void invertirArray(int validos,char C[])
{
    int aux, i;
    for(i=0; i<validos/2; i++)
    {
        aux = C[i];             //Paso a aux para no perder el valor
        C[i] = C[validos-1-i];      //Encuentro la posicion donde debe colocarse
        C[validos-1-i] = aux;       //Coloco el valor guardado anteriormente
    }
}
/* c. Hacer una función para mostrar el contenido del arreglo.  */
void mostrarArray(int validos, char C[validos])
{
    for(int i=0; i<validos; i++)
    {
        printf("Contenido del arreglo\n");
        printf("%s\n", C[i]);
    }
}
/*d. Hacer la función main con el menú correspondiente*/
void menuDos()
{
    printf("Carga array char\n");
    printf("Invierte array char\n");
    printf("Muestra array char\n");
    printf("Elija una opci%cn\n", 162);
}

/**                                 EJERCICIO 3                        **/
/*Hacer una función que reciba como parámetro un arreglo de números enteros y retorne el valor decimal de dicho número.  */
/**                                 EJERCICIO 4                        **/
/* Hacer una función que retorne la posición del valor máximo de un arreglo de números enteros. */
int searchMax(int a[], int validos)
{
    int mayor = a[0];                   //Mayor toma el valor del primero para comenzar a comparar
    for(int i = 0; i < validos; i++)
    {
        if(a[i] > mayor)
        {
            mayor = a[i];
        }
    }
    return mayor;
}
/**                                 EJERCICIO 5                        **/
/* Sea una matriz de números enteros, de dimensiones: 12 filas y 31 columnas. Contienen las precipitaciones correspondientes a un año entero.
 Las filas corresponden a los meses y las columnas a los días. Se pide:  */
/*a. Hacer una función para cargar la matriz. */
/* b. Hacer una función que retorne el día de máxima precipitación para un mes determinado.*/
/* c. Hacer una función que cargue en un arreglo de 12 posiciones el resultado de aplicar la función anterior a cada  mes de año. */
/*d. Hacer la función main con el menú correspondiente. */
/**                                 EJERCICIO 6                        **/
/*Dada una cadena de caracteres, hacer una función que determine si dicha cadena es capicúa o no.
La función recibe como parámetro la cadena y retorna 1 o 0 según sea la respuesta. */
int capicuaArray(int C[], int validos)
{
    int capicua=0, i;
    for (i=0; i<validos/2; i++)         //Divido en 2 para comparar la primera parte con la ultima
    {
        if (C[i] != C[validos-1-i])
        {
            capicua=1;
        }
    }
    return capicua;
}
/**                                 EJERCICIO 7                        **/
/* Hacer una función que intercambie el contenido de dos variables. */
void intercambioVar(int *x, int *y)
{
    int aux;
    aux = x;
    x=y;
    y=aux;
}
/**                                 EJERCICIO 8                        **/
/* Dados dos arreglos de números enteros ordenados de menor a mayor, hacer una función que los reciba como parámetros
 y retorne un tercer arreglo que contenga los datos de los arreglos anteriores, también ordenados. Se los debe intercalar. */
/**Busca Menor y Ordena **/
int orderedSelection(int a[], int validos, int ultimaPos)
{
    int i= ultimaPos+1;
    int posMenor=ultimaPos;
    while(i<validos)
    {
        if(a[i] < a[posMenor])
            posMenor=i;
    }
    return posMenor;
}

int OrdenaSeleccion(int a[], int validos)
{
    int i, posMenor, aux;
    while (i<validos)
    {
        posMenor=orderedSelection(a,validos,i);
        aux= a[posMenor];
        a[posMenor]=a[i];
        a[i]= aux;
    }
}
/**Intercambio**/
int intercalateArrays(int a[], int B[], int I[], int validos, int valuesB, int dimI)
{
    int i=0, j=0, k=0;
    while(i<validos && j<valuesB && k<dimI )
    {
        if (a[i] < B[j])
        {
            I[k] = a[i];                //Pongo ese valor en el nuevo array I
            i++;                        //Utilizo el siguiente numero de ese Array
        }
        else
        {
            I[k] = B[j];
            j++;
        }
        k++;                            //Paso a la segunda posicion del Nuevo Array
    }

    while (i<validos && k<dimI)          //Son los datos que sobran a A o B
    {
        I[k] = a[i];                    //Si no le sobran, no entra al  while
        i+=1;                           //Y estaban ordenados, asique solo los copias al I[]
        k+=1;
    }

    while (j<valuesB && k<dimI)
    {
        I[k] = B[j];
        j+=1;
        k+=1;
    }
    return k;
}

/**                                 EJERCICIO 9                        **/
/* Dados dos arreglos paralelos, uno con apellidos y otro con edades. Se debe hacer un programa para encontrar el
apellido de la persona de mayor edad. Se debe modularizar. */
int cargaArreglosParalelos(char apellido[][maxChar], int edad[], int dim)
{
    int i=0;
    char control='s';
    while(i<dim && control=='s')
    {
        printf("Ingrese el apellido: ");
        fflush(stdin);
        scanf("%s", apellido[i]);
        printf("Ingrese la edad: ");
        scanf("%d", &edad[i]);
        i++;
        printf("Desea continuar la carga ? s/n \n");
        fflush(stdin);
        scanf("%c", &control);
    }
    return i;
}

int buscaMayorEdad(char apellido[][maxChar], int edad[], int validos)
{
    int i=0;
    int mayor=edad[0];
    char aux[maxChar];
    while(i<validos)
    {
        if(edad[i]>edad[mayor])
        {
            strcpy(aux, apellido[i]);
        }
        i++;
    }
    return i;
}

/**                                 EJERCICIO 10                       **/
/* Hacer una función que reciba como parámetro de entrada un arreglo de enteros y tres parámetros de salida,
tres números enteros que representen: valor máximo, valor mínimo y promedio. Se debe usar pasaje de parámetros por referencia. */
