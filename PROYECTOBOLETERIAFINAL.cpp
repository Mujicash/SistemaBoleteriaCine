#include<iostream>
using namespace std;

struct Datos_clientes{
    int codCliente; //llave
    int dni;
    char Apellido[20];
    char Nombre[20];
    int diaNac;
    int mesNac;
    int anioNac;
};

struct Compra{
    int numCompra; //llave
    int dia;
    int mes;
    int anio;
};

struct Funciones{
    int codFun;
    int codPeli;
    int hora_inicio;
    int hora_fin;
    int capacidad;
};

struct Detalle_compra{
    int numCompra;
    int codFuncion;
    int codEntrad;
    int codCliente;
    int cantEntrada;
};

struct Peliculas{
    int codigoPel;
    char nomPeli[30];
    char director[20];
    char pais[20];
    char genero[20];
    int anio;
};

struct Entradas{
    char nom[20];
    int cod; //lave
    int mont;
};

//Menu
void inicio(FILE *EN, Entradas tipos, FILE *CO, Compra camp_compras, FILE *CLI, Datos_clientes cliente, FILE *DC, Detalle_compra detalle, FILE *FU, Funciones fun, FILE *PE, Peliculas pelis);
int menuPrincipal();
int menuModulos();
int menuArchivos();
int menuLlenarPrincipal();
int menuMostrarTabla();
bool pago();
int metodo_pago();
void titulo_principal(void);
//3 modulos principales
void procesoVenta(FILE *CO, Compra camp_compras, FILE *CLI, Datos_clientes cliente, FILE *DC, Detalle_compra detalle, FILE *FU, Funciones fun, FILE *PE, Peliculas pelis);
void procesoRegistrar(FILE *CO, Compra camp_compras);
void modulos(FILE *EN, Entradas tipos, FILE *CO, Compra camp_compras, FILE *CLI, Datos_clientes cliente, FILE *DC, Detalle_compra detalle, FILE *FU, Funciones fun, FILE *PE, Peliculas pelis);
//crear archivos
void crearArchivos(FILE *EN, FILE *CLI, FILE *CO, FILE *DC, FILE *PE, FILE *FU);
void crearEntradas(FILE *F);
void crearCliente(FILE *F);
void crearCompra(FILE *F);
void crearDetalleCompra(FILE *F);
void crearPeliculas(FILE *F);
void crearFunciones(FILE *F);
//llenar tablas
void llenarTablasPrincipales(FILE *EN, Entradas tipos, FILE *PE, Peliculas pelis, FILE *FU, Funciones fun);
void validarCodEntrada(int x, int &z);
void TipoEntradas(FILE *F, Entradas x);
void validarCodCliente(int x, int &z);
void IngresarCliente(FILE *F, Datos_clientes &x);
void validarCodCompra(int x, int &z);
void IngresarCompra(FILE *F, Compra &x);
void llenarDetalleCompra(FILE *F, Detalle_compra x, int &y,int cant);
void calcSubtotal(Detalle_compra &x, int &y, FILE *EN, Entradas z, int cant); 
void buscarEntrada(FILE *EN, Entradas x, int y, bool &z);
void validarCodIngPeli(int x, int &z);
void llenarPeliculas(FILE *F, Peliculas x); // Digitar las peliculas que hay en cartelera.
void validarcodPeli(FILE *F, int c, Peliculas x, int &y);
void validarCodFun(int x, int &y);
void llenarFunciones(FILE *F, Funciones x);
void cartelera(int &x,FILE *PE, Peliculas pelis, FILE *FU, Funciones fun, bool &continuacion,int &cant); 
int validacion(FILE *FU, Funciones fun, bool x, int y, int &z,int &cant);
int validacionFun(bool x);
void validarFunPeli(FILE *F, Funciones x, int y, int z, int &w);
void validarNumAsientos(FILE *F, Funciones x, int y, int &cant, int &z);
bool preguntaContinuacion();
void buscarPeli(FILE *PE, Peliculas x, int y, bool &z);
void buscarPelInFun(FILE *F, Funciones x, int y);
void ActualizarCantAsientos(FILE *F, Funciones x, int y, int z);
//validar pago
bool pagoTarjeta();
bool pagoEfectivo();
void resetearTablas(bool x,Detalle_compra y, FILE *F, int z);
void modificaciones(FILE *F, Detalle_compra x, int z);
void eliDatDetCompra(int x);
void eliDatCompra(int x);
void eliDatCliente(int x);
void eliDatFuncion(int x, int y);
//Impresion de boleta
void imprimirBoleta(FILE *F, Detalle_compra y);
void imprimirTipos(FILE *F, Detalle_compra y, int &x, int z);
void buscarPrecio(int x, int &y);
void imprimirCliente(Detalle_compra x);
void imprimirCompra(Detalle_compra x);
void imprimirPelicula(Funciones x);
void imprimirFuncion(Detalle_compra x);
// Ingreso a sala
void validarEntrada(FILE *F, Compra x, int y);
//Mostrar tablas
void tablas(FILE *EN, Entradas tipos, FILE *CO, Compra camp_compras, FILE *CLI, Datos_clientes cliente, FILE *DC, Detalle_compra detalle, FILE *FU, Funciones fun, FILE *PE, Peliculas pelis);
void mostrarEntradas(FILE *F,Entradas x);
void mostrarDataCliente(FILE *F, Datos_clientes x);
void mostrarTablaCompras(FILE *F, Compra x);
void mostrarTablaDetalleCompra(FILE *F, Detalle_compra x);
void mostrarTablaPeliculas(FILE *F, Peliculas x);
void mostrarTablaFunciones(FILE *F, Funciones x);
//Informes
void informes(FILE *EN, Entradas tipos, FILE *CO, Compra camp_compras, FILE *CLI, Datos_clientes cliente, FILE *DC, Detalle_compra detalle, FILE *FU, Funciones fun, FILE *PE, Peliculas pelis);
int menuInformes();
void primerInforme(FILE *EN, Entradas tipos, FILE *DC, Detalle_compra detalle);
void calcEntradas(FILE *DC, Detalle_compra detalle, Entradas B, int &x);
void segundoInforme(FILE *FU, Funciones fun, FILE *DC, Detalle_compra detalle);
void calcFunciones(FILE *DC, Detalle_compra detalle, Funciones B, int &x);
//mesaje de salida
void salir();

int main(){
    FILE *EN, *CLI, *CO, *DC, *FU, *PE;
    Entradas tipos;
    Compra camp_compras;
    Datos_clientes cliente;
    Detalle_compra detalle;
    Funciones fun;
    Peliculas pelis;
    
    inicio(EN,tipos,CO,camp_compras,CLI,cliente,DC,detalle,FU,fun,PE,pelis);

    system("pause");
}

void titulo_principal(void) {
	cout << "\n             ======================================================================\n";
	cout << "\t\t\t\t         CINEMA FISI\n";
	cout << "             ======================================================================\n";
}

void inicio(FILE *EN, Entradas tipos, FILE *CO, Compra camp_compras, FILE *CLI, Datos_clientes cliente, FILE *DC, Detalle_compra detalle, FILE *FU, Funciones fun, FILE *PE, Peliculas pelis){
    int opc;
    char rpta;


    do{
        system("cls");
        opc = menuPrincipal();
        switch (opc){
            case 1: procesoVenta(CO,camp_compras,CLI,cliente,DC,detalle,FU,fun,PE,pelis);
                break;
            case 2: procesoRegistrar(CO,camp_compras);
                break;
            case 3: modulos(EN,tipos,CO,camp_compras,CLI,cliente,DC,detalle,FU,fun,PE,pelis);
                break;
            case 4: salir();
                break;            
            default: cout<<"Opcion Invalida"<<endl;
                break;
        }
        if(opc != 4){
            cout<<"\t\tDesea continuar en el menu principal (S/N): "; cin>>rpta;
        }
        else{
            rpta = 'N';
        }
    }while(rpta == 'S' || rpta == 's');
}

