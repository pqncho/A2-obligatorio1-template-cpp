# Bitácora — Obligatorio 1

**Integrantes:** Pia Gutierrez (359147), Francisco Lino (347691)

> **Instrucciones** (borrar esta sección antes de entregar): agregar una entrada por
> cada día trabajado, indicando la fecha y quién trabajó (un integrante o "En conjunto").
> Registrar el proceso real: ideas exploradas, decisiones y su justificación, partes de
> implementaciones, bugs encontrados y cómo se corrigieron, resultados de pruebas y dudas
> abiertas. Si se usó IA ese día, indicar herramienta, consulta y qué se hizo con la
> respuesta. Una bitácora escrita íntegramente el día de la entrega implica pérdida de puntos.

## 2026-09-05 — En conjunto 
- Comenzamos leyendo la letra del ej.1. Investigamos la libreria string para utilizar funciones utiles para poder dividir y leer el input.
- Modificamos el AVL y BST que habiamos hecho en clase para agregar las funciones especificas al ejercicio.
- Al momento de correr las pruebas nos saltaron errores ya que definimos el tipo de nuestro avl como int, pero los datos de entrada eran mayores que los que abarca el int, por lo que cambiamos el tipo a long long. Ahí si compiló correctamente pero solamente se escribieron 3 de los 5 datos esperados de los datos de llegada.
- Utilizamos IA para entender los errores que nos aparecieron en la terminal luego de intentar compilar, con eso entendimos mejor el funcionamiento de cin y por qué era mejor utilizar getline según la lógica que se nos ocurrió para resolver el ejercicio.

## 2026-09-06 — En conjunto
- Pía: Corregí el error de range2()
- Leimos el ejercicio 2 y comenzamos a tirar ideas de como implementar el hash. Pensamos para la clave crear un array de 26 posiciones y sumar las apariciones de cada letra y ademas su posicion en el array para que hubieran menos colisiones. Igual nos parecio que surgirian muchas colisiones por lo que investigamos funcines de Hash con strings. Luego de esto, combinamos la 'polynomial rolling hash function' con nuestra version de los arrays, para que a palabras con misma cantidad de letras iguales, devuelva la misma clave del array.
- Comenzamos armando el hash abierto, el constructor y la funcion de set(). También arrancamos con la función main() para leer las primeras lineas y crear la tabla.

## 2026-09-08 — En conjunto
- Consultamos con el profe sobre la estructura del HashTable y los ordenes de la funcion de hash.
- Cambiamos la implementacion de nuestras clases para que sean abstractas, y comenzamos con "ejercicio2.cpp"
- Implementamos las funciones necesarias para resolver el ejercicio, basándonos en lo dado en clase de hash table.
- Corrimos la primer prueba pero no imprime nada y da segmentation fault, cambiamos algunas cosas del constructor para ver si imprime algo y pusimos un cout luego de la creación de la tabla que ahora si sale en el out, por lo que el problema está en otro lado.

## 2026-09-09 — En conjunto
- Corrimos tests más grandes para el ejercicio1, y pasaron las pruebas.
- Leimos el ejercicio3 y comenzamos con la implementación del minHeap. Pensamos mantener una variable en la estructura para llevar la cuenta del costo de los archivos. Faltaría implementar siftDown() y remove() para luego hacer consolidate(), que seleccione la cabeza del minHeap y su hijo más chico para sumarlos en un nodo ¨archivo¨ y reingresarlo al heap, borrando los dos que lo componen.

## 2026-09-10 — Pia
- Seguí el consejo del profe y agregué couts en varias partes del código del ejercicio2 para intentar ver el error. La tabla cajones se crea bien y el hash recorre y ordena la palabra correctamente. Tambien verifiqué que hs sea menor a cap. Es raro porque lo único que hay después en la función son llamadas a las funciones de lista que se nos dieron o incrementar el valor de una variable. Hasta ahora muestra esto:

se creo el array
entro al for
llega al hash
pasa letters(odena palabra)
palabra ordenada cdeghjjklnopquvxy
hs es: 2
el cap es: 15

después lo seguimos con Fran.

## 2026-09-12 - Francisco
- investigando las partes del codigo y consultando con ChatGPT me di cuenta que el problema estaba en el constructor de la open hash table, al momento de crear la tabla dejabamos todos los indices en null, por lo que al momento de insertar un elemento, el programa accedia a un puntero nulo que generaba el segmentation fault. Por lo que por separado cree el array de punteros List, y luego llenaba todas las posiciones por medio de un for con ListImp para que no quedara ningun indice en nulo. 

- Luego de volver a ejecutar el programa, este compilaba, pero ahora fallaban algunos de los outputs, por lo que me puse a investigar y vi que en la parte de crear el get2 (el que devuelve la cantidad de tipos en un bucket) estabamos retornando directamente el size de la lista, y esto genera errores ya que no estamos teniendo en cuenta las colisiones, Luego con Pia lo correjiremos.

## 2026-09-12 - En conjunto
