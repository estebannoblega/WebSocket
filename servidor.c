#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include<arpa/inet.h>



#define	N 	50100
#define	M	50000
#define PORT_CL	2500

void leercadena(char c[200]);
int menu();
int main()
{
	int fd1,PORT,longcliente,max,opcion=1,enter;
	int n; 		//contiene la cantidad de caracteres leidos o escritos=?
	struct sockaddr_in	servidor;		//informacion del servidor
	struct sockaddr_in	cliente;		//informacion del cliente
	char buf[200];					//Buffer donde el servidor va a leer el mensaje.
	PORT = M+rand() % (N-M+1);
	printf("\t--------Aplicacion Servidor--------\n");
	
	//Control de error para el socket
	fd1 = socket(AF_INET, SOCK_DGRAM, 0);
	if (fd1<0){	//Creo el socket
		perror("Error en socket(). Error\n");
		exit(-1);				//finaliza el programa
	}
	bzero(&servidor.sin_zero, sizeof(servidor));	//pone a 0 todos los valores=?
	bzero(&cliente.sin_zero, sizeof(cliente));	//pone a 0 todos los valores=?
	bzero (buf,200);
	//Defino el servidor
	servidor.sin_family 	 = AF_INET;		//
	servidor.sin_addr.s_addr = INADDR_ANY;		//Obtengo la dirección automatica del servidor
	servidor.sin_port	 = htons (PORT);	//Dir del puerto
	//Defino el cliente
	cliente.sin_family 	 = AF_INET;		//
	cliente.sin_addr.s_addr = inet_addr("192.168.1.11");	//indico la dirección del cliente
	cliente.sin_port	 = htons (PORT_CL);	//Dir del puerto
	if(bind(fd1, (struct sockaddr *) &servidor, sizeof(servidor)) < 0){
		perror("Error en bind(). Error\n");
		exit(-1);				//finaliza el programa
	}
	//En este punto no hubo errores, entonces puedo comenzar la transmisión.
	printf("Bienvenido!, recuerde: Para salir presione 2\n");
	longcliente = sizeof(cliente);
	while(opcion!=2){
		leercadena(buf);
		max = strlen(buf)+1;
		if(strlen(buf)>200){
			printf("El mensaje no puede poseer mas de 200 caracteres\n");
		}
		else{					//Envio el mensaje
			n=sendto(fd1,buf,max,0,(struct sockaddr*)&cliente,longcliente);
			if(n<0){
				perror("Error al enviar el mensaje, Error");			
			}
			else{	printf("Mensaje envidado!\n");
				bzero (buf,200);			
			}
		}
		
		opcion=menu();
	 }
		
	close(fd1);
	return 0;
}	
	
//Función para leer la cadena
void leercadena(char c[200]){
	printf ("Escriba su mensaje:\n");	
	scanf("%[^\n]s",c);
	fflush(stdin);
}
int menu(){
	int valor=0;
	printf ("Desea enviar otro mensaje:\n1-SI\n2-NO\n");	
	scanf("%d",&valor);
	getchar();
	return valor;
}

