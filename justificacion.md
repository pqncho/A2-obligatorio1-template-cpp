# Justificación de órdenes — Obligatorio 1

**Integrantes:** Pia Gutierrez (359147), Francisco Lino (347691)

## Ejercicio 6

orden temporal O(N) en el peor caso: si bien tenemos un while adentro de un for, solo entra al while cuando esa posicion del array es > 0, y si es > 2 va descontando de a 2 por lo que al final termina siendo O(N) para recorrer todas las placas ingresadas.

Orden espacial O(N): Dado que los numeros de las placas van de 0 a 1000, siempre creamos un array de 1000 posiciones sin importar el tamaño del input, por lo que es orden constante.

## Ejercicio 7

orden temporal O(NlogN) en el peor caso: Lo pensamos como un merge sort donde dividimos el array a la mitad hasta que solo queden arrays de un indice, luego para calcular las remontadas epicas lo que hacemos es empezar en los indices de cada sub array
y mientras estemos dentro de la ventana de los sub arrays que tenemos que ver, si un elemento del primer sub array (el que termino antes) es mayor al doble que los del segundo sub array seguimos avanzando en el segundo. Sabemos que podemos cortar en el momento que encontramos un elemento que no es dos veces mas chico que el del primer sub array porque estos ya vienen ordenados de menor a mayor. Entonces a las remontadas epicas le sumamos todas las posiciones que avanzamos, que como no estamos empezando en tenemos que restarle el inicio del array (c += n-m+1). Despues es la logica del merge sort, creamos los dos sub arrays y vamos modificando el array principal ordenando los elmentos de menor a mayor, moviendo el indice de un sub array solo cuando agregamos un elemento (es mas chico que los elementos del otro sub array) entonces como descartamos casos para calcular las remontadas epicas y hacemos el merge sort nos queda O(N.LogN).

Orden espacial O(N): Esto se ve claramente ya que creamos el array del tamaño que nos pasan al principio, y luego para el merge sort creamos otros dos arrays que como maximo tienen tamaño N/2 entonces nos sigue quedando O(N).

## Ejercicio 8

Orden temporal O(N⋅W⋅L0⋅L1⋅L2⋅L3) en el peor caso: lo vemos al realizar 6 for anidados y cada for va hasta cada letra del orden temporal.

Orden espacial O(N⋅W⋅L0⋅L1⋅L2⋅L3): creamos un tensor de 6 dimensiones por lo que el orden espacial es el propuesto.

## Ejercicio 9

Orden temporal O(K.K):
Si bien hay maximos de dos recursiones en muchos casos este valor ya va a estar calculado, entonces simplemente es devolver ese valor que se encuentra en la matriz memo en O(1). igualmente el indice va de 0 hasta k, el contador tambien y tenemos dos opciones de si bailo o no bailo, al pasar por todas las opciones posibles nos queda k.k.2 que seria O(k.k).

Orden espacial O(K.K): Como creamos dos matrices de dimensiones K.K dado que como mucho vamos a estar K goles arriba en el contador, y los arrays de likes y goles son de tamaño K, entonces es 2K.K + 2K que es O(K.K);

## Ejercicio 10