int menuPrincipal(){
    int opcion;
	titulo_principal();
    cout<<"\n\t\t\t\t        MENU PRINCIPAL\n"<<endl;
    cout<<"\n\t\t[1] Iniciar venta de boletos"<<endl;
    cout<<"\n\t\t[2] Registrar ingreso a sala"<<endl;
    cout<<"\n\t\t[3] Modulos"<<endl;
    cout<<"\n\t\t[4] Salir"<<endl;
    cout<<"\n\t\tSeleccione la opcion, colaborador: "; cin>>opcion;
 
    return opcion;
}

void procesoVenta(FILE *CO, Compra camp_compras, FILE *CLI, Datos_clientes cliente, FILE *DC, Detalle_compra detalle, FILE *FU, Funciones fun, FILE *PE, Peliculas pelis){
    bool reset, continuacion=true;
    int code, cant, asientos;

    cartelera(code,PE,pelis,FU,fun,continuacion,asientos);
    
    if(continuacion){
    	system("cls");
	    detalle.codFuncion = code;
	    IngresarCompra(CO,camp_compras);
	    detalle.numCompra = camp_compras.numCompra;
	    IngresarCliente(CLI,cliente);
	    detalle.codCliente = cliente.codCliente;
	    llenarDetalleCompra(DC,detalle,cant,asientos);
	    ActualizarCantAsientos(FU,fun,code,cant);
	    reset = pago();
	    resetearTablas(reset,detalle,DC,cant);	
	}
	
}


//INICIO IMPRESION DE BOLETO
void imprimirBoleta(FILE *F, Detalle_compra y){
    int codComp, total;
    Detalle_compra B;

    codComp = y.numCompra;
    cout<<"\n\t\t\t\t------------------"<<endl;
    cout<<"\t\t\t\tIMPRIMIENDO BOLETA"<<endl;
    cout<<"\t\t\t\t------------------"<<endl<<endl<<endl;
    cout<<"\t\t\t\tCINEMA FISI"<<endl;

    F = fopen("c:Detalle_compra","r");
    if(F == NULL){
        cout<<"\t\tNo se pudo abrir el archivo Detalle_compra"<<endl;
        system("pause");
        return;
    }

    while(!feof(F)){
        fread(&y,sizeof(y),1,F);
        if(y.numCompra == codComp){
            cout<<"\t\t\t\tNro. compra: "<<y.numCompra<<endl;
            B = y;
            break;
        }
    }
    fclose(F);

    imprimirCliente(B);
    imprimirCompra(B);
    imprimirFuncion(B);

    cout<<"\t\t\t\t-----------------------"<<endl;
    cout<<"\t\t\t\tENTRADAS CANT. SUBTOTAL"<<endl;
    imprimirTipos(F,y,total,codComp);
    cout<<"\t\t\t\t   PRECIO TOTAL: "<<total<<endl;
}

void imprimirTipos(FILE *F, Detalle_compra y, int &x, int z){
    int subtotal, code, monto;

    F = fopen("c:Detalle_compra","r");
    if(F == NULL){
        cout<<"\t\tNo se pudo abrir el archivo Detalle_compra"<<endl;
        system("pause");
        return;
    }

    x = 0;
    fread(&y,sizeof(y),1,F);
    while(!feof(F)){
        if(y.numCompra == z){
            code = y.codEntrad;
            buscarPrecio(code,monto);
            subtotal = y.cantEntrada*monto;
            cout<<"\t\t\t\t  "<<y.codEntrad<<"      "<<y.cantEntrada<<"     "<<subtotal<<endl;
        }
        x += subtotal;
        fread(&y,sizeof(y),1,F);
    }
    fclose(F);    
}

void buscarPrecio(int x, int &y){
    FILE *EN;
    Entradas tipos;

    EN = fopen("c:Entrada","r");
    if(EN == NULL){
        cout<<"\t\tNo se pudo abrir el archivo Entrada"<<endl;
        system("pause");
        return;
    }

    while(!feof(EN)){
        fread(&tipos,sizeof(tipos),1,EN);
        if(tipos.cod == x){
            y = tipos.mont;
        }
    }
    fclose(EN);
}

void imprimirCliente(Detalle_compra x){
    FILE *CLI;
    Datos_clientes cliente;

    CLI = fopen("c:Data_cliente","r");
    if(CLI == NULL){
        cout<<"\t\tNo se pudo abrir el archivo Data_cliente"<<endl;
        system("pause");
        return;
    }

    while(!feof(CLI)){
        fread(&cliente,sizeof(cliente),1,CLI);
        if(cliente.codCliente == x.codCliente){
            cout<<"\t\t\t\tCliente: "<<cliente.Apellido<<" "<<cliente.Nombre<<endl;
            break;
        }
    }
    fclose(CLI);    
}

void imprimirCompra(Detalle_compra x){
    FILE *CO;
    Compra comp;

    CO = fopen("c:Compra","r");
    if(CO == NULL){
        cout<<"\t\tNo se pudo abrir el archivo Compra"<<endl;
        system("pause");
        return;
    }

    while(!feof(CO)){
        fread(&comp,sizeof(comp),1,CO);
        if(comp.numCompra == x.numCompra){
            cout<<"\t\t\t\tFecha: "<<comp.dia<<"/"<<comp.mes<<"/"<<comp.anio<<endl;
            break;
        }
    }
    fclose(CO);
}

void imprimirPelicula(Funciones x){
    FILE *PE;
    Peliculas peli;

    PE = fopen("c:Pelicula","r");
    if(PE == NULL){
        cout<<"\t\tNo se pudo abrir el archivo Pelicula"<<endl;
        system("pause");
        return;
    }

    while(!feof(PE)){
        fread(&peli,sizeof(peli),1,PE);
        if(peli.codigoPel == x.codPeli){
            cout<<"\t\t\t\tPelicula: "<<peli.nomPeli<<endl;
            break;
        }
    }
    fclose(PE);
}

void imprimirFuncion(Detalle_compra x){
    FILE *FU;
    Funciones fun, A;

    FU = fopen("c:Funcione","r");
    if(FU == NULL){
        cout<<"\t\tNo se pudo abrir el archivo Funcion"<<endl;
        system("pause");
        return;
    }

    while(!feof(FU)){
        fread(&fun,sizeof(fun),1,FU);
        if(fun.codFun == x.codFuncion){
            A = fun;
            imprimirPelicula(A);
            cout<<"\t\t\t\tFuncion: "<<fun.codFun<<endl;
            break;
        }
    }
    fclose(FU);
}
//FIN IMPRESION DE BOLETO

void resetearTablas(bool x,Detalle_compra y, FILE *F, int z){

    if(x == false){
        modificaciones(F,y,z);
    }
    else{
        imprimirBoleta(F,y);
        cout<<"\n\t\t\t\tGRACIAS POR SU COMPRA."<<endl;
    }
}

