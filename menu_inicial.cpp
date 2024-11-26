#include <iostream>
#include <string>
using namespace std;

const int NUM_ALUMNOS = 20; // N�mero m�ximo de alumnos

// Estructura para almacenar los datos personales de los alumnos
struct Alumno {
    string nombre;
    string grupo;
    string carrera;
    float calificaciones[8]; // Calificaci�n global para cada una de las 8 materias
    bool activo = false; // Bandera para verificar si el alumno est� registrado
};

// Estructura para almacenar los nombres de las materias
struct Materias {
    string nombreMaterias[8];
};

// Funci�n para mostrar el men�
void mostrarMenu() {
    cout << "\n--- Men\xA3 Principal ---" << endl;
    cout << "1. Dar de alta un alumno (incluyendo calificaciones)" << endl;
    cout << "2. Consultar alumno por nombre" << endl;
    cout << "3. Eliminar un alumno" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opci\xA2n: ";
}

// Funci�n para dar de alta a un alumno (incluyendo calificaciones)
void altaAlumno(Alumno alumnos[], int &numAlumnos, Materias &materias) {
    if (numAlumnos >= NUM_ALUMNOS) {
        cout << "Ya se alcanz\xA2 el m\xA0ximo de alumnos." << endl;
        return;
    }

    cout << "\n--- Dar de alta a un alumno ---" << endl;
    cout << "Nombre: ";
    cin.ignore(); // Limpiar el buffer antes de usar getline
    getline(cin, alumnos[numAlumnos].nombre); // Captura el nombre del alumno
    cout << "Grupo: ";
    getline(cin, alumnos[numAlumnos].grupo);  // Captura el grupo del alumno
    cout << "Carrera: ";
    getline(cin, alumnos[numAlumnos].carrera); // Captura la carrera del alumno

    // Captura de las calificaciones globales para cada materia
    for (int j = 0; j < 8; j++) {
        cout << "Calificaci\xA2n global para la materia " << materias.nombreMaterias[j] << ": ";
        cin >> alumnos[numAlumnos].calificaciones[j];
    }
    cin.ignore(); // Limpiar el buffer despu�s de la entrada num�rica

    alumnos[numAlumnos].activo = true; // Activar el registro del alumno
    numAlumnos++;
    cout << "Alumno registrado con \x82xito." << endl;
}

// Funci�n para consultar los datos de un alumno
void consultarAlumno(Alumno alumnos[], int numAlumnos, Materias &materias) {
    if (numAlumnos == 0) {
        cout << "No hay alumnos registrados." << endl;
        return;
    }

    string nombre;
    cout << "\n--- Consultar alumno ---" << endl;
    cout << "Ingrese el nombre del alumno: ";
    cin.ignore(); // Limpiar el buffer antes de usar getline
    getline(cin, nombre);

    bool encontrado = false;
    for (int i = 0; i < numAlumnos; i++) {
        if (alumnos[i].nombre == nombre && alumnos[i].activo) {
            encontrado = true;
            cout << "\n--- Datos del alumno ---" << endl;
            cout << "Nombre: " << alumnos[i].nombre << endl;
            cout << "Grupo: " << alumnos[i].grupo << endl;
            cout << "Carrera: " << alumnos[i].carrera << endl;
            cout << "--- Calificaciones ---" << endl;
            float suma = 0;
            for (int j = 0; j < 8; j++) {
                cout << "Materia: " << materias.nombreMaterias[j] << endl;
                cout << "  Calificaci\xA2n global: " << alumnos[i].calificaciones[j] << endl;
                suma += alumnos[i].calificaciones[j];
            }
            float promedio = suma / 8;
            cout << "Promedio: " << promedio << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "Alumno no encontrado." << endl;
    }
}

// Funci�n para eliminar un alumno
void eliminarAlumno(Alumno alumnos[], int &numAlumnos) {
    if (numAlumnos == 0) {
        cout << "No hay alumnos registrados." << endl;
        return;
    }

    string nombre;
    cout << "\n--- Eliminar alumno ---" << endl;
    cout << "Ingrese el nombre del alumno a eliminar: ";
    cin.ignore();
    getline(cin, nombre);

    bool encontrado = false;
    for (int i = 0; i < numAlumnos; i++) {
        if (alumnos[i].nombre == nombre && alumnos[i].activo) {
            encontrado = true;
            alumnos[i].activo = false; // Marcar como inactivo
            cout << "Alumno eliminado con \x82xito." << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "Alumno no encontrado o ya eliminado." << endl;
    }
}

int main() {
    Alumno alumnos[NUM_ALUMNOS]; // Array de 20 alumnos
    Materias materias;

    // Captura de los nombres de las materias al inicio
    cout << "Ingrese los nombres de las 8 materias:" << endl;
    for (int i = 0; i < 8; i++) {
        cout << "Materia " << i + 1 << ": ";
        getline(cin, materias.nombreMaterias[i]);
    }

    int numAlumnos = 0; // Contador de alumnos registrados
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore(); // Limpiar el salto de l�nea despu�s de seleccionar una opci�n

        switch (opcion) {
            case 1:
                altaAlumno(alumnos, numAlumnos, materias);
                break;
            case 2:
                consultarAlumno(alumnos, numAlumnos, materias);
                break;
            case 3:
                eliminarAlumno(alumnos, numAlumnos);
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opci\xA2n no v\xA0lida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);

    return 0;
}
