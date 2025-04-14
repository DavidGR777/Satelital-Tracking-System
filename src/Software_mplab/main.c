/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F26K42
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "math.h"

/*
                        Macros generales
*/
#define micro 16         // Resolución de micropasos stepper motor 
#define Angulo 1.8      // Giro en grados del motor por paso
#define pi 3.141592
#define w_max 0.07     //Velocidad máxima rad/s (modo manual)
//----------------------------------------------------------------

/*
                            FUNCTIONS
*/
void calibracion(void);
void recepcion(void);
void f_gps(void);
void parametros(void);
void orientacion(void);
void inicio(void);
void seguimiento(void);
void transmision(void);
void ang2msj(void);
void emergency(void);

//----------------------------------------------------------------

/*
                            Variables
*/

int8_t Rx_data[33];

uint8_t state;
bool direccion1, direccion2, bandera = 0;
uint16_t Azi, Azm, Azf, Steps_ini, Steps1[2], Steps2, pos_ini;
int El, hi, hm, hf, mi, mm, mf, Time[2];
float M1_Ang[2], M2_Ang, M1_Vel[2], M2_Vel, Frec_max;
uint32_t N1 = 0, Yr1 = 0, N2 = 0, Yr2 = 0;  
float Avance, ang2step,ang2rad, w2sps, aux;

uint8_t msj1[4], msj2[4], cont = 0, contador = 0; 
uint16_t ref = 0;

bool flag_timer_Tx = 0, flag_gps = 0, Apagar1 = 0, Apagar2 = 0;
uint16_t tope1 = 0, tope2 = 0;

int buffer[15], gps = 0;
int8_t hora_gps, min_gps;
float Az_gps;

/*
                         Main application
*/
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // INICIALIZACIÓN
    state = 0;
    Avance = Angulo/micro;
    ang2step = 1/Avance;  
    w2sps = 180/Avance/pi;
    aux = w2sps*4/36500;
    ang2rad = pi/180;
    ENABLE_SetLow();
    LED_VERDE_SetLow();
    LED_ROJO_SetLow();
    
    //N1 = 223*ang2step;
    //N2 = 82*ang2step;
    Frec_max = w_max*w2sps;
    tope1 = 1/(w_max*aux);
    tope2 = 1/(w_max*aux);
    
    MS0_SetHigh();
    MS1_SetHigh();
    MS2_SetHigh();
    
    //MULTIPLICAR X2 TANTO LA VELOCIDAD COMO LA CANTIDAD DE PASOS A DAR
    
    while (1)
    {  
        switch(state){
            case 0: 
                calibracion();
                recepcion();
                //f_gps();
                break;
            case 1: 
                parametros();
                break;
            case 2: 
                orientacion(); 
                break;
            case 3: 
                f_gps();
                inicio();
                break;
            case 4:
                seguimiento();
                break;
        }   /* End switch-case */
        
        emergency();                         
        if( flag_timer_Tx ){
            flag_timer_Tx = 0;
            transmision();
        }      
       
    }   /* End while */
}   /* End main */

/*
 *                  FUNCIÓN DE RECEPCIÓN DE DATOS
*/
void recepcion(){
    if( UART1_is_rx_ready() ){
        Rx_data[contador] = UART1_Read()-48;   
        
        if( Rx_data[contador] == -38 ){
            Azi = (Rx_data[0]*100) + (Rx_data[1]*10) + (Rx_data[2]);
            Azm = (Rx_data[4]*100) + (Rx_data[5]*10) + (Rx_data[6]);
            Azf = (Rx_data[8]*100) + (Rx_data[9]*10) + (Rx_data[10]);
            El  = (Rx_data[12]*10 + Rx_data[13]);
            hi  = (Rx_data[15]*10 + Rx_data[16]);
            mi  = (Rx_data[18]*10 + Rx_data[19]);
            hm  = (Rx_data[21]*10 + Rx_data[22]);
            mm  = (Rx_data[24]*10 + Rx_data[25]);
            hf  = (Rx_data[27]*10 + Rx_data[28]);
            mf  = (Rx_data[30]*10 + Rx_data[31]);
            contador = 0;
            state = 1;
        }else contador+=1;
    }
    return;
}