void modificaciones(FILE *F, Detalle_compra x, int z){
    int codComp, codcliente, codfun;

    codComp = x.numCompra;
    codcliente = x.codCliente;
    codfun = x.codFuncion;
    eliDatDetCompra(codComp);
    eliDatCompra(codComp);
    eliDatCliente(codcliente);
    eliDatFuncion(codfun,z);

    cout<<"\n\t\t\t\tQUE TENGA UN BUEN DIA, REGRESE PRONTO"<<endl;
}

void eliDatDetCompra(int x){
    FILE *F, *G;
    Detalle_compra deta;
    int Rem, Ren;

    F = fopen("c:Detalle_compra","r");
    if(F == NULL){
        cout<<"\t\tNo se pudo abrir el archivo Detalle_compra"<<endl;
        system("pause");
        return;
    }
    G = fopen("c:temporal","a");
    if(G == NULL){
        cout<<"\t\tNo se pudo abrir el archivo temporal"<<endl;
        system("pause");
        return;
    }
    fread(&deta,sizeof(deta),1,F);

    while(!feof(F)){
        if(deta.numCompra != x){
            fwrite(&deta,sizeof(deta),1,G);
        }
        fread(&deta,sizeof(deta),1,F);
    }
    fclose(F);
    fclose(G);

    Rem = remove("c:Detalle_compra");
    cout<<Rem;
    Ren = rename("c:temporal","c:Detalle_compra");
    cout<<Ren;
}

void eliDatCompra(int x){
    FILE *F, *G;
    Compra comp;
    int Rem, Ren;

    F = fopen("c:Compra","r");
    if(F == NULL){
        cout<<"\t\tNo se pudo abrir el archivo Compra"<<endl;
        system("pause");
        return;
    }
    G = fopen("c:temporal","a");
    if(G == NULL){
        cout<<"\t\tNo se pudo abrir el archivo temporal"<<endl;
        system("pause");
        return;
    }
    fread(&comp,sizeof(comp),1,F);
    while(!feof(F)){
        if(comp.numCompra != x){
            fwrite(&comp,sizeof(comp),1,G);
        }
        fread(&comp,sizeof(comp),1,F);
    }
    fclose(F);
    fclose(G);

    Rem = remove("c:Compra");
    cout<<Rem;
    Ren = rename("c:temporal","c:Compra");
    cout<<Ren;
}

void eliDatCliente(int x){
    FILE *F, *G;
    Datos_clientes dcliente;
    int Rem, Ren;

    F = fopen("c:Data_cliente","r");
    if(F == NULL){
        cout<<"\t\tNo se pudo abrir el archivo Data_cliente"<<endl;
        system("pause");
        return;
    }
    G = fopen("c:temporal","a");
    if(G == NULL){
        cout<<"\t\tNo se pudo abrir el archivo temporal"<<endl;
        system("pause");
        return;
    }
    fread(&dcliente,sizeof(dcliente),1,F);
    while(!feof(F)){
        if(dcliente.codCliente != x){
            fwrite(&dcliente,sizeof(dcliente),1,G);
        }
        fread(&dcliente,sizeof(dcliente),1,F);
    }
    fclose(F);
    fclose(G);

    Rem = remove("c:Data_cliente");
    cout<<Rem;
    Ren = rename("c:temporal","c:Data_cliente");
    cout<<Ren;
}

void eliDatFuncion(int x, int y){
    FILE *F, *G;
    Funciones func;
    int Rem, Ren, aux;

    F = fopen("c:Funcione","r");
    if(F == NULL){
        cout<<"\t\tNo se pudo abrir el archivo Funcion"<<endl;
        system("pause");
        return;
    }
    G = fopen("c:temporal","a");
    if(G == NULL){
        cout<<"\t\tNo se pudo abrir el archivo temporal"<<endl;
        system("pause");
        return;
    }
    fread(&func,sizeof(func),1,F);
    while(!feof(F)){
        if(func.codFun == x){
            aux = func.capacidad + y;
            func.capacidad = aux;
            fwrite(&func,sizeof(func),1,G);
        }
        else{
            fwrite(&func,sizeof(func),1,G);
        }
        fread(&func,sizeof(func),1,F);
    }
    fclose(F);
    fclose(G);

    Rem = remove("c:Funcione");
    cout<<Rem;
    Ren = rename("c:temporal","c:Funcione");
    cout<<Ren;
}

void buscarPeli(FILE *PE, Peliculas x, int y, bool &z){

    PE = fopen("c:Pelicula","r");
    if(PE == NULL){
        cout<<"\t\tNo se pudo abrir el archivo Pelicula"<<endl;
        system("pause");
        return;
    }

	z = false;
    while(!feof(PE)){
        fread(&x,sizeof(x),1,PE);
        if(x.codigoPel == y){
            z = true;
        }
    }
    fclose(PE);

}


void validarFunPeli(FILE *F, Funciones x, int y, int z, int &w){
	
    F = fopen("c:Funcione","r");
    if(F == NULL){
        cout<<"\t\tNo se pudo abrir el archivo Funciones"<<endl;
        system("pause");
        return;
    }

    fread(&x,sizeof(x),1,F);
    while(!feof(F)){
        if(x.codPeli == y){
			if(x.codFun == z){
				w = 1;
				break;
			}else{
				
				w = 0;
			}
        }
        fread(&x,sizeof(x),1,F);
    }
    fclose(F);
    
    if(w==0){
    	cout<<"\t\tNo se ha encontrado el codigo para la funcion indicada"<<endl;
	}
}

void validarNumAsientos(FILE *F, Funciones x, int y, int &cant, int &z){
	
    F = fopen("c:Funcione","r");
    if(F == NULL){
        cout<<"\t\tNo se pudo abrir el archivo Funciones"<<endl;
        system("pause");
        return;
    }

    fread(&x,sizeof(x),1,F);
    while(!feof(F)){
        if(x.codFun == y){
			if(x.capacidad >0){
				z = 1;
				cant=x.capacidad;
				break;
			}else{
				z = 0;
			}
        }
        fread(&x,sizeof(x),1,F);
    }
    fclose(F);
    
    if(z == 0){
    	cout<<"\t\tNo hay asientos disponibles para dicha funcion"<<endl;
	}
	
}

bool preguntaContinuacion(){
	char rpta;
	bool valor;
	
	cout<<"\t\tEsta conforme con la cantidad de entradas disponibles? (S/N): ";
	cin>>rpta;
	
	if(rpta == 'S' || rpta == 's'){
		valor=true;
	}else{
		valor=false;
	}
	
	return valor;
}

int validacion(FILE *FU, Funciones fun, bool x, int y, int &z, int &cant){
    int n, vd, vp;
    bool band, aux;

    if(x == false){
        cout<<"\t\tCodigo invalido, no existe en la base de datos de Peliculas."<<endl;
        cout<<"\t\tIngrese nuevamente un codigo valido"<<endl;
        n = 0;
    }
    else{
        buscarPelInFun(FU,fun,y);
        aux=preguntaContinuacion();
        if(aux){
	        do{
	            cout<<"\t\tCodigo de funcion a ingresar: "; cin>>z;
	            validarFunPeli(FU,fun,y,z,vd);
	            validarNumAsientos(FU,fun,z,cant,vp);
	        }while(vd == 0 || vp == 0);
        	n = 1;
    	}
		else{
    		n=3;
		}
    }
    return n;
}

void cartelera(int &x,FILE *PE, Peliculas pelis, FILE *FU, Funciones fun, bool &continuacion,int &cant){
    int codepe, vd;
    bool band;

    mostrarTablaPeliculas(PE,pelis);
    do{
        cout<<"\t\tCodigo de la pelicula a ver: "; cin>>codepe;
        buscarPeli(PE,pelis,codepe,band);
        vd = validacion(FU,fun,band,codepe,x,cant);
        if(vd==3){
        	cout<<"\t\tQue tenga un buen dia"<<endl;
        	continuacion=false;
        	break;
		}
    }while(vd == 0);
}

