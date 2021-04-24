service Calculadora{
   void ping(),
   i32 suma(1:i32 num1, 2:i32 num2),
   i32 resta(1:i32 num1, 2:i32 num2),
   i32 multiplicacion(1:i32 num1, 2:i32 num2),
   i32 division(1:i32 num1, 2:i32 num2),
   list<i32> suma_vectores(1:list<i32> vec1, 2:list<i32> vec2),
   list<i32> resta_vectores(1:list<i32> vec1, 2:list<i32> vec2),
   i32 producto_escalar(1:list<i32> vec1, 2:list<i32> vec2),
   list<i32> producto_vectorial(1:list<i32> vec1, 2:list<i32> vec2),
}
