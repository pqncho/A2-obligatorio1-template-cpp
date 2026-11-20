# Bitácora — Obligatorio 1

**Integrantes:** Pia Gutierrez (359147), Francisco Lino (347691)

## 2026-11-04 — Pia

- Ayer en clase discutimos los ejercicios 6, 7 y 9, creemos que sabemos como hay que resolverlos. Para el ejercicio 6 yo ya habia pensado una solucion que pense que no iba a funcionar porque requeria de ordenar las placas me mayor a menor(lo que no cumpliria el tiempo de ejecucion O(n)), pero en clase hablamos que el orden espacial, si es constante no importa que supere el N que nos puedan llegar a ingrasar por consola. Por esto, armamos un array de 1001 posiciones para las placas que van de 0 a 1000. El resto es lo que yo ya habia pensado de, mientras que la cantidad sea mayor a dos ir agregandolo a lo que se va a transformar en la parte simetrica(de una porque recorremos del 1000 al 0, por lo que ya nos da el cartel mas grande), y si es 1 y i > centro entonces actualizamos el centro. Puede que nos pasen solo placas pares, por lo que el cartel podria no tener centro. por ahora lo hice guardando solo un lado (y el centro) y luego dandolo vuelta y borrando el primer espacio, capaz hay una forma mas eficiente. Despues lo probamos con Fran.

## 2026-11-7 - En conjunto

Bueno la banda se puso la camiseta y liquido 3 ejercicios.

Empezamos cambiando unos detalles de manejo de strings del ejercicio 6, y al parecer quedo hecho.

luego para el ejercicio 7, lo pensamos como un merge sort con una logica distinta en el merge.
vamos separando el array en dos hasta llegar al caso base en que tenemos solo 1 elemento y devolvemos 0 remontadas epicas.
Despues en contar comparamos cada elemento del primer array para ver si es mayor al doble que los elementos del segundo array;
si lo es sumamos 1 a las remontadas epicas.

Para el 9, (no queriamos estresarnos con el 8 asi que metimos doble salto), primero hicimos la version recursiva en la que llevamos cuenta del indice en el que vamos para los array de likes y goles, ademas dos variables golA y golB para chequear si podiamos bailar o quedabamos perdiendo.

Para pasarlo a memo si lo haciamos manteniendo golesA y golesB no nos daban las dimensiones de la matriz, pero lo que nos importa es saber si estamos empatados o por cuanto vamos ganando. Entonces lo pensamos como el problema de los parentesis (sumando 1 cuando abre un parentesis y restando 1 cuando cierran) manteniendo una variable que le sumamos 1 cuando hay gol de A y le restamos 1 por cada gol de B. Cuando el contador vale 0 estamos empatados y sino es la ventaja de goles que llevamos. Entonces tenemos una sola variable para el contador y podemos hacer la matriz de indices in y contador.

Para cada ronda tenemos dos valores segun si bailo o no, Entonces dijimos de mantener dos matrices separadas para poder cumplir con el orden espacial k.k Y con la variable bailo vamos viendo que matriz consultar.

## 2026-11-8 - En conjunto

Empezamos resolviendo el ejercicio de la mochila (recursivo y con tabulacion) por separado para empezar a pensar el ejercicio 8.
Despues leimos bien la letra del ejercicio e hicimos la version recursiva con w, ix(0-n), l0, l1, l2, l3
ademas de los arrays de peso, satisfaccion y categoria.
El tema es pasarlo a tabulacion, porque cambian seis variables, entonces nos quedaria de dimension 6. Ya pensamos que la optimizacion que se puede hacer es que siempre comparamos unicamente con el producto anterior para calcular el actual, entonces podriamos quedarnos solo con la fila anterior, que nos quedaria dimension 5. Vamos a dejar para implementarlo despues porque no tenemos tan claro como crear un tensor tan grande, pero despues de ver eso seria la misma logica que tenemos en la verison recursiva. En esa verison, si el indice ix es menor a 0 o w == 0 entonces devolvemos cero. Luego, si el peso del producto es menor o igual al w y todavia se pueden agregar productos de esa categoria, devolvemos la maxima satisfaccion entre poner ese producto(sumar satisfaccion de ix mas la recursion del producto anterior restando el peso correspondiente al de w y con 1 producto menos de capacidad maxima en la categoria correspondiente) o no ponerlo(solo la recursion del producto anterior, sin restarle a ninguna categoria). Si el peso del producto es mayor al de la heladera o no se pueden poner mas productos de esa categoria simplemente devolvemos la satisfaccion del producto anterior, sin restar al w ni a las categorias.

## 2026-11-10 - En conjunto

- nos llego la nota del parcial profe lpm como sobrevivimos ahora??? :(
- Justificando ordenes del ejercicio 7 vimos que nos quedaba O(n^2) porque chequeabamos cada elemento del primer array con todos los elementos del segundo array, nos quedaba (n/2)(n/2). Entonces lo que hicimos fue hacer mergeSort, ordenar los arrays, lo que hace que no tengamos que chequear cada elemento. como los subarrays que recibimos ya estan ordenados no tenemos que ir chequeando elemento por elemento.

## 2026-11-17 - En conjunto

- El dia de hoy hicimos el tab del ejercicio 8, como no nos salio la super optimizacion decidimos hacer la vieja y confiable dimension 6.

- tambien hicimos las justificaciones del 7 , 8 y 9 que estaban pendientes.

## 2026-11-20 - En conjunto
- Estamos re felices porq creemos que encontramos una forma de resolver el ejercicio 10. O sea, el backtracking en si lo pensamos el martes en clase, pero nos preocupaba como ir manejando los strings y los digitos que les ibamos asignando a cada letra en simultaneo. Pia tiro la idea de guardar el valor acumulado por un lado, y la palabra con todas sus letras por otro, y hacer alguna cuenta para ir sumando en unidades, decenas, etc. A Francisco se le ocurrio que con potencias de 10 salia, vimos que seria el length de la palabra menos la posicion de la letra a la que le vamos a asignar el digito, menos 1. Entonces, al valor acumulado de la palabra le vamos sumando digito*(10^(length - pos - 1)). En quitar, simplemente le vamos restando eso al acumulado de la palabra. Para chequear si se puede podar, primero vemos si el resultado actual es mas grande que el mejor resultado que tenemos, si es, devolvemos true(si se puede podar). Sino, vamos en orden de primer a ultimo sumando, haciendo el mismo chequeo. 