void buscarPelInFun(FILE *F, Funciones x, int y){
    F = fopen("c:Funcione","r");
    if(F == NULL){
        cout<<"No se pudo abrir el archivo Funciones"<<endl;
        system("pause");
        return;
    }
    cout<<"\n\t\t\t\tCODFUNC  CODPELI  INICIO  FIN  ASIENTOS.DISP"<<endl;
    cout<<"\t\t\t\t=============================================="<<endl;
    fread(&x,sizeof(x),1,F);
    while(!feof(F)){
        if(x.codPeli == y){
            cout<<"\t\t\t\t  "<<x.codFun<<"      "<<x.codPeli<<"      "<<x.hora_inicio<<"     "<<x.hora_fin<<"      "<<x.capacidad<<endl;
            cout<<"\t\t\t\t=============================================="<<endl;
        }
        fread(&x,sizeof(x),1,F);
    }
    fclose(F);
}

void validarCodCompra(int x, int &z){
	FILE *F;
	Compra y;
	
	F = fopen("c:Compra","r");
	if(F == NULL){
        cout<<"\t\tError en apertura del archivo Compra"<<endl;
        system("pause");
        return;
	}
	z = 0;
	while(!feof(F)){
		fread(&y,sizeof(y),1,F);
		if(y.numCompra == x){
			z = 1;
		}
	}
	fclose(F);

	if(z == 1){
		cout<<"\t\tEl codigo ya existe. Ingrese un nuevo codigo."<<endl;
	}
}

void IngresarCompra(FILE *F, Compra &x){
    int c;
    
    cout<<"\n\t\t\t\t------COMPRA------\n"<<endl;
    do{
	    cout<<"\t\t\t\tCodigo compra: "; cin>>x.numCompra;
	    validarCodCompra(x.numCompra,c);
    }while(c==1);
    
    cout<<"\t\t\t\tDia: "; cin>>x.dia;
    cout<<"\t\t\t\tMes: "; cin>>x.mes;
    cout<<"\t\t\t\tAnio: "; cin>>x.anio;

    F = fopen("c:Compra","a");
    if(F != NULL){
        fwrite(&x,sizeof(x),1,F);
        if(!ferror(F)){
            fclose(F);
        }
        else{
            cout<<"\t\tError de escritura en el archivo Compras"<<endl;
        }
    }
    else{
        cout<<"\t\tNo se pudo abrir el archivo Compras"<<endl;
    }
}

void validarCodCliente(int x, int &z){
	FILE *F;
	Datos_clientes y;

	F = fopen("c:Data_cliente","r");
	if(F == NULL){
        cout<<"\t\tError en apertura del archivo Data_cliente"<<endl;
        system("pause");
        return;
	}

	z = 0;
	while(!feof(F)){
		fread(&y,sizeof(y),1,F);
		if(y.codCliente == x){
			z = 1;
		}
	}
	fclose(F);

	if(z == 1){
		cout<<"\t\tEl codigo ya existe. Ingrese un nuevo codigo."<<endl;
	}
}


void IngresarCliente(FILE *F, Datos_clientes &x){
    int c;
    
    cout<<"\n\t\t\t\t-----INGRESO DE NUEVO CLIENTE-----\n"<<endl;
    cout<<"\t\t\t\tDATOS DEL CLIENTE"<<endl;
    fflush(stdin);
    cout<<"\t\t\t\tApellido: "; gets(x.Apellido);
    cout<<"\t\t\t\tNombre: "; gets(x.Nombre);
    cout<<"\t\t\t\tDNI: "; cin>>x.dni;
    cout<<"\t\t\t\tFecha de nacimiento"<<endl;
    cout<<"\t\t\t\tDia: "; cin>>x.diaNac;
    cout<<"\t\t\t\tMes: "; cin>>x.mesNac;
    cout<<"\t\t\t\tAnio: "; cin>>x.anioNac;
    do{
	    cout<<"\t\t\t\tCodigo generado: "; cin>>x.codCliente;
	    validarCodCliente(x.codCliente,c);
    }while(c==1);
    
    F = fopen("c:Data_cliente","a");
    if(F != NULL){
        fwrite(&x,sizeof(x),1,F);
        if(!ferror(F)){
            fclose(F);
        }
        else{
            cout<<"\t\tError de escritura en el archivo Data_cliente"<<endl;
        }
    }
    else{
        cout<<"\t\tNo se pudo abrir el archivo Data_cliente"<<endl;
    }
}

void buscarEntrada(FILE *EN, Entradas x, int y, bool &z){

    EN = fopen("c:Entrada","r");
    if(EN == NULL){
        cout<<"\t\tNo se pudo abrir el archivo de Entradas"<<endl;
        system("pause");
        return;
    }

	z = false;
    while(!feof(EN)){
        fread(&x,sizeof(x),1,EN);
        if(x.cod == y){
           z = true;
        }
    }
    fclose(EN);

}

void calcSubtotal(Detalle_compra &x, int &y, FILE *EN, Entradas z, int cant){
    bool band;
    int cod, aux;

    do{
        cout<<"\t\t\t\tCodigo de la entrada a comprar: "; cin>>x.codEntrad;
        cod = x.codEntrad;
        buscarEntrada(EN,z,cod,band);

        if(band == true){
            cout<<"\t\t\t\tCantidad: "; cin>>x.cantEntrada;
            if(y+x.cantEntrada>cant){
            	cout<<"\t\tHa excedido la cantidad de asientos disponibles"<<endl;
            	cout<<"\t\tDigite una cantidad valida"<<endl;
            	aux=0;
			}else{
				y += x.cantEntrada;
				aux=1;
			}
        }
        else{
            cout<<"\t\tCodigo invalido, no existe en la base de datos de Peliculas."<<endl;
            cout<<"\t\tIngrese nuevamente un codigo valido"<<endl;
        }
    }while(band == false || aux == 0);
}

void llenarDetalleCompra(FILE *F, Detalle_compra x, int &y, int cant){
    char rpta;
    FILE *EN;
    Entradas tipos;

    mostrarEntradas(EN,tipos);
    
    F = fopen("c:Detalle_compra","a");
    if(F != NULL){
        y = 0;
        do{
            calcSubtotal(x,y,EN,tipos,cant);
            fwrite(&x,sizeof(x),1,F);
            cout<<"\t\tDesea comprar mas entradas? (S/N)"; cin>>rpta;
        }while(rpta == 'S' || rpta == 's');
        if(!ferror(F)){
            fclose(F);
        }
        else{
            cout<<"\t\tError de escritura en el archivo Detalle_compra."<<endl;
        }
    }
    else{
        cout<<"\t\tNo se pudo abrir el archivo Detalle_compra."<<endl;
    }
}

void ActualizarCantAsientos(FILE *F, Funciones x, int y, int z){
    FILE *G;
    int Rem, Ren, aux;
    
    F = fopen("c:Funcione","r");
    if(F == NULL){
        cout<<"\t\tNo se pudo abrir el archivo Funciones"<<endl;
        system("pause");
        return;
    }

    G = fopen("c:temporal","a");
    if(G == NULL){
        cout<<"\t\tNo se pudo abrir el archivo temporal"<<endl;
        system("pause");
        return;
    }

    fread(&x,sizeof(x),1,F);
    while(!feof(F)){
        if(x.codFun == y){
            aux = x.capacidad - z;
            x.capacidad = aux;
            fwrite(&x,sizeof(x),1,G);
        }
        else{
            fwrite(&x,sizeof(x),1,G);
        }
        fread(&x,sizeof(x),1,F);
    }
    fclose(F);
    fclose(G);

    Rem = remove("c:Funcione");
    cout<<Rem;
    Ren = rename("c:temporal","c:Funcione");
    cout<<Ren;
}

