#include <main.h>
#int_RB
int boton_de_inicio  = input_state(PIN_A0);
int motor_Derecho    = PIN_B0;
int inversa_derecha  = PIN_B1;
int motor_Izquierdo  = PIN_B2;
int inversa_izquierda= PIN_B3;
int Sensor_Derecho   = input_state(PIN_B4);
int Sensor_Izquierdo = input_state(PIN_B5) + 1; 
int sensores = Sensor_derecho + Sensor_Izquierdo;
int on_off = 0;
void  RB_isr(void) 
{
   switch(sensores){
   case 1:
      while(Sensor_Derecho == 1){
      output_low(motor_Izquierdo);
      }
      output_high(motor_Izquierdo);
      break;
   case 2:
      while(Sensor_Derecho == 1){
      output_low(motor_Derecho);
      }
      output_high(motor_Derecho);
      break;
   case 3:
      while(Sensor_Derecho == 1 && Sensor_Izquierdo == 1){
      output_low(motor_Derecho);
      output_low(motor_Izquierdo);
      output_high(inversa_derecha);
      output_high(inversa_izquierda);
      }
      output_low(inversa_derecha);
      output_low(inversa_izquierda);
      output_high(motor_Derecho);
      output_high(motor_Izquierdo);
   }      
}



void main()
{

   setup_timer_3(T3_DISABLED|T3_DIV_BY_1);
   enable_interrupts(INT_RB);
   enable_interrupts(GLOBAL);
     if(boton_de_inicio == 1){
      if(on_off == 1){
      on_off = 0;
      }else{
      on_off = 1;
      }
   }
   if(on_off == 1){
   output_high(motor_derecho);
   output_high(motor_izquierdo);
   }else{
   output_low(motor_derecho);
   output_low(motor_izquierdo);
   }

}
