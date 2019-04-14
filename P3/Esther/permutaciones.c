/**
 *
 * Descripcion: Implementacion de funciones de generacion de permutaciones
 *
 * Fichero: permutaciones.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 16-09-2017
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "permutaciones.h"

/***************************************************/
/* Funcion: aleat_num Fecha:                       */
/* Autores:                                        */
/*                                                 */
/* Rutina que genera un numero aleatorio           */
/* entre dos numeros dados                         */
/*                                                 */
/* Entrada:                                        */
/* int inf: limite inferior                        */
/* int sup: limite superior                        */
/* Salida:                                         */
/* int: numero aleatorio                           */
/***************************************************/
int aleat_num(int inf, int sup)
{
	return rand()/(RAND_MAX+1.)*(sup-inf+1) + inf;
}

/***************************************************/
/* Funcion: genera_perm Fecha:                     */
/* Autores:                                        */
/*                                                 */
/* Rutina que genera una permutacion               */
/* aleatoria                                       */
/*                                                 */
/* Entrada:                                        */
/* int n: Numero de elementos de la                */
/* permutacion                                     */
/* Salida:                                         */
/* int *: puntero a un array de enteros            */
/* que contiene a la permutacion                   */
/* o NULL en caso de error                         */
/***************************************************/
int* genera_perm(int N)
{
	int *perm,j,dum,a;
	perm=calloc(N,sizeof(int));
	if(perm==NULL)
		return NULL;
	for (j=0;j<N; j++)
		perm[j]=j+1;
	for (j=0;j<N;j++){
		a=aleat_num(j,N-1);
		dum=perm[j];
		perm[j]=perm[a];
		perm[a]=dum;
	}
	return perm;
  /* vuestro codigo */
}

/***************************************************/
/* Funcion: genera_permutaciones Fecha:            */
/* Autores:                                        */
/*                                                 */
/* Funcion que genera n_perms permutaciones        */
/* aleatorias de tamanio elementos                 */
/*                                                 */
/* Entrada:                                        */
/* int n_perms: Numero de permutaciones            */
/* int N: Numero de elementos de cada              */
/* permutacion                                     */
/* Salida:                                         */
/* int**: Array de punteros a enteros              */
/* que apuntan a cada una de las                   */
/* permutaciones                                   */
/* NULL en caso de error                           */
/***************************************************/
int** genera_permutaciones(int n_perms, int N)
{
	int **perms;
	int i,j;
	perms=malloc(n_perms*sizeof(int*));
	if(perms==NULL)
		return NULL;
	for(j=0;j<n_perms;j++){
		perms[j]=genera_perm(N);
		if(perms[j]==NULL){
			for(i=0;i<j;i++)
				free(perms[i]);
			free(perms);
			return NULL;
		}
	}
	return perms;
/* vuestro codigo */
}