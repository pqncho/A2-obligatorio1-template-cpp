# Plantilla Obligatorio 1 — C++

Plantilla para el **obligatorio 1** (ejercicios 1 a 5) de Estructura de Datos y Algoritmos 2, en C++.

## Estructura del repositorio

- `ejercicioX.cpp`: archivo fuente de cada ejercicio (1 a 5). La solución de cada ejercicio parte de su archivo raíz.
- `funciones/`: carpeta para funciones auxiliares reutilizables entre ejercicios.
- `tads/`: carpeta para Tipos Abstractos de Datos (TADs).
- `bitacora.md`: bitácora de trabajo del equipo. **Completar una entrada por cada día trabajado.**
- `autoria.md`: declaración de autoría por ejercicio. **Completar antes de entregar.**

## Cómo usar esta plantilla

1. Hacer clic en el botón **Use this template** para crear un repositorio propio.
2. Clonar el repositorio en el entorno local.
3. Resolver cada ejercicio en su archivo correspondiente.
4. Registrar el avance en `bitacora.md` **cada día que se trabaje** (no dejarlo para el final).
5. Completar `autoria.md` con las fuentes utilizadas en cada ejercicio.

## Compilación y ejecución

```bash
g++ -std=c++11 -o ejercicioX ejercicioX.cpp
```

Las soluciones se ejecutan con el formato de entrada/salida del curso:

```bash
./ejercicioX < test.in.txt > test.myout.txt
```

## Entrega

El zip de entrega debe contener en la raíz los archivos `ejercicioX.cpp`, `bitacora.md` y `autoria.md`, más los directorios auxiliares si se usan. No incluir pruebas, binarios ni scripts. Ver el formato de entrega completo y los lineamientos de uso de IA en la letra del obligatorio del semestre.