//VALIDACION METODOS DE PAGO
int metodo_pago(){
	int opc;
	
	cout<<"\n\t\tSeleccione el metodo de pago: "<<endl;
	cout<<"\n\t\tPago con tarjeta.........[1]";
	cout<<"\n\t\tPago con efectivo........[2]";
	cout<<"\n\t\tOpcion: ";
	cin>>opc;	

	return opc;
}

bool pago(){
	int opc;
	char rpta;
	bool valido, r;
	
	do{
        system("cls");
		opc=metodo_pago();
		switch(opc){
			case 1:
				valido = pagoTarjeta();
				break;
			case 2:
				valido = pagoEfectivo();
				break;
			default: cout<<"\t\topcion invalida "<<endl;
			break;
		}
		if(valido==false){
			cout<<"\n\t\t desea continuar? (s/n) "; cin>>rpta;

            if(rpta == 'N' || rpta == 'n'){
                r = false;
            }
		}else{
			r = true;
			rpta='n';
		}
	}while(rpta== 's' || rpta =='S');

    return r;
}

bool pagoEfectivo(){
	bool val;
	char rspta;
	
	fflush(stdin);
	cout<<"\t\tEl pago en efectivo es correcto (s)i-(n)o? : ";//respondido por el personal
	cin>>rspta;
	
	if(rspta=='s'|| rspta=='S'){
		val=true;
	}else{
		cout<<"\t\tPago no valido ";
		val=false;
	}
	
	return val;
}

bool pagoTarjeta(){
	bool valido;
	int nro;
	
	cout<<"\t\tDigite su clave (4): ";
	cin>>nro;
			
	if(nro > 999 && nro < 10000){
		valido=true;
	}else{
		cout<<"\t\tPago no valido ";
		valido=false;
	}
	return valido;
}

void procesoRegistrar(FILE *CO, Compra camp_compras){
    int cod;
    char rpta;

    do{
        system("cls");
        titulo_principal();
        cout<<"\t\tDigite el codigo de la compra: "; cin>>cod;
        validarEntrada(CO,camp_compras,cod);
        cout<<"\t\tDesea ingresar otro codigo de compra (S/N): "; cin>>rpta;
    }while(rpta == 'S' || rpta == 's');
}

void validarEntrada(FILE *F, Compra x, int y){
    bool r= false;

    F = fopen("c:Compra","r");
    if(F == NULL){
        cout<<"\t\tNo se pudo abrir el archivo Compra"<<endl;
        system("pause");
        return;
    }

    fread(&x,sizeof(x),1,F);
    while(!feof(F)){
        if(x.numCompra == y){
            r = true;
            cout<<"\t\tCODIGO VALIDO, DISFRUTE SU PELICULA."<<endl;
        }
        fread(&x,sizeof(x),1,F);
    }
    if(r == false){
        cout<<"\t\tCODIGO INVALIDO!!!"<<endl;
    }

    fclose(F);
}

void informes(FILE *EN, Entradas tipos, FILE *CO, Compra camp_compras, FILE *CLI, Datos_clientes cliente, FILE *DC, Detalle_compra detalle, FILE *FU, Funciones fun, FILE *PE, Peliculas pelis){
    int opc;
    char rpta;
    bool n = true;

    do{
        opc = menuInformes();
        switch(opc){
            case 1: primerInforme(EN,tipos,DC,detalle);
                break;
            case 2:segundoInforme(FU,fun,DC,detalle);
                break;
            case 3: n = false;
            	break;
            default: cout<<"\t\tOpcion invalida"<<endl;
                break;
        }
        if(n == true){
        	cout<<"\n\t\tDesea continuar en el menu-informes (S/N): "; cin>>rpta;	
		}
		else{
			rpta = 'n';
		}
    }while(rpta == 'S' || rpta == 's');

}

int menuInformes(){
    int opcion;
    system("cls");
    titulo_principal();
    cout<<"\n\t\t\t\t-----MENU INFORMES-----"<<endl;
    cout<<"\t\t\t\t1. Cantidad de entradas vendidas segun su tipo (codigo)."<<endl;
    cout<<"\t\t\t\t2. Cantidad de entradas vendidas por funcion."<<endl;
    cout<<"\t\t\t\t3. Salir."<<endl;
    cout<<"\t\t\t\tOpcion: "; cin>>opcion;

    return opcion;
}

void primerInforme(FILE *EN, Entradas tipos, FILE *DC, Detalle_compra detalle){
    int code, cant;
    Entradas B;

    EN = fopen("c:Entrada","r");
    if(EN == NULL){
        cout<<"\t\tNo se pudo abrir el archivo Entradas"<<endl;
        system("pause");
        return;
    }

    cout<<"\n\t\t\t\tRelacion de la cantidad de entradas vendidas segun su codigo"<<endl;
    cout<<"\t\t\t\t------------------------------------------------------------"<<endl;
    fread(&tipos,sizeof(tipos),1,EN);
    while(!feof(EN)){
        cant = 0;
        B = tipos;

        calcEntradas(DC,detalle,B,cant);

        cout<<"\t\t\t\tCodigo "<<B.cod<<": "<<cant<<" entradas vendidas."<<endl;
        fread(&tipos,sizeof(tipos),1,EN);
    }
    fclose(EN);
}

void calcEntradas(FILE *DC, Detalle_compra detalle, Entradas B, int &x){
    DC = fopen("c:Detalle_compra","r");
    if(DC == NULL){
        cout<<"\t\tNo se pudo abrir el archivo Detalle_compra"<<endl;
        system("pause");
        return;
    }
    fread(&detalle,sizeof(detalle),1,DC);
    while(!feof(DC)){
       if(detalle.codEntrad == B.cod){
            x += detalle.cantEntrada;
        }
       fread(&detalle,sizeof(detalle),1,DC);
    }
    fclose(DC);
}

void segundoInforme(FILE *FU, Funciones fun, FILE *DC, Detalle_compra detalle){
	int code, cant;
	Funciones B;

    FU = fopen("c:Funcione","r");
    if(FU == NULL){
        cout<<"\t\tNo se pudo abrir el archivo Funciones"<<endl;
        system("pause");
        return;
    }

    cout<<"\n\t\t\t\tRelacion de la cantidad de entradas vendidas segun su funcion"<<endl;
    cout<<"\t\t\t\t------------------------------------------------------------"<<endl;
    fread(&fun,sizeof(fun),1,FU);
    while(!feof(FU)){
        cant = 0;
        B = fun;

        calcFunciones(DC,detalle,B,cant);

        cout<<"\t\t\t\tCodigo "<<B.codFun<<": "<<cant<<" entradas vendidas."<<endl;
        fread(&fun,sizeof(fun),1,FU);
    }
    fclose(FU);
}

void calcFunciones(FILE *DC, Detalle_compra detalle, Funciones B, int &x){
    DC = fopen("c:Detalle_compra","r");
    if(DC == NULL){
        cout<<"\t\tNo se pudo abrir el archivo Detalle_compra"<<endl;
        system("pause");
        return;
    }
    fread(&detalle,sizeof(detalle),1,DC);
    while(!feof(DC)){
       if(detalle.codFuncion == B.codFun){
            x += detalle.cantEntrada;
        }
       fread(&detalle,sizeof(detalle),1,DC);
    }
    fclose(DC);
}

