#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    cout << fixed << setprecision(2);   // todos los decimales salen con 2 cifras

    char respuesta;   // guarda la respuesta s/n para repetir el programa

    // Bucle principal: repite todo el programa mientras el usuario quiera otro grupo
    do {
        int cantidadEstudiantes;
        int aprobados = 0;          // contador
        int reprobados = 0;         // contador
        double sumaPromedios = 0;   // acumulador de los promedios del grupo
        double mejorPromedio = -1;  // -1 para que cualquier promedio real lo supere
        string mejorNombre = "";

        // Bucle de validación: repite mientras la cantidad sea inválida
        do {
            cout << "Cantidad de estudiantes: ";
            cin >> cantidadEstudiantes;

            if (cantidadEstudiantes <= 0) {
                cout << "La cantidad debe ser mayor que 0. Intente nuevamente." << endl;
            }
        } while (cantidadEstudiantes <= 0);

        // Bucle for: recorre cada estudiante (se sabe cuántos son)
        for (int i = 1; i <= cantidadEstudiantes; i++) {
            string nombre;
            double nota;
            double sumaNotas = 0;   // se reinicia en cada estudiante

            cout << "--- Estudiante " << i << " ---" << endl;
            cout << "Nombre: ";
            cin.ignore();           // quita el salto de línea que dejó el cin anterior
            getline(cin, nombre);   // permite nombres con espacios

            // Bucle for: recorre las 4 calificaciones del estudiante
            for (int j = 1; j <= 4; j++) {

                // Bucle de validación: repite la misma nota hasta que esté entre 0 y 100
                do {
                    cout << "Calificacion " << j << ": ";
                    cin >> nota;

                    if (nota < 0 || nota > 100) {
                        cout << "La nota debe estar entre 0 y 100." << endl;
                    }
                } while (nota < 0 || nota > 100);

                sumaNotas += nota;  // acumula las notas para sacar el promedio
            }

            double promedio = sumaNotas / 4;
            cout << "Promedio: " << promedio << " - ";

            if (promedio >= 70) {
                cout << "Aprobado" << endl;
                aprobados++;
            }
            else {
                cout << "Reprobado" << endl;
                reprobados++;
            }

            sumaPromedios += promedio;

            // guarda al estudiante con el promedio más alto hasta ahora
            if (promedio > mejorPromedio) {
                mejorPromedio = promedio;
                mejorNombre = nombre;
            }
        }

        double promedioGrupo = sumaPromedios / cantidadEstudiantes;

        cout << endl << "===== RESUMEN =====" << endl;
        cout << "Aprobados: " << aprobados << " | Reprobados: " << reprobados << endl;
        cout << "Promedio del grupo: " << promedioGrupo << endl;
        cout << "Mejor promedio: " << mejorNombre << " (" << mejorPromedio << ")" << endl;

        // Bucle de validación: repite hasta que la respuesta sea s o n
        do {
            cout << "Desea procesar otro grupo? (s/n): ";
            cin >> respuesta;

            if (respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N') {
                cout << "Responda solo con s o n." << endl;
            }
        } while (respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N');

    } while (respuesta == 's' || respuesta == 'S');

    return 0;
}