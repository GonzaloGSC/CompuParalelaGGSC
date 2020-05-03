
import 'dart:ffi';
import 'dart:io';
import 'dart:async';
import 'dart:convert';

main(List arguments) /// CREAR ARCHIVO "resultados.csv" con script en carpeta "tarea en clase rut psu", luego, colocarlo en el directorio de esta tarea.
{ 
  final File file = File("resultados.csv");
  Stream<List> inputStream = file.openRead();
  inputStream
      .transform(utf8.decoder)       // transforma a codificacion UTF-8.
      .transform(new LineSplitter()) // convierte a lineas individuales stream.
      .listen((String line) 
      {

        // procesa resultados.
        int rut = 0;
        double prom = 0.0;

        List <dynamic> row = line.split(';'); // separa por puntocoma
        if(int.tryParse(row[0])!=null)
        {
          rut = int.tryParse(row[0]);
          prom = (double.tryParse(row[1])+double.tryParse(row[2])+double.tryParse(row[3])+double.tryParse(row[4])+double.tryParse(row[5])+double.tryParse(row[6]))/6;
          escribir(rut,prom);
        }
        //print('$rut, $prom');
      },
      onDone: () { print('Proceso terminado.'); },
      onError: (e) { print(e.toString()); });
}

void escribir(int r,double p)
{
  var mensaje=r.toString()+";"+p.toStringAsFixed(2)+"\n";
  var file = new File('promedios.csv');
  file.writeAsStringSync(mensaje, mode: FileMode.append);
}

void integrantes()
{
  print("Gonzalo Salinas, Camila Carrasco, Ignacio Valdes")
}