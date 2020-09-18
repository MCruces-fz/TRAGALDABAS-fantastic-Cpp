# TRAGALDABAS-fantastic-Cpp
Saeta's reconstruction for TRAGALDABAS detector with Kalman filter.

### Files:

- ***ttmatrix.cc*** contains *ttmatrix* class
- ***trpcsaeta.cc*** contains *trpcsaeta* class
- ***trpcsaetaf.cc*** contains the reconstruction

> **Cambiar los siguientes aspectos:**
> - Añadir comentarios según vaya entendido el código.
> - Cambiar los parámetros de slowness S, por S0.
> - Reunir expresiones repetidas para aligerar el texto, es decir:
>> Float_t Dz = z1 - z2, Dy = y1 - y2, Dx = x1 - x2;  
>> Float_t k2 = k*k, kdi = 1 / k2, ...;
> - Orden de las variables en las siguientes expresiones:
>> pesos * expresión * z / k
> - Separar con espacios +. -, / y dejar juntas las multiplicaciones *
> - Ordenar las asignacionnes de los valores de las matrices, de tal 
>forma que arriba estén las expresiones y abajo las copias de los valores 
>(cuando hay matrices diagonales o con valores repetidos)