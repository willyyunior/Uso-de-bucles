# Uso de bucles

**Nombre:** Willy Yunior De La Rosa Sanchez  
**Matrícula:** 2026-1776  
**Asignatura:** Lógica de Programación  
**Profesor:** Gamalier Reyes del Carmen

## Descripción del programa

Programa en C++ de consola para el centro educativo "La Nueva Escuela". Sirve para registrar las calificaciones de un grupo de estudiantes, calcular sus promedios y determinar quiénes están aprobados y reprobados, utilizando bucles.

El programa solicita la cantidad de estudiantes, y por cada uno pide el nombre y 4 calificaciones (cada una entre 0 y 100). Calcula el promedio de cada estudiante y muestra si está aprobado (70 o más) o reprobado (menos de 70).

Al terminar el grupo muestra un resumen con la cantidad de aprobados y reprobados, el promedio general del grupo y el nombre y promedio del estudiante con el promedio más alto. Al final pregunta si se desea procesar otro grupo (s/n); si se responde s, el programa se repite desde el inicio.

## Datos de entrada

- Cantidad de estudiantes del grupo (entero mayor que 0).
- Nombre de cada estudiante (puede tener espacios).
- 4 calificaciones por estudiante (valores entre 0 y 100).
- Respuesta s/n para decidir si se procesa otro grupo.

## Proceso

1. Pide la cantidad de estudiantes. Si no es mayor que 0, la vuelve a pedir.
2. Por cada estudiante pide el nombre y las 4 calificaciones. Si una calificación no está entre 0 y 100, repite solo esa calificación.
3. Suma las 4 calificaciones y calcula el promedio.
4. Si el promedio es 70 o más, el estudiante queda Aprobado. Si no, Reprobado.
5. Va contando los aprobados y reprobados, sumando los promedios y guardando al estudiante con el mejor promedio.
6. Al terminar el grupo, calcula el promedio del grupo (suma de promedios entre la cantidad de estudiantes) y muestra el resumen.
7. Pregunta si quiero procesar otro grupo. Si respondo s, vuelve al paso 1.

## Salida

Por cada estudiante muestra su promedio y si aprobó o reprobó, por ejemplo: `Promedio: 83.00 - Aprobado`.

Al final de cada grupo muestra un resumen con:

- Cantidad de aprobados y reprobados.
- Promedio del grupo.
- Mejor promedio y el nombre del estudiante.

Los promedios salen con dos decimales gracias a `fixed` y `setprecision(2)` de la librería `<iomanip>`.

## Capturas de pantalla

### 1. Validación de la cantidad de estudiantes

<img width="569" height="330" alt="Captura de pantalla 2026-11-16 144320" src="https://github.com/user-attachments/assets/0b66d36f-2bdc-4a05-815c-a632e172e20e" />

Aquí escribí 0 y un número negativo. El programa me volvió a pedir la cantidad hasta que puse un valor válido.

### 2. Validación de calificaciones y nombre con espacios

<img width="953" height="634" alt="Captura de pantalla 2026-11-16 144424" src="https://github.com/user-attachments/assets/4658f824-5eb2-4d8f-b2fa-31aabc447310" />

Aquí puse calificaciones fuera de rango (170 y -67) y el programa repitió solo esa calificación. También se ve que el nombre con espacios funciona y el resumen del grupo.

### 3. Dos grupos seguidos

<img width="945" height="916" alt="Captura de pantalla 2026-11-16 144811" src="https://github.com/user-attachments/assets/ca4d39b4-f118-418d-9f26-3355ece64d40" />

En el primer grupo todos reprobaron. Después respondí s y el programa empezó otra vez con un segundo grupo que tuvo un aprobado y un reprobado. En cada resumen se ve el mejor promedio de ese grupo.

## Tipos de bucles utilizados y por qué

**`do-while` para repetir el programa.** Envuelve todo el programa. Usé `do-while` porque el grupo se tiene que procesar al menos una vez, y recién después se pregunta si quiero otro. Se repite mientras responda s.

**`do-while` para validar la cantidad de estudiantes.** Necesito pedir el dato primero para poder saber si es válido. Por eso la condición va al final: si la cantidad es 0 o menor, lo vuelve a pedir.

**`for` para recorrer los estudiantes.** Lo usé porque ya sé cuántas vueltas son: la cantidad de estudiantes que escribió el usuario. Cada vuelta procesa a un estudiante.

**`for` para recorrer las 4 calificaciones.** Cada estudiante siempre tiene 4 calificaciones, así que el número de vueltas es fijo. Dentro de este bucle voy sumando las notas en `sumaNotas`.

**`do-while` para validar cada calificación.** Está dentro del `for` de las 4 calificaciones. Pide la nota y, si no está entre 0 y 100, la pide otra vez. Como el `for` no avanza hasta que la nota sea válida, se repite solo esa calificación y no todo el estudiante.

**`do-while` para validar la respuesta s/n.** Repite la pregunta hasta que se responda s o n.

**Contadores y acumuladores.** `aprobados` y `reprobados` son contadores porque suben de 1 en 1. `sumaNotas` y `sumaPromedios` son acumuladores porque van sumando valores. `sumaNotas` se reinicia con cada estudiante, y los contadores junto con `sumaPromedios` se reinician con cada grupo nuevo.
