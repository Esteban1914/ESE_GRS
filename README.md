# Proyecto ESE_GRS 

Este proyecto tiene como objetivo el desarrollo de una aplicaci�n
para simular el movimiento del brazo ESE_GRS de 6 articulaciones y 
generar superficies complejas utilizando planos y superficies a partir 
de puntos, l�neas y curvas con un acabado final en el editor 3D Autodesk 
Inventor.


## [Descargar ESE_GRS](https://github.com/Esteban191900/ESE_GRS-Class/tree/master/media/ESE_GRS)

![Foto de ESE_GRS](https://github.com/Esteban191900/ESE_GRS-Class/blob/master/media/ESE_GRS.png)

## Plataforma
>Windows

## Lenguaje
>C++ 

## Librerias utilizadas
> - OpenGL(Simular el brazo en un entorno 3D)
> - winsock(Conexiones por Sockets)
> - libxl(Comunicaci�n de la Aplicacion con Autodesk Inventor)

## Conexiones
> - Puerto Serie
> - Sockets(Eternet y Wifi)

## Sobre los desarrolladores
>***Creaci�n y mantenimiento del brazo f�sico:***
> - Telegram:@ACB273
>
>***Comunicaci�n entre sensores y arduino:***
> - Telegram:@Andros_Cuba_98
>
>***Comunicaci�n arduino PC y desarrollo de la aplicaci�n:***
> - Telegram:@EstebanACB2

***Importante para el desarrollo en Visual Studio 2012***
> 1. Configuration Properites->General->characterSet=Not Set
> 2. Configuration Properites->General->Common Language Runtime Support=No Common Language Runtime Support
> 3. C/C++->General->Additional Include Directories=.../libxl/include_cpp && .../freeglut/include
> 4. Linker->General->Additional Library Directories=.../freegut/lib/ && .../xlms/lib/)
> 5. Linker->Input->Additinal Dependencies=freeglut.dll && libxl.dll