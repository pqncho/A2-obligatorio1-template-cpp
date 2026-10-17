# Declaración de autoría — Obligatorio 1
**Integrantes:** Pia Gutierrez (359147), Francisco Lino (347691)


## Ejercicio 1
- Se implementó con lo hecho en clase de AVL, modificando algunas funciones que no eran relevantes al ejercicio y agregando las propias.

## Ejercicio 2
- Fuentes externas: 
[Algorithms for Competitive Programming: String Hashing](https://cp-algorithms.com/string/string-hashing.html)
- Se extrajo el codigo de la funcion de hash y se modifico para incorporar lo que se le ocurrio al equipo que funcionaria mejor para este ejercicio.

- Preguntamos a chat gpt que errores en un codigo podrian ocasionar un segmentation fault, y dentro de su respuesta nos dijo que una de las cosas que podria ser era intentar acceder a un puntero que es nulo, por lo que al analizar el archivo de open_hash_table ya que estabamos bastantes seguros de que el problema estaba ahi, nos dimos cuenta de que en el constructor de la tabla inicializabamos todas las listas del array que son punteros en null, por lo que al momento de acceder a ellas daba ese error.

## Ejercicio 3
- Utilizamos parte del template de heap que dio el profe en clase y luego fue implementación íntegramente propia.

## Ejercicio 4
- Utilizamos el template de grafos que dio el profe en clase (con distinto nombre porque lo habiamos empezado antes) y utilizamos ordenacion topologica, agregando algunas cosas propias para resolver el ejercicio.

## Ejercicio 5
- Fuentes externas:
[Algorithms for Competitive Programming: Disjoint Set Union](https://cp-algorithms.com/data_structures/disjoint_set_union.html) 
- Leimos sobre Path Compression y Union by Rank/Size para poder implementar las optimizaciones como pedia la letra, ademas de usar kruskal, luego agregando algunas cosas propias del equipo para resolver lo pedido.
