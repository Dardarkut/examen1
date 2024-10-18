#include <iostream>
#include <string>
#include <cctype> 
using namespace std;

bool isDigit(const string& cedula) {
    for (char c : cedula) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool isString(const string& nombre) {
    for (char c : nombre) {
        if (!isalpha(c) && c != ' ') { 
            return false;
        }
    }
    return true;
}

bool isTypeEmployee(int tipoEmpleado) {
    return tipoEmpleado >= 1 && tipoEmpleado <= 3;
}

bool isFloat(const string& str) {
    bool puntoEncontrado = false;
    for (char c : str) {
        if (c == '.') {
            if (puntoEncontrado) {
                return false; 
            }
            puntoEncontrado = true;
        } else if (!isdigit(c)) {
            return false; 
        }
    }
    return !str.empty(); 
}

int main() {
    string id, name, horasStr, precioStr;
    int employeeType;
    float workedHours, hourlyRate, regularSalary, increase, grossSalary, ccssDeduction, netSalary;
    int contOperarios = 0, contTecnicos = 0, contProfesionales = 0;
    float totalNetSalaryOperarios = 0, totalNetSalaryTecnicos = 0, totalNetSalaryProfesionales = 0;
    char response;

    do {
        do {
            cout << "Ingrese la cedula del empleado (solo numeros): ";
            cin >> id;
            if (!isDigit(id)) {
                cout << "Error: La cedula debe contener solo numeros." << endl;
            }
        } while (!isDigit(id));

        do {
            cout << "Ingrese el nombre completo del empleado (solo letras y espacios): ";
            cin.ignore();
            getline(cin, name);
            if (!isString(name)) {
                cout << "Error: El nombre solo puede contener letras y espacios." << endl;
            }
        } while (!isString(name));

        do {
            cout << "Ingrese el tipo de empleado (1: Operario, 2: Tecnico, 3: Profesional): ";
            cin >> employeeType;
            if (!isTypeEmployee(employeeType)) {
                cout << "Error: El tipo de empleado debe ser 1, 2 o 3." << endl;
            }
        } while (!isTypeEmployee(employeeType));

        do {
            cout << "Ingrese la cantidad de horas laboradas (pueden ser decimales): ";
            cin >> horasStr;
            if (!isFloat(horasStr)) {
                cout << "Error: Debe ingresar un numero valido (solo numeros y punto decimal permitido)." << endl;
            } else {
                workedHours = stof(horasStr);
            }
        } while (!isFloat(horasStr));

        do {
            cout << "Ingrese el precio por hora (puede ser decimal): ";
            cin >> precioStr;
            if (!isFloat(precioStr)) {
                cout << "Error: Debe ingresar un numero valido (solo numeros y punto decimal permitido)." << endl;
            } else {
                hourlyRate = stof(precioStr);
            }
        } while (!isFloat(precioStr));

        regularSalary = workedHours * hourlyRate;

        if (employeeType == 1) {
            increase = regularSalary * 0.15;
            contOperarios++;
            totalNetSalaryOperarios += regularSalary + increase - ((regularSalary + increase) * 0.0917);
        } else if (employeeType == 2) {
            increase = regularSalary * 0.10;
            contTecnicos++;
            totalNetSalaryTecnicos += regularSalary + increase - ((regularSalary + increase) * 0.0917);
        } else if (employeeType == 3) {
            increase = regularSalary * 0.05;
            contProfesionales++;
            totalNetSalaryProfesionales += regularSalary + increase - ((regularSalary + increase) * 0.0917);
        }

        grossSalary = regularSalary + increase;
        ccssDeduction = grossSalary * 0.0917;
        netSalary = grossSalary - ccssDeduction;

        cout << "\n--- Resultados del empleado ---" << endl;
        cout << "Cedula: " << id << endl;
        cout << "Nombre: " << name << endl;
        cout << "Salario Ordinario: " << regularSalary << endl;
        cout << "Aumento: " << increase << endl;
        cout << "Salario Bruto: " << grossSalary << endl;
        cout << "Deduccion CCSS: " << ccssDeduction << endl;
        cout << "Salario Neto: " << netSalary << endl;

        cout << "\nDesea procesar otro empleado? (s/n): ";
        cin >> response;

    } while (response == 's' || response == 'S');

    cout << "\n--- Estadisticas Finales ---" << endl;

    cout << "Cantidad de empleados por tipo:" << endl;
    cout << "Operarios: " << contOperarios << endl;
    cout << "Tecnicos: " << contTecnicos << endl;
    cout << "Profesionales: " << contProfesionales << endl;

    cout << "\nAcumulado de salario neto por tipo:" << endl;
    cout << "Operarios: " << totalNetSalaryOperarios << endl;
    cout << "Tecnicos: " << totalNetSalaryTecnicos << endl;
    cout << "Profesionales: " << totalNetSalaryProfesionales << endl;

    if (contOperarios > 0) {
        cout << "\nPromedio Salario Neto Operarios: " << totalNetSalaryOperarios / contOperarios << endl;
    } else {
        cout << "No hay operarios registrados." << endl;
    }
    if (contTecnicos > 0) {
        cout << "Promedio Salario Neto Tecnicos: " << totalNetSalaryTecnicos / contTecnicos << endl;
    } else {
        cout << "No hay tecnicos registrados." << endl;
    }
    if (contProfesionales > 0) {
        cout << "Promedio Salario Neto Profesionales: " << totalNetSalaryProfesionales / contProfesionales << endl;
    } else {
        cout << "No hay profesionales registrados." << endl;
    }

    return 0;
}
