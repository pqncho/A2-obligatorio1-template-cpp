# Justificación de órdenes — Obligatorio 1
**Integrantes:** Pia Gutierrez (359147), Francisco Lino (347691)
> **Instrucciones** (borrar esta sección antes de entregar): para cada ejercicio cuya
> letra plantea restricciones de órdenes (tiempo o espacio), justificar brevemente por
> qué la solución cumple, indicando qué estructuras de datos o algoritmos se utilizaron.
> Ejemplo: "La letra exige inserción en O(log n); usamos un min-heap sobre arreglo,
> donde flotar/hundir recorren a lo sumo la altura del árbol". Si un ejercicio no tiene
> restricciones de órdenes, indicarlo.

## Ejercicio 1
- ALTA y BUSCAR O(log K). / Justificación: dado que los árboles son AVL, y tanto busqueda como alta hacen recorridos binarios (solo al nodo mayor o solo al nodo menor) el orden queda logarítmico.
- Vale aclarar que las rotaciones para volver a balancear el arbol son O(1).
- RANGO O(log K + R). / Justificación: fuera del intervalo que se pide, la funcion range2 sigue la misma lógica que add y search2 (Recorridos binarios). La diferencia es que si un dato pertenece al intervalo pedido, se chequearán ambos hijos (derecho e izquierdo) para ver si también se deben mostrar en consola.
- Queda O(log K + R) porque se recorreran los R nodos que pertenecen al rango y para el resto de los nodos se ira solo para un lado, segun si se pasan del rango o no alcanzan a entrar.

## Ejercicio 2
- Orden temporal O(L) con cajón más grande y cantidad de cajones en O(1) / Justificación: Para setear una nueva palabra, primero la ordenamos (siempre un for de 26 iteraciones) y luego recorremos cada caracter de la palabra para calcular su hash, entonces es O(L); después al ser una talba de hash, en promedio tenemos O(1), ya que controlamos el factor de carga (decidimos que dejarla en 1.5 estaria bien porque es un hash abierto) y la función de hash. La parte de la última linea la vamos manteniendo con variables que se actualizan cada vez que agregamos una palabra(para esto necesitamos hacer findPos() y getPos() que serian orden del tamaño la lista, pero por lo ya mencionado del hash y el factor de carga, este tamaño es mucho mejor al del largo de la palabra en promedio), entonces al momento de imprimir la última linea, esta es O(1).

## Ejercicio 3
- Orden espacial O(n), orden temporal O(n . log n). / Justificación: El espacial se ve claramente porque el heap se guarda como un array de n+1 posiciones (dado que la pos cero no se utiliza). Interactuamos con el array como si fuera un árbol, por lo tanto nos movemos por "ramas" y de manera logarítmica, chequeando hijos y padre(i.2 i.2+1 y i/2). Esto(remove()) lo hacemos tantas veces como archivos se ingresaron. Por esto el orden temporal es O(n . log n).

## Ejercicio 4
- Orden espacial O(V + A), Orden temporal O((V + A) log V). / Justificación: El orden espacial se cumple por lo visto en clase de la implementación de grafos como listas de adyacencia; guardamos el array de los vértices y las listas que contienen únicamente las aristas existentes, sin desperdiciar espacio de memoria.

- Para el orden temporal, primero creamos el array con los grados de entrada de los vertices y esto es O(A) porque debemos recorrer todas las aristas para sumar en la posicion v del array cada vez que v aparece como edge.to, luego creamos una prio queue para todos los vertices(modulos con su prioridad), que es O(V). Luego para cada vertice de la prio queue recorremos sus adyacentes, por lo que termina siendo O(V+A). Entonces el total es O(V+A).

## Ejercicio 5
- Orden espacial O(V+E), Orden temporal O(E*Log E). / Justificación: Dado que en djset se implementaron ambas optimizaciones, podemos decir que las funciones de union y find son practicamente constantes en promedio, como se explica en la seccion Time Complexity de [Algorithms for Competitive Programming: Disjoint Set Union](https://cp-algorithms.com/data_structures/disjoint_set_union.html) 

- Cumple con el orden espacial porque lo guardamos como un grafo O(V+E) y ademas tenemos una cola de prioridad con 2*e porque el grafo es no dirigido, queda O(E). Tambien tenemos el djset que es O(V) porque guarda dos arrays de largo v+1.

- En la parte de kruskal primero creamos la prio queue, que tiene O(E), luego para todas las aristas las vamos desencolando que es O(Log E) y utilizamos find() y unionn(), que como ya mencionamos tienen casi orden constante por la funcion inversa de ackermann. Luego de terminar la prio queue chequeamos el size del djset que es O(V), pues se debe recorrer todo el array viendo que find(i) == i. Entonces O(E) + O(E*Log E) + O(V) = O(E.Log E)
