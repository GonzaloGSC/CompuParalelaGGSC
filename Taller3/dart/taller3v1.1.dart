import 'dart:ffi';
import 'dart:io';
import 'dart:async';
import 'dart:convert';
import 'dart:math';

//Declaracion de cada lista
//Aqui se guardaran los datos de cada columna
List listaNem = new List();
List listaRanking = new List();
List listaMatematicas = new List();
List listaLenguaje = new List();
List listaHistoria = new List();
List listaCiencias = new List();

//Se guardaran los resultados obtenidos de cada operacion
//para luego mostrarlos a partir de las listas
List prom = new List();
List medianaa = new List();
List desviacion = new List();
List modad = new List();
//Declaracion de los promedios
//para utilizarlos en el calculo de la 
//desviacion estandar
double promNem=0.0;
double promRanking=0.0;
double promMatematicas=0.0;
double promLenguaje=0.0;
double promHistoria=0.0;
double promCiencias=0.0;

void main(List arguments)
{ //Abrimos el archivo
  final file = new File('puntajes.csv');
  Stream<List<int>> inputStream = file.openRead();
  String linea;
  inputStream
    .transform(utf8.decoder)       
    .transform(new LineSplitter()) 
    .listen((String line) {  
      //declaramos una variable rut para sacar la 1ra columna      
        int rut=0;
        List <dynamic> row = line.split(';'); // Separamos la linea por ";"
        if(int.tryParse(row[0])!=null)
        { //Agregamos los valores a las variables
          rut = int.tryParse(row[0]);
          //Los valores seran ingresados en listas globales
          meter(listaNem, int.tryParse(row[1]));
          meter(listaRanking, int.tryParse(row[2]));
          meter(listaMatematicas, int.tryParse(row[3]));
          meter(listaLenguaje, int.tryParse(row[4]));
          meter(listaHistoria, int.tryParse(row[5]));
          meter(listaCiencias, int.tryParse(row[6]));
          
        }

      },
      onDone: () { print('Comenzamos a operar.'); 
      //Llamamos a la funcion sumatoriapromedio
      //la cual calcula promedio
      sumatoriaprom(listaNem);
      sumatoriaprom(listaRanking);
      sumatoriaprom(listaMatematicas);
      sumatoriaprom(listaLenguaje);
      sumatoriaprom(listaHistoria);
      sumatoriaprom(listaCiencias);
      
      //Ordenamos las listas
      ordenar();
      
      //Calculamos las medianas
      mediana(listaNem);
      mediana(listaRanking);
      mediana(listaMatematicas);
      mediana(listaLenguaje);
      mediana(listaHistoria);
      mediana(listaCiencias);
      //Pasamos el dato promedio para trabajar
      //en la desviacion estandar
      pasardato();
      //Calculamos la desviacion estandar
      desviacionS(listaNem,promNem);
      desviacionS(listaRanking,promRanking);
      desviacionS(listaMatematicas,promMatematicas);
      desviacionS(listaLenguaje,promLenguaje);
      desviacionS(listaHistoria,promHistoria);
      desviacionS(listaCiencias,promCiencias);

      //Calculamos la moda
      moda(listaNem);
      moda(listaRanking);
      moda(listaMatematicas);
      moda(listaLenguaje);
      moda(listaHistoria);
      moda(listaCiencias);
      //Mostramos los resultados obtenidos
      mostrar();
      //Mostramos a los autores del trabajo
      integrantes();
      },


      onError: (e) { print(e.toString()); });
  print(linea);
}
//Guardamos los datos del csv en listas
void meter(List b, int a){
  b.add(a);
}
//Mostramos los resultados
void mostrar(){
  for(int i=0;i<prom.length;i++){
    if(i==0){
      print("Nem");
      print("Promedio: ${prom[i]}");
      print("Mediana: ${medianaa[i]}");
      print("Desviacion estandar: ${desviacion[i]}");
      print("Moda: ${modad[i]}");
      print("\n");
    }
    if(i==1){
      print("Ranking");
      print("Promedio: ${prom[i]}");
      print("Mediana: ${medianaa[i]}");
      print("Desviacion estandar: ${desviacion[i]}");
      print("Moda: ${modad[i]}");
      print("\n");
    }
    if(i==2){
      print("Matematicas");
      print("Promedio: ${prom[i]}");
      print("Mediana: ${medianaa[i]}");
      print("Desviacion estandar: ${desviacion[i]}");
      print("Moda: ${modad[i]}");
      print("\n");
    }
    if(i==3){
      print("Lenguaje");
      print("Promedio: ${prom[i]}");
      print("Mediana: ${medianaa[i]}");
      print("Desviacion estandar: ${desviacion[i]}");
      print("Moda: ${modad[i]}");
      print("\n");
    }
    if(i==4){
      print("Historia");
      print("Promedio: ${prom[i]}");
      print("Mediana: ${medianaa[i]}");
      print("Desviacion estandar: ${desviacion[i]}");
      print("Moda: ${modad[i]}");
      print("\n");
    }
    if(i==5){
      print("Ciencias");
      print("Promedio: ${prom[i]}");
      print("Mediana: ${medianaa[i]}");
      print("Desviacion estandar: ${desviacion[i]}");
      print("Moda: ${modad[i]}");
      print("\n");
    }
  }
}
//Calculamos promedio
void sumatoriaprom(List a){
  int b=0;
  double c=0.0;
  for(int i=0;i<a.length;i++){
    b+=a[i];
  }
  c=b/a.length;
  prom.add(c);
}
//Ordenamos las listas
void ordenar(){
  listaNem.sort();
  listaRanking.sort();
  listaMatematicas.sort();
  listaLenguaje.sort();
  listaHistoria.sort();
  listaCiencias.sort();
  
}
//Calculamos mediana
void mediana(List a){
  int b;
  double c= a.length/2;
  int d=c.toInt();
  if(a.length%2==0){        //Si es par seran 2 posibles modas
    b = ((a[d-1]+a[d])/2).toInt();      //Por tanto obtenemos un promedio de ambas
  }else{
    b = a[d];
  }
  medianaa.add(b);
}
//Calculamos desviacion
void desviacionS(List a, double b){
  double c;
  double diferencia=0;
  double cuadrado=0;
  double total=0;
  double varianza=0;
  for(int i=0;i<a.length;i++){
    diferencia= a[i]-b;
    cuadrado=pow(diferencia,2);
    total+=cuadrado;
  }
  varianza=total/a.length;
  c=(sqrt(varianza));
  desviacion.add(c);
}
//Mostramos a los autores
void integrantes(){
  print("Camila Carrasco Latin");
  print("Gonzalo Salinas Campos");
  print("Ignacio Valdes Chavez");
}
//Pasamos los valores de las listas promedio a las variables
void pasardato(){
  promNem=prom[0];
  promRanking=prom[1];
  promMatematicas=prom[2];
  promLenguaje=prom[3];
  promHistoria=prom[4];
  promCiencias=prom[5];
}
//Calculamos la moda
void moda(List a){
  int dato=a[0];
  var contador=0;
  var saveContadorr=0;
  var saveDato=0;
  
  for(int i=0;i<a.length;i++){
    if(dato==a[i]){
      contador+=1;
    }
    else{
      if(contador>saveContadorr){
        saveContadorr=contador;
        saveDato=dato;
      }

      dato=a[i];
      contador=1;
    }
  }
  if(saveContadorr>contador){
    contador=saveContadorr;
    dato=saveDato;
  }
  modad.add(dato);
}