/*
 *                  FUNCIÓN DE TRANSMISIÓN DE DATOS
*/
void transmision(){ 
    // TRANSFORMANDO PASOS A ÁNGULO
    ang2msj();          
    // ENVIANDOI ÁNGULO AZ
    UART1_Write(msj1[0]+48);    
    UART1_Write(msj1[1]+48);
    UART1_Write(msj1[2]+48);
    UART1_Write(msj1[3]+48);
    UART1_Write(10);            //(ganancia de 0.01))
    // ENVIANDO ÁNGULO EL
    UART1_Write(msj2[0]+48);    
    UART1_Write(msj2[1]+48);
    UART1_Write(msj2[2]+48);
    UART1_Write(msj2[3]+48);
    UART1_Write(44);  // ','         (ganancia de 0.01))         
    return;
}

// TRANSFORMACIÓN DE VEL ACTUAL 
void ang2msj(){
    ref = N1*Avance*10;                // ÁNGULO AZIMUTH
    msj1[3] = ref % 10;
    msj1[2] = ref / 10 % 10;
    msj1[1] = ref / 100 % 10;
    msj1[0] = ref / 1000 % 10;
    ref = N2*Avance*100;                // ÁNGULO ELEVATION
    msj2[3] = ref % 10;
    msj2[2] = ref / 10 % 10;
    msj2[1] = ref / 100 % 10;
    msj2[0] = ref / 1000 % 10;   
    return;
}

/*
 *                  FUNCIÓN DE CALIBRACIÓN MANUAL
*/
void calibracion(){
    
    if( AZ_R_GetValue() ){  // MOTOR AZ A LA DERECHA
        DIR1_SetLow();
        LED_VERDE_SetHigh();
        direccion1 = 0;
        Apagar1 = 1;
    }else if( AZ_L_GetValue() ){  // MOTOR AZ A LA IZQUIERDA
        DIR1_SetHigh();
        LED_VERDE_SetHigh();
        direccion1 = 1;
        Apagar1 = 1;
    }else{
        Apagar1 = 0;
        LED_VERDE_SetLow();
    }
    
    if( EL_R_GetValue() ){    // MOTOR EL A LA DERECHA
        DIR2_SetLow();
        LED_VERDE_SetHigh();
        direccion2 = 0;
        Apagar2 = 1;
    }else if( EL_L_GetValue() ){  // MOTOR EL A LA IZQUIERDA
        DIR2_SetHigh();
        LED_VERDE_SetHigh();
        direccion2 = 1;
        Apagar2 = 1;
    }else{
        Apagar2 = 0;
        LED_VERDE_SetLow();
    }
    return;
}

/*
 *                  FUNCIÓN DE USO DE GPS
*/
void f_gps(){
    if( flag_gps ){
        if( UART2_is_rx_ready() ){
            buffer[gps] = UART2_Read()-48;
            if( gps >= 15 ){
                hora_gps = buffer[9]*10 + buffer[10] - 5;
                if( hora_gps < 0 ) hora_gps = 24 - hora_gps;
                min_gps = buffer[11]*10 + buffer[12];
                //Az_gps = buffer[45]*100 + buffer[46]*10 + buffer[47] + buffer[49]*0.1;
                gps = 0;
                flag_gps = 0;
            }else gps += 1;
        }           
    }
    
    return;
}

