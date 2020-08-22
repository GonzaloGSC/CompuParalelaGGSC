/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Gonzalo Gabriel Salinas Campos
 * Ignacio Javier Valdés Chávez
 * Camila Tamara Carrasco Latin
 *
 * Created on 8 de mayo de 2020, 21:23
 */

#include <cstdlib>
#include <iostream>
#include <postgresql/libpq-fe.h>
#include <fstream>

using namespace std;
//Creamos las variables que se relacionaran con la base de datos
//conn llevara las credenciales y result recibira la respuesta a la consulta
PGconn *conn = NULL;
PGresult *result = NULL;
//PGresult *suma = NULL;
//Credenciales para acceder a la base de datos
char *host = "192.168.100.16";
char *port = "5432";
char *database = "psudb";
char *user = "psu";
char *passwd ="psupsu";
/*
 * 
 */
int main(int argc, char** argv) {
    //Declaracion de variables y objetos
    //int i;
    string linea;
    ofstream archivo("promedio.csv");
    conn = PQsetdbLogin(host,port,NULL,NULL,database,user,passwd);
    //Comprobamos que la conexion se realice de hacerlo ejecutara la consulta y
    //escribira en el archivo promedio.csv de lo contrario imprimira mensaje de
    //error y terminara el programa
    if (PQstatus(conn) != CONNECTION_BAD){
        cout<<"Conexion lograda con exito"<<endl;
        //realizamos la consulta pedimos el rut y el promedio redondeado
        result = PQexec(conn, "select rut, round((nem+ranking+matematicas+lenguaje+ciencias+historia)/6.0,2)  from puntajes;");
        //suma = PQexec(conn, "SELECT (nem+ranking+matematicas+lenguaje+ciencias+historia) from puntajes");
        
        //Si la respuesta a la consulta no es nula pasara este if para obtener
        //la cantidad de filas y columnas
        if(result != NULL){
            int tuplas = PQntuples(result);
            int campos = PQnfields(result);
           
            //Recorremos los campos 
            for(int i=0 ;i<tuplas; i++){
                for(int j=0;j<campos;j++){
                    //Formamos la linea con los resultados de la funcion 
                    //PQgetvalue
                    //cout << PQgetvalue(result,i,j) << "|";
                    linea=linea+PQgetvalue(result,i,j)+";";
                    
                }
                
                //Escribimos el dato en el archivo
                archivo<<linea<<endl;
                //seteamos linea para la siguiente iteracion
                linea="";
            }
            //cout<<linea<<endl;
        }
        //Cerramos el archivo y liberamos la memoria utilizada
        archivo.close();
        PQclear(result);
    }
    else{
        //Mensaje de error si la conexion ha fallado
        cout << "ERROR EN LA CONEXION" <<endl;
        return 0;
    }
    
    PQfinish(conn);
    return 0;
}

