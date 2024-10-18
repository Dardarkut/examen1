#include <iostream>
#include <string>
#include <cctype> 
using namespace std;

const int PRICE_SOL = 10500;
const int PRICE_SOMBRA = 20500;
const int PRICE_PREFERENCIAL = 25500;
const int SERVICE_CHARGE = 1000;

int totalTicketsSol = 0, totalTicketsSombra = 0, totalTicketsPref = 0;
int totalMoneySol = 0, totalMoneySombra = 0, totalMoneyPref = 0;

bool isDigit(const string& id) {
    for (char c : id) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool isString(const string& name) {
    for (char c : name) {
        if (!isalpha(c) && c != ' ') {
            return false;
        }
    }
    return true;
}

bool isValidLocalidad(int locality) {
    return locality >= 1 && locality <= 3;
}

bool isValidticketCount(int ticketCount) {
    return ticketCount >= 1 && ticketCount <= 4;
}


int main() {
    int locality, ticketCount;
    string buyerName, invoice, id;
    char continueInput = 'S';
    
    do {
        do {
            cout << "Ingrese el numero de factura (solo numeros): ";
            cin >> invoice;
            if (!isDigit(invoice)) {
                cout << "Error: El numero de factura debe contener solo numeros.\n";
            }
        } while (!isDigit(invoice));
     
        do {
            cout << "Ingrese la cedula del comprador (solo numeros): ";
            cin >> id;
            if (!isDigit(id)) {
                cout << "Error: La cedula debe contener solo numeros.\n";
            }
        } while (!isDigit(id));

        do {
            cout << "Ingrese el nombre del comprador (solo letras y espacios): ";
            cin.ignore();
            getline(cin, buyerName);
            if (!isString(buyerName)) {
                cout << "Error: El nombre solo puede contener letras y espacios.\n";
            }
        } while (!isString(buyerName));

        do {
            cout << "Seleccione la localidad (1: Sol Norte/Sur, 2: Sombra Este/Oeste, 3: Preferencial): ";
            cin >> locality;
            if (!isValidLocalidad(locality)) {
                cout << "Error: Localidad no valida. Ingrese 1, 2 o 3.\n";
            }
        } while (!isValidLocalidad(locality));

        do {
            cout << "Ingrese la cantidad de entradas (maximo 4 por cliente): ";
            cin >> ticketCount;
            if (!isValidticketCount(ticketCount)) {
                cout << "Error: La cantidad maxima de entradas por cliente es 4.\n";
            }
        } while (!isValidticketCount(ticketCount));

        int ticketPrice = 0;
        string localityName;
        switch (locality) {
            case 1:
                ticketPrice = PRICE_SOL;
                localityName = "Sol Norte/Sur";
                totalTicketsSol += ticketCount;
                totalMoneySol += ticketCount * ticketPrice;
                break;
            case 2:
                ticketPrice = PRICE_SOMBRA;
                localityName = "Sombra Este/Oeste";
                totalTicketsSombra += ticketCount;
                totalMoneySombra += ticketCount * ticketPrice;
                break;
            case 3:
                ticketPrice = PRICE_PREFERENCIAL;
                localityName = "Preferencial";
                totalTicketsPref += ticketCount;
                totalMoneyPref += ticketCount * ticketPrice;
                break;
        }

        int subtotal = ticketPrice * ticketCount;
        int serviceCharges = SERVICE_CHARGE * ticketCount;
        int totalToPay = subtotal + serviceCharges;

        cout << "\nResumen de la venta:\n";
        cout << "Numero de factura: " << invoice << endl;
        cout << "Cedula: " << id << endl;
        cout << "Nombre del comprador: " << buyerName << endl;
        cout << "Localidad: " << localityName << endl;
        cout << "Cantidad de entradas: " << ticketCount << endl;
        cout << "Subtotal: " << subtotal << " colones\n";
        cout << "Cargos por servicios: " << serviceCharges << " colones\n";
        cout << "Total a pagar: " << totalToPay << " colones\n";

        cout << "\n¿Desea ingresar otra venta? (S/N): ";
        cin >> continueInput;
        
    } while (continueInput == 'S' || continueInput == 's');
    
    cout << "\nEstadisticas finales:\n";
    cout << "Cantidad de entradas en Sol Norte/Sur: " << totalTicketsSol << endl;
    cout << "Acumulado de dinero en Sol Norte/Sur: " << totalMoneySol << " colones\n";
    cout << "Cantidad de entradas en Sombra Este/Oeste: " << totalTicketsSombra << endl;
    cout << "Acumulado de dinero en Sombra Este/Oeste: " << totalMoneySombra << " colones\n";
    cout << "Cantidad de entradas en Preferencial: " << totalTicketsPref << endl;
    cout << "Acumulado de dinero en Preferencial: " << totalMoneyPref << " colones\n";

    return 0;
}
