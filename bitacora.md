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

- Luego de volver a ejecutar el programa, este compilaba, pero ahora fallaban algunos de los outputs, por lo que me puse a investigar y vi que en la parte de crear el get2 (el que devuelve la cantidad de tipos en un bucket) estabamos retornando directamente el size de la lista, y esto genera errores ya que no estamos teniendo en cuenta las colisiones, luego con Pia lo correjiremos.

## 2026-09-12 - En conjunto
- Estuvimos mirando el ejercicio2 para ver como resolver el tema de palabras distintas colisionando en el mismo bucket, pero los cambios que hacíamos no mejoraban el out, así que lo dejamos para la semana que viene preguntarle al profe.
- Implementamos las funciones que faltaban (siftDown, remove y consolidate) y completamos el archivo cpp con el for y el cout.
- compilamos el programa y las salidas nos dieron diferente con las que estan en las pruebas. Sospechamos que el error esta en siftDown pero aun no logramos detectarlo.

## 2026-09-13 - Francisco

- Luego de volver a leer el codigo de siftDown mas tranquilo y con una foto que Pia me mandó, en la cual hizo correctamente la funcion en su cuaderno sin mirar lo que teniamos en el codigo, me di cuenta que nuestro principal error era que estabamos intentado tratar todas las restricciones juntas, por lo que al escribir las restricciones que precisabamos y cambiar alguna cosa menor se soluciono el problema y la salida de los inputs quedaron igual que los de las pruebas.

## 2026-09-14 - En conjunto
- Comenzamos a leer el ejercicio4, y pensamos armar un minheap que tenga el módulo y su prioridad. Igualmente hay muchas dudas y no estamos seguros si esta lógica cumpliría los ordenes, seguramente falte algo de grafos para guardar bien las dependencias.
- Definimos los operadores de igualdad del par según pedía la letra (por prioridad, desempatando por elemento). 

## 2026-09-19 — Pia
- Después de hablar con el profe sobre el ejercicio2 el martes, volví a pensar el ejercicio de cero y entendí donde es que nos habíamos confundido, al pensar en un cajón como un bucket de la tabla y no simplemente como un elemento clave-valor. 
- Por esto, cambié la implementación de listas que usabamos y la implementé desde cero como una lista simplemente enlazada en la que los elementos tienen la cantidad de veces (times) que aparecen, en vez de agregar un elemento a ciegas sin chequear que ya esté. Creo que resuelve nuestro problema de devolver correctamente los cajones, pero deberíamos chequear bien los órdenes.
- También cambié la función ordenAlfabetico() de estar dentro de open_hash_table a estar en ejercicio2.cpp
- Volví a leer la letra del ejercicio4 ahora que empezamos con grafos, las dependencias serían un grafo implementado como listas de adyacencia. Igualmente me cuesta ver como vamos a conectar el grafo de dependencias con el minHeap. Porque no solo habría que ordenar el heap por prioridad y módulo, sino que también por dependencias. Por ahora solo empecé la clase abstracta graph con adyacents(g) (devuelve lista de vecinos) y entryDegree() (devuelve array con grado según la posición, pos 0 no se usa) que seguro los vamos a necesitar para el algoritmo de orden topológico. Igualmente mañana lo pensamos con Francisco.
- Más tarde seguí con lo de graph.cpp, agregué hasEdge() que quizás nos sea util, y empecé adyacency_list implementando las funciones de graph. Igual hay que ver si adyacents no devuelve ya el iterador, por ahora hice que devuevla la lista de vecinos.

## 2026-09-19 — Francisco
- compile y probe la nueva implementacion y resolucion del ejercicio 2 que hizo pia, con la prueba de 1000 inputs y efectivamente devolvio lo que debia devolver, por lo que estamos muy felices.

## 2026-09-14 - En conjunto
- Seguimos pensando en como resolver el ejercicio4, teníamos la idea de armar el heap y el grafo de dependencias al mismo tiempo y luego en ordenTopologico ir, para cada vertice, consultando la cabeza del heap a ver si no tenía dependencias. Si las tenía pensabamos guardar esos elementos en una lista y luego volver a agregarlos, pero nos dimos cuenta que se nos iba de ordenes. Entonces volvimos a una idea que ya habíamos tirado antes, de ir construyendo el heap solo con los elementos que estan listos(grado de entrada cero), e imprimirlos antes de seguir avanzando al siguiente vértice.
- No tenemos muy claro como guardar las prioridades si seguimos esa logica, por ahora las pensamos tener en un array.
