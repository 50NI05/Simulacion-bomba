#include<iostream> // Mostrar datos en pantalla
#include<fstream> // leer y escribir en un archivo de texto
#include<windows.h> // Control de ejecucion (tiempo de refrescamiento de pantalla)
using namespace std;

int main()
{
 	string bomba="APAGADA";
	string valvula_de_desvio="CERRADA";
 	double presion=100;
 	string pantalla="ON";
 	int aux=1;
 
 
 
 	// Leemos los datos del archivo de texto prueba a traves de la funcion
 	// Sheila (Puede ser cualquier nombre)
 
 	inicio:
	
 	ifstream sheila("C:\\Users\\AMD\\Desktop\\Yo\\Programacion II\\Simulacion de la bomba\\prueba.txt"); 
  
 	string nivel_bajo; 
 	string nivel_alto;
 	string valvula_servicio;
 	string valvula_desvio;
 	string modobomba;  
  
 	sheila>>nivel_bajo>>nivel_alto>>valvula_servicio>>valvula_desvio>>modobomba; 
 
 
 	//CHEQUEO EL MODO DE OPERACION DE LA BOMBA
 
 	if (modobomba=="REMOTO")
 	{
	  	aux=0;
	  	pantalla="ON";
 	}
 
 	if (modobomba=="LOCAL")
 	{
	  	aux=1;
	  	pantalla="ON";
 	}
 
 
 
 	// HACEMOS TODOS LOS C¨¢LCULOS PARA EL MODO REMOTO AUTOMATICO
  
 	if (aux==0)
 	{
	 	// imprimimos los valores en pantalla para el modo Remoto
 		if(pantalla=="ON")
	 	{
	 		system("cls");
	 		cout <<" - La Presion= "<<presion<<endl;
	 		cout <<" - Tu bomba esta= "<<bomba<<endl; 
	 		cout <<" - El Switch de bajo nivel= "<<nivel_bajo<<endl;
	 		cout <<" - El Switch de alto nivel= "<<nivel_alto<<endl;
	 		cout <<" - La valvula de servicio esta= "<<valvula_servicio<<endl;  
	 		cout <<" - La valvula de desvio esta= "<<valvula_desvio<<endl; 
	 		cout <<" - La salida de valvula de desvio esta= "<<valvula_de_desvio<<endl; 
	    	cout <<"    ***    MODO AUTOMATICO REMOTO     ***";
	 		pantalla ="OFF"; 
		}

		//  Establecemos un tiempo de 1/4 de segundo para ver los cambios en la presion
		Sleep (250);
    
    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
    
												// Simulamos la Presion    
    
/////////////////////////////////////               ACCION NUEVA                    //////////////////////////////
    
     	if (valvula_desvio=="ABIERTA" and valvula_servicio=="ABIERTA" and bomba=="APAGADA")
     	{
	     	presion = presion - 5;
	     	pantalla = "ON";
	 	}
	 
	 	if (valvula_desvio=="ABIERTA" and valvula_servicio=="ABIERTA" and bomba=="ENCENDIDA" and presion>32)
     	{
	     	presion = presion - 2;
	     	pantalla = "ON";
	 	}
	 
	 	if (valvula_desvio=="ABIERTA" and valvula_servicio=="ABIERTA" and bomba=="ENCENDIDA" and presion<32)
     	{
	    	presion = presion - 0.5;
	     	pantalla = "ON";
		}
	 
	 	if (valvula_desvio=="ABIERTA" and valvula_servicio=="CERRADA" and bomba=="APAGADA")
     	{
     		presion = presion - 1;
     		pantalla = "ON";
	 	}
	 
	 	if (valvula_desvio=="ABIERTA" and valvula_servicio=="CERRADA" and bomba=="ENCENDIDA")
     	{
	     	presion = presion + 2;
	     	pantalla = "ON";
	 	}
    
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////                 ACCION MODIFICADA                   /////////////////////////////////
    
     	if (valvula_desvio=="CERRADA" and valvula_servicio=="CERRADA" and bomba=="ENCENDIDA")
    	{
     		presion = presion + 3;
        	pantalla = "ON";
 		}
 
     	if (valvula_desvio=="CERRADA" and valvula_servicio=="ABIERTA" and bomba=="APAGADA")
    	{
     		presion = presion - 3;
        	pantalla = "ON";
 		}
 
     	if (valvula_desvio=="CERRADA" and valvula_servicio=="ABIERTA" and bomba=="ENCENDIDA" and presion<32)
    	{
     		presion = presion + 1;
        	pantalla = "ON";
 		}		
 
      	if (valvula_desvio=="CERRADA" and valvula_servicio=="ABIERTA" and bomba=="ENCENDIDA" and presion>32)
    	{
     		presion = presion - 1;
        	pantalla = "ON";
 		}
 
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
 									//impedimos que la presion de negativo
  
      	if (presion<0)
    	{
     		presion=0;
        	pantalla ="ON";
 		}

    									// Controlamos el encendido y apagado de la bomba
    
////////////////////////////////////                   ACCION MODIFCADA                         /////////////////////////////
    
      	if (nivel_alto=="OFF" and nivel_bajo=="OFF" and bomba=="ENCENDIDA")
    	{
     		bomba = "APAGADA";
        	pantalla ="ON";
 		} 
  
      	if (nivel_alto=="OFF" and nivel_bajo=="ON" and presion<20 and bomba=="APAGADA")
    	{
     		bomba = "ENCENDIDA";
        	pantalla = "ON";
 		}  
 		
      	if (nivel_alto=="OFF" and nivel_bajo=="ON" and presion>40 and bomba=="ENCENDIDA")
    	{
     		bomba = "APAGADA";
        	pantalla = "ON";
 		} 
 
///////////////////////////////////                    ACCION NUEVA                           ///////////////////////////

      	if (nivel_alto=="OFF" and nivel_bajo=="ON" and presion<32 and bomba=="APAGADA")
      	{
      		bomba="ENCENDIDA";
      		pantalla ="ON";
	  	}
	  
	  	if (nivel_alto=="ON" and nivel_bajo=="OFF" and bomba=="ENCENDIDA")
      	{
	      	bomba="APAGADA";
	      	pantalla ="ON";
	  	}
	  
	  	if (nivel_alto=="ON" and nivel_bajo=="ON" and presion<20 and bomba=="APAGADA")
      	{
		  	bomba="ENCENDIDA";
		  	pantalla ="ON";
	  	}
	  
	  	if (nivel_alto=="ON" and nivel_bajo=="ON" and presion>40 and bomba=="ENCENDIDA")
      	{
      		bomba="APAGADA";
      		pantalla ="ON";
	  	}
	  
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////       CONTROLAMOS LA VALVULA DE DESVIO (ABRIR Y CERRAR)       /////////////////////////
    
       	if (nivel_alto=="OFF" and nivel_bajo=="OFF")
       	{
       		valvula_de_desvio="ABIERTA";
       		pantalla="ON";
	   	}
	   
	   	if (nivel_alto=="OFF" and nivel_bajo=="ON")
       	{
       		valvula_de_desvio="ABIERTA";
       		pantalla="ON";
	   	}
	   
	   	if (nivel_alto=="ON" and nivel_bajo=="OFF")
       	{
       		valvula_de_desvio="CERRADA";
       		pantalla="ON";
	   	}
	   
	   	if (nivel_alto=="ON" and nivel_bajo=="ON")
       	{
       		valvula_de_desvio="CERRADA";
       		pantalla="ON";
	   	}
 	}
 
  // PRESENTAMOS LOS DATOS DEL MODO LOCAL
  
 	if (aux==1)
 	{
 		// imprimimos los valores en pantalla para el modo Local
 
 		if(pantalla=="ON")
 		{
 			system("cls");
    		cout <<" * MODO LOCAL - EL PROGRAMA NO CONTROLA LA BOMBA**";
 			pantalla ="OFF"; 
   		} 
 
   	}
 
 	goto inicio;
}
