#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>
#include <arpa/inet.h>
#define	PORT 	2500
#define	M	50000
void horayfecha();
int main()
{
	int fd1,longitudservidor;	//fd1 para crear el socket
	int n; //contiene la cantidad de caracteres leidos o escritos=?
	struct sockaddr_in	servidor;		//informacion del servidor
	struct sockaddr_in	cliente;		//informacion del cliente
	char buf[200],ipremitente[200];					//Buffer donde el servidor va a leer el mensaje.
	printf("\t--------Aplicacion Cliente--------\n");
	
	//Control de error para el socket
	fd1 = socket (AF_INET, SOCK_DGRAM, 0);
	
	if (fd1<0){	//Creo el socket
		printf("Error en socket()\n");
		exit(-1);				//finaliza el programa
	}
	bzero((char *) & cliente, sizeof(cliente));	//pone a 0 todos los valores=?
	bzero (buf,200);
	cliente.sin_family 	 = AF_INET;		//
	cliente.sin_addr.s_addr = INADDR_ANY;		//Obtengo la dirección automatica del servidor
	cliente.sin_port	 = htons (PORT);	//Dir del puerto
	
	if(bind(fd1, (struct sockaddr *) &cliente, sizeof(cliente)) < 0){
		printf("Error en bind()\n");
		exit(-1);				//finaliza el programa
	}
	//En este punto no hubo errores, entonces puedo comenzar la recepción.
	printf("Bienvenido!, esperando mensaje...\n");
	while(1){
	longitudservidor=sizeof(servidor); 
	n=recvfrom(fd1,(char *)&buf,sizeof(buf),0,(struct sockaddr *) &servidor, &longitudservidor);
	buf[n]='\n';
	//ipremitente=inet_ntoa(servidor.sin_addr);
	if(n<0){
		perror("Error");	
	}
	else{	
		horayfecha();
		printf("Recibido desde: %s----Puerto: %d\n",inet_ntoa(servidor.sin_addr),htons(servidor.sin_port));
		printf("Mensaje: %s\n\n",buf);
		}
	if(strcmp(buf,"cerrar")==0){break;}
	}
	close(fd1);
	return 0;	
	
}
void horayfecha(){
	time_t tiempo = time(0);
	struct tm *tlocal=localtime(&tiempo);
	char fecha[128];
	strftime(fecha,128, "%d/%m/%y %H:%M:%S", tlocal);
	printf("Fecha y Hora: %s\n",fecha);
	return;
}

