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
- RANGO O(log K mas R). / Justificación: fuera del intervalo que se pide, la funcion range2 sigue la misma lógica que add y search2. La diferencia es que si un dato pertenece al intervalo pedido, se chequearán ambos hijos (derecho e izquierdo) para ver si también se deben mostrar en consola.

## Ejercicio 2
- Orden espacial O(n), orden temporal O(n . log n). / Justificación: El espacial se ve claramente porque el heap se guarda como un array de n+1 posiciones (dado que la pos cero no se utiliza). Interactuamos con el array como si fuera un arbol, por lo tanto nos movemos por "ramas" y de manera logar'itmica, chequeando hijos y padre. Esto lo hacemos (remove()) tantas veces como archivos se ingresaron. Por esto el orden temporal es O(n . log n).

## Ejercicio 3
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 4
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 5
- Sin restricciones de órdenes. / Justificación: ...

