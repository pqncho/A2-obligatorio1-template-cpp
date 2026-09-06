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
- Pasan los casos de prueba 1 a 4 del ejercicio 1.