void parametros(){
    
    //PARÁMETROS TRAMO 1
    Time[0] = ((hm-hi)*60) + ((mm-mi));
    M1_Ang[0] = abs(Azm-Azi);          // Motor Azimuth
    M1_Vel[0] = M1_Ang[0]*ang2rad/(Time[0]*60);      
    Steps1[0] = M1_Ang[0]*ang2step*2;    

    //PARÁMETROS TRAMO 2
    Time[1] = ((hf-hm)*60) + ((mf-mm));
    M1_Ang[1] = abs(Azf-Azm);          // Motor Azimuth
    M1_Vel[1] = M1_Ang[1]*ang2rad/(Time[1]*60);    
    Steps1[1] = M1_Ang[1]*ang2step*2; 
    
    M2_Ang = El;                        // Motor Elevation
    M2_Vel = M2_Ang*ang2rad/(((Time[0]+Time[1]))*30);     // En la mitad exacta de tiempo 
    Steps2 = M2_Ang*ang2step*2;   
    
    //-------------PARÁMETROS DE LA ORIENTACIÓN INICIAL--------------//
    //DIRECCIÓN DE ORIENTACIÓN
    if( Azi > 180 ){
        direccion1 = 1;
        pos_ini = 360 - Azi;
    }else{
        direccion1 = 0; 
        pos_ini = Azi;
    }
    Steps_ini = pos_ini*ang2step*2;
    
    // INICIALIZAR LA ORIENTACIÓN
    if( !direccion1 ){
        N1 = 0;
        DIR1_SetLow();
    }else{
        N1 = 360*ang2step;
        DIR1_SetHigh();
    }
    N2 = 0;
    Yr1 = 0;
    Apagar1 = 1;
    LED_VERDE_SetHigh();
    
    state = 2;
    return;
}

/*
 *                  FUNCIÓN DE ORIENTACIÓN INICIAL DEL SISTEMA
*/
void orientacion(){
    if( Yr1 >= Steps_ini){        
        //APAGAR LA ORIENTACIÓN
        LED_VERDE_SetLow();
        STEP1_SetLow();        
        Apagar1 = 0;
        
        //DIRECCIONES
        if( Azi < 180 ){
            if( Azi+180 > Azf && Azf > Azi ) direccion1 = 0;
            else direccion1 = 1;    
        }else{
            if( Azi-180 < Azf && Azi > Azf ) direccion1 = 1;
            else direccion1 = 0;    
        }
        direccion2 = 0;   
        
        state = 3;       
    }  
    return;
}

/*
 *                  FUNCIÓN DE INICIO DE SEGUIMIENTO
*/
void inicio(){
    if( AZ_R_GetValue() ){
    //if( hi == hora_gps && mi == min_gps ){
             
        if( !direccion1 ) DIR1_SetLow();
        else DIR1_SetHigh();           
        DIR2_SetLow();
        
        STEP1_SetHigh();
        STEP2_SetHigh();
            
        LED_VERDE_SetHigh();
        
        tope2 = 1/(M2_Vel*aux);   // *1000*2    a ms y luego a la mitad
        Yr1 = 0;
        Yr2 = 0;
        Apagar1 = 1;
        Apagar2 = 1;      
        state = 4; 
    }
    return;
}

/*
 *                  FUNCIÓN DE SEGUIMIENTO
*/
void seguimiento(){
    if( Yr1 <= Steps1[0] ){     // Az alcanza todo el recorrido  
        tope1 = 1/(M1_Vel[0]*aux);    // *1000*2    a ms y luego a la mitad
    }else{
        tope1 = 1/(M1_Vel[1]*aux);    // *1000*2    a ms y luego a la mitad
    }    
    
    if( Yr1 >= Steps1[0]+Steps1[1] ){     // Az alcanza todo el recorrido
        //APAGAR SEÑAL PASO DE MOTOR AZ
        STEP1_SetLow();
        DIR1_SetLow();
        Apagar1 = 0;
        Yr1 = 0;        
    }
    if( Yr2 >= Steps2 && Yr2 < Steps2*2 ){     // EL alcanza mitad del recorrido
        // INVERTIR DIRECCIÓN DE MOTOR EL
        direccion2 = 1;
        DIR2_SetHigh();
    }
    else if( Yr2 >= Steps2*2 ){   // EL alcanza todo el recorrido
        // APAGAR SEÑAL PASO MOTOR EL
        STEP2_SetLow();
        DIR2_SetLow();
        Apagar2 = 0;
        Yr2 = 0;
    }
    
    if( !Apagar1 && !Apagar2 ){ //-----------------------------
        bandera = 0;
        LED_VERDE_SetLow();
        state = 0;
    }
    return;
}

/*
 *                  FUNCIÓN DE PARADA DE EMERGENCIA
*/
void emergency(){  
    if ( EMERGENCY_GetValue() ){
        ENABLE_SetHigh(); 
        LED_ROJO_SetHigh();
    }
    return;
}