void modulos(FILE *EN, Entradas tipos, FILE *CO, Compra camp_compras, FILE *CLI, Datos_clientes cliente, FILE *DC, Detalle_compra detalle, FILE *FU, Funciones fun, FILE *PE, Peliculas pelis){
    int opc;
    char rpta;
    bool r = true;
    
    do{
        opc = menuModulos();
        switch (opc){
            case 1: crearArchivos(EN,CLI,CO,DC,PE,FU);
                break;
            case 2: llenarTablasPrincipales(EN,tipos,PE,pelis,FU,fun);
                break;
            case 3: tablas(EN,tipos,CO,camp_compras,CLI,cliente,DC,detalle,FU,fun,PE,pelis);
                break;
            case 4: informes(EN,tipos,CO,camp_compras,CLI,cliente,DC,detalle,FU,fun,PE,pelis);
                break;
            case 5: r = false;
            	break;
            default: cout<<"\t\tOpcion invalida"<<endl;
                break;
        }
        if(r == true){
        	cout<<"\t\tDesea continuar en el menu modulos (S/N): "; cin>>rpta;	
		}
		else{
			rpta = 'n';
		}
    }while(rpta == 'S' || rpta == 's');
}

int menuModulos(){
    int opcion;
    system("cls");
    titulo_principal();
    cout<<"\n\t\t\t\t      Menu Modulos"<<endl;
    cout<<"\t\t\t\t Elija una de las opciones"<<endl;
    cout<<"\n\t\t1. Menu creacion archivos "<<endl;
    cout<<"\n\t\t2. Llenar tablas principales"<<endl;
    cout<<"\n\t\t3. Mostrar Archivos/tablas"<<endl;
    cout<<"\n\t\t4. Mostrar informes"<<endl;
    cout<<"\n\t\t5. Salir"<<endl;
    cout<<"\n\t\tOpcion: "; cin>>opcion;

    return opcion;
}

void salir(){
    cout<<"\n\n\n\t\t\t\t GRACIAS POR UTILIZAR EL SISTEMA"<<endl;
}

void crearArchivos(FILE *EN, FILE *CLI, FILE *CO, FILE *DC, FILE *PE, FILE *FU){
    int opc;
    char rpta;
    bool n = true;

    do{
        opc = menuArchivos();
        switch(opc){
            case 1: crearEntradas(EN);
                break;
            case 2: crearCliente(CLI);
                break;
            case 3: crearCompra(CO);
                break;
            case 4: crearDetalleCompra(DC);
                break;
            case 5: crearPeliculas(PE);
                break;
            case 6: crearFunciones(FU);
                break;
            case 7: n = false;
            	break;
        }
        if(n == true){
        	cout<<"\t\tDesea abrir crear otro archivo (S/N): "; cin>>rpta;	
		}
		else{
			rpta = 'n';
		}
        
    }while(rpta == 'S' || rpta == 's');    
}

int menuArchivos(){
    int opcion;
    system("cls");
    titulo_principal();
    cout<<"\n\t\t\t\t OPCION 1: Crear Archivos"<<endl;
    cout<<"\t\t\t\t Quiero crear un archivo de\n"<<endl;
    cout<<"\n\t\t1. Entradas"<<endl;
    cout<<"\n\t\t2. Data_clientes"<<endl;
	cout<<"\n\t\t3. Compras"<<endl;
	cout<<"\n\t\t4. Detalle compras"<<endl;
    cout<<"\n\t\t5. Peliculas"<<endl;
    cout<<"\n\t\t6. Funciones"<<endl; 
    cout<<"\n\t\t7. Salir"<<endl;
    cout<<"\n\t\tOpcion: "; cin>>opcion;
    return opcion;
}

void llenarTablasPrincipales(FILE *EN, Entradas tipos, FILE *PE, Peliculas pelis, FILE *FU, Funciones fun){
    int opc;
    char rpta;
	bool n = true;
	
    do{
        opc = menuLlenarPrincipal();
        switch(opc){
            case 1: TipoEntradas(EN,tipos);
                break;
            case 2: llenarPeliculas(PE,pelis);
                break;
            case 3: llenarFunciones(FU,fun);
                break;
            case 4: n = false;
            	break;
        }
        if(n == true){
        	cout<<"\t\tDesea llenar otra tabla (S/N): "; cin>>rpta;	
		}
		else{
			rpta = 'n';
		}
        
    }while(rpta == 'S' || rpta == 's'); 
}

int menuLlenarPrincipal(){
    int opcion;
    system("cls");
    titulo_principal();
    cout<<"\n\t\t\t\tQUE TABLA PRINCIPAL DESEA LLENAR"<<endl;
    cout<<"\t\t1. Entradas"<<endl;
    cout<<"\t\t2. Peliculas"<<endl;
    cout<<"\t\t3. Funciones"<<endl;
    cout<<"\t\t4. Salir"<<endl;
    cout<<"\n\t\tOpcion: "; cin>>opcion;

    return opcion;
}

/*******************************************************************************************************************************************/
//Creacion de los archivos
void crearEntradas(FILE *F){

    F= fopen("c:Entrada","w");
    if(F == NULL){
        cout<<"\t\tNo se pudo crear el archivo Entrada"<<endl;
    }
    else{
        cout<<"\t\tArchivo Entradas creado exitosamente"<<endl;
        fclose(F);
    }
}

void crearCliente(FILE *F){
    F= fopen("c:Data_cliente","w");
    if(F == NULL){
        cout<<"\t\tNo se pudo crear el archivo Data_cliente"<<endl;
    }
    else{
        cout<<"\t\tArchivo Data_clientes creado exitosamente"<<endl;
        fclose(F);
    }
}

void crearCompra(FILE *F){
    F= fopen("c:Compra","w");
    if(F == NULL){
        cout<<"\t\tNo se pudo crear el archivo Compra."<<endl;
    }
    else{
        cout<<"\t\tArchivo Compras creado exitosamente."<<endl;
        fclose(F);
    }
}

void crearDetalleCompra(FILE *F){
    F= fopen("c:Detalle_compra","w");
    if(F == NULL){
        cout<<"\t\tNo se pudo crear el archivo Detalle_compra."<<endl;
    }
    else{
        cout<<"\t\tArchivo Detalle_compras creado exitosamente."<<endl;
        fclose(F);
    }
}

void crearPeliculas(FILE *F){
    F= fopen("c:Pelicula","w");
    if(F == NULL){
        cout<<"\t\tNo se pudo crear el archivo Pelicula."<<endl;
    }
    else{
        cout<<"\t\tArchivo Peliculas creado exitosamente."<<endl;
        fclose(F);
    }
}

void crearFunciones(FILE *F){
    F= fopen("c:Funcione","w");
    if(F == NULL){
        cout<<"\t\tNo se pudo crear el archivo Funciones."<<endl;
    }
    else{
        cout<<"\t\tArchivo Funciones creado exitosamente."<<endl;
        fclose(F);
    }
}

/*******************************************************************************************************************************************/
//CREACION DE TABLAS DEL CINE.
void validarCodEntrada(int x, int &z){
	FILE *F;
	Entradas y;
	
	F = fopen("c:Entrada","r");
	if(F == NULL){
        cout<<"\t\tError en apertura del archivo Entrada"<<endl;
        system("pause");
        return;
	}
	
	z = 0;
	while(!feof(F)){
		fread(&y,sizeof(y),1,F);
		if(y.cod == x){
			z = 1;
		}
	}
	fclose(F);

	if(z == 1){
		cout<<"\t\tEl codigo ya existe. Ingrese un nuevo codigo."<<endl;
	}
}

