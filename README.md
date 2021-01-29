# TRAGALDABAS-fantastic-Cpp
Saeta's reconstruction for TRAGALDABAS detector with Kalman filter.

[Good Method](https://github.com/go-hep/hep/blob/main/cmd/root2csv/main.go)


### Files:

- ***sshcopy.sh*** updates local repository by scp.
- ***soft_TT/*** is the directory with the full trufa code.

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
> - Cambiar en trpcsaetaf.cc (linea 15) Double_t vc = 299.792458; por Double_t vc = 299.8; // mm/ns y cambiar 300. por vc en las líneas 115 y 125
> - Arreglar tabulaciones en los bucles de tunpacker.cc

Utilizar este código en bash para desempaquetar los datos:
###### unpack.sh

```bash
#!/bin/bash
for i in {306..335}
do
for a in `find /media/Datos2TB/tragaldabas/data/done/alberto/T01T02T03/20150107/done/ -type f -name tr20$i* -print`; do ./dst_nov2020.sh `basename $a`; done
done
```
