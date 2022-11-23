#include <iostream>

double sin(double x){
   double t = x;
   double result = t;
   for (int a = 1; a < 5; a++){
      double mult = -x*x/((2*a+1)*(2*a));
      t *= mult;
      result += t;
   }
   return result;
}


int main(){
    
}
