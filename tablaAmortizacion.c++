/**
 * @file tablaAmortizacion.c++
 * @author Alexisis Jara & Cesar Ramos 
 * @brief 
 * @version 0.1
 * @date 2024-02-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <fstream>
//#include <limits> 
using namespace std;

class TablaAmortizacion {
private:
    string numeroTabla;
    time_t fecha;
    float capital;
    float tazaInteresMensual;
    float totalInteres;
    float totalPagar;
    int plazo;

public:
    TablaAmortizacion() {
        numeroTabla = "000000";
        fecha = time(nullptr);
        capital = 0.0;
        tazaInteresMensual = 0.0;
        totalInteres = 0.0;
        totalPagar = 0.0;
        plazo = 0;
    }
    string obtenerNumeroTabla() {
        string numeroAleatorio;
        for (int i = 0; i < 6; ++i) {
            numeroAleatorio += to_string(rand() % 10);
        }
        return numeroAleatorio;
    }
    void mostrarFechaActual() {
        time_t tiempo_actual = time(nullptr);
        tm* fechaActual = localtime(&tiempo_actual);
        cout << (fechaActual->tm_year + 1900) << '/' << (fechaActual->tm_mon + 1) << '/'
             << fechaActual->tm_mday << endl;
    }

    float obtenerCapital() {
        do {
            cout << "Monto del credito: ";
            cin >> capital;
            if (capital <= 0) {
                cout << "Por favor, ingrese un monto de credito valido" << endl;
            }
        } while (capital <= 0);
        return capital;
    }

    float establecerTazaInteres() {
        do {
            cout << "Interes mensual: ";
            cin >> tazaInteresMensual;
            if (tazaInteresMensual <= 0) {
                cout << "Por favor, ingrese un interes valido" << endl;
            }
        } while (tazaInteresMensual <= 0);
        return tazaInteresMensual;
    }
    //arhcivo
    void guardarEnArchivo(const string& nombreArchivo, const string& contenido) {
        ofstream archivo(nombreArchivo, ios::app);
        if (archivo.is_open()) {
            archivo << contenido;
            archivo.close();
            cout << "Se ha guardado la informacion en el archivo correctamente." << endl;
        } else {
            cout << "Error al abrir el archivo para escritura." << endl;
        }
    }

    float calcularTotalInteres() {
        return capital * (tazaInteresMensual / 100);
    }

    int definirPlazo() {
        do {
            cout << "Plazo de devolucion del credito en meses: ";
            cin >> plazo;
            if (plazo <= 0) {
                cout << "Por favor, ingrese un plazo valido" << endl;
            }

        } while (plazo <= 0);
        return plazo;
    }
    //consola
    void mostrarDetallesCredito(string noTabla, float capital, float tazaInteresMensual, int plazo) {
        
        cout << "Fecha de emision: ";
        mostrarFechaActual();
        cout << "Tabla No: " << noTabla << endl;
        cout << "Capital solicitado: " << capital << endl;
        cout << "Plazo (meses): " << plazo << endl;
        cout << "Tasa de interes mensual (%): " << tazaInteresMensual << endl;
    }
    //Archivo
    void guardarEnArchivoDetalle(const string& nombreArchivo,string noTabla, float capital, float tazaInteresMensual, int plazo) {
        ofstream archivo(nombreArchivo, ios::app);
        time_t tiempo_actual = time(nullptr);
        tm* fechaActual = localtime(&tiempo_actual);

            archivo << "Fecha de emision: ";
            archivo << (fechaActual->tm_year + 1900) << '/' << (fechaActual->tm_mon + 1) << '/'<< fechaActual->tm_mday << endl;
            archivo << "Tabla No: " << noTabla << endl;
            archivo << "Capital solicitado: " << capital << endl;
            archivo << "Plazo (meses): " << plazo << endl;
            archivo << "Tasa de interes mensual (%): " << tazaInteresMensual << endl;
    }
    

    void mostrarTotales() {
        cout << "Total Interes: " << calcularTotalInteres() << endl;
        cout << "Total a pagar: " << (int)(capital + calcularTotalInteres()) << endl;
    }

    ~TablaAmortizacion() {
    }

    string getNumeroTabla() {
        return numeroTabla;
    }

    void setNumeroTabla() {
        this->numeroTabla = obtenerNumeroTabla();
    }

    time_t getFecha() {
        return fecha;
    }

    void setFecha(time_t _Fecha) {
        this->fecha = _Fecha;
    }

    float getCapital() {
        return capital;
    }

    void setCapital(float _Capital) {
        this->capital = _Capital;
    }

    float getTazaInteresMensual() {
        return tazaInteresMensual;
    }

    void setTazaInteresMensual(float _TazaInteresMensual) {
        this->tazaInteresMensual = _TazaInteresMensual;
    }

    float getTotalInteres() {
        return totalInteres;
    }

    void setTotalInteres(float _TotalInteres) {
        this->totalInteres = _TotalInteres;
    }

    float getTotalPagar() {
        return totalPagar;
    }

    void setTotalPagar(float _TotalPagar) {
        this->totalPagar = _TotalPagar;
    }

    int getPlazo() {
        return plazo;
    }

    void setPlazo(int _Plazo) {
        this->plazo = _Plazo;
    }
};

class Cliente {
private:
    int idCliente;
    string nombres;
    string apellidos;
    string dni;
    string correo;
    string direccion;

public:
    Cliente() {
        idCliente = obtenerIdCliente();
        nombres = "";
        apellidos = "";
        dni = "";
        correo = "";
        direccion = "";
    }

    int obtenerIdCliente() {
        return rand() % 9999 + 1;
    }
    //obterner texto
    string obtenerTexto(string mensaje) {
    string texto;
    cout << mensaje;
    getline(cin, texto);
    while (texto.empty()) {
        // Si está vacía, solicitar al usuario que ingrese una cadena válida
        cout << "Por favor, ingrese un valor válido." << endl;
        cout << mensaje;
        getline(cin, texto);
    }
    return texto;
}
    void obtenreNombres() {
    cout << "Cliente\n";
    nombres = obtenerTexto("Nombres:\n");
    apellidos = obtenerTexto("Apellidos:\n");
    }
    //validacion datos personales
    void obtenerInformacion(){
    do {
        dni = obtenerTexto("DNI: ");
        if (dni.length() != 10) {
            cout << "DNI no valido. No encontrado en nuestra base de datos." << endl;
        }
    } while (dni.length() != 10);
    do {
        correo = obtenerTexto("Correo electronico:\n");
        if (correo.find("@gmail.com") == string::npos && correo.find("@hotmail.com") == string::npos) {
            cout << "Ingrese un correo valido que termine en @gmail.com o @hotmail.com." << endl;
        }
    } while (correo.find("@gmail.com") == string::npos && correo.find("@hotmail.com") == string::npos);
    direccion = obtenerTexto("Direccion:\n");
    }
    //archivo
    void guardarEnArchivoCliente(const string& nombreArchivo) {
        ofstream archivo(nombreArchivo, ios::app);
            archivo << "Nombre: " << nombres << ' ' << apellidos << endl;
            archivo << "DNI: " << dni << endl;
            archivo << "Correo Electronico: " << correo << endl;
            archivo << "Direccion: " << direccion << endl;
            archivo << "ID: " << obtenerIdCliente() << endl;
    }
    //consola
    void mostrarInformacion() {
        cout <<"Nombre: " <<nombres << ' ' <<apellidos << endl;
        cout <<"DNI: " << dni << endl;
        cout <<"Correo Electronico: " <<correo << endl;
        cout <<"Direccion: " <<direccion << endl;
        cout <<"ID: " <<obtenerIdCliente() << endl;
    }
   
    ~Cliente() {
    }

    int getIdCliente() {
        return idCliente;
    }

    void setIdCliente(int _IdCliente) {
        this->idCliente = _IdCliente;
    }

    string getNombres() const {
        return nombres;
    }

    void setNombres(const string& _Nombres) {
        this->nombres = _Nombres;
    }

    string getApellidos() const {
        return apellidos;
    }

    void setApellidos(const string& _Apellidos) {
        this->apellidos = _Apellidos;
    }

    string getDni() const {
        return dni;
    }

    void setDni(const string& _Dni) {
        this->dni = _Dni;
    }

    string getCorreo() const {
        return correo;
    }

    void setCorreo(const string& _Correo) {
        this->correo = _Correo;
    }

    string getDireccion() const {
        return direccion;
    }

    void setDireccion(const string& _Direccion) {
        this->direccion = _Direccion;
    }
};

class Cuota {
private:
    int numeroCuota;
    string descripcion;
    float capital;
    float interes;
    float valor;
    int total;

public:
    Cuota() {
        numeroCuota = 0;
        descripcion = "";
        capital = 0.0;
        interes = 0.0;
        valor = 0.0;
        total = 0;
    }

    Cuota(int numeroCuota, string descripcion, float capital, float interes, float valor, int total) {
        this->numeroCuota = numeroCuota;
        this->descripcion = descripcion;
        this->capital = capital;
        this->interes = interes;
        this->valor = valor;
        this->total = total;
    }
    //consola
    void mostrarCuota(int plazo, float capital, float totalInteres) {
        int capitalTotal = capital;
        totalInteres = totalInteres / plazo;
        int capitalCuota = capitalTotal / plazo;
        valor = capital / plazo;
        total = totalInteres + valor;
        cout << "Nro\tDescripcion\tCapital\t\tValor\t\tInteres\t\tTotal\n";
        cout << setfill('0');
        //bucle para presentar las cuotas en cuncion del plazo 
        for (int i = 1; i <= plazo; i++) {
            cout << setw(3) << i << "\t";
            cout << "Cuota " << setw(3) << i << "\t";
            cout << capitalTotal << "\t\t" << valor << "\t\t" << totalInteres << "\t\t" << total << endl;
            capitalTotal -= capitalCuota;
        }
    }
    //archivo
    void guardarEnArchivoCuota(const string& nombreArchivo,int plazo, float capital, float totalInteres) {
        ofstream archivo(nombreArchivo, ios::app);
        int capitalTotal = capital;
        totalInteres = totalInteres / plazo;
        float valor = capital / plazo;
        float total = totalInteres + valor;
        float cuota = capitalTotal/plazo;
        //bucle para presentar las cuotas en cuncion del plazo 
        archivo << "Nro\tDescripcion\tCapital\t\tValor\t\tInteres\t\tTotal\n";
        archivo << setfill('0');
        for (int i = 1; i <= plazo; i++) {
            archivo << setw(3) << i << "\t";
            archivo << "Cuota " << setw(3) << i << "\t";
            archivo << capitalTotal << "\t\t" << valor << "\t\t" << totalInteres << "\t\t" << total << endl;
            capitalTotal -= cuota;
        }
    }
    ~Cuota() {
    }

    int getNumeroCuota() {
        return numeroCuota;
    }

    void setNumeroCuota(int _NumeroCuota) {
        this->numeroCuota = _NumeroCuota;
    }

    string getDescripcion() {
        return descripcion;
    }

    void setDescripcion(const string& _Descripcion) {
        this->descripcion = _Descripcion;
    }

    float getCapital() {
        return capital;
    }

    void setCapital(float _Capital) {
        this->capital = _Capital;
    }

    float getInteres() {
        return interes;
    }

    void setInteres(float _Interes) {
        this->interes = _Interes;
    }

    float getValor() {
        return valor;
    }

    void setValor(float _Valor) {
        this->valor = _Valor;
    }

    int getTotal() {
        return total;
    }

    void setTotal(int _Total) {
        this->total = _Total;
    }
};

void guardarArchivo(TablaAmortizacion& tablaAmortizacion, Cliente& cliente, Cuota& cuota,
    string numeroTabla, float capitalSolicitado, float interes, int plazo,
    float totalInteres, bool mostrarConsola);
void presentarTabla(TablaAmortizacion& tablaAmortizacion, Cliente& cliente, Cuota& cuota,
    string numeroTabla, float capitalSolicitado, float interes, int plazo,
    float totalInteres);                                               
int main() {
    system("@cls||clear");
    srand(time(nullptr));
    TablaAmortizacion tablaAmortizacion;
    Cliente cliente;
    Cuota cuota;
    cliente.obtenreNombres();
    cliente.obtenerInformacion();

    
    string numeroTabla = tablaAmortizacion.obtenerNumeroTabla();
    float capitalSolicitado = tablaAmortizacion.obtenerCapital();
    float interes = tablaAmortizacion.establecerTazaInteres();
    int plazo = tablaAmortizacion.definirPlazo();
    float totalInteres = tablaAmortizacion.calcularTotalInteres();
  
    //limpiar la consola antes de presentar la tabala para mejorar la legibilidad
    system("@cls||clear");
    presentarTabla(tablaAmortizacion, cliente, cuota, numeroTabla, capitalSolicitado, interes,
        plazo, totalInteres);
    char opcion;
    cout<<"Para generar archivo con tabla de armortizacion presione  P"<<endl;
    cin >> opcion;
    if (opcion == 'p'||opcion == 'P'){
        guardarArchivo(tablaAmortizacion, cliente, cuota, numeroTabla, capitalSolicitado, interes,
        plazo, totalInteres, true);
    }   
    return 0;
}
//procedimiento generar archivo
void guardarArchivo(TablaAmortizacion& tablaAmortizacion, Cliente& cliente, Cuota& cuota,
    string numeroTabla, float capitalSolicitado, float interes, int plazo,
    float totalInteres, bool mostrarConsola) {
    
    // Construir el nombre del archivo usando el nombre y apellidos del cliente
    string nombreArchivo = cliente.getNombres() + "_" + cliente.getApellidos() + ".txt";
    
    ofstream archivo(nombreArchivo, ios::app); // Abrir el archivo con el nombre generado

    if (archivo.is_open()) {
        archivo << "-------------------------------------------------------------------------------\n";
        archivo << "                            TABLA DE AMORTIZACIÓN                              \n";
        archivo << "                                FINANCIERA AC                                  \n";
        archivo << "-------------------------------------------------------------------------------\n";
        archivo << "Fecha de emisión: ";
        tablaAmortizacion.mostrarFechaActual();
        archivo << "Tabla No: " << numeroTabla << endl;
        archivo << "Capital solicitado: " << capitalSolicitado << endl;
        archivo << "Plazo (meses): " << plazo << endl;
        archivo << "Tasa de interés mensual (%): " << interes << endl;
        archivo << "Cliente\n";
        archivo << "-------------------------------------------------------------------------------\n";
        archivo << "Nombre: " << cliente.getNombres() << ' ' << cliente.getApellidos() << endl;
        archivo << "DNI: " << cliente.getDni() << endl;
        archivo << "Correo Electrónico: " << cliente.getCorreo() << endl;
        archivo << "Dirección: " << cliente.getDireccion() << endl;
        archivo << "ID: " << cliente.getIdCliente() << endl;
        archivo << "-------------------------------------------------------------------------------\n";
        cuota.guardarEnArchivoCuota(nombreArchivo, plazo, capitalSolicitado, totalInteres);
        archivo <<endl<<"-------------------------------------------------------------------------------\n";
        archivo << "Total Interés: " << tablaAmortizacion.calcularTotalInteres() << endl;
        archivo << "Total a pagar: " << (int)(capitalSolicitado + totalInteres) << endl;
        archivo << "-------------------------------------------------------------------------------\n";
        archivo << "                   !!!Gracias por confiar en FINANCIERA AC                     \n";
        archivo << "-------------------------------------------------------------------------------\n";
        archivo << "-------------------------------------------------------------------------------\n";
        archivo << "                    Programado por Alexis Jara & Cesar Ramos                   \n";
        archivo << "-------------------------------------------------------------------------------\n";

        archivo.close();
        if (mostrarConsola) {
            cout << "Se ha guardado la informacion en el archivo correctamente." << endl;
        }
    } else {
        cout << "Error al abrir el archivo para escritura." << endl;
    }
}
//procedimiento imprimir consola
void presentarTabla(TablaAmortizacion& tablaAmortizacion, Cliente& cliente, Cuota& cuota,
    string numeroTabla, float capitalSolicitado, float interes, int plazo,
    float totalInteres){
        cout << "-------------------------------------------------------------------------------\n";
        cout << "                            TABLA DE AMORTIZACIoN                              \n";
        cout << "                                FINANCIERA AC                                  \n";
        cout << "-------------------------------------------------------------------------------\n";
        tablaAmortizacion.mostrarDetallesCredito(numeroTabla, capitalSolicitado, interes, plazo);
        cout << "Cliente\n";
        cout << "-------------------------------------------------------------------------------\n";
        cliente.mostrarInformacion();
        cout << "-------------------------------------------------------------------------------\n";
        cuota.mostrarCuota(plazo, capitalSolicitado, totalInteres);
        cout << "-------------------------------------------------------------------------------\n";
        cout << "Total Interes: " << tablaAmortizacion.calcularTotalInteres() << endl;
        cout << "Total a pagar: " << (int)(capitalSolicitado + totalInteres) << endl;
        cout << "-------------------------------------------------------------------------------\n";
        cout << "                   !!!Gracias por confiar en FINANCIERA AC                     \n";
        cout << "-------------------------------------------------------------------------------\n";
        cout << "-------------------------------------------------------------------------------\n";
        cout << "                    Programado por Alexis Jara & Cesar Ramos                   \n";
        cout << "-------------------------------------------------------------------------------\n";
    }