void TipoEntradas(FILE *F, Entradas x){
    char rpta;
    int c;
    
    do{
        system("cls");
        titulo_principal();
        cout<<"\n\t\t\t\tOpcion 1: Entradas\n"<<endl;
        fflush(stdin);
        cout<<"\t\tNombre: "; gets(x.nom);
        do{
	        cout<<"\t\tCodigo: "; cin>>x.cod;
	        validarCodEntrada(x.cod,c);
        }while(c==1);
        cout<<"\t\tValor de la entrada: "; cin>>x.mont;

        F = fopen("c:Entrada","a");
        if(F != NULL){
            fwrite(&x,sizeof(x),1,F);
            if(!ferror(F)){
                fclose(F);
            }
            else{
                cout<<"\t\tError de escritura en archivo Entradas"<<endl;
            }
        }
        else{
            cout<<"\t\tNo se pudo abrir el archivo Entradas"<<endl;
        }

        cout<<"\t\tAgregar otra entrada S/N: "; cin>>rpta;
    }while(rpta == 'S' || rpta == 's');
}

void validarCodIngPeli(int x, int &z){
	FILE *F;
	Peliculas y;

	F = fopen("c:Pelicula","r");
	if(F == NULL){
        cout<<"\t\tError en apertura del archivo Pelicula"<<endl;
        system("pause");
        return;
	}
	
	z = 0;
	while(!feof(F)){
		fread(&y,sizeof(y),1,F);
		if(y.codigoPel == x){
			z = 1;
		}
	}
	fclose(F);

	if(z == 1){
		cout<<"\t\tEl codigo ya existe. Ingrese un nuevo codigo."<<endl;
	}
}


void llenarPeliculas(FILE *F, Peliculas x){
    char rpta;
    int c;
    
    do{
        system("cls");
        titulo_principal();
        cout<<"\n\t\t\t\t Opcion 2: INGRESO DE NUEVA PELICULA"<<endl;
    	cout<<"\n\t\t\t\t Digite los datos de la pelicula\n"<<endl;
        fflush(stdin);
        cout<<"\t\tTitulo: "; gets(x.nomPeli);
        cout<<"\t\tDirector: "; gets(x.director);
        cout<<"\t\tPais: ";gets(x.pais);
		cout<<"\t\tGenero: ";gets(x.genero);
		do{
	        cout<<"\t\tCodigo: "; cin>>x.codigoPel;
	        validarCodIngPeli(x.codigoPel,c);
        }while(c==1);
        cout<<"\t\tAnio de estreno: "; cin>>x.anio;

        F = fopen("c:Pelicula","a");
        if(F != NULL){
            fwrite(&x,sizeof(x),1,F);
            if(!ferror(F)){
                fclose(F);
            }
            else{
                cout<<"\t\tError de escritura en archivo Peliculas"<<endl;
            }
        }
        else{
            cout<<"\t\tNo se pudo abrir el archivo Peliculas"<<endl;
        }
        cout<<"\n\t\tAgregar otra pelicula a la lista (S/N): "; cin>>rpta;
    }while(rpta == 'S' || rpta == 's');
}

void validarcodPeli(FILE *F, int c, Peliculas x, int &y){

    F=fopen("c:Pelicula","r");
    if(F == NULL){
        cout<<"\t\tError en apertura del archivo Pelicula"<<endl;
        system("pause");
		return;	
	}
    
    y = 0;
    while(!feof(F)){
    	fread(&x,sizeof(x),1,F);
        if(c == x.codigoPel){
            y = 1;
        }
    }
    fclose(F);

	if(y == 0){
		cout<<"\t\tNo se ha encontrado el codigo"<<endl;
	}
}

void validarCodFun(int x, int &y){
	FILE *FU;
	Funciones fun;
	
	FU = fopen("c:Funcione","r");
	if(FU == NULL){
        cout<<"\t\tError en apertura del archivo Funciones"<<endl;
        system("pause");
		return;	
	}
	
	y = 0;
	while(!feof(FU)){
		fread(&fun,sizeof(fun),1,FU);
		if(fun.codFun == x){
			y = 1;
		}
	}
	fclose(FU);
	
	if(y == 1){
		cout<<"\t\tEl codigo ya existe. Ingrese un nuevo codigo."<<endl;
	}
}

void llenarFunciones(FILE *F, Funciones x){
    char rpta;
    int vd, aux;
    Peliculas pel;
    
    do{
        system("cls");
        titulo_principal();	
        cout<<"\n\t\t\t\tOpcion 3: INGRESO DE NUEVA FUNCION"<<endl;
        cout<<"\n\t\t\t\t Digite los datos de la funcion\n"<<endl;
        do{
        	cout<<"\t\tCodigo de la funcion: "; cin>>x.codFun;
        	validarCodFun(x.codFun,aux);
		}while(aux == 1);      
        do{
	        cout<<"\t\tCodigo de la pelicula: "; cin>>x.codPeli;
	        validarcodPeli(F,x.codPeli,pel,vd);
        }while(vd == 0);
        
        cout<<"\t\tHora de inicio: "; cin>>x.hora_inicio;
        cout<<"\t\tHora fin: "; cin>>x.hora_fin;
        cout<<"\t\tCapacidad de la sala: "; cin>>x.capacidad;

        F = fopen("c:Funcione","a");
        if(F != NULL){
            fwrite(&x,sizeof(x),1,F);
            if(!ferror(F)){
                fclose(F);
            }
            else{
                cout<<"\t\tError de escritura en archivo Peliculas"<<endl;
            }
        }
        else{
            cout<<"\t\tNo se pudo abrir el archivo Peliculas"<<endl;
        }
        cout<<"\n\t\tAgregar otra funcion a la lista (S/N): "; cin>>rpta;
    }while(rpta == 'S' || rpta == 's');
}

/*******************************************************************************************************************************************/
//SE MUESTRAN LAS TABLAS
void mostrarEntradas(FILE *F,Entradas x){
    cout<<"\n\t\t\t\t-------RELACION DE ENTRADAS-------"<<endl;
    F = fopen("c:Entrada","r");
    if(F == NULL){
        cout<<"\t\tNo se pudo abrir el archivo Entradas"<<endl;
        system("pause");
        return;
    }
 
    cout<<"\t\t\t\t      TABLA DE ENTRADAS"<<endl;
    cout<<"\t\t\t\t----------------------------------"<<endl;
    cout<<"\t\t\t\t  COD       TIPO        PRECIO"<<endl;
    cout<<"\t\t\t\t----------------------------------"<<endl;
    while(!feof(F)){
        fread(&x,sizeof(x),1,F);
        if(ferror(F)){
            cout<<"\t\tError de lectura del archivo Entradas"<<endl;
            system("pause");
            return;
        }
        if(!feof(F)){
            cout<<"\t\t\t\t  "<<x.cod<<"        "<<x.nom<<"        "<<x.mont<<endl;
            cout<<"\t\t\t\t=================================="<<endl;
        }
    }
    fclose(F);
}

void mostrarDataCliente(FILE *F, Datos_clientes x){
    cout<<"\n\t\t\t\tRELACION DE CLIENTES"<<endl;
    F = fopen("c:Data_cliente","r");
    if(F == NULL){
        cout<<"\t\tNo se pudo abrir el archivo Datos_clientes"<<endl;
        system("pause");
        return;
    }

    cout<<"\n\t\t\t\t------------------------DATOS DEL CLIENTE------------------------"<<endl;
    cout<<"\t\t\t\t-----------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\tCOD     DNI      APELLIDO   NOMBRE    FECHA DE NACIMIENTO (D/M/A)"<<endl;
    cout<<"\t\t\t\t================================================================="<<endl;
    while(!feof(F)){
        fread(&x,sizeof(x),1,F);
        if(ferror(F)){
            cout<<"\t\tError de lectura del archivo Datos_clientes."<<endl;
            system("pause");
            return;
        }
        if(!feof(F)){
            cout<<"\t\t\t\t "<<x.codCliente<<"   "<<x.dni<<"   "<<x.Apellido<<"   "<<x.Nombre<<"       "<<x.diaNac<<"/"<<x.mesNac<<"/"<<x.anioNac<<endl;
            cout<<"\t\t\t\t================================================================="<<endl;
        }
    }
    fclose(F);
}

void mostrarTablaCompras(FILE *F, Compra x){
    cout<<"\t\t\t\tRELACION DE COMPRAS\n"<<endl;
    F = fopen("c:Compra","r");
    if(F == NULL){
        cout<<"\t\tNo se pudo abrir el archivo Compras"<<endl;
        system("pause");
        return;
    }

    cout<<"\t\t\t\t-----DATOS DE LA COMPRA-----"<<endl;
    cout<<"\t\t\t\t----------------------------"<<endl;
    cout<<"\t\t\t\tNo\tDia\tmes\tAnio"<<endl;
    while(!feof(F)){
        fread(&x,sizeof(x),1,F);
        if(ferror(F)){
            cout<<"\t\tError de lectura del archivo Compras."<<endl;
            system("pause");
            return;
        }
        if(!feof(F)){
            cout<<"\t\t\t\t"<<x.numCompra<<"\t"<<x.dia<<"\t"<<x.mes<<"\t"<<x.anio<<endl;
            cout<<"\t\t\t\t============================"<<endl;
        }
    }
    fclose(F); 
}

void mostrarTablaDetalleCompra(FILE *F, Detalle_compra x){
    cout<<"\t\t\t\tDETALLE DE LAS COMPRAS"<<endl;
    F = fopen("c:Detalle_compra","r");
    if(F == NULL){
        cout<<"\t\tNo se pudo abrir el archivo Detalle_compras"<<endl;
        system("pause");
        return;
    }

    cout<<"\n\t\t\t\t-------TABLA DE DETALLE COMPRAS-------"<<endl;
    cout<<"\t\t\t\t--------------------------------------"<<endl;
    cout<<"\t\t\t\tNro codENTRADA codFunc codCLIENTE CANT"<<endl;
    while(!feof(F)){
        fread(&x,sizeof(x),1,F);
        if(ferror(F)){
            cout<<"\t\tError de lectura del archivo Detalle_compras."<<endl;
            system("pause");
            return;
        }
        if(!feof(F)){
            cout<<"\t\t\t\t"<<x.numCompra<<"     "<<x.codEntrad<<"       "<<x.codFuncion<<"       "<<x.codCliente<<"     "<<x.cantEntrada<<endl;
            cout<<"\t\t\t\t======================================"<<endl;
        }
    }
    fclose(F);
}

void mostrarTablaPeliculas(FILE *F, Peliculas x){
    cout<<"\n\t\t\t\tPELICULAS DISPONIBLES"<<endl;
    F = fopen("c:Pelicula","r");
    if(F == NULL){
        cout<<"\t\tNo se pudo abrir el archivo Peliculas"<<endl;
        system("pause");
        return;
    }

    cout<<"\t\t\t\t---------------------------------"<<endl;
    while(!feof(F)){
        fread(&x,sizeof(x),1,F);
        if(ferror(F)){
            cout<<"\t\tError de lectura del archivo Peliculas"<<endl;
            system("pause");
            return;
        }
        if(!feof(F)){
            cout<<"\t\t\t\tCodigo: "<<x.codigoPel<<endl;
            cout<<"\t\t\t\tPelicula: "<<x.nomPeli<<endl;
            cout<<"\t\t\t\tDirector: "<<x.director<<endl;
            cout<<"\t\t\t\tGenero: "<<x.genero<<endl;
            cout<<"\t\t\t\tPais: "<<x.pais<<endl;
            cout<<"\t\t\t\tEstreno: "<<x.anio<<endl;
            cout<<"\t\t\t\t================================="<<endl;
        }
    }
    fclose(F);
}

void mostrarTablaFunciones(FILE *F, Funciones x){
    cout<<"\n\t\t\t\tFUNCIONES DISPONIBLES POR PELICULAS"<<endl;
    F = fopen("c:Funcione","r");
    if(F == NULL){
        cout<<"\t\tNo se pudo abrir el archivo Funciones"<<endl;
        system("pause");
        return;
    }

    cout<<"\t\t\t\t--------------------------------------------"<<endl;
    cout<<"\t\t\t\tCODFUNC  CODPELI  INICIO  FIN  ASIENTOS.DISP"<<endl;
    while(!feof(F)){
        fread(&x,sizeof(x),1,F);
        if(ferror(F)){
            cout<<"\t\tError de lectura del archivo Funciones"<<endl;
            system("pause");
            return;
        }
        if(!feof(F)){
            cout<<"\t\t\t\t  "<<x.codFun<<"      "<<x.codPeli<<"      "<<x.hora_inicio<<"     "<<x.hora_fin<<"      "<<x.capacidad<<endl;
            cout<<"\t\t\t\t============================================"<<endl;
        }
    }
    fclose(F);
}

void tablas(FILE *EN, Entradas tipos, FILE *CO, Compra camp_compras, FILE *CLI, Datos_clientes cliente, FILE *DC, Detalle_compra detalle, FILE *FU, Funciones fun, FILE *PE, Peliculas pelis){
    int opc;
    char rpta;
    bool n = true;

    do{
        opc = menuMostrarTabla();
        switch (opc){
            case 1: mostrarEntradas(EN,tipos);
                break;
            case 2: mostrarDataCliente(CLI,cliente);
                break;
            case 3: mostrarTablaCompras(CO,camp_compras);
                break;
            case 4: mostrarTablaDetalleCompra(DC,detalle);
                break;
            case 5: mostrarTablaPeliculas(PE,pelis);
                break;
            case 6: mostrarTablaFunciones(FU,fun);
                break;
            case 7: n = false;
            	break;
            default: cout<<"\t\tOpcion invalida"<<endl;
                break;
        }
        if(n == true){
            cout<<"\t\tDesea mostrar otra tabla (S/N): "; cin>>rpta;
        }
        else{
            rpta = 'N';
        }
    }while(rpta == 'S' || rpta == 's');
}


int menuMostrarTabla(){
    int opcion;
    system("cls");
    titulo_principal();
    cout<<"\n\t\t\t\tOpcion 4: QUE TABLA DESEA MOSTRAR"<<endl;
    cout<<"\t\t1. Entradas"<<endl;
    cout<<"\t\t2. Data_clientes"<<endl;
    cout<<"\t\t3. Compras"<<endl;
    cout<<"\t\t4. Detalle compras"<<endl; 
    cout<<"\t\t5. Peliculas"<<endl;  
    cout<<"\t\t6. Funciones"<<endl; 
    cout<<"\t\t7. Salir"<<endl;
    cout<<"\t\tOpcion: "; cin>>opcion;

    return opcion;
}
